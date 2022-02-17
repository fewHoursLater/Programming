#include "Header.h"
#include "CVector.h"

CVector CVector::operator+(const CVector& other)
{
	if (this->size == other.size)
	{
		CVector rez(this->size);

		for (int a = 0; a < this->size; a++)
		{
			rez.vector[a] = vector[a] + other.vector[a];
		}

		return rez;
	}
	else
	{
		throw - 1;
	}
}

CVector CVector::operator-(const CVector& other)
{
	if (this->size == other.size)
	{
		CVector rez(this->size);

		for (int b = 0; b < this->size; b++)
		{
			rez.vector[b] = vector[b] - other.vector[b];
		}

		return rez;
	}
	else
	{
		throw - 1;
	}
}

CVector& CVector::operator=(const CVector& other)
{
	this->size = other.size;

	if (this->vector != nullptr)
	{
		delete[] this->vector;
	}

	this->vector = new double[other.size];

	for (int c = 0; c < other.size; c++)
	{
		vector[c] = other.vector[c];
	}
	
	return *this;
}

double& CVector::operator[](const int index)
{
	if (index > this->size - 1)
	{
		double* tmp = new double[this->size + 1];

		for (int h = 0; h < this->size; h++)
		{
			tmp[h] = this->vector[h];
		}

		this->size = this->size + 1;

		delete[] this->vector;

		this->vector = tmp;
	}

	return this->vector[index];
}

double CVector::operator*(CVector other)
{
	if (this->size == other.size)
	{
		double rez = 0.;

		for (int d = 0; d < this->size; d++)
		{
			rez = rez + (vector[d] * other.vector[d]);
		}

		return rez;
	}
	else
	{
		throw - 1;
	}
	
}