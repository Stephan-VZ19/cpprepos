#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& vec) {
	for (int elem : vec) {
		cout << elem << ' ';
	}
	cout << endl;
}

int main() {
	vector<int> v1{ 1, 2, 3, 4 };
	print(v1);
}