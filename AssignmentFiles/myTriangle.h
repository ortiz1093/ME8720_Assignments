#pragma once
#include "myPoint.h"


class myTriangle
{
public:
	myPoint ptA, ptB, ptC, centroid;
	void calcCentroid();
public:
	myTriangle();
	myTriangle(myPoint Top, myPoint LL, myPoint LR);
	void scale(double factor);
	void rotate(double angle, int units);
	void translate(const myVector& u);
	void draw(CDC* pDC);
};

