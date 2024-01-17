#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <map>
#include <variant>
#include <cassert>

using namespace std::literals;	// "abc"s

class FileStorage;	// class prototype

using Key = std::string;

class FileNode {
	friend class FileStorage;

	std::ifstream m_ifs;
	std::istream& m_is;
	std::variant<std::map<Key, FileNode>, std::string> m_data;

public:
	const FileNode& operator[](const Key& key) const {
		return map().at(key);
	}

	const FileNode& operator>>(std::string& s) const {
		s = text();
		return *this;
	}

	const FileNode& operator>>(int& i) const {
		i = stoi(text());
		return *this;
	}

	const FileNode& operator>>(bool& b) const {
		b = stoi(text());
		return *this;
	}

private:
	FileNode()
		: m_is(m_ifs)
	{}

	FileNode(const std::string& fileName, bool read)
		: m_ifs(read ? std::ifstream(fileName) : std::ifstream())
		, m_is(m_ifs)
	{
		if (read) parse();
	}

	// create inner node
	FileNode(std::istream& is)
		: m_is(is)
	{
		assert(m_data.index() == 0);
		parse();		// parse ruft immer nur die Kinder auf
	}


	// create leaf node
	FileNode(std::istream& is, const std::string& s)
		: m_is(is)
		, m_data(s)
	{
		assert(m_data.index() == 1);
	}

	std::map<Key, FileNode>& map() { 
		return std::get<std::map<Key, FileNode>>(m_data); 
	}

	const std::map<Key, FileNode>& map() const {
		return std::get<std::map<Key, FileNode>>(m_data);
	}

	const std::string& text() const {
		return std::get<std::string>(m_data);
	}

	void parse() {
		char delimiter;

		m_is >> std::ws;
		m_is >> delimiter;

		while (delimiter != '}') {
			Key key;

			m_is >> key;		// formattiertes Einlesen funktioniert bis kein Leerzeichen (Whitespaces, wie Newline, tab, ..) mehr kommt, und auch der :
			key.erase(key.size() - 1, 1);	// Doppelpunkt gelöscht

			// skip whitespaces and check nest character
			m_is >> std::ws;
			switch (m_is.peek()) {
			case '{':		// innerer Knoten
			{
				auto [it, inserted] = map().emplace(key, FileNode(m_is));
				if (!inserted) throw std::runtime_error("key "s + key + " is already defined");
				break;
			}
			case '"':		// leaf node
			{
				std::string t;

				m_is.get();
				std::getline(m_is, t, '"');		// Schlusszeichen wird konsumiert
				auto [it, inserted] = map().emplace(key, FileNode(m_is, t));
				if (!inserted) throw std::runtime_error("key "s + key + " is already defined");
				break;
			}
			default:	// int einlesen
			
				std::string t;
				m_is >> t;
				if (t.back() == ',') {
					t.erase(t.size() - 1, 1);
					m_is.unget();		// letzten char wieder zurückstellen
				}
				auto [it, inserted] = map().emplace(key, FileNode(m_is, t));
				if (!inserted) throw std::runtime_error("key "s + key + " is already defined");

			}

			m_is >> std::ws;
			m_is >> delimiter;
		}
	}
};