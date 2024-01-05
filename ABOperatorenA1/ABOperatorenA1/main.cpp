#include <iostream>

struct Point {
	int m_x;
	int m_y;
};

int main() {

	Point* pp = new Point();

	if (!pp) {
		pp = new Point();
		pp->m_x = 3;
		pp->m_y = 4;
	}
	Point* ip;


	if (Point* ip = new Point()) {
		ip->m_x = 3;
		// delete ip;
	}

	std::cout << "Point pp: " << ip->m_x << std::endl;

}