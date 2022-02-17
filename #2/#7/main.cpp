#include "Header.h"
#include "Autotest.h"



int main()
{
	if (Core_test())
	{
		int Res;
		char name[32];

		printf("Enter the name of the file you want to scan:\n");

		if (!scanf("%s", &name))
		{
			printf("\nFailed to read file name.\n");
		}

		Res = FFF(name,1);

		if (Res == -1)	
		{
			printf("\nError in working with files.\n");
			return -1;
		}

		if (Res == -2)
		{
			printf("\nMemory error.\n");
			return -2;
		}

		if (Res == -3)
		{
			printf("\nError in working with reading elements.\n");
			return -3;
		}

		if (Res == -4)
		{
			printf("\nThere are two people in the list with the same name.\n");
			return -4;
		}

		if (Res == -5)
		{
			printf("\nRatings are incorrect.\n");
			return -5;
		}

		if (Res == -6)
		{
			printf("\nGroup numbers are incorrect.\n");
			return -6;
		}

		if (Res == -7)
		{
			printf("\nFile is empty.\n");
			return -7;
		}

		printf("\nNew elders appointed: %d\n", Res);
		printf("\nYou can find the result in the file Res.Data.txt\n");

		return Res;
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





