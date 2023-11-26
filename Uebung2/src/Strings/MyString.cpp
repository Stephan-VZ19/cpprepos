#include <memory>
#include <iostream>
#include "MyString.h"

/// <summary>
/// Author: Stephan Baumann
/// </summary>

String::String() noexcept
	: m_size(0)
	, m_capacity()
	, m_data(nullptr) 
{
	m_short[0] = '\0';
}

String::String(const String& s) noexcept
	: 