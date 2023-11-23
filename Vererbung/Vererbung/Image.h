#pragma once

#include <memory>
#include <iostream>
#include <cstdint>
#include <span>

// Student's version

class Image {
protected:
    const int m_nChannels;
    int m_width, m_height;
    std::unique_ptr<uint8_t[]> m_data;

public:
    Image(int width, int height, int nChannels);
    Image(const Image& img);
    Image(Image&& img) noexcept;
    ~Image() {
        std::cout << "~Image" << std::endl;
    }

    Image& operator=(const Image& other);
    Image& operator=(Image&& other) noexcept;

    int width() const { return m_width; }
    int height() const { return m_height; }
    size_t size() const { return m_width * m_height; }
    size_t bytes() const { return size() * m_nChannels; }
    uint8_t* data(int x, int y) const {
        return m_data.get() + m_nChannels * (m_width * y + x);
    }

    double brightness(int x, int y) const;
    double brightness() const;
    size_t whitePixels() const;

    void load(const std::span<uint8_t>& data);
    void load(std::unique_ptr<uint8_t[]>&& data);

    friend std::ostream& operator<<(std::ostream& os, const Image& img);
};

class GrayscaleImage : public Image {
    const static int s_numChannels = 1;     // braucht kein Speicher weil const, wird einfach 1 eingesetzt

public:
    GrayscaleImage(int width, int height)
        : Image(width, height, s_numChannels)
    {}
    ~GrayscaleImage() {
        std::cout << "~GrayscaleImage" << std::endl;
    }
};

class RGBImage : public Image {
    const static int s_numChannels = 3;     // braucht kein Speicher weil const, wird einfach 1 eingesetzt

public:
    RGBImage(int width, int height)
        : Image(width, height, s_numChannels)
    {}
    ~RGBImage() {
        std::cout << "~RGBImage" << std::endl;
    }
};