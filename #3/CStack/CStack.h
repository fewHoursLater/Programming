#pragma once

#include "Header.h"

class CStack
{
public:

	struct SNode
	{
		string value;

		SNode* next;

		SNode()
		{
			next = NULL;
		}


	};

private:

	SNode* head;

	int cnt = 0;

	int size = 0;

public:

	CStack();
	CStack(int);
	~CStack();
	void set_NULL(void);
	void push(string);
	int get_top_lenght(void);
	void del_top(void);
	int get_stack_size(void);
	void save_stack(void);
	int load_stack(void);
	bool is_empty(void);
	bool is_full(void);
	void clean(void);
	void print(void);

};
