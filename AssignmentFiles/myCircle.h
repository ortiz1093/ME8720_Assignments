#pragma once
#include "myPoint.h"


class myCircle
{
private:
	myPoint center;
	double radius;
public:
	myCircle();
	myCircle(myPoint C, double r);
	myCircle(float X, float Y, double r);
	myPoint getCenter();
	void translate(const myVector& u);
	void scale(double factor);
	void draw(CDC* pDC);
};

