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
	: m_size(sizeof(s))
	, m_capacity(ShortCapacity)
	, m_data(nullptr)
{
	if (m_size < ShortCapacity) {		// Stack
		int i = 0;
		while (s[i] != '\0') {
			m_short[i] = s[i];
			++i;
		}
	}
	else {								// Heap
		ensureCapacity(m_size);
		m_capacity = m_size + 1;
		m_data = std::make_unique<char[]>(m_size);
		for (int i = 0; i < m_size; i++) {
			m_data[i] = m_data[i];
		}
	}
}

String::String(const char s[], size_t len) 
	: m_size(len)
	, m_capacity(ShortCapacity)
	, m_data(nullptr)
{
	if (m_size < ShortCapacity) {		// Stack
		int i = 0;
		while (i < len && s[i] != '\0') {
			m_short[i] = s[i];
			++i;
		}
	}
	else {								// Heap
		ensureCapacity(len);
		m_capacity = m_size + 1;
		m_data = std::make_unique<char[]>(m_size);
		for (int i = 0; i < len; i++) {
			m_data[i] = m_data[i];
		}
		m_short[0] = '\0';
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
		return String(&m_data[beg], end - beg);
	}
}

const char* String::toCString() const noexcept {
	if (m_size < ShortCapacity) {		// Stack
		return m_short;
	}
	else {								// Heap
		return m_data.get();
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
	if (*this == s) {
		return *this;
	}
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
	int len = m_size + 1;
	if (len < ShortCapacity - 1) {	// Stack
		m_data = nullptr;
		m_short[m_size] = c;
		m_short[m_size + 1] = '\0';
		++m_size;
	}
	else {								// Heap
		ensureCapacity(len);
		m_data[m_size] = c;
		m_data[m_size+1] = '\0';
		m_short[0] = '\0';
		++m_capacity;
		++m_size;
	}
	return *this;
}

String& String::operator+=(const String& s) noexcept {
	int len = m_size + s.m_size + 1;
	if (len < ShortCapacity - 1) {		// Stack
		m_data = nullptr;
		for (int i = m_size - 1, j = 0; i < len; i++, j++) {
			m_short[i] = s.m_short[j];
		}
		m_size += s.m_size;
	}
	else {								// Heap
		ensureCapacity(len);
		for (int i = m_size - 1, j = 0; i < len; i++, j++) {
			m_data[i] = s.m_data[j];
		}
		m_size += s.m_size;
	}
	return *this;
}

String String::operator+(char c) const noexcept {
	return String(toCString() + c);
}

String String::operator+(const String& s) const noexcept {
	const char* str = toCString();
	int so = sizeof(s.toCString());
	for (int i = 0; i < so; i++) {
		*this + s.toCString();
	}
	return String();
}

char String::operator[](size_t i) const {
	if (i > m_size) {
		throw std::out_of_range("out of range");
	}
	if (m_size < ShortCapacity) {
		return m_short[i];
	}
	else {
		return m_data[i];
	}
}

char& String::operator[](size_t i) {
	if (i > m_size) {
		throw std::out_of_range("out of range");
	}
	if (m_size < ShortCapacity) {
		return m_short[i];
	}
	else {
		return m_data[i];
	}
}

std::strong_ordering String::operator<=>(const String& s) const noexcept {
	throw std::runtime_error("not yet implemented");
}

void String::ensureCapacity(size_t capacity) {
	if (m_size < ShortCapacity - 1 || capacity % ShortCapacity < ShortCapacity - 1) {		// at least 1 slot free
		return;
	}
	else if (capacity == ShortCapacity) {		// Stack string copy into heap
		auto data = std::make_unique<char[]>(2*capacity);
		for (int i = 0; i < m_size; i++) {
			data[i] = m_data[i];
		}
		m_data = move(data);
		m_short[0] = '\0';
	}
	else {										// Heap string to heap + ShortCapacity string
		int multiplier = capacity / ShortCapacity;
		auto data = std::make_unique<char[]>((++multiplier) * ShortCapacity);
		for (int i = 0; i < m_size; i++) {
			data[i] = m_data[i];
		}
		m_data = move(data);
		m_short[0] = '\0';
	}
}