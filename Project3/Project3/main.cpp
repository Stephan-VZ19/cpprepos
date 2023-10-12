#include "Point.h"
#include "Person.h"
#include <cassert>
#include <vector>

#include <iostream>

#include "PointArray.h"

int Person::getAge() const { return m_age; }

void foo(const Point& pIn, Point& pOut) {
	pOut = pIn;	// output,input -> zwei Variablen zurückgeben
}

int main() {
	PointArray pa1;
	PointArray pa2(10);
}