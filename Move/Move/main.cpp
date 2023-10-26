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
	RGBImage rgb0 = RGBImage(3, 4);

	const uint8_t data[] = {
		255, 0, 0,
		0, 255, 0,
		0, 0, 255
	};

}