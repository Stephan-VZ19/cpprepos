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
	, m_capacity(0)
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





