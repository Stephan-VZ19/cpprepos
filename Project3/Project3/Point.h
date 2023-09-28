#pragma once

#include <iostream>

struct Point {
	int m_x, m_y;

	Point(int x = 0, int y = 0)
		: m_x(x)
		, m_y(y)
	{}

	friend std::ostream& operator<<(std::ostream& os, const Point& p) {
		return os << '(' << p.m_x << ',' << p.m_y << ')';
	}
};