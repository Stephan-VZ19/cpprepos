#include <iostream>
#include <vector>

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
	vector<int> v1{ 1, 2, 3, 4 };
	print(v1);
	print({ 1, 2, 3 });		// in/out object

	int x = 5, y = 3;
	int* ptr = &y;
	test(x);	// l value
	test(5);	// r value
	test(x + 5);	// r value
	test(*ptr);		// l value


}