#pragma once
#include "myShape.h"
#include "myPoint.h"


class myCircle : public myShape
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
	void rotate(double angle, int units);
	void scale(double factor);
	void draw(CDC* pDC);
};

