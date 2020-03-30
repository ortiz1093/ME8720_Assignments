#include "pch.h"
#include "myClasses.h"
#include "myPoint.h"
#include <iostream>
#include <math.h>

constexpr double Pi = 3.14159265;

using namespace std;


////////////////////////////////////////////////////////////////////////////////
/////////////////// myVector ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
myVector::myVector() : x(0), y(0), z(0) {}

myVector::myVector(double x, double y) : x(x), y(y), z(1) {}

myVector::myVector(double x, double y, double z) : x(x), y(y), z(z) {}

myVector myVector::operator + (const myVector& u) {
	/**
	 * Sum two vectors.
	 *
	 * @param u  right-hand side myVector to be summed with *this left-hand side.
	 * @return sum of vectors as myVector.
	 */

	myVector result;

	result.x = x + u.x;
	result.y = y + u.y;
	result.z = z + u.z;

	return result;
}

myVector myVector::operator - (const myVector& u) {
	/**
	 * Difference between two vectors.
	 *
	 * @param u  right-hand side myVector to be subtracted from *this left-hand side.
	 * @return difference of vectors as myVector.
	 */
	myVector result;

	result.x = x - u.x;
	result.y = y - u.y;
	result.z = z - u.z;

	return result;
}

myVector myVector::operator - () {
	/**
	 * Negative vector.
	 *
	 * @param None.
	 * @return Return negative of calling instance.
	 */
	myVector result;

	result.x = -x;
	result.y = -y;
	result.z = -z;

	return result;
}

myVector myVector::operator * (double a) {
	/**
	 * Scale a vector
	 *
	 * @param a right-hand side double scale factor to be applied to *this left-hand side.
	 * @return scaled myVector.
	 */
	myVector result;

	result.x = x * a;
	result.y = y * a;
	result.z = z * a;

	return result;
}

double myVector::dot(const myVector& u) {
	/**
	 * Dot product of two vectors
	 *
	 * @param u right-hand side myVector to be dotted with *this left-hand side.
	 * @return dot product as double.
	 */
	return x * u.x + y * u.y + z * u.z;
}

myVector myVector::cross(const myVector& u) {
	/**
	 * Cross product of two vectors
	 *
	 * @param u right-hand side myVector to be crossed with *this left-hand side.
	 * @return cross product as myVector.
	 */
	myVector result;

	result.x = y * u.z - u.y * z;
	result.y = -(x * u.z - u.x * z);
	result.z = x * u.y - u.x * y;

	return result;
}

myVector myVector::rotate2D(double angle, int units) {
	/**
	 * Rotate vector in two-dimensions
	 *
	 * @param 'angle' gives angle by which to rotate *this about positive z-axis, positive angle CCW, negative CW.
	 * @param 'units' indicates radians (1) or degrees (2), assumes radians if invalid input.
	 * @return rotated vector, or zero-vector if input vector is not 2D.
	 */
	if (units == 1) {
		;
	}
	else if (units == 2) {
		// Convert input angle from degrees to radians
		angle = angle * Pi / 180;
	}
	else {
		cout << "Invalid choice for units. Assuming input in radians." << endl;
	}

	myMatrix rotMat;
	myVector result;

	if (z < 0 || z > 1) {
		cout << "Input vector must be 2D (z = 0 or 1). Returning zero vector." << endl;
		return result;
	}

	rotMat.a11 = cos(angle);
	rotMat.a12 = -sin(angle);
	rotMat.a13 = 0;

	rotMat.a21 = sin(angle);
	rotMat.a22 = cos(angle);
	rotMat.a23 = 0;

	rotMat.a31 = 0;
	rotMat.a32 = 0;
	rotMat.a33 = 1;

	result = rotMat * *this;
	//result.x = floor(result.x);
	//result.y = floor(result.y);
	//result.z = floor(result.z);

	return result;
}

double myVector::getAngle2D(const myVector& u, int units) {
	/**
	 * Calculate angle between two vectors in two-dimensions. Positive output implies CCW
	 * from input. Negative implies CW.
	 *
	 * @param 'u' is vector to compare to *this.
	 * @param 'units' indicates desired output in radians (1) or degrees (2),
	 * assumes radians if invalid input.
	 *
	 * @return angle from input to *this.
	 */

	double angle = atan(y / x) - atan(u.y / u.x);
	double result;

	if (units == 1) {
		// angle already in radians, output as is
		result = angle;
	}
	else if (units == 2) {
		// Convert output angle from radians to degrees
		result = angle * 180.0 / Pi;
	}
	else {
		cout << "Invalid choice for units. Output is in radians." << endl;
		result = angle;
	}

	return result;
}

double myVector::getMagnitude2D() {
	/**
	 * Calculate magnitude of two-dimensional vector
	 *
	 * @return magnitude of *this.
	 */

	double result = 0;

	if (z < 0 || z > 1) {
		cout << "Input vector must be 2D (z = 0 or 1). Returning zero." << endl;
		return result;
	}

	result = sqrt(pow(x, 2) + pow(y, 2));

	return result;
}

double myVector::getMagnitude3D() {
	/**
	 * Calculate magnitude of three-dimensional vector
	 *
	 * @return magnitude of *this.
	 */
	double result;

	result = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

	return result;
}

myVector myVector::scale2D(double a) {
	/**
	 * Scale a two-dimensional vector
	 *
	 * @param a right-hand side double scale factor to be applied to *this left-hand side.
	 * @return scaled myVector.
	 */
	myVector result;

	result.x = x * a;
	result.y = y * a;
	result.z = z;

	return result;
}

void myVector::display() {
	/**
	 * Print vector to std out.
	 */

	cout << "\n[" << x << "]" << endl;
	cout << "[" << y << "]" << endl;
	cout << "[" << z << "]" << endl;
}

void myVector::draw(double tailX, double tailY, CDC* pDC) {
	pDC->MoveTo(tailX, tailY);
	pDC->LineTo(tailX + x, tailY + y);
}

void myVector::draw(CDC* pDC) {
	pDC->MoveTo(0, 0);
	pDC->LineTo(x, y);
}



////////////////////////////////////////////////////////////////////////////////
/////////////////// myMatrix ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
myMatrix::myMatrix() {
	a11 = 0;
	a12 = 0;
	a13 = 0;
	a21 = 0;
	a22 = 0;
	a23 = 0;
	a31 = 0;
	a32 = 0;
	a33 = 0;
}

myMatrix::myMatrix(int* elements) {
	a11 = elements[0];
	a12 = elements[1];
	a13 = elements[2];
	a21 = elements[3];
	a22 = elements[4];
	a23 = elements[5];
	a31 = elements[6];
	a32 = elements[7];
	a33 = elements[8];
}

myMatrix::myMatrix(const myVector A, const myVector B, const myVector C, int direction) {
	switch (direction) {
	case 1:
		a11 = A.x;
		a12 = A.y;
		a13 = A.z;

		a21 = B.x;
		a22 = B.y;
		a23 = B.z;

		a31 = C.x;
		a32 = C.y;
		a33 = C.z;
	case 2:
		a11 = A.x;
		a21 = A.y;
		a31 = A.z;

		a12 = B.x;
		a22 = B.y;
		a32 = B.z;

		a13 = C.x;
		a23 = C.y;
		a33 = C.z;
	default:
		a11 = 0;
		a21 = 0;
		a31 = 0;

		a12 = 0;
		a22 = 0;
		a32 = 0;

		a13 = 0;
		a23 = 0;
		a33 = 0;
	}
}

myMatrix myMatrix::operator +(const myMatrix& B) {
	myMatrix result;

	result.a11 = a11 + B.a11;
	result.a12 = a12 + B.a12;
	result.a13 = a13 + B.a13;
	result.a21 = a21 + B.a21;
	result.a22 = a22 + B.a22;
	result.a23 = a23 + B.a23;
	result.a31 = a31 + B.a31;
	result.a32 = a32 + B.a32;
	result.a33 = a33 + B.a33;

	return result;
}

myMatrix myMatrix::operator -(const myMatrix& B) {
	myMatrix result;

	result.a11 = a11 - B.a11;
	result.a12 = a12 - B.a12;
	result.a13 = a13 - B.a13;
	result.a21 = a21 - B.a21;
	result.a22 = a22 - B.a22;
	result.a23 = a23 - B.a23;
	result.a31 = a31 - B.a31;
	result.a32 = a32 - B.a32;
	result.a33 = a33 - B.a33;

	return result;
}

myMatrix myMatrix::operator *(const myMatrix& B) {
	myMatrix result;

	result.a11 = a11 * B.a11 + a12 * B.a21 + a13 * B.a31;
	result.a12 = a11 * B.a12 + a12 * B.a22 + a13 * B.a32;
	result.a13 = a11 * B.a13 + a12 * B.a23 + a13 * B.a33;

	result.a21 = a21 * B.a11 + a22 * B.a21 + a23 * B.a31;
	result.a22 = a21 * B.a12 + a22 * B.a22 + a23 * B.a32;
	result.a23 = a21 * B.a13 + a22 * B.a23 + a23 * B.a33;

	result.a31 = a31 * B.a11 + a32 * B.a21 + a33 * B.a31;
	result.a32 = a31 * B.a12 + a32 * B.a22 + a33 * B.a32;
	result.a33 = a31 * B.a13 + a32 * B.a23 + a33 * B.a33;

	return result;
}


myMatrix myMatrix::operator *(double a) {
	myMatrix result;

	result.a11 = a11 * a;
	result.a12 = a12 * a;
	result.a13 = a13 * a;

	result.a21 = a21 * a;
	result.a22 = a22 * a;
	result.a23 = a23 * a;

	result.a31 = a31 * a;
	result.a32 = a32 * a;
	result.a33 = a33 * a;

	return result;
}

myVector myMatrix::operator *(const myVector& u) {
	myVector result;

	result.x = a11 * u.x + a12 * u.y + a13 * u.z;
	result.y = a21 * u.x + a22 * u.y + a23 * u.z;
	result.z = a31 * u.x + a32 * u.y + a33 * u.z;

	return result;
}

myPoint myMatrix::operator *(const myPoint& p) {
	myPoint result;

	result.x = a11 * p.x + a12 * p.y + a13 * p.z;
	result.y = a21 * p.x + a22 * p.y + a23 * p.z;
	result.z = a31 * p.x + a32 * p.y + a33 * p.z;

	return result;
}

//myPoint myMatrix::operator *(const myPoint& p) {
//	myPoint result;
//
//	result.x = a11 * p.x + a12 * p.y + a13 * p.z;
//	result.y = a21 * p.x + a22 * p.y + a23 * p.z;
//	result.z = a31 * p.x + a32 * p.y + a33 * p.z;
//
//	cout << "\nmultiply result = ";
//	result.display();
//
//	return result;
//}

myVector myMatrix::vecMultiply(const myVector& u) {
	myVector result;

	result.x = a11 * u.x + a12 * u.y + a13 * u.z;
	result.y = a21 * u.x + a22 * u.y + a23 * u.z;
	result.z = a31 * u.x + a32 * u.y + a33 * u.z;

	return result;
}

myMatrix myMatrix::transpose() {
	myMatrix result;

	result.a11 = a11;
	result.a22 = a22;
	result.a33 = a33;

	result.a12 = a21;
	result.a13 = a31;
	result.a23 = a32;

	result.a21 = a12;
	result.a31 = a13;
	result.a32 = a23;

	return result;
}

double myMatrix::getDeterminant() {
	double det;

	det = a11 * (a22 * a33 - a32 * a23) - a12 * (a21 * a33 - a31 * a23) + a13 * (a21 * a32 - a31 * a22);

	return det;
}

myMatrix myMatrix::getInverse() {
	myMatrix result;
	double det = this->getDeterminant();

	result.a11 = (a22 * a33 - a32 * a23) / det;
	result.a12 = -(a21 * a33 - a31 * a23) / det;
	result.a13 = (a21 * a32 - a31 * a22) / det;

	result.a21 = -(a12 * a33 - a32 * a13) / det;
	result.a22 = (a11 * a33 - a31 * a13) / det;
	result.a23 = -(a11 * a32 - a31 * a12) / det;

	result.a31 = (a12 * a23 - a22 * a13) / det;
	result.a32 = -(a11 * a23 - a21 * a13) / det;
	result.a33 = (a11 * a22 - a21 * a12) / det;

	return result;
}

void myMatrix::makeRotationMat(double angle) {
	a11 = cos(angle);
	a12 = -sin(angle);
	a13 = 0;

	a21 = sin(angle);
	a22 = cos(angle);
	a23 = 0;

	a31 = 0;
	a32 = 0;
	a33 = 1;
}

void myMatrix::makeTranslationMat(double x, double y) {
	a11 = 1;
	a12 = 0;
	a13 = x;

	a21 = 0;
	a22 = 1;
	a23 = y;

	a31 = 0;
	a32 = 0;
	a33 = 1;
}

void myMatrix::makeScaleMat(double s) {
	a11 = s;
	a12 = 0;
	a13 = 0;

	a21 = 0;
	a22 = s;
	a23 = 0;

	a31 = 0;
	a32 = 0;
	a33 = 1;
}

void myMatrix::display() {
	cout << "\n[" << a11 << " " << a12 << " " << a13 << "]" << endl;
	cout << "[" << a21 << " " << a22 << " " << a23 << "]" << endl;
	cout << "[" << a31 << " " << a32 << " " << a33 << "]" << endl;
}