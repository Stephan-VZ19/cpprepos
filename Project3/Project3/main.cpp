#include "Point.h"
#include "Person.h"
#include <cassert>
#include <vector>
#include <array>
#include <iostream>
#include <assert.h>
#include "PointArray.h"
#include <string_view>


int Person::getAge() const { return m_age; }

void foo(const Point& pIn, Point& pOut) {
	pOut = pIn;	// output,input -> zwei Variablen zurückgeben
}

int main() {
	Point p1(1, -1, Color::yellow);
	Point p2;
	Point p3 = Point(1, 3);
	Point p4{ 3, 0 };
	Point* p5 = new Point(1, 2, Color::red);
	auto up = std::make_unique<Point>();

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;
	std::cout << p4 << std::endl;
}