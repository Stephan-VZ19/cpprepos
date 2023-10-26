#pragma once

#include <iostream>
#include <memory>

class RGBImage {
	size_t m_size;
	int m_width, m_height;
	std::unique_ptr<uint8_t[]> m_date;
};