#pragma once

#include <iostream>
#include <cmath>
#include "Color.h"


class Point {
	int m_x, m_y;
	Color m_color;

public:
	Point()
		: Point(0, 0)
	{
		std::cout << "ctor 2" << std::endl;
	}
	Point(int x, int y, Color c = Color::black)
		: m_x(x)
		, m_y(y)
		, m_color(c)
	{
		std::cout << "ctor 1" << std::endl;
	}

	~Point() {
		std::cout << "dtor" << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& p);

	double dist(const Point& p);
};