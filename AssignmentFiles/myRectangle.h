#pragma once
#include "myPoint.h"


class myRectangle
{
public:
	myPoint ptA, ptB, ptC, ptD,centroid;
	void calcCentroid();
public:
	myRectangle();
	myRectangle(myPoint UL, myPoint UR, myPoint LR, myPoint LL);
	myRectangle(const myPoint& upperLeft, const myPoint& lowerRight);
	void scale(int factor);
	//void rotate(double angle, int units);
	//void translate(const myVector& u);
	void draw(CDC* pDC);
};

