#include "Point.h"

double Point::dist(const Point& p) {
	const int dx = m_x - p.m_x;
	const int dy = m_y - p.m_y;
	return hypot(dx, dy);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
	return os << '(' << p.m_x << ',' << p.m_y << ') ' << p.m_color;
}