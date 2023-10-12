#pragma once

#include "Point.h"
#include <memory>

class PointArray {
	size_t m_capacity;
	std::unique_ptr<Point[]> m_data;

public:
	PointArray(size_t capacity = 0)
		: m_capacity(capacity)
		, m_data(std::make_unique<Point[]>(capacity))
	{
		std::cout << "ctor, capacity =" << m_capacity << std::endl;
	}

	~PointArray() {
		std::cout << "dtor, capacity =" << m_capacity << std::endl;
	}
};