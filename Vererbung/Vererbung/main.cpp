#include "Image.h"

int main() {
	GrayscaleImage gray(5, 5);
	std::cout << gray << std::endl;

	RGBImage rgb1(5, 5);
	rgb1.load(std::make_unique<uint8_t[]>(rgb1.bytes()));
	std::cout << rgb1 << std::endl << std::endl;

	RGBImage rgb2(2, 2);
	uint8_t data[] = {
		255, 255, 255, 0, 255,   0,
		255,   0,   0, 0,   0, 255
	};
	rgb2.load(data);
	std::cout << rgb2 << std::endl << std::endl;
}