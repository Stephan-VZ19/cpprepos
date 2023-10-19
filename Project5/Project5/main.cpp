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

struct Header {
	uint64_t a;
	uint32_t b;
	uint64_t c;
	uint16_t d;
};	// 8 + 4 + 2 + 8 = 22

int main() {
	Bools example{ true, false, false, true };
	std::cout << example.a << std::endl;
	std::cout << "Bools belegen " << sizeof(Bools) << " Bytes" << std::endl;
	std::cout << "Bools belegen " << sizeof(Chars) << " Bytes" << std::endl;

	Header h;
	std::cout << "Header belegen " << sizeof(h) << " Bytes" << std::endl;
	std::cout << &h.a << std::endl;
	std::cout << &h.b << std::endl;
	std::cout << &h.c << std::endl;
	std::cout << &h.d << std::endl;
}