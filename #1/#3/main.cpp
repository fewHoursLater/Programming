#include "Header.h"
#include "Autotests.h"

int main(void)
{
	if (Core_test())
	{
		int final_length = 0;

		char name[32];

		printf("Notice:\n\nThere must be no spaces at the end of each line. The last element must be a number.");
		printf("\nThe next situation is not allowed: 5454 5454 5454_\n\n");
		printf("Enter the name of file you want to read:");

		if (!scanf("%s", &name))
		{
			printf("Failed to read file name");
			exit(1);
		}

		final_length = FFF(name, 1);

		return final_length;
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

		return -1;

	}

}