#include "Header.h"
#include "CStack.h"

int main()
{

	if (test())
	{
		setlocale(LC_ALL, "Russian");

		int answer = 0;
		int is_already_created = 0;
		int size = 0;
		string incoming_word;

		cout << "��� �� ������ �������?" << endl;

		cout << "1 - ������� ������ ����" << endl;
		cout << "2 - �������� ������" << endl;
		cout << "3 - �������� ����� ������ �� ������� �����" << endl;
		cout << "4 - ������� ������� �����" << endl;
		cout << "5 - �������� ����� ���������� ����� � �����" << endl;
		cout << "6 - �������� ����" << endl;
		cout << "7 - ��������� ��������� ����� � �����" << endl;
		cout << "8 - ��������� �� ����� �������" << endl;
		cout << "9 - ��������� ������" << endl;

		cin >> answer;

		if (answer == 1)
		{
			is_already_created = 1;


			cout << endl << "������� ������ �����:" << endl;
			cin >> size;
			CStack CST(size);
			cout << endl<< "���� �� "<<size<<" ��������� ������." << endl;

			while (true)
			{
				cout <<endl<< "2 - �������� ������" << endl;
				cout << "3 - �������� ����� ������ �� ������� �����" << endl;
				cout << "4 - ������� ������� �����" << endl;
				cout << "5 - �������� ����� ���������� ����� � �����" << endl;
				cout << "6 - �������� ����" << endl;
				cout << "7 - ��������� ��������� ����� � �����" << endl;
				cout << "8 - ��������� �� ����� �������" << endl;
				cout << "9 - ������� ���� �� �����" << endl;
				cout << "10 - ��������� ������" << endl;
				cin >> answer;

				if (answer == 2)
				{
					if (CST.is_full())
					{
						cout <<endl<< "���� ��������. ��������� ��� �������." << endl;

						continue;
					}

					cout <<endl<< "������� ������:" << endl;

					cin >> incoming_word;

					CST.push(incoming_word);

					cout <<endl<< "������ ���������." << endl;
				}

				if (answer == 3)
				{
					if (CST.is_empty())
					{
						cout <<endl<< "���� ����." << endl;
					}
					else
					{
						cout <<endl<< "����� ������� - " << CST.get_top_lenght() << endl;
					}
				}

				if (answer == 4)
				{
					if (CST.is_empty())
					{
						cout <<endl<< "���� ����." << endl;
					}
					else
					{
						CST.del_top();

						cout <<endl<< "������� �������." << endl;
					}
				}

				if (answer == 5)
				{
					if (CST.is_empty())
					{
						cout <<endl<< "���� ����." << endl;
					}
					else
					{
						cout <<endl<< "����� ��������� - " << CST.get_stack_size() << endl;
					}
				}

				if (answer == 6)
				{
					CST.clean();

					cout <<endl<< "�������." << endl;
				}

				if (answer == 7)
				{
					if (!CST.is_empty())
					{
						CST.save_stack();
						CST.clean();

						cout <<endl<< "��������� ����� �������� � ���� � ���� ������." << endl;
					}
					else
					{
						cout <<endl<< "���� ����." << endl;
					}
				}

				if (answer == 8)
				{
					if (CST.is_empty())
					{
						if (CST.load_stack() == 0)
						{
							cout <<endl<< "���� ������� ����. �������� �����-�� ������." << endl;
						}
						else
						{
							cout <<endl<< "��������� �� ����� �������." << endl;
						}
					}
					else
					{
						cout <<endl<< "� ����� �������� ������, ��������� �� �������." << endl;
					}
				}

				if (answer == 9)
				{
					CST.print();
				}

				if (answer == 10)
				{
					CST.clean();
					return 1;
				}
			}
		}

		return 1;
	}
	else
	{
		cout << "���-�� ����� �� ���." << endl;

		return 0;
	}

}