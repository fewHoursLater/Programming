#include "Header.h"
#include "CVector.h"

int main(void)
{
	setlocale(LC_ALL, "Russian");

	if (test() == 1)
	{
		try
		{
			int answer = 0;
			int answer2 = 0;

			double coordinate;

			int cnt1 = 0;
			int cnt2 = 0;

			CVector a, b;

			cout << "������� ������� ���������� ������� �������. ����� ���������, ������� ����� ��������� ������." << endl << endl;

			while (true)
			{
				cout << "������� " << cnt1 + 1 << " ���������� �������:" <<endl;

				cin >> coordinate;

				if (cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');

					if (cnt1 == 0)
					{
						cout <<endl<< "�� �� ����� �� ����� ����������. ����� ������ ���������� ������ 0." << endl;
						cout <<endl<< "������ ������ ����� ���������� 1." << endl;
						break;
					}

					cout <<endl<< "��������� ������ � ������������ " << cnt1 <<"."<< endl;

					break;
				}

				a[cnt1] = coordinate;

				cnt1++;

				cout << endl;
			}

			cout << endl;

			cout << "������� ������� ���������� ������� �������. ����� ���������, ������� ����� ��������� ������." << endl<<endl;

			while (true)
			{
				cout << "������� " << cnt2 + 1 << " ���������� �������:" << endl;

				cin >> coordinate;

				if (cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');

					if (cnt2 == 0)
					{
						cout <<endl<< "�� �� ����� �� ����� ����������. ����� ������ ���������� ������ 0." << endl;
						cout <<endl<< "������ ������ ����� ����������� 1." << endl;
						break;
					}

					cout <<endl<< "������ ������ ����� ����������� " << cnt2 <<"."<< endl;

					break;
				}

				b[cnt2] = coordinate;

				cnt2++;
			}

			while (true)
			{
				cout << endl;
				cout << "��� �� ������ �������?" << endl<<endl;
				cout << "1 - ����� ����� �������� " << endl;
				cout << "2 - ����� �������� ��������" << endl;
				cout << "3 - ����� ��������� ������������ ��������" << endl;
				cout << "4 - ��������� ������ ������ �� ��������" << endl;
				cout << "5 - ����� �� ���������" << endl;
				cout << endl;

				cin >> answer;

				if (cin.fail())
				{
					throw - 2;
				}

				if (answer == 1)
				{
					CVector c = a + b;
					cout << endl;
					c.print();
					cout << endl;
					break;
				}

				if (answer == 2)
				{
					CVector c = a - b;
					cout << endl;
					c.print();
					cout << endl;
					break;
				}

				if (answer == 3)
				{
					double c = a * b;
					cout << endl;
					cout << c;
					cout << endl;
					break;
				}

				if (answer == 4)
				{
					cout <<endl<< "����� �� �������� �� ������ ���������? ������� 1 ��� 2." << endl;

					cin >> answer2;

					if (cin.fail())
					{
						throw - 2;
					}

					if (answer2 == 1)
					{
						cout <<endl<< "����������� ������� ���������� ������� �������. ����� ���������, ������� ����� �����." << endl;

						while (true)
						{
							cout <<endl<< "������� " << cnt1 + 1 << " ���������� �������:" << endl;

							cin >> coordinate;

							if (cin.fail())
							{
								std::cin.clear();
								std::cin.ignore(32767, '\n');
								cout <<endl<< "����� ����������� �������: " << cnt1 << endl;

								break;
							}

							a[cnt1] = coordinate;

							cnt1++;
						}
					}

					if (answer2 == 2)
					{
						cout <<endl<< "����������� ������� ���������� ������� �������. ����� ���������, ������� ����� ��������� ������." << endl;

						while (true)
						{
							cout <<endl<< "������� " << cnt2 + 1 << " ���������� �������:" << endl;

							cin >> coordinate;

							if (cin.fail())
							{
								std::cin.clear();
								std::cin.ignore(32767, '\n');
								cout <<endl<< "����� ����������� �������: " << cnt2 << endl;

								break;
							}

							b[cnt2] = coordinate;

							cnt2++;
						}
					}
				}

				if (answer == 5)
				{
					break;
				}
			}

			return 1;
		}
		catch (int err)
		{
			if (err == -1)
			{
				cout << endl;
				cout << "���������� ��������� �������� � ��������� ������ �����������.";
				cout << endl;
				return 0;
			}

			if (err == -2)
			{
				cout << endl;
				cout << "�� ������� �������� �����.";
				cout << endl;
				return 0;
			}
		}
	}
	else
	{
		cout << "���-�� ����� �� ���." << endl;
	}

	return 0;
}

