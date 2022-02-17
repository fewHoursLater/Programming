#include "Header.h"

List* ListCreator(int X_1, int Y_1, int X_2, int Y_2, int X_3, int Y_3)
{
	List* tmp = (List*)malloc(sizeof(List));

	if (!tmp)
	{
		return NULL;
	}


	(tmp->firstVertex).x = X_1;
	(tmp->firstVertex).y = Y_1;

	(tmp->secondVertex).x = X_2;
	(tmp->secondVertex).y = Y_2;

	(tmp->thirdVertex).x = X_3;
	(tmp->thirdVertex).y = Y_3;

	tmp->next = NULL;

	return (tmp);

}


int AddElement(List* head, int X_1, int Y_1, int X_2, int Y_2, int X_3, int Y_3)
{

	List* tmp = (List*)malloc(sizeof(List));

	if (!tmp)
	{
		return -1;
	}

	List* p = head;

	(tmp->firstVertex).x = X_1;
	(tmp->firstVertex).y = Y_1;

	(tmp->secondVertex).x = X_2;
	(tmp->secondVertex).y = Y_2;

	(tmp->thirdVertex).x = X_3;
	(tmp->thirdVertex).y = Y_3;

	tmp->next = NULL;

	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = tmp;

	return 0;
}

List* Remover(List* head)
{

	while (head != NULL)
	{
		List* p = head;

		head = head->next;

		free(p);
	}

	return NULL;
}

int IsIntersection(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4)
{
	int determinant = INT_MIN;
	int determinant_x = INT_MIN;
	int determinant_y = INT_MIN;

	double solution_x;
	double solution_y;

	determinant = (x_4 - x_3) * (y_1 - y_2) - (x_1 - x_2) * (y_4 - y_3);

	if (determinant == 0)
	{

		if (ZeroDeterminant(x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4) == 1)
		{
			return 1;
		}

		return 0;
	}


	determinant_x = (x_1 - x_3) * (y_1 - y_2) - (y_1 - y_3) * (x_1 - x_2);
	determinant_y = (x_4 - x_3) * (y_1 - y_3) - (y_4 - y_3) * (x_1 - x_3);

	solution_x = (double)determinant_x / (double)determinant;
	solution_y = (double)determinant_y / (double)determinant;

	if (solution_x >= 0 && solution_x <= 1 && solution_y >= 0 && solution_y <= 1)
	{
		return 1;
	}

	return 0;

}

int ZeroDeterminant(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4)
{
	
	double t1;
	double t2;
	double t;
	

	t1 = (double)((x_1) - (x_3)) / (double)((x_4) - (x_3));
	t2 = (double)((y_1) - (y_3)) / (double)((y_4) - (y_3));

	if (t1 == t2)
	{
		t = t1;

		if (t >= 0 && t <= 1)
		{
			return 1;
		}
	}

	t1 = (double)((x_2) - (x_3)) / (double)((x_4) - (x_3));
	t2 = (double)((y_2) - (y_3)) / (double)((y_4) - (y_3));

	if (t1 == t2)
	{
		t = t1;

		if (t >= 0 && t <= 1)
		{
			return 1;
		}
	}

	t1 = (double)((x_3) - (x_1)) / (double)((x_2) - (x_1));
	t2 = (double)((y_3) - (y_1)) / (double)((y_2) - (y_1));

	if (t1 == t2)
	{
		t = t1;

		if (t >= 0 && t <= 1)
		{
			return 1;
		}
	}

	t1 = (double)((x_4) - (x_1)) / (double)((x_2) - (x_1));
	t2 = (double)((y_4) - (y_1)) / (double)((y_2) - (y_1));

	if (t1 == t2)
	{
		t = t1;

		if (t >= 0 && t <= 1)
		{
			return 1;
		}
	}

	return 0;

}

int last_chanse_to_have_intersection(int firstx, int firsty, int secondx, int secondy, int thirdx, int thirdy, int x1, int y1, int x2, int y2, int x3, int y3)
{
	
	double first_medium_x;
	double first_medium_y;

	double second_medium_x;
	double second_medium_y;

	int signum1;
	int signum2;
	int signum3;

	first_medium_x = (double)(firstx + secondx + thirdx) /(double)3;
	first_medium_y = (double)(firsty + secondy + thirdy) / (double)3;

	second_medium_x = (double)(x1+x2+x3) / (double)3;
	second_medium_y = (double)(y1+y2+y3) / (double)3;

	signum1 = ((double)x1 - first_medium_x)*((double)y2 - (double)y1) - ((double)x2 - (double)x1)*((double)y1 - first_medium_y);
	signum2 = ((double)x2 - first_medium_x)*((double)y3 - (double)y2) - ((double)x3 - (double)x2)*((double)y2 - first_medium_y);
	signum3 = ((double)x3 - first_medium_x)*((double)y1 - (double)y3) - ((double)x1 - (double)x3)*((double)y3 - first_medium_y);

	if ((signum1 > 0 && signum2 > 0 && signum3 > 0) || (signum1 < 0 && signum2 < 0 && signum3 < 0))
	{
		return 1;
	}

	signum1 = ((double)firstx - second_medium_x) * ((double)secondy - (double)firsty) - ((double)secondx - (double)firstx) * ((double)firsty - second_medium_y);
	signum2 = ((double)secondx - second_medium_x) * ((double)thirdy - (double)secondy) - ((double)thirdx - (double)secondx) * ((double)secondy - second_medium_y);
	signum3 = ((double)thirdx - second_medium_x) * ((double)firsty - (double)thirdy) - ((double)firstx - (double)thirdx) * ((double)thirdy - second_medium_y);

	if ((signum1 > 0 && signum2 > 0 && signum3 > 0) || (signum1 < 0 && signum2 < 0 && signum3 < 0))
	{
		return 1;
	}

	return 0;
}

int global(int firstx, int firsty, int secondx, int secondy, int thirdx, int thirdy, int x1, int y1, int x2, int y2, int x3, int y3)
{

	if (IsIntersection(firstx, firsty, secondx, secondy, x1, y1, x2, y2) == 1)
	{
		return 1;	
	}

	if (IsIntersection(secondx, secondy, thirdx, thirdy, x1, y1, x2, y2) == 1)
	{
		return 1;
	}

	if (IsIntersection(firstx, firsty, thirdx, thirdy, x1, y1, x2, y2) == 1)
	{
		return 1;
	}

	if (IsIntersection(firstx, firsty, secondx, secondy, x2, y2, x3, y3) == 1)
	{
		return 1;
	}

	if (IsIntersection(secondx, secondy, thirdx, thirdy, x2, y2, x3, y3) == 1)
	{
		return 1;
	}
	
	if (IsIntersection(firstx, firsty, thirdx, thirdy, x2, y2, x3, y3) == 1)
	{
		return 1;
	}

	if (IsIntersection(firstx, firsty, secondx, secondy, x1, y1, x3, y3) == 1)
	{
		return 1;
	}
	
	if (IsIntersection(secondx, secondy, thirdx, thirdy, x1, y1, x3, y3) == 1)
	{
		return 1;
	}

	if (IsIntersection(firstx, firsty, thirdx, thirdy, x1, y1, x3, y3) == 1)
	{
		return 1;
	}

	if (last_chanse_to_have_intersection(firstx, firsty, secondx, secondy, thirdx, thirdy, x1, y1, x2, y2, x3, y3) == 1)
	{
		return 1;
	}

	return 0;
}

int isThisTriangle(int x1, int y1, int x2, int y2,int x3, int y3)
{

	int A;
	int B;
	int C;

	A = y1-y3;
	B = x3 - x1;
	C = x1 * y3 - x3 * y1;


	if ((A * x2 + B * y2 + C) == 0)
	{
		return 0;
	}

	return 1;
}