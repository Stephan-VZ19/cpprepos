#pragma once

#include <memory>
#include <iostream>
#include <cstdint>
#include <span>

// value data types
struct PixelData {};

struct GrayPixelData : public PixelData {
	uint8_t m_intensity;

	GrayPixelData(uint8_t intensity = 0)
		: m_intensity(intensity)
	{}

	friend std::ostream& operator<<(std::ostream& os, const GrayPixelData px) {
		return os << (int)px.m_intensity;		// sonst wird der char Ausgabeoperator aufgerufen weil uint8_t
	}
};

struct RGBPixelData : PixelData {
	uint8_t m_blue, m_green, m_red;

	RGBPixelData(uint8_t px = 0)
		: m_blue((uint8_t)px)		// abschneiden, es bleibt nur der hintere Teil übrig
		, m_green((uint8_t)(px >> 8))
		, m_red((uint8_t)(px >> 16))
	{}

	friend std::ostream& operator<<(std::ostream& os, const RGBPixelData px) {
		return os << '(' << (int)px.m_red << ','
				         << (int)px.m_green << ','
						 << (int)px.m_blue << ')';
	}
};