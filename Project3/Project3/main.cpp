#include "Point.h"
#include "Person.h"
#include <cassert>

#include <iostream>

int Person::getAge() const { return m_age; }

void foo(const Point& pIn, Point& pOut) {
	pOut = pIn;	// output,input -> zwei Variablen zurückgeben
}

int main() {
	std::unique_ptr<Person> up = std::make_unique<Person>("Berta", 20);

	up->setAge(19);

	std::cout << *up << std::endl;
}