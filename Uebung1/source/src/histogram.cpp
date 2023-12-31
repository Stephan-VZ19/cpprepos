#include <iostream>
#include "histogram.hpp"
#include <cmath>

using namespace std;

Histogram::Histogram(const vector<int> &data) {
    mNumBins = (int)data.size();
    mData = make_unique<int[]>(mNumBins);
    copy(data.begin(), data.end(), mData.get());
}

bool Histogram::operator==(const Histogram& other) const {
    if (this->getNumBins() != other.getNumBins()) {
        return false;
    }
    for (int i = 0; i < getNumBins(); i++) {
        if (this->getBin(i) != other.getBin(i)) {
            return false;
        }
    }
    return true;
}

void Histogram::process(const RGBImage& img, int numBins) {
    mNumBins = numBins;
    mData = make_unique<int[]>(numBins);
    // TODO [Aufgabe] 2.b)

    // double bins = 1.0 / numBins;        // range of 1 bins

    const double lastBin = 1 - 1.0 / numBins;

    for (int y = 0; y < img.getHeight(); y++) {
        for (int x = 0; x < img.getWidth(); x++) {

            const double pBright = img.getPixel(x, y).getBrightness();

            if (pBright < lastBin) {
                int bClass = (int) (pBright * numBins);     // which bins class the pixel should be
                mData[bClass]++;                  
            }
            else {
                mData[numBins - 1]++;       // last bins class
            }
        }
    }

}

void Histogram::print(int height) const {
    // TODO [Aufgabe] 2.c)
    // cout << "❚";

    // search highest value
    int highest = 0;
    for (int i = 0; i < mNumBins; i++) {
        if (highest < mData[i]) {
            highest = mData[i];
        }
    }

    // print each line, if each bins has enough value like i, print a block
    for (int line = height; line > 0; line--) {      // height = number of lines, line = 1 bar
        for (int i = 0; i < mNumBins; i++) {        // i for each bin
            const int h = (mData[i] * height) / highest;      // actual bin computed to bars
            if (line <= h) {
                cout << "❚";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;       // neue Linie
    }

    cout << "|";
    for (int i = 1; i < mNumBins-1; i++) {
        cout <<  "-";
    }
    cout << "|" << endl;

    cout << "0% ";
    for (int i = 3; i < mNumBins-4; i++) {
        cout << " ";
    }
    cout << "100%" << endl;
}
