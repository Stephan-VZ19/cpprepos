#pragma once

#include "Point.h"
#include <memory>

class PointArray {
	size_t m_capacity, m_size;
	std::unique_ptr<Point[]> m_data;

public:
	PointArray(size_t capacity = 0)
		: m_capacity(capacity)
		, m_size(0)
		, m_data(std::make_unique<Point[]>(capacity))
	{
		std::cout << "ctor, capacity =" << m_capacity << std::endl;
	}

	~PointArray() {
		std::cout << "dtor, capacity =" << m_capacity << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const PointArray& pa) {
		os << '[';
		if (pa.m_size > 0) {
			os << ',' << pa.m_data[0];
		}
		for (size_t i = 1; i < pa.m_size; i++) {
			os << ',' << pa.m_data[i];
 		}
		return os << ']';
	}

	void pushBack(const Point& p) {
		if (m_size == m_capacity) {

			m_capacity = 2 * m_capacity + 1;	// sonst nützt das verdoppeln nichts
			auto up = std::make_unique<Point[]>(m_capacity);

			for (size_t i = 0; i < m_size; i++) {
				up[i] = m_data[i];
			}

			m_data = std::move(up);		// move Beispiel <<<<<<<<<<<<<<<<================

		}
		m_data[m_size++] = p;
	}
};