#pragma once

#include <fstream>
#include <iostream>
#include <functional>
#include <stdexcept>

#include "FileNode.h"

constexpr int indentWidth = 4;

using Func = std::function<FileStorage&(FileStorage&)>;

class FileStorage {
	std::ofstream m_ofs;		// File-Stream
	std::ostream& m_os;			// Output-Stream
	int m_indentLevel = 0;		// Anzahl Einrückungen
	bool m_writing;				// Schreiben oder Lesen
	bool m_keyExpected = true;	// nächste Ausgabe ist ein Schlüssel
	bool m_firstkey = true;		// es ist der Schlüssel
	std::iostream m_root;

public:
	static constexpr bool Read = true;
	static constexpr bool Write = false;

	friend FileStorage& objectBegin(FileStorage&);
	friend FileStorage& objectEnd(FileStorage&);

	FileStorage(const std::string& fileName, bool reading)
		: m_root(fileName, reading)
		, m_ofs(reading ? std::ofstream() : std::ofstream(fileName))
		, m_os(m_ofs)
		, m_writing(!reading)
	{
		if (m_writing) objectBegin(*this);
	}

	FileStorage(std::ostream& os)
		: m_os(os)
		, m_writing(true)
	{}

	FileStorage(std::istream& is)
		: m_root(is)
		, m_writing(true)
	{}

	~FileStorage() {
		release();
	}

	void release() {
		if (m_writing) {
			m_os << std::endl;
			objectEnd(*this);
			m_os << std::endl;
			m_os.flush();
			m_ofs.close();
			m_writing = false;
		}
	}

	const FileNode& operator[](const Key& key) const {
		return m_root[key];
	}

	FileStorage& operator<<(const std::string& s) {
		if (m_keyExpected) {
			// Schlüssel ausgeben
			if (!checkKey(s)) throw std::runtime_error("invalid key");

			// write delimiter
			if (m_firstkey) {
				m_firstkey = false;
			}
			else {
				m_os << s << ": ";

				m_keyExpected = false;
			}
		}
		else {
			// StringWert ausgeben
			m_os << '"' << s << '"';

			m_keyExpected = true;
		}
		return *this;
	}

	FileStorage& opertator<<(int i) {
		if (m_keyExpected) throw std::runtime_error("key expected");
		// not completed ..
	}

	FileStorage& operator<<(Func f) {
		return f.(*this);
	}

private:
	void indent() const {
		if (m_indentLevel) m_os << std::endl;
		for (int i = 0; i < m_indentLevel * indentWidth; i++) {
			m_os << ' ';
		}
	}

	bool checkKey(const std::string& s) const {
		for (char c : s) {
			if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
				return false;
			}
		}
	}
};

inline FileStorage& objectBegin(FileStorage& fs) {
	fs.indent();
	fs.m_os << '{';
	++fs.m_indentLevel;
	fs.m_keyExpected = true;
	fs.m_firstkey = true;
	return fs;
}

inline FileStorage& objectEnd(FileStorage& fs) {
	--fs.m_indentLevel;
	fs.indent();
	fs.m_os << '}';
	fs.m_firstkey = false;
	return fs;
}