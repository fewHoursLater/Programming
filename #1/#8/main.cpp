#include "Header.h"
#include "Autotest.h"

int main()
{
	if (Core_test())
	{
		List* ListPointer = NULL;

		int loop = 1;
		int action = 0;
		int cnt = 0;
		int wayOut = 0;
		int addedElement = INT_MIN;

		int isAlreadyCreated = 0;
		int isAlredyRemoved = 0;
		int isThereValues = 0;

		int X_1 = INT_MIN;
		int Y_1 = INT_MIN;
		int X_2 = INT_MIN;
		int Y_2 = INT_MIN;
		int X_3 = INT_MIN;
		int Y_3 = INT_MIN;


		while (loop)
		{
			printf("Select an action:\n");

			printf("1 - Create list\n");
			printf("2 - Add item to list\n");
			printf("3 - Delete list\n");
			printf("4 - Print list\n");
			printf("5 - Exit the program\n");

			if (!scanf("%d", &action))
			{
				printf("\nTry again.\n");

				return -2;
			}

			if (action == 1 && isAlreadyCreated == 1)
			{
				printf("\nList is alredy created\n\n");
				continue;
			}

			if (action == 1)
			{
				printf("\nEnter coordinates of the first vertex\n");
				printf("X_1: ");

				if (!scanf("%d", &X_1))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				printf("Y_1: ");

				if (!scanf("%d", &Y_1))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				printf("\nEnter coordinates of the second vertex\n");
				printf("X_2: ");

				if (!scanf("%d", &X_2))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				printf("Y_2: ");

				if (!scanf("%d", &Y_2))
				{
					printf("\nRead error.\n");
					return -2;
				}
				printf("\n");

				printf("\nEnter coordinates of the third vertex\n");
				printf("X_3: ");

				if (!scanf("%d", &X_3))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				printf("Y_3: ");

				if (!scanf("%d", &Y_3))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				if (isThisTriangle(X_1,Y_1,X_2,Y_2,X_3,Y_3) == 1)
				{
					ListPointer = ListCreator(X_1, Y_1, X_2, Y_2, X_3, Y_3);

					if (ListPointer == NULL)
					{
						printf("\nMemory error.\n");
						return -1;
					}

					printf("List created and vertex of the triangle has been successfully written.\n\n");

					isAlredyRemoved = 0;
					isAlreadyCreated = 1;
					isThereValues = 1;

					cnt++;

					continue;
				}
				else
				{
					printf("\nThis is not triangle. Failed to create an list.\n\n");
					continue;
				}
				
			}

			if (action == 2 && isAlreadyCreated == 0)
			{
				printf("\nList is not created.\n\n");
				continue;
			}

			if (action == 2)
			{
				printf("\nEnter coordinates of the first vertex\n");
				printf("X_1: ");

				if (!scanf("%d", &X_1))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				printf("Y_1: ");

				if (!scanf("%d", &Y_1))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				printf("\nEnter coordinates of the second vertex\n");
				printf("X_2: ");

				if (!scanf("%d", &X_2))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				printf("Y_2: ");

				if (!scanf("%d", &Y_2))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				printf("\nEnter coordinates of the third vertex\n");
				printf("X_3: ");

				if (!scanf("%d", &X_3))
				{
					printf("\nRead error.\n");
					return -2;
				}

				printf("\n");

				printf("Y_3: ");

				if (!scanf("%d", &Y_3))
				{
					printf("\nRead error.\n");
					return -2;
				}

				if (isThisTriangle(X_1,Y_1,X_2,Y_2,X_3,Y_3) == 1)
				{
					struct Node* temp = ListPointer;

					while (temp != NULL)
					{

						if (global((temp->firstVertex).x, (temp->firstVertex).y, (temp->secondVertex).x, (temp->secondVertex).y, (temp->thirdVertex).x, (temp->thirdVertex).y, X_1, Y_1, X_2, Y_2, X_3, Y_3) == 1)
						{
							printf("\nThis triangle has an intersection with existing.\n\n");
							wayOut = 1;
							break;
						}

						temp = temp->next;
					}

					if (wayOut == 1)
					{
						wayOut = 0;
						continue;
					}

					addedElement = AddElement(ListPointer, X_1, Y_1, X_2, Y_2, X_3, Y_3);

					if (addedElement == -1)
					{
						printf("Memory error");
						return -1;
					}

					cnt++;

					printf("The vertex of the triangle has been successfully written.\n\n");

					continue;
				}

				else
				{
					printf("This is not triangle.\n");
					continue;
				}


				
			}

			if (action == 3 && isAlreadyCreated == 0)
			{
				printf("\nNo list to delete.\n\n");
				continue;
			}

			if (action == 3)
			{
				ListPointer = Remover(ListPointer);

				printf("\nlist removed.\n\n");

				isAlreadyCreated = 0;
				isAlredyRemoved = 1;

				loop = 0;

				continue;
			}

			if (action == 4 && isThereValues == 0)
			{
				printf("\nThere are no vertices or the list has not been created.\n\n");
				continue;
			}

			if (action == 4)
			{
				printf("\n");
				while (ListPointer != NULL)
				{
					printf("{ ( %d , %d ) , ( %d , %d ) , ( %d , %d ) }\n", ListPointer->firstVertex.x, ListPointer->firstVertex.y, ListPointer->secondVertex.x, ListPointer->secondVertex.y, ListPointer->thirdVertex.x, ListPointer->thirdVertex.y);

					ListPointer = ListPointer->next;
				}

				loop = 0;
			}

			if (action == 5)
			{
				loop = 0;
				continue;
			}
		}

		printf("\nNumber of disjoint triangles: %d\n", cnt);

		return cnt;
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




