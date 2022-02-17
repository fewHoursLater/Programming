#pragma once

#include "Header.hpp"

class CintN
{
private:

	int arr[N];

public:

	CintN(); 

	CintN operator+(const CintN);
	CintN operator-(const CintN);

	int set_value(int); 
	int converter(void);
	
	void printer(void); 

	friend int check_summ(CintN);
	friend int check_subtract(CintN);
};



