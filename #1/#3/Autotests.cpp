#include "Header.h"
#include "Autotests.h"

int Auto_test1(void)
{
	int result1 = -1;

	char name1[] = "test_data1";

	FILE* test_data1;

	test_data1 = fopen(name1, "w");

	if (!test_data1)
	{
		return 0;
	}

	fprintf(test_data1, "%d %d %d %d %d", 1, 2, 3, 4, 5);

	fclose(test_data1);

	result1 = FFF(name1,0);
	
	if (result1 == 0)
	{
		return 1;
	}

	return 0;
}

int Auto_test2(void)
{
	int result2 = -1;

	char name2[] = "test_data2";

	FILE* test_data2;

	test_data2 = fopen(name2, "w");

	if (!test_data2)
	{
		return 0;
	}

	fprintf(test_data2, "%d %d %d %d %d", 12, 2, 3, 4, 5);

	fprintf(test_data2,"\n");

	fprintf(test_data2, "%d %d %d %d %d", 5, 5, 5, 5, 5);

	fclose(test_data2);

	result2 = FFF(name2, 0);

	if (result2 == 1)
	{
		return 1;
	}

	return 0;
}

int Core_test(void)
{
	if (Auto_test1() * Auto_test2() == 1)
	{
		return 1;
	}
		
}