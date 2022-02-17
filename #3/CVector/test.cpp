#include "Header.h"
#include "CVector.h"

int test(void)
{
	int summ = 0;

	CVector a(10), b(10), c;

	for (int j = 0; j < 10; j++)
	{
		a[j] = j;
		b[j] = -j;
	}

	c = a + b;

	for (int i = 0; i < 10; i++)
	{
		if (c[i] != 0)
		{
			return 0;
		}
	}

	for (int h = 0; h < 10; h++)
	{
		a[h] = (double ) h * h;
		b[h] = (double) h * h + 15;
	}

	if (a * b != 19608)
	{
		return 0;
	}

	return 1;
}