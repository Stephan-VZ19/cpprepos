#include "Image.h"

// Student's version

Image::Image(int width, int height, int nChannels)
    : m_nChannels(nChannels)
    , m_width(width)
    , m_height(height)
    , m_data(std::make_unique<uint8_t[]>(bytes()))
{}

Image::Image(const Image& img)
    : Image(img.m_width, img.m_height, img.m_nChannels)
{
    std::copy(img.m_data.get(), img.m_data.get() + bytes(), m_data.get());
}

Image::Image(Image&& img) noexcept
    : m_nChannels(img.m_nChannels)
    , m_width(std::exchange(img.m_width, 0))
    , m_height(std::exchange(img.m_height, 0))
    , m_data(std::exchange(img.m_data, nullptr))
{}

Image& Image::operator=(const Image& other) {
    if (&other != this) {
        m_width = other.m_width;
        m_height = other.m_height;
        m_data = std::make_unique<uint8_t[]>(bytes());
        std::copy(other.m_data.get(), other.m_data.get() + bytes(), m_data.get());
    }
    return *this;
}

Image& Image::operator=(Image&& other) noexcept {
    if (&other != this) {
        std::swap(m_width, other.m_width);
        std::swap(m_height, other.m_height);
        std::swap(m_data, other.m_data);
    }
    return *this;
}

void Image::load(const std::span<uint8_t>& data) {
    std::copy(data.begin(), data.begin() + std::min(bytes(), data.size()), m_data.get());
}

void Image::load(std::unique_ptr<uint8_t[]>&& data) {
    m_data = std::move(data);
}

double Image::brightness(int x, int y) const {
    uint8_t* p = data(x, y);
    int sum = 0;

    for (int i = 0; i < m_nChannels; i++) {
        sum += *p++;
    }
    return sum / (255.0 * m_nChannels);
}

double Image::brightness() const {
    double avg = 0;

    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            avg += brightness(x, y);
        }
    }
    return avg / size();
}

size_t Image::whitePixels() const {
    size_t n = 0;
    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            n += isWhite(x, y);
        }
    }
    return n;
}

std::ostream& operator<<(std::ostream& os, const Image& img) {
    const std::type_info& t = typeid(img);
    os << t.name() << std::endl;
    return os << '(' << img.m_width << 'x' << img.m_height << ')' << " data[" << img.bytes() << ']';
}