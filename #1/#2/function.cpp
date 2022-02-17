#include "Header.h"

int Searcher(const char* filename, char* shortest)
{
	int j = 0;
	int k = 0;
	int minlength = 513;
	int check = -1;
	int pointofenter = 0;

	char bracket = '\"';
	char mainletter = 'A';
	char alphabet[52] = { 'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M' };
	char symbol[1];
	char word[513];
	char shortword[513];

	FILE* stream;

	stream = fopen(filename, "r");

	if (!stream)
	{
		return 0;
	}

	while (fscanf(stream, "%c", &symbol) == 1)
	{

		if (*symbol == bracket)
		{
			pointofenter++;

			if (!fscanf(stream, "%c", &symbol))
			{
				printf("\nFailed to read symbol.");
				fclose(stream);
				exit(1);
			}

			if (*symbol == bracket)
			{
				pointofenter++;
				continue;
			}

			if (*symbol == mainletter)
			{
				check = 1;

				word[0] = *symbol;

				for (int j = 1; j < 513;)
				{

					if (!fscanf(stream, "%c", &symbol))
					{
						printf("\nFailed to read symbol.");
						fclose(stream);
						exit(1);
					}

					for (int y = 0; y < 52; y++)
					{
						if (*symbol == alphabet[y])
						{
							word[j] = *symbol;

						}
					}

					if (*symbol == bracket && j<512)
					{
						word[j] = '\0';
						break;
					}

					if (j == 512 && *symbol != bracket)
					{
						printf("\nToo long word in file.\n");
						fclose(stream);
						exit(1);
					}

					j++;

				}				

				if (strlen(word) < minlength)
				{
					minlength = strlen(word);

					strcpy(shortword, word);

				}

			}

		}

	}

	if (check == -1)
	{
		printf("\nThere are no words in the file that satisfy the condition.\n");
		fclose(stream);
		exit(1);
	}

	strcpy(shortest, shortword);

	fclose(stream);

	return 1;
}