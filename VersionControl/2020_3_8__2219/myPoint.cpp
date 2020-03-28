#include "pch.h"
#include "myClasses.h"
#include "myPoint.h""


myPoint::myPoint() : myVector::myVector() {}

myPoint::myPoint(float x, float y) : myVector::myVector() {
	x = x;
	y = y;
	z = 1;
}

void myPoint::translate(float x, float y) {
	myPoint result;
	myMatrix T;
	T.makeTranslationMat(x, y);

	*this = T * *this;
}