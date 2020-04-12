#include "pch.h"
#include "myPattern.h"
#include "myShape.h"


myPattern::myPattern(string name) : name(name) {
	cursor = nullptr;
	head = nullptr;
	tail = nullptr;
};

void myPattern::addShape(myShape* newShape) {
	if (!head) {
		head = newShape;
		tail = newShape;
		cursor = newShape;
	}
	else {
		tail->nextShape = newShape;
		tail = newShape;
		tail->prevShape = newShape;
	}
};

void myPattern::draw(CDC* pDC) {
	while (cursor) {
		cursor->draw(pDC);
		cursor = cursor->nextShape;
	}

	cursor = head;
};