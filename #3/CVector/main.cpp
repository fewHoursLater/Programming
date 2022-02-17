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

			cout << "Начните вводить координаты первого вектора. Когда закончите, введите любой буквенный символ." << endl << endl;

			while (true)
			{
				cout << "Введите " << cnt1 + 1 << " координату вектора:" <<endl;

				cin >> coordinate;

				if (cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');

					if (cnt1 == 0)
					{
						cout <<endl<< "Вы не ввели ни одной координаты. Такой вектор полагается равным 0." << endl;
						cout <<endl<< "Первый вектор имеет размерноть 1." << endl;
						break;
					}

					cout <<endl<< "Получился вектор с размерностью " << cnt1 <<"."<< endl;

					break;
				}

				a[cnt1] = coordinate;

				cnt1++;

				cout << endl;
			}

			cout << endl;

			cout << "Начните вводить координаты второго вектора. Когда закончите, введите любой буквенный символ." << endl<<endl;

			while (true)
			{
				cout << "Введите " << cnt2 + 1 << " координату вектора:" << endl;

				cin >> coordinate;

				if (cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');

					if (cnt2 == 0)
					{
						cout <<endl<< "Вы не ввели ни одной координаты. Такой вектор полагается равным 0." << endl;
						cout <<endl<< "Второй вектор имеет размерность 1." << endl;
						break;
					}

					cout <<endl<< "Второй вектор имеет размерность " << cnt2 <<"."<< endl;

					break;
				}

				b[cnt2] = coordinate;

				cnt2++;
			}

			while (true)
			{
				cout << endl;
				cout << "Что вы хотите сделать?" << endl<<endl;
				cout << "1 - Найти сумму векторов " << endl;
				cout << "2 - Найти разность векторов" << endl;
				cout << "3 - Найти скалярное произведение векторов" << endl;
				cout << "4 - Увеличить размер одного из векторов" << endl;
				cout << "5 - Выйти из программы" << endl;
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
					cout <<endl<< "Какой из векторов вы хотите увеличить? Введите 1 или 2." << endl;

					cin >> answer2;

					if (cin.fail())
					{
						throw - 2;
					}

					if (answer2 == 1)
					{
						cout <<endl<< "Продолжайте вводить координаты первого вектора. Когда закончите, введите любую букву." << endl;

						while (true)
						{
							cout <<endl<< "Введите " << cnt1 + 1 << " координату вектора:" << endl;

							cin >> coordinate;

							if (cin.fail())
							{
								std::cin.clear();
								std::cin.ignore(32767, '\n');
								cout <<endl<< "Новая размерность вектора: " << cnt1 << endl;

								break;
							}

							a[cnt1] = coordinate;

							cnt1++;
						}
					}

					if (answer2 == 2)
					{
						cout <<endl<< "Продолжайте вводить координаты второго вектора. Когда закончите, введите любой буквенный символ." << endl;

						while (true)
						{
							cout <<endl<< "Введите " << cnt2 + 1 << " координату вектора:" << endl;

							cin >> coordinate;

							if (cin.fail())
							{
								std::cin.clear();
								std::cin.ignore(32767, '\n');
								cout <<endl<< "Новая размерность вектора: " << cnt2 << endl;

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
				cout << "Невозможно выполнить операцию с векторами разной размерности.";
				cout << endl;
				return 0;
			}

			if (err == -2)
			{
				cout << endl;
				cout << "Не удалось получить ответ.";
				cout << endl;
				return 0;
			}
		}
	}
	else
	{
		cout << "Что-то пошло не так." << endl;
	}

	return 0;
}

