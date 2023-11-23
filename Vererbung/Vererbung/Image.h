#pragma once

#include <memory>
#include <iostream>
#include <cstdint>
#include <span>
#include "Pixel.h"

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

    virtual bool isWhite(int x, int y) const = 0;   // pure virtual == abstract
    virtual const PixelData& getPixel(int x, int y) const = 0;      // nur für Lesezwecke nutzen
    virtual PixelData& getPixel(int x, int y) = 0;      // um den Pixel zu überschreiben
};

class GrayscaleImage : public Image {
    const static int s_numChannels = 1;     // braucht kein Speicher weil const, wird einfach 1 eingesetzt
    static_assert(sizeof(GrayPixelData) == s_numChannels, "wrong size");        // guard für Fehler

public:
    GrayscaleImage(int width, int height)
        : Image(width, height, s_numChannels)
    {}
    ~GrayscaleImage() {
        std::cout << "~GrayscaleImage" << std::endl;
    }

    bool isWhite(int x, int y) const {
        GrayPixelData* p = reinterpret_cast<GrayPixelData*>(data(x, y));      // ist ein Point p der an die richte Stelle zeigt im Bild
        return p->isWhite(); 
    }

    virtual GrayPixelData& getPixel(int x, int y) const override {
        return *reinterpret_cast<GrayPixelData*>(data(x, y));
    }

    virtual GrayPixelData& getPixel(int x, int y) override {
        return *reinterpret_cast<GrayPixelData*>(data(x, y));
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

    bool isWhite(int x, int y) const {
        RGBPixelData* p = reinterpret_cast<RGBPixelData*>(data(x, y));      // ist ein Point p der an die richte Stelle zeigt im Bild
        return p->isWhite();
    }

    virtual RGBPixelData& getPixel(int x, int y) const override {
        return *reinterpret_cast<RGBPixelData*>(data(x, y));
    }

    virtual RGBPixelData& getPixel(int x, int y) override {
        return *reinterpret_cast<RGBPixelData*>(data(x, y));
    }
};