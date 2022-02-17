#include "Header.h"
#include "Autotests.h"

int main()
{

	if (Core_test()==1)
	{
		char shortest[513];
		char name[128];

		printf("Enter the name of file you want to read:\n");

		if (!scanf("%s", &name))
		{
			printf("\nCould not read file name.");
			exit(1);
		}

		if (Searcher(name, shortest) == 1)
		{
			printf("\nThe shortest word starting with English letter A is: %s\n", shortest);
			
			return 0;
		}

		else
		{
			printf("\nCould not open file.");
			return 1;
		}

	}

	else
	{
		printf("Something went wrong.\n");
		printf("\nAutotest results:\n");

		if (Auto_test1() == 1)
		{
			printf("\nAutotest #1 - passed.\n");
		}

		else
		{
			printf("Autotest #1 - failed.\n");
		}

		if (Auto_test2() == 1)
		{
			printf("Autotest #2 - passed.\n");
		}

		else
		{
			printf("Autotest #2 - failed.\n");
		}

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
























