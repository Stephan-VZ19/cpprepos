#include <iostream>
#include <vector>
#include "image.h"

using namespace std;

void print(const vector<int>& vec) {
	for (int elem : vec) {
		cout << elem << ' ';
	}
	cout << endl;
}

void test(int& x) {
	cout << "non-moveable" << endl;
}

void test(int&& x) {
	cout << "moveable" << endl;
}


int main() {
	RGBImage rgb0;
	RGBImage rgb1 = RGBImage(3, 4);

	const uint8_t data[] = {
		255, 0, 0,
		0, 255, 0,
		0, 0, 255
	};
	RGBImage img3(data, 2, 2);

	auto up = std::make_unique<uint8_t[]>(3000);
	RGBImage img4(std::move(up), 100, 10);

	RGBImage img5(std::move(img3));

}