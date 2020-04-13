#pragma once
#include "myShape.h"
#include "myPoint.h"


class myRectangle : public myShape
{
public:
	myPoint ptA, ptB, ptC, ptD;
	void calcCentroid();
public:
	myRectangle();
	myRectangle(myPoint UL, myPoint UR, myPoint LR, myPoint LL);
	myRectangle(const myPoint& upperLeft, const myPoint& lowerRight);
	void scale(double factor);
	void rotate(double angle, int units);
	void translate(const myVector& u);
	void draw(CDC* pDC);
};

