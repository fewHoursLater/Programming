#include "Header.h"
#include "Autotest.h"

int Auto_test1(void)
{
	int auxiliary1 = INT_MIN;
	int cnt1 = 0;
	List* testList1 = NULL;

	testList1 = ListCreator(1, 2, 3, 4, 5, 6);

	if (testList1 == NULL)
	{
		return 0;
	}

	auxiliary1 = AddElement(testList1, 1, 1, 1, 1, 1, 1);

	if (auxiliary1 == -1)
	{
		return 0;
	}

	auxiliary1 = AddElement(testList1, 1, 1, 1, 6, 1, 3);

	if (auxiliary1 == -1)
	{
		return 0;
	}

	while (testList1 != NULL)
	{
		cnt1++;
		testList1 = testList1->next;
	}

	testList1 = Remover(testList1);


	/*printf(" cnt1 - %d ---", cnt1);*/

	if (cnt1 == 3)
	{
		return 1;
	}

	return 0;
}

int Auto_test2(void)
{
	int auxiliary2 = INT_MIN;
	int cnt2 = 0;
	List* testList2 = NULL;

	testList2 = ListCreator(1, 2, 3, 4, 5, 6);

	if (testList2 == NULL)
	{
		return 0;
	}

	auxiliary2 = AddElement(testList2, 1, 4, 1, 1, 1, 1);

	if (auxiliary2 == -1)
	{
		return 0;
	}

	auxiliary2 = AddElement(testList2, 1, 1, 1, 1, 8, 1);

	if (auxiliary2 == -1)
	{
		return 0;
	}

	while (testList2 != NULL)
	{
		cnt2++;
		testList2 = testList2->next;
	}

	testList2 = Remover(testList2);

	if (cnt2 == 3)
	{
		return 1;
	}

	return 0;
}

int Core_test(void)
{
	if (Auto_test1() * Auto_test2())
	{
		return 1;
	}

	return 0;
}