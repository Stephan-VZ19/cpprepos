#include "Point.h"
#include "Person.h"

#include <iostream>

int main() {
	Point p0;
	Point p1(1);
	Point p2{ 1, 2};
	Point p3{ 3, 4};

	Person peter{ "Peter", 25 };
	Person susi{ "Susi", 22 };

	std::cout << p0 << std::endl;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;

	std::cout << peter << std::endl;
	std::cout << susi << std::endl;

}