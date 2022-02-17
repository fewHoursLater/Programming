#include "Header.hpp"
#include "CintN.hpp"

int check_x(int var)
{
	if (N > 1)
	{
		if (var >= (int)pow(10, N - 1) && var <= (int)pow(10, N) - 1)
		{
			return 1;
		}

		return  0;
	}

	if (var >= 0 && var <= 9)
	{
		return 1;
	}

	return 0;
}

int check_summ(CintN S)
{
	if (S.arr[0] > 9)
	{
		return 0;
	}

	return 1;
}

int check_subtract(CintN Sub)
{
	if (N > 1)
	{
		if (Sub.arr[0] == 0)
		{
			return 0;
		}

		return 1;
	}

	return 1;
}

int summ_function(int Fir, int Sec, int printparam)
{
	CintN a, b, c;

	if (!a.set_value(Fir))
	{
		return 1;
	}

	if (!b.set_value(Sec))
	{
		return 1;
	}

	c = a.operator+(b);

	if ((Fir + Sec) == c.converter())
	{
		if (check_summ(c))
		{
			if (printparam == 1)
			{
				c.printer();
			}

			return 2;
		}
	}

	return 3;
}

int subtract_function(int Fir, int Sec, int printparam)
{
	CintN a, b, c;

	if (!a.set_value(Fir))
	{
		return 1;
	}

	if (!b.set_value(Sec))
	{
		return 1;
	}

	if (N == 1)
	{
		if (Sec > Fir)
		{
			return 2;
		}
	}

	if (N > 1)
	{
		if (Sec >= Fir)
		{
			return 2;
		}
	}

	c = a.operator-(b);

	if ((Fir - Sec) == c.converter())
	{
		if (check_subtract(c))
		{
			if (printparam == 1)
			{
				c.printer();
			}

			return 3;
		}
	}

	return 4;
}

int test(void)
{
	int first = -1;
	int second = -1;

	srand(time(0));

	for (int h = 0; h < 100;)
	{
		if (N > 1)
		{
			first = rand() % ((int)pow(10, N) - 1 - (int)pow(10, N - 1) + 1) + (int)pow(10, N - 1);
			second = rand() % ((int)pow(10, N) - 1 - (int)pow(10, N - 1) + 1) + (int)pow(10, N - 1);
		}

		if (N == 1)
		{
			first = rand() % (9 - 0 + 1) + 0;
			second = rand() % (9 - 0 + 1) + 0;
		}

		if (N > 1)
		{
			if ((first + second) <= (int)(pow(10, N) - 1) && (first - second) >= (int)pow(10, N - 1))
			{
				if (!summ_function(first, second, 0))
				{
					return 0;
				}

				if (!subtract_function(first, second, 0))
				{
					return 0;
				}

				h++;
			}
		}

		if (N == 1)
		{
			if ((first + second) <= 9 && (first - second) >= 0)
			{
				if (!summ_function(first, second, 0))
				{
					return 0;
				}

				if (!subtract_function(first, second, 0))
				{
					return 0;
				}

				h++;
			}
		}
	}

	return 1;
}