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

		cout << "Что Вы хотите сделать?" << endl;

		cout << "1 - Создать пустой стек" << endl;
		cout << "2 - Добавить строку" << endl;
		cout << "3 - Получить длину строки на вершине стека" << endl;
		cout << "4 - Удалить вершину стека" << endl;
		cout << "5 - Получить общее количество строк в стеке" << endl;
		cout << "6 - Очистить стек" << endl;
		cout << "7 - Сохранить состояние стека в файле" << endl;
		cout << "8 - Загрузить из стека записей" << endl;
		cout << "9 - Завершить работу" << endl;

		cin >> answer;

		if (answer == 1)
		{
			is_already_created = 1;


			cout << endl << "Введите размер стека:" << endl;
			cin >> size;
			CStack CST(size);
			cout << endl<< "Стек из "<<size<<" элементов создан." << endl;

			while (true)
			{
				cout <<endl<< "2 - Добавить строку" << endl;
				cout << "3 - Получить длину строки на вершине стека" << endl;
				cout << "4 - Удалить вершину стека" << endl;
				cout << "5 - Получить общее количество строк в стеке" << endl;
				cout << "6 - Очистить стек" << endl;
				cout << "7 - Сохранить состояние стека в файле" << endl;
				cout << "8 - Загрузить из стека записей" << endl;
				cout << "9 - Вывести стек на экран" << endl;
				cout << "10 - Завершить работу" << endl;
				cin >> answer;

				if (answer == 2)
				{
					if (CST.is_full())
					{
						cout <<endl<< "Стек заполнен. Сохраните его сначала." << endl;

						continue;
					}

					cout <<endl<< "Введите строку:" << endl;

					cin >> incoming_word;

					CST.push(incoming_word);

					cout <<endl<< "Строка добавлена." << endl;
				}

				if (answer == 3)
				{
					if (CST.is_empty())
					{
						cout <<endl<< "Стек пуст." << endl;
					}
					else
					{
						cout <<endl<< "Длина вершины - " << CST.get_top_lenght() << endl;
					}
				}

				if (answer == 4)
				{
					if (CST.is_empty())
					{
						cout <<endl<< "Стек пуст." << endl;
					}
					else
					{
						CST.del_top();

						cout <<endl<< "Вершина удалена." << endl;
					}
				}

				if (answer == 5)
				{
					if (CST.is_empty())
					{
						cout <<endl<< "Стек пуст." << endl;
					}
					else
					{
						cout <<endl<< "Всего элементов - " << CST.get_stack_size() << endl;
					}
				}

				if (answer == 6)
				{
					CST.clean();

					cout <<endl<< "Очищено." << endl;
				}

				if (answer == 7)
				{
					if (!CST.is_empty())
					{
						CST.save_stack();
						CST.clean();

						cout <<endl<< "Состояние стека записано в блок и стек очищен." << endl;
					}
					else
					{
						cout <<endl<< "Стек пуст." << endl;
					}
				}

				if (answer == 8)
				{
					if (CST.is_empty())
					{
						if (CST.load_stack() == 0)
						{
							cout <<endl<< "Блок записей пуст. Добавьте какие-то данные." << endl;
						}
						else
						{
							cout <<endl<< "Загружено из блока записей." << endl;
						}
					}
					else
					{
						cout <<endl<< "В стеке хранятся данные, сохраните их сначала." << endl;
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
		cout << "Что-то пошло не так." << endl;

		return 0;
	}

}