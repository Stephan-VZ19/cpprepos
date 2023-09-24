#include <iostream>
#include "math.h"

// static int x = 10;	// Modulvariable
int x = 10;	// Globalevariable

int main() {
	int x = 5;
	int y = 7;
	int* px = new int(99);

	std::cout << xyz::sum(3, 5) << std::endl;
	std::cout << "x = " << x << std::endl;
	std::cout << "&x = " << &x << std::endl;
	std::cout << "&y = " << &y << std::endl;
	std::cout << "px = " << px << std::endl;
	std::cout << "*px = " << *px << std::endl;

	delete px;

}