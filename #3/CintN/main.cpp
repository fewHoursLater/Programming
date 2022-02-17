#include "Header.hpp"

int main()
{
	if (test())
	{
		int answer = 0;

		while (true)
		{
			cout << "1 - Info" << endl << "2 - Find the sum of numbers" << endl << "3 - Find the difference of numbers" << endl << "4 - Exit" << endl << endl;
			cin >> answer;

			if (cin.fail())
			{
				cout << endl;
				cout << "This answer is not provided. Try again." << endl << endl;
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				continue;
			}

			if (answer == 1)
			{
				cout << endl;
				cout << "The capacity of the system is " << N << "." << endl;
				cout << endl;
				continue;
			}

			if (answer == 2)
			{
				int first = -1;
				int second = -1;
				int progKey = 0;
				bool loop = true;
				bool loop2 = true;

				while (loop)
				{
					cout <<endl<< "Enter the first number:" << endl;
					cin >> first;

					if (cin.fail())
					{
						cout << endl;
						cout << "It seems you entered the wrong value. Try again." << endl;
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}

					loop = false;
				}

				while (loop2)
				{
					cout << endl<<"Enter the second number:" << endl;
					cin >> second;

					if (cin.fail())
					{
						cout << endl;
						cout << "It seems you entered the wrong value. Try again" << endl;
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}

					loop2 = false;
				}

				progKey = summ_function(first, second, 1);

				if (progKey == 1)
				{
					cout << endl << "Wrong number power. Try again." << endl << endl;
					continue;
				}

				if (progKey == 2)
				{
					continue;
				}

				if (progKey == 3)
				{
					cout << endl<< "The result is out of bounds. Try again." << endl << endl;
					continue;
				}
			}

			if (answer == 3)
			{
				int first = -1;
				int second = -1;
				int progKey = 0;

				bool loop = true;
				bool loop2 = true;

				while (loop)
				{
					cout << endl<<"Enter the first number:" << endl;
					cin >> first;

					if (cin.fail())
					{
						cout << endl;
						cout << "It seems you entered the wrong value. Try again" << endl;
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}

					loop = false;
				}

				while (loop2)
				{
					cout << "Enter the second number" << endl;
					cin >> second;

					if (cin.fail())
					{
						cout << endl;
						cout << "It seems you entered the wrong value. Try again" << endl;
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}

					loop2 = false;
				}

				progKey = subtract_function(first, second, 1);

				if(progKey ==1)
				{
					cout << endl << "Wrong number power. Try again." << endl << endl;
					continue;
				}

				if (progKey == 2)
				{
					cout << endl<<"The first number must not be less than the second." <<endl<< endl;
					continue;
				}

				if (progKey == 3)
				{
					continue;
				}

				if (progKey == 4)
				{
					cout << endl<<"The result is out of bounds. Try again." << endl<< endl;
					continue;
				}
			}

			if (answer == 4)
			{
				exit(1);
			}

			cout << endl<<"This answer is not provided. Try again."<<endl<<endl;
		}

		return 1;
	}
	
	else
	{
		cout << "Something went wrong." << endl;
		return 0;
	}
}

