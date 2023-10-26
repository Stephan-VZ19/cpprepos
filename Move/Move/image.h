#pragma once

#include <iostream>
#include <memory>

class RGBImage {
	size_t m_size;
	int m_width, m_height;
	std::unique_ptr<uint8_t[]> m_data;

public:
	RGBImage() {}
	
	RGBImage(int width, int height)
		: m_size(3 * width * height)
		, m_width(width)
		, m_height(height)
		, m_data(std::make_unique<uint8_t[]>(m_size))
	{}

	RGBImage(const uint8_t data[], int width, int height)
		: RGBImage(width, height)
	{
		std::copy(data, data + m_size, m_data.get());
		std::cout << "copy" << std::endl;
	}

	RGBImage(std::unique_ptr<uint8_t[]>&& data, int width, int height)
		: m_size(3 * width * height)
		, m_width(width)
		, m_height(height)
		, m_data(std::move(data))
	{
		std::cout << "move" << std::endl;
	}

	RGBImage(const RGBImage& img)		// Copy Constructor
		: RGBImage(img.m_width, img.m_height)
	{
		std::copy(img.m_data.get(), img.m_data.get() + m_size, m_data.get());
		std::cout << "copy" << std::endl;
	}

	RGBImage(RGBImage&& img)
		: m_size(std::exchange(img.m_size, 0))
		, m_width(std::exchange(img.m_width, 0))
		, m_height(std::exchange(img.m_height, 0))
		, m_data(std::exchange(img.m_data, nullptr))
	{
		std::cout << "move" << std::endl;
	}
};