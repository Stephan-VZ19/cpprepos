#include "Fraction.hpp"

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