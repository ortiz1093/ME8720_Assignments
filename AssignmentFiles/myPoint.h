#pragma once
#include "myClasses.h"


class myPoint : public myVector
{
	friend class myRectangle;
public:
	myPoint();
	myPoint(float x, float y);
	myPoint operator = (const myPoint& p);
	void translate(float x, float y);
	void translate(const myVector& u);
	void movePt(float x, float y);
	void show(CDC* pDC);
	void display();
	double getX();
	double getY();
};
