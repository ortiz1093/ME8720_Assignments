#include "pch.h"
#include "myRectangle.h"

constexpr double Pi = 3.14159265;

myRectangle::myRectangle() 
	: ptA(myPoint(100,100)), ptB(myPoint(200, 100)), ptC(myPoint(200, 200)), ptD(myPoint(100, 200)) {
	
	this->calcCentroid();
}

myRectangle::myRectangle(myPoint UL, myPoint UR, myPoint LR, myPoint LL)
	: ptA(UL), ptB(UR), ptC(LR), ptD(LL) {

	this->calcCentroid();
}

myRectangle::myRectangle(const myPoint& upperLeft, const myPoint& lowerRight) 
	: ptA(upperLeft), ptC(lowerRight), ptB(myPoint(lowerRight.x, upperLeft.y)), ptD(myPoint(upperLeft.x, lowerRight.y)) {

	this->calcCentroid();
}

void myRectangle::calcCentroid() {
	double centX = (ptA.x - ptB.x) / 2;
	double centY = (ptA.y - ptB.y) / 2;

	centroid = myPoint(centX, centY);
}

void myRectangle::scale(double factor) {
	myMatrix S;
	S.makeScaleMat(factor);
	ptA = S * ptA;
	ptB = S * ptB;
	ptC = S * ptC;
	ptD = S * ptD;
}

void myRectangle::rotate(double angle, int units) {

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
	ptA = R * ptA;
	ptB = R * ptB;
	ptC = R * ptC;
	ptD = R * ptD;
}

void myRectangle::translate(const myVector& u) {
	myMatrix T;
	T.makeTranslationMat(u.x, u.y);

	ptA = T * ptA;
	ptB = T * ptB;
	ptC = T * ptC;
	ptD = T * ptD;
}

void myRectangle::draw(CDC* pDC) {
	pDC->MoveTo(ptA.getX(), ptA.getY());
	pDC->LineTo(ptB.getX(), ptB.getY());
	pDC->LineTo(ptC.getX(), ptC.getY());
	pDC->LineTo(ptD.getX(), ptD.getY());
	pDC->LineTo(ptA.getX(), ptA.getY());
}