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
	if (s.m_size + 1 < ShortCapacity) {		// Stack
		m_data = nullptr;
		for (int i = 0; i < s.m_size + 1; i++) {	// +1 for 0 termination
			m_short[i] = s.m_short[i];
		}
	}
	else {								// Heap
		m_short[0] = '\0';
		m_data = std::make_unique<char[]>(s.m_capacity);
		for (int i = 0; i < s.m_size + 1; i++) {
			m_data[i] = s.m_data[i];
		}
	}
}

String::String(String&& s) noexcept 
	: m_size(s.m_size)
	, m_capacity(s.m_capacity)
{
	if (s.m_size < ShortCapacity) {
		m_data = nullptr;
		for (int i = 0; i < s.m_size + 1; i++) {
			m_short[i] = s.m_short[i];
		}
	}
	else {
		m_short[0] = '\0';
		m_data = std::move(s.m_data);
	}
	
}

String::String(const char s[])
	: m_size(0)
	, m_capacity(ShortCapacity)
{
	if (nullptr == s) {
		throw std::invalid_argument("String is nullptr");
	}
	int len = 0;
	while (s[len] != '\0') {		// find length of C-String without 0 termination
		++m_size;
		++len;
	}
	++len;							// 0 termination
	if (len < ShortCapacity) {
		m_data = nullptr;
		for (int i = 0; i < len; i++) {
			m_short[i] = s[i];
		}
	}
	else {
		m_short[0] = '\0';
		m_capacity = 0;
		m_data = std::make_unique<char[]>(len);
		for (int i = 0; i < len; i++) {
			m_data[i] = m_data[i];
			++m_capacity;
		}
	}
}

String::String(const char s[], size_t len) 
	: m_size(len)
{
	++len;
	if (nullptr == s) {
		throw std::invalid_argument("String is nullptr");
	}
	if (len < ShortCapacity) {
		m_data = nullptr;
		m_capacity = ShortCapacity;
		int i = 0;
		while (i < len) {
			m_short[i] = s[i];
			++i;
		}
	}
	else {
		m_short[0] = '\0';
		m_capacity = len;
		m_data = std::make_unique<char[]>(len);
		for (int i = 0; i < len; i++) {
			m_data[i] = m_data[i];
		}
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
	if (*this == s) {
		return *this;
	}
	m_size = s.m_size;
	m_capacity = s.m_capacity;
	if (s.m_size < ShortCapacity) {		// Stack
		m_data = nullptr;
		for (int i = 0; i < s.m_size; i++) {
			m_short[i] = s.m_short[i];
		}
	}
	else {								// Heap
		m_short[0] = '\0';
		m_data = std::make_unique<char[]>(s.m_capacity);
		for (int i = 0; i < s.m_size; i++) {
			m_data[i] = s.m_data[i];
		}		
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
		m_short[0] = '\0';
		m_data = std::move(s.m_data);
	}
	return *this;
}

String& String::operator+=(char c) noexcept {
	size_t len = m_size + 1;
	if (len < ShortCapacity - 1) {	// Stack
		m_data = nullptr;
		m_short[len] = c;
		m_short[len + 1] = '\0';
		++m_capacity;
		++m_size;
	}
	else {								// Heap
		ensureCapacity(len);
		m_data[len] = c;
		m_data[len+1] = '\0';
		m_short[0] = '\0';
		++m_capacity;
		++m_size;
	}
	return *this;
}

String& String::operator+=(const String& s) noexcept {
	size_t len = m_size + s.m_size + 1;
	if (len < ShortCapacity) {		// Stack
		m_data = nullptr;
		for (int i = m_size - 1, j = 0; i < s.m_size + 1; i++, j++) {
			m_short[i] = s.m_short[j];
		}	
	}
	else {								// Heap
		ensureCapacity(len);
		for (int i = m_size - 1, j = 0; i < len; i++, j++) {
			m_data[i] = s.m_data[j];
		}
	}
	m_size = len - 1;
	m_capacity = len;
	return *this;
}

String String::operator+(char c) const noexcept {
	return String(toCString() + c);
}

String String::operator+(const String& s) const noexcept {
	String str = *this;
	str += s;
	return str;
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
	if (m_size < ShortCapacity && s.m_size < ShortCapacity) {
		int i = 0;
		while (i < m_size && i < s.m_size) {
			if (m_short[i] < s.m_short[i]) {
				return std::strong_ordering::less;
			}
			else if (m_short[i] > s.m_short[i]) {
				return std::strong_ordering::greater;
			}
			else {
				++i;		// same character
			}	
		}
		if (m_size == s.m_size) {
			return std::strong_ordering::equal;		// same character and same length
		}
		else if (m_size < s.m_size) {
			return std::strong_ordering::greater;	// same character *this is shorter
		}
		else {
			return std::strong_ordering::less;		// same character s is shorter
		}
	}
	else if (m_size < ShortCapacity) {
		int i = 0;
		while (i < m_size) {
			if (m_short[i] < s.m_data[i]) {
				return std::strong_ordering::less;
			}
			else if (m_short[i] > s.m_data[i]) {
				return std::strong_ordering::greater;
			}
			else {
				++i;
			}
		}
		return std::strong_ordering::greater;		// *this is shorter
	}
	else if (s.m_size < ShortCapacity) {
		int i = 0;
		while (i < s.m_size) {
			if (m_data[i] < s.m_short[i]) {
				return std::strong_ordering::less;
			}
			else if (m_data[i] > s.m_short[i]) {
				return std::strong_ordering::greater;
			}
			else {
				++i;
			}
		}
		return std::strong_ordering::greater;		// s is shorter
	}
	else {
		int i = 0;
		while (i < m_size && i < s.m_size) {
			if (m_data[i] < s.m_data[i]) {
				return std::strong_ordering::less;
			}
			else if (m_data[i] > s.m_data[i]) {
				return std::strong_ordering::greater;
			}
			else {
				++i;
			}
		}
		if (m_size == s.m_size) {
			return std::strong_ordering::equal;
		}
		else if (m_size < s.m_size) {
			return std::strong_ordering::greater;
		}
		else {
			return std::strong_ordering::less;
		}
	}
}

void String::ensureCapacity(size_t capacity) {
	if (capacity <= m_capacity) {
		return;
	}
	else {								
		auto data = std::make_unique<char[]>(capacity);
		for (int i = 0; i < capacity; i++) {
			data[i] = m_data[i];
		}
		m_data = move(data);
		m_short[0] = '\0';
		m_capacity = capacity;
	}
}