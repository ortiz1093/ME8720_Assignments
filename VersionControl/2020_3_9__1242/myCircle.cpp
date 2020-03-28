#include "pch.h"
#include "myCircle.h"

myCircle::myCircle() : center(myPoint(100, 100)), radius(1) {}

myCircle::myCircle(myPoint C, double r) : center(C), radius(r) {}

myCircle::myCircle(float X, float Y, double r) : center(myPoint(X, Y)), radius(r) {}

void myCircle::draw(CDC* pDC) {
	myVector pointVec(radius, 0,0);
	//center.show(pDC);

	pDC->MoveTo(center.x + pointVec.x, center.y + pointVec.y);
	int n = 36;

	for (int i = 1; i < n+1; i++) {
		//pointVec.draw(center.getX(), center.getY(), pDC);
		pointVec = pointVec.rotate2D(360 / n, 2);
		pDC->LineTo(center.x + pointVec.x, center.y + pointVec.y);
	}
}

