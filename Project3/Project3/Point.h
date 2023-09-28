#pragma once

#include <iostream>
#include <cmath>

struct Point {
	int m_x, m_y;

	Point(int x = 0, int y = 0)
		: m_x(x)
		, m_y(y)
	{}

	double dist(const Point& p) {
		const int dx = m_x - p.m_x;
		const int dy = m_x - p.m_x;
		return hypot(dx, dy);
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& p) {
		return os << '(' << p.m_x << ',' << p.m_y << ')';
	}
};