#pragma once
#include "myPoint.h"


class myTriangle
{
public:
	myPoint ptA, ptB, ptC, centroid;
	void calcCentroid();
public:
	myTriangle();
	//myTriangle(myPoint UL, myPoint UR, myPoint LR, myPoint LL);
	//myTriangle(const myPoint& upperLeft, const myPoint& lowerRight);
	//void scale(double factor);
	//void rotate(double angle, int units);
	//void translate(const myVector& u);
	void draw(CDC* pDC);
};

