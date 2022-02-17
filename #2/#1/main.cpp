#include "Header.h"
#include "Autotest.h"

int main()
{
	if (Core_test() == 1)
	{
		int strings = -1;
		int columns = -1;
		int** arr;
		char filename[256];
		int alphacolumns;

		printf("Enter the name of the file you want to read:\n\n");

		if (!scanf("%s", &filename))
		{
			printf("\nFailed to get the correct file name.\n");
			exit(1);
		}

		FILE* read = fopen(filename, "r");

		if (!read)
		{
			printf("\nCould not open file.\n");
			exit(1);
		}

		if (!fscanf(read, "%d", &strings))
		{
			printf("\nFailed to read file.\n");
			exit(1);
		}

		if (!fscanf(read, "%d", &columns))
		{
			printf("\nFailed to read file.\n");
			exit(1);
		}

		if (strings <= 0 || columns <= 0)
		{
			printf("\nIncorrect array sizes.\n");
			exit(1);
		}

		arr = (int**)malloc(strings * sizeof(int*));

		if (!arr)
		{
			printf("\nFailed to allocate memory.\n");
			exit(1);
		}

		for (int i = 0; i < strings; i++)
		{
			arr[i] = (int*)malloc(columns * sizeof(int));

			if (!arr)
			{
				for (int j = 0; j < i; j++)
				{
					free(arr[j]);
				}

				printf("\nFailed to allocate memory.\n");

				exit(1);
			}
		}

		for (int y = 0; y < strings; y++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (!fscanf(read, "%d", &arr[y][j]))
				{
					printf("\nFailed to read array elements.\n");
					exit(1);
				}
			}
		}

		printf("\n");
		printf("The given array:\n\n");
		for (int p = 0; p < strings; p++)
		{
			for (int f = 0; f < columns; f++)
			{
				printf("%d ", arr[p][f]);

			}

			printf("\n");
		}

		alphacolumns = Enter(arr, strings, columns,2);
		
		for (int p = 0; p < alphacolumns; p++)
		{
			free(arr[p]);
		}

		free(arr);

		return 0;
	}

	else
	{
		printf("Something went wrong.\n");
		printf("\nAutotes result:\n");

		if (Core_test() == 1)
		{
			printf("\nCore test - passed.\n");
		}

		else
		{
			printf("\nCore test - failed.\n");
		}

		return 1;
	}
}

