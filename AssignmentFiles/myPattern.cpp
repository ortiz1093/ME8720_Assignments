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

void myPattern::scale(double factor) {
	while (cursor) {
		cursor->scale(factor);
		cursor = cursor->nextShape;
	}

	cursor = head;
};

void myPattern::translate(const myVector& u) {
	while (cursor) {
		cursor->translate(u);
		cursor = cursor->nextShape;
	}

	cursor = head;
};

void myPattern::rotate(double angle, int units) {
	while (cursor) {
		cursor->rotate(angle,units);
		cursor = cursor->nextShape;
	}

	cursor = head;
};