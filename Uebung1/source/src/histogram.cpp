#include <iostream>
#include "histogram.hpp"

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
}

void Histogram::print(int height) const {
    // TODO [Aufgabe] 2.c)
    // cout << "❚";

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