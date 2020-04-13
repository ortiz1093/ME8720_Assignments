#include "pch.h"
#include "myPattern.h"
#include "myShape.h"


myPattern::myPattern(string name) : name(name) {
	cursor = nullptr;
	head = nullptr;
	tail = nullptr;
};

void myPattern::addShape(myShape* newShape, string label) {
	if (!head) {
		head = newShape;
		tail = newShape;
		cursor = newShape;
	}
	else {
		tail->nextShape = newShape;
		newShape->prevShape = tail;
		tail = newShape;
	}

	numShapes++;
	newShape->label = label;
	this->calcCentroid();
	
};

void myPattern::deleteShape(string label) {

	bool flag = TRUE;
	while (flag) {
		string shapeLabel = cursor->label;

		if (shapeLabel.compare(label) == 0) {
			if (cursor == head) {
				head = cursor->nextShape;
				cursor->nextShape = nullptr;
			}
			else if (cursor == tail) {
				tail = cursor->prevShape;
				cursor->prevShape = nullptr;
			}
			else {
				myShape* previous = cursor->prevShape;
				myShape* subsequent = cursor->nextShape;
				previous->nextShape = subsequent;
				subsequent->prevShape = previous;
			}

			flag = FALSE;
		}
		else if (shapeLabel.compare(tail->label) == 0) {
			flag = FALSE;
		}
		else {
			cursor = cursor->nextShape;
		}
	}

	numShapes--;
	this->calcCentroid();
	cursor = head;
}

myShape* myPattern::getShape(string label) {
	
	myShape* found = nullptr;
	
	bool flag = TRUE;
	while (flag) {
		string shapeLabel = cursor->label;

		if (shapeLabel.compare(label) == 0) {
			found = cursor;
			flag = FALSE;
		}
		else if (shapeLabel.compare(tail->label) == 0) {
			flag = FALSE;
		}
		else {
			cursor = cursor->nextShape;
		}
	}

	cursor = head;
	return found;
}

void myPattern::calcCentroid() {
	cursor = head;

	double xSum = 0;
	double ySum = 0;
	
	bool flag = TRUE;
	
	while (cursor) {
		xSum += cursor->getCentroid()->getX();
		ySum += cursor->getCentroid()->getY();

		cursor = cursor->nextShape;
	}

	double centX = xSum / numShapes;
	double centY = ySum / numShapes;
	centroid = myPoint(centX, centY);

	cursor = head;
}

void myPattern::showCentroid(CDC* pDC) {
	centroid.show(pDC);
	int x;
}

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
	this->calcCentroid();
};

void myPattern::translate(const myVector& u) {
	while (cursor) {
		cursor->translate(u);
		cursor = cursor->nextShape;
	}

	cursor = head;
	this->calcCentroid();
};

void myPattern::rotate(double angle, int units) {
	while (cursor) {
		cursor->rotate(angle,units);
		cursor = cursor->nextShape;
	}

	cursor = head;
	this->calcCentroid();
};