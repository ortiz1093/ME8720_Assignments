#pragma once
#include<iostream>
#include<string>
#include "pch.h"
#include "myShape.h"
using namespace std;

class myPattern
{
private:
	string name;
	myShape* cursor;
	myShape* head;
	myShape* tail;
public:
	myPattern(string name);
	void addShape(myShape* newShape);
	void draw(CDC* pDC);
	void scale(double factor);
	void translate(const myVector& u);
	void rotate(double angle, int units);
};

