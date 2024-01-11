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

template <class Iter, typename AT, typename Func>
AT accumulate(Iter beg, Iter end, AT a, Func f) {
	while (beg != end) {
		a = f(a, *beg++);
	}
	return a;
}

template<class Iter, class Pred>
size_t count(Iter b, Iter e, Pred p) {
	size_t cnt = 0;
	while (b != e) {
		cnt += p(*b++);
	}
	return cnt;
}

int main() {

	std::vector<int> v = { 1, 2, 3, 4, 5 };
	
	int x = accumulate(v.cbegin(), v.cend(), 0);
	int y = accumulate(v.cbegin(), v.cend(), 1, [] (int a, int x) {
		return a *= x;
		});

	std::cout << x << std::endl;
	std::cout << y << std::endl;

	/*size_t b = count(v.cbegin(), v.cend(), [] (int a, int x) {
		return a & 2 == 0;
		});*/

}