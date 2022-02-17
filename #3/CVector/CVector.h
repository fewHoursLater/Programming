#pragma once

#include "Header.h"

class CVector
{
private:
	int size = 0;
	double* vector;

public:
	CVector();
	CVector(const int);
	CVector(const CVector&); 
	~CVector(); 

	CVector operator+(const CVector&);
	CVector operator-(const CVector&);
	CVector& operator=(const CVector&);

	double operator*(CVector);
	double& operator[](const int);
	void print(void);

	friend int test(void);
};