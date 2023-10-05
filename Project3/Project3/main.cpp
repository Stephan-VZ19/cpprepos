#include "Point.h"
#include "Person.h"
#include <cassert>

#include <iostream>

int Person::getAge() const { return m_age; }

void foo(const Point& pIn, Point& pOut) {
	pOut = pIn;	// output,input -> zwei Variablen zurückgeben
}

int main() {
	std::shared_ptr<Person> up = std::make_shared<Person>("Berta", 20);
	std::shared_ptr<Person> sp = std::make_shared<Person>("Paul", 22);

	up->setAge(19);

	std::cout << sp.use_count() << std::endl;

	auto sp1 = sp;

	std::cout << sp1.use_count() << std::endl;	// sp oder sp1 ist das gleiche

	up->setAge(19);
	sp->setAge(23);

	std::cout << *up << std::endl;
}