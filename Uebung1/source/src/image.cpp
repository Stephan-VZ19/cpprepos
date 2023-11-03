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
        const size_t readCharsSize = mSize * sizeof(RGBPixel);
        in.read((char*) mData.get(), readCharsSize);
    }

    else
    {
        throw std::runtime_error("error magic number");
    }
}

void RGBImage::write(ostream& out) const {
    // TODO [Aufgabe] 3.b)
    out << "P6";
    out << "/n";
    out << mWidth << mHeight;
    out << "255";
    const size_t writeCharSize = mSize * sizeof(RGBPixel);
    out.write((char*)mData.get(), writeCharSize);       // mData ist ein RBG Pointer
}

const RGBPixel RGBImage::getPixel(int x, int y) const {
    return mData[y*mWidth + x];
}

void RGBImage::setPixel(int x, int y, const RGBPixel &px) {
    mData.get()[y*mWidth + x] = px;
}

double RGBPixel::getBrightness() const {
    // TODO [Aufgabe] 2.a)
    return (red + green + blue) / (3.0 * 255);  // -> nur einmal dividieren
}

Coordinate RGBImage::findBrightestPixel() const {
    // TODO [Aufgabe] 3.a)
    int xb = 0, yb = 0;
    RGBPixel b = getPixel(xb, yb);

    for (int y = 0; y < mHeight; y++) {
        for (int x = 0; x < mWidth; x++) {
            if (getPixel(x, y).getBrightness() > b.getBrightness()) {
                b = getPixel(x, y);
                xb = x;
                yb = y;
            }
        }
    }

    return {xb, yb};
}
