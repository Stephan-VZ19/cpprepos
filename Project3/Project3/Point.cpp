#include "Point.h"

int Point::s_instances = 0;

int Point::getNumberOfInstances() {
	return s_instances;
}

double Point::dist(const Point& p) const {
	const int dx = m_x - p.m_x;
	const int dy = m_y - p.m_y;
	return hypot(dx, dy);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
	return os << '(' << p.m_x << ',' << p.m_y << ') ' << p.m_color;
}

Point& Point::move(int x, int y) {
	m_x += x;
	m_y += y;
	return *this;
}