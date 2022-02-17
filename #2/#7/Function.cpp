#include "Header.h"

int FFF(char* filename,int param)
{
	int n = 0;
	int ElderCounter = 0;
	float Rank = 0.0;

	char string[256];
	char tmpname[32];
	
	FILE* Stream;
	
	Stream = fopen(filename, "r+");

	if (!Stream)
	{
		return -1;
	}

	while (fgets(string, 256, Stream) != NULL)
	{
		n++;
	}

	if (n == 0)
	{
		fclose(Stream);
		return -7;
	}

	fclose(Stream);

	Stream = fopen(filename, "r+");

	if (!Stream)
	{
		return -1;
	}

	struct Student* arr = (struct Student*)malloc(n * sizeof(struct Student));

	if (!arr)
	{
		return -2;
	}

	int* ARR = (int*)malloc(n * sizeof(int));

	if (!ARR)
	{
		free(arr);
		return -2;
	}

	for (int a = 0; a < n; a++)
	{
		if (!fscanf(Stream, "%s", &tmpname))
		{
			fclose(Stream);
			free(arr);
			free(ARR);
			return -3;
		}

		strcpy(arr[a].Name, tmpname);

		if (!fscanf(Stream, "%d", &arr[a].Group))
		{
			fclose(Stream);
			free(arr);
			free(ARR);
			return -3;
		}

		if (!fscanf(Stream, "%g", &arr[a].Rating))
		{
			fclose(Stream);
			free(arr);
			free(ARR);
			return -3;
		}

		if (!fscanf(Stream, "%d", &arr[a].IsElder))
		{
			fclose(Stream);
			free(arr);
			free(ARR);
			return -3;
		}

		ARR[a] = arr[a].Group;
	}

	for (int c = 0; c < n; c++)
	{
		if (ARR[c] > 0)
		{
			for (int b = c + 1; b < n; b++)
			{
				if (ARR[b] > 0)
				{
					if (ARR[c] == ARR[b])
					{
						ARR[b] = -1;
					}
				}
			}
		}
	}

	for (int g = 0; g < n; g++)
	{
		for (int h = g + 1; h < n; h++)
		{
			if (strcmp(arr[g].Name, arr[h].Name) == 0)
			{
				fclose(Stream);
				free(arr);
				free(ARR);
				return -4;
			}
		}
	}

	for (int hhghg = 0; hhghg < n; hhghg++)
	{
		if (arr[hhghg].Rating < 0)
		{
			fclose(Stream);
			free(arr);
			free(ARR);
			return -5;
		}
	}

	for (int hhhg = 0; hhhg < n; hhhg++)
	{
		if (arr[hhhg].Group <= 0)
		{
			fclose(Stream);
			free(arr);
			free(ARR);
			return -6;
		}
	}

	for (int hg = 0; hg < n; hg++)
	{
		arr[hg].IsElder = 0;
	}

	for (int bs = 0; bs < n; bs++)
	{
		if (ARR[bs] != -1)
		{
			Rank = MedRank(arr, ARR[bs], n);

			if (Rank == -2)
			{
				fclose(Stream);
				free(arr);
				free(ARR);
				return -2;
			}

			for (int kiol = 0; kiol < n; kiol++)
			{
				if (arr[kiol].Group == ARR[bs] && arr[kiol].Rating == Rank)
				{
					arr[kiol].IsElder = 1;
					ElderCounter++;
					break;
				}
			}
		}
	}

	if (param == 1)
	{
		FILE* Record;

		Record = fopen("Res.Data.txt", "w");

		if (!Record)
		{
			fclose(Stream);
			free(arr);
			free(ARR);
			return -1;
		}

		for (int dddf = 0; dddf < n; dddf++)
		{
			fprintf(Record, "%s %d %g %d", arr[dddf].Name, arr[dddf].Group, arr[dddf].Rating, arr[dddf].IsElder);
			fprintf(Record, "\n");
		}
	}
	
	fclose(Stream);
	free(arr);
	free(ARR);

	return ElderCounter;
}

float MedRank(struct Student* arr, int group, int size)
{
	int peoplecnt = 0;
	int werrt = 0;
	int temp;

	float medrank = 0.0;

	for (int ja = 0; ja < size; ja++)
	{
		if (arr[ja].Group == group)
		{
			peoplecnt++;
		}
	}

	float* j = (float*)malloc(peoplecnt * sizeof(float));

	if (!j)
	{
		return -2;
	}

	for (int trt = 0; trt < size; trt++)
	{
		if (arr[trt].Group == group)
		{
			j[werrt] = arr[trt].Rating;
			werrt++;

		}
	}
	
	for (int vbrew = 0; vbrew < peoplecnt - 1; vbrew++)
	{
		for (int poiu = (peoplecnt - 1); poiu > vbrew; poiu--)
		{
			if (j[poiu - 1] > j[poiu])
			{
				temp = j[poiu - 1];
				j[poiu - 1] = j[poiu];
				j[poiu] = temp;
			}
		}
	}

	if (peoplecnt % 2 == 1)
	{
		medrank = j[(peoplecnt - 1) / 2];
	}

	if (peoplecnt % 2 == 0)
	{
		medrank = j[peoplecnt / 2];
	}

	return medrank;
}