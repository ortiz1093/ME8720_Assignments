#include "pch.h"
#include "myCircle.h"

constexpr double Pi = 3.14159265;

myCircle::myCircle() : radius(10) {
	centroid = myPoint(100, 100);
}

myCircle::myCircle(myPoint C, double r) : radius(r) {
	centroid = C;
}

myCircle::myCircle(float X, float Y, double r) : radius(r) {
	centroid = myPoint(X, Y);
}

myPoint myCircle::getCenter() {
	return centroid;
}

void myCircle::translate(const myVector& u) {
	centroid.translate(u);
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
	centroid = R * centroid;
}

void myCircle::scale(double factor) {

	myMatrix S;
	S.makeScaleMat(factor);
	centroid = S * centroid;

	radius = radius * factor;
	
}

void myCircle::draw(CDC* pDC) {
	myVector pointVec(radius, 0,0);

	pDC->MoveTo(centroid.x + pointVec.x, centroid.y + pointVec.y);
	int n = 36;

	for (int i = 1; i < n+1; i++) {
		pointVec = pointVec.rotate2D(360 / n, 2);
		pDC->LineTo(centroid.x + pointVec.x, centroid.y + pointVec.y);
	}
}

