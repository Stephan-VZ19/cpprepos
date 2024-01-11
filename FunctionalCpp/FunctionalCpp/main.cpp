#include <iostream>
#include <functional>
#include <vector>


template <class Iter, typename AT>
AT accumulate(Iter beg, Iter end, AT a) {
	while (beg != end) {
		a += *beg++;
	}
	return a;
}

int main() {

	std::vector<int> v = { 1, 2, 3, 4, 5 };

	int x = accumulate(v.cbegin(), v.cend(), 0);

	std::cout << x << std::endl;

}