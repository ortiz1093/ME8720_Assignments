#include "pch.h"
#include "myClasses.h"
#include "myPoint.h"
//#include <wchar.h>
#include <iostream>
#include <string.h>


myPoint::myPoint() : myVector::myVector() {}

myPoint::myPoint(float x, float y) : myVector::myVector() {
	this->x = x;
	this->y = y;
	this->z = 1;
}

void myPoint::translate(float x, float y) {
	myPoint result;
	myMatrix T;
	T.makeTranslationMat(x, y);

	*this = T * *this;
}

void myPoint::movePt(float x, float y) {
	this->x = x;
	this->y = y;
}

void myPoint::print(CDC* pDC) {
	double x1 = x - 2.5;
	double x2 = x + 2.5;

	double y1 = y - 2.5;
	double y2 = y + 2.5;

	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y1);
	pDC->LineTo(x2, y2);
	pDC->LineTo(x1, y2);
	pDC->LineTo(x1, y1);
}

double myPoint::getX() {
	return x;
}
double myPoint::getY() {
	return y;
}