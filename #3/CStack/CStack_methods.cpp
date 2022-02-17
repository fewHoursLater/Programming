#include "Header.h"
#include "CStack.h"

CStack::CStack()
{
	
}

CStack::CStack(int size)
{

	this->size = size;

	ofstream fout;
	fout.open("buffer.txt");
	fout.close();

	head = new SNode;

	SNode* p = head;

	for (int a = 0; a < this->size; a++)
	{
		SNode* S;

		S = new SNode;

		p->next = S;

		p = S;
	}

	p->next = NULL;

	set_NULL();
}

CStack::~CStack()
{
	clean();
}

void CStack::set_NULL(void)
{
	SNode* q;

	q = this->head;

	for (int j = 0; j < this->size; j++)
	{
		q = q->next;

		q->value.clear();
	}
}

void CStack::push(string inc)
{
	this->cnt++;

	SNode* t = head;

	for (int j = 0; j < this->cnt; j++)
	{
		t = t->next;
	}

	if (this->cnt <= this->size)
	{
		t->value = inc;
	}
}

int CStack::get_top_lenght(void)
{
	SNode* p;

	p = head;

	for (int j = 0; j < cnt; j++)
	{
		p = p->next;
	}

	return p->value.size();
}

void CStack::del_top(void)
{
	SNode* p;

	p = head;

	for (int j = 0; j < cnt; j++)
	{
		p = p->next;
	}

	p->value.clear();

	cnt = cnt - 1;
}

int CStack::get_stack_size(void)
{
	return cnt;
}


void CStack::save_stack(void)
{
	ofstream buff;
	buff.open("buffer.txt", ios_base::app);

	SNode* q = head;

	int tmp = cnt;

	
		for (int j = 0; j < tmp; j++)
		{
			q = q->next;

			if (!q->value.empty())
			{
				buff << q->value << endl;
				
			}
		}

	buff.close();
}

int CStack::load_stack(void)
{
	int counter = 0;
	int temp;
	int temp2;
	int A_counter = 0; 

	string line;

	fstream in;
	fstream out;

	SNode* k = head;

	in.open("buffer.txt", ios_base::in);

	while (getline(in, line))
	{
		counter++;
	}

	in.close();

	if (counter == 0)
	{
		return 0;
	}

	if (counter>=this->size)
	{
		temp = counter;

		temp2 = this->size;

		for (int a = 0; a < this->size; a++)
		{
			in.open("buffer.txt", ios_base::in);

			if (temp > 0)
			{
				for (int jd = 0; jd < temp2; jd++)
				{
					k = k->next;
		
				}
				
				for (int b = 0; b < temp; b++)
				{
					if (getline(in, line))
					{
						continue;
					}
				}

				temp--;
				temp2--;

				k->value = line;
				k = head;
				A_counter++;
				
			}
			else
			{
				break;
			}

			in.close();
		}

		if (counter - A_counter == 0)
		{
			ofstream buff;

			buff.open("buffer.txt");
			buff.close();

			this->cnt = A_counter;

			return 1;
		}

		in.open("buffer.txt", ios_base::in);

		out.open("mirror.txt", ios_base::out);

		for (int c = 0; c < (counter - A_counter); c++)
		{
			if (!getline(in, line))
			{
				break;
			}

			out << line << endl;
		}

		out.close();
		in.close();

		ofstream finalF;

		finalF.open("buffer.txt", ios_base::out);

		out.open("mirror.txt", ios_base::in);

		while (getline(out, line))
		{
			finalF << line << endl;
		}

		finalF.close();
		out.close();

		this->cnt = A_counter;

		return 1;
	}

	if (counter < this->size)
	{
		in.open("buffer.txt", ios_base::in);

		for (int d = 0; d < counter; d++)
		{
			k = k->next;

			if (!getline(in, line))
			{
				return 0;
			}

			k->value = line;
			A_counter++;
		}

		in.close();

		ofstream buff2;

		buff2.open("buffer.txt");
		buff2.close();

		this->cnt = A_counter;

		return 1;
	}
}

bool CStack::is_empty(void)
{
	if (cnt == 0)
	{
		return true;
	}

	return false;
}

bool CStack::is_full(void)
{
	if (cnt == this->size)
	{
		return true;
	}

	return false;
}

void CStack::clean(void)
{
	SNode* p;

	p = head;

	for (int j = 0; j < this->size; j++)
	{
		p = p->next;
		p->value.clear();
	}

	cnt = 0;
}

void CStack::print(void)
{
	SNode* L;
	L = head;

	for (int b = 0; b < cnt; b++)
	{
		L = L->next;
		cout << L->value <<" ";

	}
	cout << endl;

}