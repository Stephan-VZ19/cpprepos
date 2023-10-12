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
	PointArray pa1;
	PointArray pa2(10);
	Person person[] {Person("Peter", 20), Person("Moni", 21)};

	std::array<Point, 3> a1{ Point(1,1), Point(2,3), Point(3,4)};
	std::vector<Person> v1{ Person("Peter", 20), Person("Moni", 21) };

	auto x = a1[1];		// Kopie
	// assert(&x != a1[1]);

	pa1.pushBack({ 3, 5 });
	pa1.pushBack({ 7, 5 });

	std::cout << pa1 << std::endl;
	std::cout << pa2 << std::endl;



	

}