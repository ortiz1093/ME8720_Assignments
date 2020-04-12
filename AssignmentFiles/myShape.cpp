#include "pch.h"
#include "myShape.h"

myShape::myShape() {
	nextShape = nullptr;
	prevShape = nullptr;
}

myShape::~myShape() {
	/*delete nextShape;
	delete prevShape;*/
}