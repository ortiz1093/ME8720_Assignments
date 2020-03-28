#include "pch.h"
#include "myCircle.h"

myCircle::myCircle() : center(myPoint(100, 100)), radius(10) {}

myCircle::myCircle(myPoint C, double r) : center(C), radius(r) {}

myCircle::myCircle(float X, float Y, double r) : center(myPoint(X, Y)), radius(r) {}

myPoint myCircle::getCenter() {
	return center;
}

void myCircle::translate(const myVector& u) {
	center.translate(u);
}

void myCircle::draw(CDC* pDC) {
	myVector pointVec(radius, 0,0);

	pDC->MoveTo(center.x + pointVec.x, center.y + pointVec.y);
	int n = 36;

	for (int i = 1; i < n+1; i++) {
		pointVec = pointVec.rotate2D(360 / n, 2);
		pDC->LineTo(center.x + pointVec.x, center.y + pointVec.y);
	}
}

