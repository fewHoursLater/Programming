#include "Header.h"
#include "Autotest.h"


int Core_test()
{
	int check = 1;
	int cc = -1;
	int** temparr;

	temparr = (int**)malloc(1*sizeof(int*));

	if (temparr == NULL)
	{
		printf("\nFailed to allocate memory.\n");
		return 0;
	}

	temparr[0] = (int*)malloc(5*sizeof(int));

	if (temparr == NULL)
	{
		printf("\nFailed to allocate memory.\n");
		free(temparr);
		return 0;
	}

	for (int g = 0; g < 5; g++)
	{
		temparr[0][g] = 0;
	}

	cc = Enter(temparr, 1, 5,check);

	if (cc == 0)
	{

		free(temparr[0]);
		free(temparr);

		return 1;
	}

	free(temparr[0]);
	free(temparr);

	return 0;
}