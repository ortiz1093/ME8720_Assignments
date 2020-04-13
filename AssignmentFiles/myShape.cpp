#include "pch.h"
#include "myShape.h"

myShape::myShape() {
	nextShape = nullptr;
	prevShape = nullptr;
	string label = "";
	centroid = myPoint(0,0);
}

myShape::~myShape() {}