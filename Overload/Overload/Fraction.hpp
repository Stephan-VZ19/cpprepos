#pragma once

#include <cstdint>
#include <iostream>

class Fraction {
	int64_t m_top, m_bottom;

	void reduce();

public:
	Fraction(int64_t top, int64_t buttom = 1) 
		: m_top(top)
		, m_bottom(buttom)		
	{
		reduce();
	}

	explicit operator double() const;
	Fraction operator-() const;
	Fraction& operator+=(const Fraction& other);
	friend bool operator==(const Fraction& lhs, const Fraction& rhs);
	friend std::ostream &operator<<(std::ostream& os, const Fraction& f);

};