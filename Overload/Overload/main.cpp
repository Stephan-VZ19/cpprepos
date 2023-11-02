#include <iostream>

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

int main() {
	test(2);
	test(2 * 1.0);
	math::test(3);
}