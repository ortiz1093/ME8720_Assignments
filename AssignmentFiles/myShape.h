#pragma once
#include "myClasses.h"

class myShape
{
	friend class myPattern;
protected:
	myShape* nextShape;
	myShape* prevShape;
public:
	myShape();
	~myShape();
	virtual void draw(CDC* pDC)=0;
	virtual void scale(double factor) = 0;
	virtual void rotate(double angle, int units) = 0;
	virtual void translate(const myVector& u) = 0;
};