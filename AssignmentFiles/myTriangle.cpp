#include "pch.h"
#include "myTriangle.h"

constexpr double Pi = 3.14159265;

myTriangle::myTriangle(){

	double apexX = 100.0;
	double apexY = 100.0;
	double side_length = 100.0;

	ptA = myPoint(apexX, apexY);

	double leftX = apexX - side_length / 2;

	double rightX = apexX + side_length / 2;
	double baseY = apexY + sqrt(pow(side_length, 2) - pow(side_length / 2, 2));

	ptB = myPoint(leftX, baseY);
	ptC = myPoint(rightX, baseY);

	this->calcCentroid();
}

myTriangle::myTriangle(myPoint Top, myPoint LL, myPoint LR)
	: ptA(Top), ptB(LL), ptC(LR){

	this->calcCentroid();
}

void myTriangle::calcCentroid() {
	double centX = (ptA.getX() + ptB.getX() + ptC.getX()) / 3;
	double centY = (ptA.getY() + ptB.getY() + ptC.getY()) / 3;

	centroid = myPoint(centX, centY);
}

void myTriangle::scale(double factor) {
	myMatrix S;
	S.makeScaleMat(factor);
	ptA = S * ptA;
	ptB = S * ptB;
	ptC = S * ptC;

	this->calcCentroid();
}

void myTriangle::rotate(double angle, int units) {

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

	this->calcCentroid();
}

void myTriangle::translate(const myVector& u) {
	myMatrix T;
	T.makeTranslationMat(u.x, u.y);

	ptA = T * ptA;
	ptB = T * ptB;
	ptC = T * ptC;

	this->calcCentroid();
}

void myTriangle::draw(CDC* pDC) {
	pDC->MoveTo(ptA.getX(), ptA.getY());
	pDC->LineTo(ptB.getX(), ptB.getY());
	pDC->LineTo(ptC.getX(), ptC.getY());
	pDC->LineTo(ptA.getX(), ptA.getY());
}