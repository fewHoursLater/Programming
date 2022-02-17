#include "Header.h"
#include "Autotests.h"

int Core_test()
{
	if (Auto_test1() * Auto_test2() == 1)
	{
		return 1;
	}

	return 0;
}

int Auto_test1(void)
{
	
	char testword1[] = "\"AAA\"";
	char name1[] = "datatest1.txt";
	char charres1[16];

	int result1;

	FILE* test1;

	test1 = fopen(name1, "w+");
	
	if (!test1)
	{
		return 0;
	}

	fprintf(test1, "%s", testword1);

	fclose(test1);

	result1 = Searcher(name1,charres1);

	if (result1 == 1 && charres1[0] == 'A' && charres1[1] == 'A' && charres1[2] == 'A')
	{			
		return 1;
	}

	return 0;
}

int Auto_test2(void)
{
	
	char testword1[] = "\"Aab\"";
	char testword2[] = "\"Asldfj\"";
	char testword3[] = "\"Abracadabra\"";
	char testword4[] = "\"Aa\"";
	char testword5[] = "\"Somethingmore\"";
	char name2[] = "datatest2.txt";
	char charres2[16];

	int result2;

	FILE* test2;

	test2 = fopen(name2, "w+");

	if (!test2)
	{
		return 0;
	}

	fprintf(test2, "%s %s %s %s %s", testword1,testword2,testword3,testword4,testword5);

	fclose(test2);

	result2 = Searcher(name2,charres2);

	if (result2 == 1 && charres2[0] == 'A' && charres2[1] == 'a')
	{
		return 1;
	}

	return 0;
}