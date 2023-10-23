#include <iostream>
#include <sstream>
#include "image.hpp"

using namespace std;

RGBImage::RGBImage(const RGBPixel data[], int width, int height)
    : mWidth(width), mHeight(height), mSize(width * height) {
    mData = make_unique<RGBPixel[]>(mSize);
    copy(data, data+mSize, mData.get());
}

void RGBImage::load(istream& in) {
    // Check size
    in.seekg(0, ios::end);
    size_t filesize = in.tellg();
    cout << "Reading file of size " << filesize << " bytes" << endl;
    in.seekg(0, ios::beg);

    // File header
    // ===========
    // First line: magic bytes
    string magic;
    in >> magic;

    // Second line: dimensions
    in >> mWidth >> mHeight;
    mSize = mWidth * mHeight;
    mData = make_unique<RGBPixel[]>(mSize);

    // Third line: color depth
    uint16_t maxval;
    in >> maxval;
    if (maxval != 255) throw std::runtime_error("unexpected maxval");
    in >> std::ws; // Discard newline

    // Image data
    // ==========
    // TODO [Aufgabe] 1.a)
    if (magic == "P3") {
        for (int i = 0; i < mSize; i++) {
            int red, green, blue;
            in >> red;
            in >> green;
            in >> blue;
            if (!in.good()) {
                throw std::runtime_error("error stream");
            }
            mData[i] = RGBPixel(red, green, blue);
        }
    }

    // TODO [Aufgabe] 1.b)
    else if (magic == "P6") {
        //for (int i = 0; i < mSize; i++) {
        //    int red, green, blue;
        //    char pixels[]{ 9 * mSize };     // mSize times pixels and 9 chars for each
        //    in.read(pixels, 9 * mSize);
        //    for (int j = i * 9; j < 9; j++) {
        //        if (j < 3) {
        //            char pixR[]{ 3 };
        //            pixR[j] = pixels[j];
        //            red = stoi(pixR);
        //        }
        //        else if (j < 6) {
        //            char pixG[]{ 3 };
        //            pixG[j-3] = pixels[j];
        //            green = stoi(pixG);
        //        }
        //        else {
        //            char pixB[]{ 3 };
        //            pixB[j-6] = pixels[j];
        //            blue = stoi(pixB);
        //        }
        //        if (!in.good()) {
        //            throw std::runtime_error("error stream");
        //        }
        //    }
        //    if (!in.good()) {
        //        throw std::runtime_error("error stream");
        //    }
        //    mData[i] = RGBPixel(red, green, blue);
        //}
    }

    else
    {
        throw std::runtime_error("error magic number");
    }
    
    
}

void RGBImage::write(ostream& out) const {
    // TODO [Aufgabe] 3.b)
}

const RGBPixel RGBImage::getPixel(int x, int y) const {
    return mData[y*mWidth + x];
}

void RGBImage::setPixel(int x, int y, const RGBPixel &px) {
    mData.get()[y*mWidth + x] = px;
}

double RGBPixel::getBrightness() const {
    // TODO [Aufgabe] 2.a)
    auto mean = ( ((red / 255) * 100) + ((green / 255) * 100) + ((blue / 255)) * 100) / 3.0;
    return mean;
}

Coordinate RGBImage::findBrightestPixel() const {
    // TODO [Aufgabe] 3.a)
    return {0, 0};
}
