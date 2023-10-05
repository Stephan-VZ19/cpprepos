#include "Point.h"
#include "Person.h"
#include <cassert>

#include <iostream>

int Person::getAge() const { return m_age; }

int main() {
	Point p0;
	Point p1(3);
	Point p2(5, 6);

	Point& rp1 = p1;
	assert(&rp1 == &p1);

	Point& rp11 = rp1;

	rp1 = p2;



	std::cout << p1 << std::endl;
}