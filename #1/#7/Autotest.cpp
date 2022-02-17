#include "Header.h"
#include "Autotest.h"

int Auto_test1(void)
{
	int test1 = -1;
	char NameTestFile1[] = "StreamTest1.txt";
	FILE* StreamTest1;

	char TestName11[] = "Alexander";
	int TestGroup11 = 123;
	float TestRank11 = 4.123;
	int TestIsElder11 = 0;

	StreamTest1 = fopen(NameTestFile1, "w");

	if (!StreamTest1)
	{
		return 0;
	}

	fprintf(StreamTest1, "%s %d %g %d", TestName11, TestGroup11, TestRank11, TestIsElder11);

	fclose(StreamTest1);

	test1 = FFF(NameTestFile1, 0);

	if (test1 == 1)
	{
		return 1;
	}

	return 0;
}

int Auto_test2(void)
{

	int test2 = -1;
	char NameTestFile2[] = "StreamTest2.txt";
	FILE* StreamTest2;

	char TestName12[] = "Boris";
	int TestGroup12 = 345;
	float TestRank12 = 13;
	int TestIsElder12 = 1;

	char TestName22[] = "Petr";
	int TestGroup22 = 5;
	float TestRank22 = 0.234;
	int TestIsElder22 = 0;

	char TestName32[] = "Nikolay";
	int TestGroup32 = 345;
	float TestRank32 = 8;
	int TestIsElder32 = 1;

	StreamTest2 = fopen(NameTestFile2, "w");

	if (!StreamTest2)
	{
		return 0;
	}

	fprintf(StreamTest2, "%s %d %g %d\n", TestName12, TestGroup12, TestRank12, TestIsElder12);
	fprintf(StreamTest2, "%s %d %g %d\n", TestName22, TestGroup22, TestRank22, TestIsElder22);
	fprintf(StreamTest2, "%s %d %g %d", TestName32, TestGroup32, TestRank32, TestIsElder32);

	fclose(StreamTest2);

	test2 = FFF(NameTestFile2, 0);

	if (test2 == 2)
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

	return 0;
}