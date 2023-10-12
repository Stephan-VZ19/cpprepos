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
	const char* s = "hallo";
	char t[] = "hallo";
	std::string_view sv("hello");
	std::cout << sizeof(sv) << std::endl;

	std::string s1 = "abcdef";
	s1[0] = 'A';
	std::cout << s1 << std::endl;

	std::cout << sizeof(s) << ", " << s << std::endl;	// 8, hallo
	std::cout << sizeof(t) << ", " << t << std::endl;	// 6, hallo


}