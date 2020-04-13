#pragma once
#include "myShape.h"
#include "myPoint.h"


class myTriangle : public myShape
{
public:
	//myPoint ptA, ptB, ptC, centroid;
	myPoint ptA, ptB, ptC;
	void calcCentroid();
public:
	myTriangle();
	myTriangle(myPoint Top, myPoint LL, myPoint LR);
	void scale(double factor);
	void rotate(double angle, int units);
	void translate(const myVector& u);
	void draw(CDC* pDC);
};