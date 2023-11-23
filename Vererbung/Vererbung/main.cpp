#include "Image.h"

int main() {
	GrayscaleImage gray(5, 5);
	gray.getPixel(1, 0) = 255;
	std::cout << "white pixels: " << gray.whitePixels() << std::endl;
	std::cout << "Get pixel: " << gray.getPixel(1, 0) << std::endl;
	std::cout << gray << std::endl;

	RGBImage rgb1(5, 5);
	rgb1.load(std::make_unique<uint8_t[]>(rgb1.bytes()));
	rgb1.getPixel(1, 0) = 0xFF8844;
	std::cout << "white pixels: " << rgb1.whitePixels() << std::endl;
	std::cout << "Get pixel: " << rgb1.getPixel(1, 0) << std::endl;
	rgb1.load(std::make_unique<uint8_t[]>(rgb1.bytes()));
	std::cout << rgb1 << std::endl << std::endl;

	RGBImage rgb2(2, 2);
	std::cout << "white pixels: " << rgb2.whitePixels() << std::endl;
	std::cout << "Get pixel: " << rgb2.getPixel(1, 0) << std::endl;
	uint8_t data[] = {
		255, 255, 255, 0, 255,   0,
		255,   0,   0, 0,   0, 255
	};
	rgb2.load(data);
	std::cout << rgb2 << std::endl << std::endl;
}