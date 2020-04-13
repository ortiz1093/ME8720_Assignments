#pragma once
#include "myClasses.h"
#include "myPoint.h"

class myShape
{
	friend class myPattern;
	friend class myCircle;
	friend class myRectangle;
	friend class myTriangle;
protected:
	myShape* nextShape;
	myShape* prevShape;
	string label = "";
	myPoint centroid;
public:
	myShape();
	~myShape();
	myPoint* getCentroid();
	virtual void draw(CDC* pDC)=0;
	virtual void scale(double factor) = 0;
	virtual void rotate(double angle, int units) = 0;
	virtual void translate(const myVector& u) = 0;
};