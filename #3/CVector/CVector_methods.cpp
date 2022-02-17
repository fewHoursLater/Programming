#include "Header.h"
#include "CVector.h"

CVector::CVector() 
{
	this->size = 1;
	vector = new double[this->size];
	vector[0] = 0;
}

CVector::CVector(const int size)
{
	this->size = size;
	vector = new double[this->size];

	for (int e = 0; e < this->size; e++)
	{
		vector[e] = 0;
	}
}

CVector::~CVector()
{
	delete[] this->vector;
}

CVector::CVector(const CVector& other) 
{
	this->size = other.size;

	this->vector = new double[this->size];

	for (int f = 0; f < this->size; f++)
	{
		this->vector[f] = other.vector[f];
	}
}

void CVector::print(void)
{
	for (int g = 0; g < this->size; g++)
	{
		cout << this->vector[g] << " ";
	}
}
