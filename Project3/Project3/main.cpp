#include "Point.h"
#include "Person.h"
#include <cassert>

#include <iostream>

int Person::getAge() const { return m_age; }

int main() {
	Point p0;
	Point p1(3);
	Point p2(5, 6);

	Point* pp0 = &p0;
	auto pp01 = pp0;

	Point p11 = p1;

	assert(&p11 != &p1);

	Point* pp2 = &p2;

	auto d = pp2->dist(p2);



	std::cout << "pp0 = " << pp0 << std::endl;
	std::cout << "*pp0 = " << *pp0 << std::endl;

	std::cout << "pp01 = " << pp01 << std::endl;
	std::cout << "*pp01 = " << *pp01 << std::endl;

	std::cout << "d = " << d << std::endl;


}