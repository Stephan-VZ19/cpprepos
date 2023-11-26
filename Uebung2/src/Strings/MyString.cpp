#include <memory>
#include <iostream>
#include "MyString.h"

/// <summary>
/// Author: Stephan Baumann
/// </summary>

String::String() noexcept
	: m_size(0)
	, m_capacity(ShortCapacity)
	, m_data(nullptr) 
{
	m_short[0] = '\0';
}

String::String(const String& s) noexcept
	: m_size(s.m_size)
	, m_capacity(s.m_capacity)
{
	if (s.m_size < ShortCapacity) {		// Stack
		m_data = nullptr;
		for (int i = 0; i < s.m_size; i++) {
			m_short[i] = s.m_short[i];
		}
	}
	else {								// Heap
		m_data = std::make_unique<char[]>(s.m_capacity);
		for (int i = 0; i < s.m_size; i++) {
			m_data[i] = s.m_data[i];
		}
		m_short[0] = '\0';
	}
}

String::String(String&& s) noexcept 
	: m_size(s.m_size)
	, m_capacity(s.m_capacity)
{
	if (s.m_size < ShortCapacity) {
		m_data = nullptr;
		for (int i = 0; i < s.m_size; i++) {
			m_short[i] = s.m_short[i];
		}
	}
	else {
		m_data = std::move(s.m_data);
	}
	s.m_size = 0;
	s.m_capacity = ShortCapacity;
	s.m_data = nullptr;
	m_short[0] = '\0';
}

String::String(const char s[])
	: m_size(0)
	, m_capacity(ShortCapacity)
	, m_data(nullptr)
{
	int i = 0;
	while (s[i] != '\0' || i < ShortCapacity - 1) {
		++m_size;
		m_short[i] = s[i];
	}
	m_short[i] = '\0';
	if (i > ShortCapacity -1) {
		throw std::runtime_error("string too big for stack");
	}
}

String::String(const char s[], size_t len) 
	: m_size(0)
	, m_capacity(ShortCapacity)
	, m_data(nullptr)
{
	int i = 0;
	while (i < len && (s[i] != '\0' || i < ShortCapacity - 1) ) {
		++m_size;
		m_short[i] = s[i];
	}
	m_short[i] = '\0';
	if (i > ShortCapacity - 1) {
		throw std::runtime_error("string too big for stack");
	}
}


bool String::isEmpty() const noexcept {
	return m_size == 0;
}

size_t String::length() const noexcept {
	return m_size;
}

size_t String::capacity() const noexcept {
	return m_capacity;
}

String String::substring(size_t beg, size_t end) const {
	if (beg > m_size) {
		throw std::out_of_range("out of range");
	}
	if (end <= beg || end > m_size) {
		end = m_size;
	}
	if (m_size < ShortCapacity) {		// Stack
		return String(m_short + beg, end - beg);
	}
	else {								// Heap
		throw std::runtime_error("heap not supported");
	}
}

const char* String::toCString() const noexcept {
	if (m_size < ShortCapacity) {		// Stack
		return m_short;
	}
	else {								// Heap
		return &m_data[0];
	}
}

String& String::operator=(const String& s) noexcept {
	m_size = s.m_size;
	m_capacity = s.m_capacity;
	if (m_size < ShortCapacity) {		// Stack
		m_data = nullptr;
		for (int i = 0; i < s.m_size; i++) {
			m_short[i] = s.m_short[i];
		}
	}
	else {								// Heap
		m_data = std::make_unique<char[]>(s.m_capacity);
		for (int i = 0; i < s.m_size; i++) {
			m_data[i] = s.m_data[i];
		}
		m_short[0] = '\0';
	}
	return *this;
}

String& String::operator=(String&& s) noexcept {
	m_size = s.m_size;
	m_capacity = s.m_capacity;
	if (m_size < ShortCapacity) {		// Stack
		m_data = nullptr;
		for (int i = 0; i < s.m_size; i++) {
			m_short[i] = s.m_short[i];
		}
	}
	else {								// Heap
		m_data = std::move(s.m_data);
		m_short[0] = '\0';
	}
	return *this;
}

String& String::operator+=(char c) noexcept {
	++m_size;
	++m_capacity;
	if (m_size < ShortCapacity - 1) {	// Stack
		m_data = nullptr;
		m_short[m_size] = c;
		m_short[m_size + 1] = '\0';
	}
	else {								// Heap
		m_data[m_size] = c;
		m_data[m_size+1] = '\0';
		m_short[0] = '\0';
	}
}

String& String::operator+=(const String& s) noexcept {
	throw std::runtime_error("not yet implemented");
}

String String::operator+(char c) const noexcept {
	throw std::runtime_error("not yet implemented");
}

String String::operator+(const String& s) const noexcept {
	throw std::runtime_error("not yet implemented");
}

char String::operator[](size_t i) const {
	throw std::runtime_error("not yet implemented");
}

char& String::operator[](size_t i) {
	throw std::runtime_error("not yet implemented");
}

std::strong_ordering String::operator<=>(const String& s) const noexcept {
	throw std::runtime_error("not yet implemented");
}

void String::ensureCapacity(size_t capacity) {
	throw std::runtime_error("not yet implemented");
}