#include "Header.h"

int Enter(int** arr, int strings, int columns,int check)
{
	if (check == 0)
	{
		goto link2;
	}

	int summ = 0;
	double average;

	for (int k = 0; k < columns; k++)
	{
		for (int r = 0; r < strings; r++)
		{
			summ = summ + arr[r][k];
		}

		average = (double)summ / (double)strings;

		for (int h = 0; h < strings; h++)
		{
			if (arr[h][k] == average)
			{
				Remover(arr, strings, columns, k,check);

				goto link;
			
			}
		}

		summ = 0;
	}

	Printer(arr, strings, columns);

return columns;

link2:;
return columns;

link:;
return;
}

void Remover(int** arr, int strings, int columns, int point,int check)
{
	int newcolumns = columns - 1;

	if (point < newcolumns)
	{
		for (int l = point; l < columns; l++)
		{
			for (int t = 0; t < strings; t++)
			{
				arr[t][l] = arr[t][l + 1];
			}
		}
	}

	if (newcolumns == 0 && check!=1)
	{
		printf("\nThe resulting array has no elements.\n");
		return;
	}

	if (newcolumns == 0 && check == 1)
	{
		Enter(arr, strings, newcolumns, 0);
		return;
	}


	for (int s = 0; s < strings; s++)
	{
		int* tmp = (int*)realloc(arr[s], newcolumns * sizeof(int));

		if (!tmp)
		{
			printf("\nFailed to allocate memory.\n");
			exit(1);
		}

		arr[s] = tmp;

	}

	Enter(arr, strings, newcolumns,check);
}

void Printer(int** arr, int strings, int columns)
{
	printf("\n");
	printf("Calculation result:");
	printf("\n\n");

	for (int p = 0; p < strings; p++)
	{
		for (int f = 0; f < columns; f++)
		{
			printf("%d ", arr[p][f]);
		}

		printf("\n");
	}
}