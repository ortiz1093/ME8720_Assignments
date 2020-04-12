#pragma once
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
};