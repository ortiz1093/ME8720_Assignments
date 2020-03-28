#pragma once
#include<iostream>

using namespace std;



////////////////////////////////////////////////////////////////////////////////
/////////////////// myVector ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class myVector {
	friend class myMatrix;
	friend class myPoint;
	friend class myCircle;
protected:
	double x, y, z;
public:
	myVector();
	myVector(double x, double y, double z);
	myVector operator + (const myVector& u);
	myVector operator - (const myVector& u);
	myVector operator - ();
	myVector operator * (double a);
	double dot(const myVector& u);
	myVector cross(const myVector& u);
	myVector rotate2D(double angle, int units);
	double getAngle2D(const myVector& u, int units);
	double getMagnitude2D();
	double getMagnitude3D();
	myVector scale2D(double a);
	void display();
	void draw(double tailX, double tailY, CDC* pDC);
};


////////////////////////////////////////////////////////////////////////////////
/////////////////// myMatrix ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class myMatrix {
	friend class myVector;
	friend class transMat;
protected:
	double a11, a12, a13;
	double a21, a22, a23;
	double a31, a32, a33;
public:
	myMatrix();
	myMatrix(int* elements);
	myMatrix(const myVector A, const myVector B, const myVector C, int direction);
	myMatrix operator +(const myMatrix& B);
	myMatrix operator -(const myMatrix& B);
	myMatrix operator *(const myMatrix& B);
	myMatrix operator *(double B);
	myVector operator *(const myVector& u);
	myPoint operator *(const myPoint& p);
	myVector vecMultiply(const myVector& u);
	myMatrix transpose();
	double getDeterminant();
	myMatrix getInverse();
	void makeRotationMat(double angle);
	void makeTranslationMat(double x, double y);
	void display();
};
