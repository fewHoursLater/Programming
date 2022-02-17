#include "Header.hpp"
#include "CintN.hpp"

CintN::CintN()
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = -1;
	}
}

CintN CintN::operator+(const CintN other)
{
	CintN rez;

	int elder = 0;

	for (int qh = N - 1; qh >= 0; qh--)
	{
		rez.arr[qh] = arr[qh] + other.arr[qh];
		rez.arr[qh] = rez.arr[qh] + elder;

		if (qh == 0)
		{
			if (rez.arr[qh] > 9)
			{
				return rez;
			}
		}

		if (rez.arr[qh] > 9)
		{
			rez.arr[qh] = rez.arr[qh] - 10;
			elder = 1;
			continue;
		}

		elder = 0;
	}

	return rez;
}

CintN CintN::operator-(const CintN other)
{
	CintN rez;

	int credit = 0;
	int tmp = 0;

	for (int vb = N - 1; vb >= 0; vb--)
	{
		if (vb == N - 1)
		{
			if (arr[vb] >= other.arr[vb])
			{
				rez.arr[vb] = arr[vb] - other.arr[vb];
			}

			if (arr[vb] < other.arr[vb])
			{
				credit = 1;
				rez.arr[vb] = (arr[vb] + 10) - other.arr[vb];
			}

			continue;
		}

		if (arr[vb] == 0)
		{
			if (other.arr[vb] != 0)
			{
				if (credit == 1)
				{
					credit = 1;
					rez.arr[vb] = 9 - other.arr[vb];
				}

				if (credit == 0)
				{
					credit = 1;
					rez.arr[vb] = 10 - other.arr[vb];
				}
			}

			if (other.arr[vb] == 0)
			{
				if (credit == 1)
				{
					rez.arr[vb] = 9;
				}

				if (credit == 0)
				{
					rez.arr[vb] = 0;
				}
			}
		}

		if (arr[vb] > 0)
		{
			tmp = arr[vb];
			tmp = tmp - credit;

			if (tmp == 0)
			{
				credit = 1;
				rez.arr[vb] = 10 - other.arr[vb];
			}

			if (tmp != 0 && tmp < other.arr[vb])
			{
				credit = 1;
				rez.arr[vb] = (tmp + 10) - other.arr[vb];
			}

			if (tmp >= other.arr[vb])
			{
				credit = 0;
				rez.arr[vb] = tmp - other.arr[vb];
			}
		}
	}

	return rez;
}