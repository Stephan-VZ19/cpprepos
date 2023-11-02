#pragma once

#include <cstdint>
#include <iostream>

class Fraction {
	int64_t m_top, m_bottom;

public:
	Fraction(int64_t top, int64_t buttom = 1) 
		: m_top(top)
		, m_bottom(buttom)		
	{}

	friend std::ostream &operator<<(std::ostream& os, const Fraction& f);

};