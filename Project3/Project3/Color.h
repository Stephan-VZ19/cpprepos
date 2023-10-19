#pragma once
#include <cstdint>
#include <iostream>

enum class Color : uint8_t {
	black, red, green, yellow, blue, magenta, cyan ,white
};

const char* const colorNames[] = {
	"black", "red", "green", "yellow", "blue", "magenta", "cyan" , "white"
};

inline std::ostream& operator<<(std::ostream& os, const Color& c) {
	return os << colorNames[(int) c];
}