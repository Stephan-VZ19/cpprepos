#include "Fraction.hpp"
#include <math.h>
#include <cstdint>
#include <numeric>

std::ostream &operator<<(std::ostream& os, const Fraction& f) {
	if (f.m_bottom == 0) {
		if (f.m_top > 0) return os << "+inf";
		else if (f.m_top < 0) return os << "-inf";
		else return os << "NaN";
	}

	if (f.m_top == 0) {
		return os << 0;
	}
	else if (f.m_bottom == 1) {
		return os << f.m_top;
	}
	else {
		return os << f.m_top << "/" << f.m_bottom;
	}
	
}

void Fraction::reduce() {
	const int gcd = std::gcd(m_top, m_bottom);		// gcd sollte im C++20 drin sein
	if (gcd != 0) {
		m_top /= gcd;
		m_bottom /= gcd;
	}
}

Fraction Fraction::operator-() const {
	return Fraction(-m_top, -m_bottom);
}

Fraction& Fraction::operator+=(const Fraction& other) {
	m_top = m_top * other.m_bottom + other.m_top * m_bottom;
	m_bottom = m_bottom * other.m_bottom;
	reduce();
	return *this;
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
	return lhs.m_top == rhs.m_top && lhs.m_bottom == rhs.m_bottom;	// return (lhs <=> rhs) == std::partial_ordering::equivalent
}

Fraction::operator double() const {
	return m_top * 1.0 / m_bottom;
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
	Fraction sum = lhs;
	sum += rhs;
	return sum;
}

std::partial_ordering operator<=>(const Fraction& lhs, const Fraction& rhs) {
	return (double)lhs <=> (double)rhs;
}
