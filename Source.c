#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define rows 20
#define symbols 129
#define words 5

char enLetters[] = "AaBbCcDdEeFfGgHhLIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
char* rawArray[rows][symbols];
char* cookedArray[rows][symbols];
char firstWord[64];
char secondWord[64];
int wordCount = 0;

int main()
{
	input();
	output();
	swapFirstAndSecondWords();
}

int input(void)
{
	char c;

	for (int i = 0; i < rows; i++)
	{
		wordCount = 0;

		for (int j = 0; j < symbols; j++)
		{
			c = getch();

			if (c != 13 && c != 27)
			{
				rawArray[i][j] = c;
				fprintf(stdout, "%c", c);

				if (j != 0)
				{
					if (wordCheck(i, j - 1) == 0 && rawArray[i][j] == ' ')
					{
						wordCount += 1;

						/*
						if (wordCount <= 1)
						{
							//firstWord[j] == c;
							putIn(i, j, firstWord);
						}
						*/

						if (wordCount == words)
						{
							printf("\n");
							break;
						}
					}
				}
			}
			else if (c == 13 && wordCount >= 2)
			{
				printf("\n");
				break;
			}
			else if (c == 27 && wordCount >= 2)
			{
				return 0;
			}
			else
			{
				//nothing
			}
		}
	}
}

int wordCheck(int i, int j)
{
	int isWord = 0;

	for (j; j >= 0; j--)
	{
		if (rawArray[i][j] != ' ')
		{
			for (int k = 0; k < strlen(enLetters); k++)
			{
				if (rawArray[i][j] == enLetters[k])
				{
					isWord = 1;
				}
			}
		}
		else
		{
			break;
		}
	}

	if (isWord != 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int output(void)
{
	printf("\n\nOriginal text:\n");
	for (int i = 0; i < rows; i++)
	{
		if (rawArray[i][0] != '\0')
		{
			for (int j = 0; j < symbols; j++)
			{
				printf("%c", rawArray[i][j]);
			}
		}
		else
		{
			break;
		}

		printf("\n");
	}
}

//
int putIn(int i, int j, char charArray[64]) //
{
	int isWord = 0;

	for (j; j >= 0; j--)
	{
		if (rawArray[i][j] != ' ')
		{
			for (int k = 0; k < strlen(enLetters); k++)
			{
				if (rawArray[i][j] == enLetters[k])
				{
					isWord = 1;
				}
			}
		}
		else
		{
			break;
		}
	}

	if (isWord != 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int swapFirstAndSecondWords(void)
{
	
}
