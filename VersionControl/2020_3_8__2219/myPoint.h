#pragma once
#include "myClasses.h"


class myPoint : public myVector
{
public:
	myPoint();
	myPoint(float x, float y);
	void translate(float x, float y);
};
