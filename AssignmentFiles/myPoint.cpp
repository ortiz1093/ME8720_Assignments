#include "pch.h"
#include "myClasses.h"
#include "myPoint.h"
#include <iostream>
#include <string.h>


myPoint::myPoint() : myVector::myVector() {}

myPoint::myPoint(float x, float y) : myVector::myVector() {
	this->x = x;
	this->y = y;
	this->z = 1;
}

void myPoint::operator = (const myPoint& p) {
	
	x = p.x;
	y = p.y;
}

void myPoint::translate(float X, float Y) {
	myPoint result;

	x = x + X;
	y = y + Y;
}

void myPoint::translate(const myVector& u) {
	myPoint result;

	x = x + u.x;
	y = y + u.y;
}

void myPoint::movePt(float x, float y) {
	this->x = x;
	this->y = y;
}

void myPoint::show(CDC* pDC) {
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

void myPoint::display() {
	cout << "(" << x << "," << y << ")" << endl;
	cout << "z = " << z << endl;
}

double myPoint::getX() {
	return x;
}
double myPoint::getY() {
	return y;
}