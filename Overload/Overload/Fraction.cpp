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