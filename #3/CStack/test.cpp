#include "Header.h"
#include "CStack.h"

int test(void)
{
	CStack test_s(8);

	test_s.push(string("1"));
	test_s.push(string("2"));
	test_s.push(string("3"));
	test_s.push(string("4"));
	test_s.push(string("5"));
	test_s.push(string("6"));
	test_s.push(string("7"));
	test_s.push(string("888"));

	if (test_s.get_stack_size() != 8)
	{
		return 0;
	}

	if (test_s.get_top_lenght() != 3)
	{
		return 0;
	}

	if (test_s.is_empty())
	{
		return 0;
	}

	if (!test_s.is_full())
	{
		return 0;
	}

	test_s.del_top();

	if (test_s.get_stack_size() != 7)
	{
		return 0;
	}

	if (test_s.get_top_lenght() != 1)
	{
		return 0;
	}

	test_s.clean();

	if (test_s.get_stack_size() != 0)
	{
		return 0;
	}

	return 1;
}