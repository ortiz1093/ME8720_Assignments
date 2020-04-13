#include "pch.h"
#include "myShape.h"

myShape::myShape() {
	nextShape = nullptr;
	prevShape = nullptr;
	string label = "Shape";
	centroid = myPoint(0,0);
}

myShape::~myShape() {}

void myShape::showLabel(CDC* pDC) {

	wstring stemp = wstring(label.begin(), label.end());
	LPCWSTR sw = stemp.c_str();
	double xOffset = 3.5*stemp.length();

	pDC->TextOut(centroid.getX() - xOffset, centroid.getY(), sw);
}

myPoint* myShape::getCentroid() {
	return &centroid;
}