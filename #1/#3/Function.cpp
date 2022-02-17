#include "Header.h"

int FFF(char* filename,int question)
{
	int b = 0;
	int N = 0;
	int spaces = 0;
	int amount = 0;
	int check = 1;
	int current_line_lenght;
	int current_value_of_string;
	
	int** arr;

	double average = 0.0;

	char string[512];

	FILE* first_read_elements;
	FILE* second_read_elements;

	FILE* first_write;
	FILE* second_write;

	FILE* first_read_of_length_of_current_string;
	FILE* second_read_of_length_of_current_string;
	FILE* third_read_of_length_of_current_string;
	FILE* fourth_read_of_length_of_current_string;

	first_read_elements = fopen(filename, "r");
	first_write = fopen("write.txt", "w");

	if (!first_read_elements)
	{
		printf("\nError 1.\n");
		exit(-1);
	}

	if (!first_write)
	{
		fclose(first_read_elements);
		printf("\nError 2.\n");
		exit(-1);
	}

	while ((fgets(string, 512, first_read_elements)) != NULL)
	{

		while (string[b] != '\0')
		{
			if (string[b] == ' ')
			{
				spaces++;
			}

			b++;
		}

		fprintf(first_write, "%d\n", spaces + 1);

		spaces = 0;

		b = 0;

		N++;
	}

	fclose(first_read_elements);
	fclose(first_write);

	arr = (int**)malloc(N * sizeof(int*));

	if (!arr)
	{
		printf("\nFailed to allocate memory.\n");
		exit(-1);
	}

	first_read_of_length_of_current_string = fopen("write.txt", "r"); // 

	if (!first_read_of_length_of_current_string)
	{
		free(arr);
		printf("\nError 3.\n");
		exit(-1);
	}

	for (int a = 0; a < N; a++)
	{
		if (!(fscanf(first_read_of_length_of_current_string, "%d", &current_line_lenght)))
		{
			fclose(first_read_of_length_of_current_string);
			
			for (int n = 0; n < a - 1; a++)
			{
				free(arr[n]);
			}

			free(arr);

			printf("\nError 4.\n");

			exit(-1);
		}

		arr[a] = (int*)malloc(current_line_lenght * sizeof(int));

		if (!arr)
		{
			for (int c = 0; c < a; c++)
			{
				free(arr[c]);
			}

			free(arr);

			fclose(first_read_of_length_of_current_string);

			printf("\nFailed to allocate memory.\n");

			exit(-1);
		}

	}

	fclose(first_read_of_length_of_current_string);

	second_read_elements = fopen(filename, "r");
	second_read_of_length_of_current_string = fopen("write.txt", "r");

	if (!second_read_elements)
	{
		for (int o = 0; o < N; o++)
		{
			free(arr[o]);
		}

		free(arr);

		printf("\nError 5.\n");

		exit(-1);
	}

	if (!second_read_of_length_of_current_string)
	{
		for (int p = 0; p < N; p++)
		{
			free(arr[p]);
		}

		free(arr);

		fclose(second_read_elements);
		
		printf("\nError 6.\n");

		exit(-1);
	}

	for (int d = 0; d < N; d++)
	{

		if (!fscanf(second_read_of_length_of_current_string, "%d", &current_line_lenght))
		{
			for (int q = 0; q < N; q++)
			{
				free(arr[q]);
			}

			free(arr);

			fclose(second_read_elements);

			fclose(second_read_of_length_of_current_string);

			printf("\nFailed to read value.\n");

			exit(-1);
		}

		for (int e = 0; e < current_line_lenght; e++)
		{

			if (!fscanf(second_read_elements, "%d", &current_value_of_string))
			{
				printf("\nFailed to read value.\n");
				exit(-1);
			}

			arr[d][e] = current_value_of_string;
		}

	}

	fclose(second_read_elements);
	fclose(second_read_of_length_of_current_string);

	third_read_of_length_of_current_string = fopen("write.txt", "r");
	second_write = fopen("secondwrite.txt", "w");

	if (!third_read_of_length_of_current_string)
	{
		for (int r = 0; r < N; r++)
		{
			free(arr[r]);
		}

		free(arr);

		printf("\nError 7.\n");

		exit(-1);
	}

	if (!second_write)
	{
		for (int s = 0; s < N; s++)
		{
			free(arr[s]);
		}

		free(arr);

		fclose(third_read_of_length_of_current_string);

		printf("\nError 8.\n");

		exit(-1);
	}

	for (int f = 0; f < N; f++)
	{
		check = 1;

		if (!fscanf(third_read_of_length_of_current_string, "%d", &current_line_lenght))
		{
			for (int t = 0; t < N; t++)
			{
				free(arr[t]);
			}

			free(arr);

			fclose(third_read_of_length_of_current_string);

			fclose(second_write);

			printf("\nFailed to read value.\n");

			exit(-1);
		}

		for (int g = 0; g < current_line_lenght; g++)
		{
			amount = amount + arr[f][g];
		}

		average = (double)amount / (double)current_line_lenght;

		for (int h = 0; h < current_line_lenght; h++)
		{
			if (arr[f][h] == average)
			{
				int* tmp = arr[f];

				for (int k = f; k < N - 1; k++)
				{
					arr[k] = arr[k + 1];
				}

				if ((N - 1) != 0)
				{
					arr = (int**)realloc(arr, (N - 1) * sizeof(int*));
				}

				free(tmp);

				if (!arr)
				{
					for (int m = 0; m < N; m++)
					{
						free(arr[m]);
					}

					free(arr);

					fclose(third_read_of_length_of_current_string);

					fclose(second_write);

					printf("\nFailed to allocate memory.\n");

					exit(0);
				}

				f = f - 1;

				N = N - 1;

				check = -1;

				break;

			}
		}

		if (check == 1)
		{
			fprintf(second_write, "%d\n", current_line_lenght);
		}

		amount = 0;
		average = 0.0;

	}

	fclose(third_read_of_length_of_current_string);
	fclose(second_write);

	if (question == 1)
	{
		fourth_read_of_length_of_current_string = fopen("secondwrite.txt", "r");

		if (!fourth_read_of_length_of_current_string)
		{
			for (int u = 0; u < N; u++)
			{
				free(arr[u]);
			}

			free(arr);

			printf("\nError 9.\n");

			exit(-1);
		}

		printf("\nResult of work:\n\n");

		for (int i = 0; i < N; i++)
		{
			if (!fscanf(fourth_read_of_length_of_current_string, "%d", &current_line_lenght))
			{
				for (int v = 0; v < N; v++)
				{
					free(arr[v]);
				}

				free(arr);

				fclose(fourth_read_of_length_of_current_string);

				printf("\nFailed to read value.\n");

				exit(-1);
			}

			for (int j = 0; j < current_line_lenght; j++)
			{
				printf("%d ", arr[i][j]);
			}

			printf("\n");
		}

		fclose(fourth_read_of_length_of_current_string);
	}
	
	for (int l = 0; l < N; l++)
	{
		free(arr[l]);
	}

	free(arr);

	return N;
}