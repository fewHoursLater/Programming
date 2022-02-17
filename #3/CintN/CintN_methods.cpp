#include "Header.hpp"
#include "CintN.hpp"

int CintN::set_value(int x)
{
	if (check_x(x))
	{
		int tail = 0;
		int remainder = 0;
		int power = 0;

		for (int g = 0; g < N; g++)
		{
			remainder = x % 10;
			tail = x - remainder;

			tail = tail / 10;

			x = tail;

			arr[(N - 1) - g] = remainder;
		}

		if (x == 0)
		{
			return 1;
		}
	}

	return 0;
}

void CintN::printer(void)
{
	cout << endl;
	cout << "= ";

	for (int p = 0; p < N; p++)
	{
		cout << arr[p];
	}

	cout << endl << endl;
}

int CintN::converter(void)
{
	int x = 0;

	for (int wq = N - 1; wq >= 0; wq--)
	{
		x = x + arr[wq] * (int)pow(10, N - 1 - wq);
	}

	return x;
}