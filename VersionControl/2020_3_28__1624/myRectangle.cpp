#include "pch.h"
#include "myRectangle.h"

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

void myRectangle::scale(int factor) {
	myMatrix S;
	S.makeScaleMat(factor);
	ptA = S * ptA;
	ptB = S * ptB;
	ptC = S * ptC;
	ptD = S * ptD;
}
//
//void myRectangle::rotate(double angle, int units) {}
//
//void myRectangle::translate(const myVector& u) {}

void myRectangle::draw(CDC* pDC) {
	pDC->MoveTo(ptA.getX(), ptA.getY());
	pDC->LineTo(ptB.getX(), ptB.getY());
	pDC->LineTo(ptC.getX(), ptC.getY());
	pDC->LineTo(ptD.getX(), ptD.getY());
	pDC->LineTo(ptA.getX(), ptA.getY());
}