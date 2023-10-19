#include <iostream>
#include <cstdint>

struct Bools {
	bool a : 1;
	bool b : 1;
	bool c : 1;
	bool d : 1;
};

struct Chars {
	char a, b, c, d;
};

int main() {
	std::cout << "Bools belegen " << sizeof(Bools) << " Bytes" << std::endl;
	std::cout << "Bools belegen " << sizeof(Chars) << " Chars" << std::endl;
}