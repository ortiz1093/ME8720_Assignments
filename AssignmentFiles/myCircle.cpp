#include "pch.h"
#include "myCircle.h"

constexpr double Pi = 3.14159265;

myCircle::myCircle() : center(myPoint(100, 100)), radius(10) {}

myCircle::myCircle(myPoint C, double r) : center(C), radius(r) {}

myCircle::myCircle(float X, float Y, double r) : center(myPoint(X, Y)), radius(r) {}

myPoint myCircle::getCenter() {
	return center;
}

void myCircle::translate(const myVector& u) {
	center.translate(u);
}

void myCircle::rotate(double angle, int units) {

	if (units == 1) {
		;
	}
	else if (units == 2) {
		// Convert input angle from degrees to radians
		angle = angle * Pi / 180;
	}
	else {
		cout << "Invalid choice for units. Assuming input in radians." << endl;
	}

	myMatrix R;
	R.makeRotationMat(angle);
	center = R * center;
}

void myCircle::scale(double factor) {

	myMatrix S;
	S.makeScaleMat(factor);
	center = S * center;

	radius = radius * factor;
	
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

