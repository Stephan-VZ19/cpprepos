#include <iostream>
#include <iomanip>
#include "Fraction.hpp"

void test(int a) {
	std::cout << "Variante 1" << std::endl;
}

void test(double a) {
	std::cout << "Variante 2" << std::endl;
}

namespace math {
	void test(int a) {
		std::cout << "Variante 3" << std::endl;
	}
}

// using namespace math;	ambigious

void precisionTest() {
	const int x = 99;
	const Fraction frac = 1.0 / x;
	Fraction sum = 0.0;
	for (int i = 0; i < x; ++i) {
		sum += frac;
	}
	if (sum == 1) std::cout << "Adds up to 1" << std::endl;
	else std::cout << "Sum is not 1: " << std::setprecision(20) << sum << std::endl;
}

int main() {
	Fraction f1(1, 2);
	Fraction f2(-2, 2);
	Fraction f3 = 2;
	Fraction f4(-1, -4);
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << f4 << std::endl;
}