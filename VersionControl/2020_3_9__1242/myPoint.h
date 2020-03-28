#pragma once
#include "myClasses.h"


class myPoint : public myVector
{
public:
	myPoint();
	myPoint(float x, float y);
	myPoint operator = (const myPoint& p);
	void translate(float x, float y);
	void translate(const myVector& u);
	void movePt(float x, float y);
	void show(CDC* pDC);
	double getX();
	double getY();
};
