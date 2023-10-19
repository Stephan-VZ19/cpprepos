#pragma once

#include <iostream>
#include <cmath>
#include "Color.h"


class Point {
	int m_x, m_y;
	Color m_color;	// m_ members
	
	static int s_instances;	// s_ static
	static const int s_version = 1;

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
		s_instances++;
		std::cout << "ctor 1" << std::endl;
	}

	Point(const Point& p) 
		: m_x(p.m_x)
		, m_y(p.m_y)
		, m_color(p.m_color)
	{
		s_instances++;
	}

	Point(Point&& p) = default;
	

	~Point() {
		std::cout << "dtor" << *this << std::endl;
	}

	static int getNumberOfInstances();

	friend std::ostream& operator<<(std::ostream& os, const Point& p);

	double dist(const Point& p) const;
	Point& move(int x, int y);
};