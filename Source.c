#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define rows 20
#define symbols 129
#define words 5

char enLetters[] = "AaBbCcDdEeFfGgHhLIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
char* rawArray[rows][symbols];
int wordCount = 0;


int main()
{
	input();
	output();
	swapFirstAndSecondWords();

	return 0;
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

						if (wordCount == words)
						{
							printf("\n");
							break;
						}
					}
				}
			}
			else if (c == 27 && wordCount >= 2)
			{
				return 0;
			}
			else if (c == 13 && wordCount >= 2)
			{
				printf("\n");
				break;
			}
			else
			{

			}
		}
	}
}

int wordCheck(int i, int j)
{
	for (j; j >= 0; j--)
	{
		if (rawArray[i][j] == ' ')
		{
			return 1;
		}
		else
		{
			if (strchr(enLetters, rawArray[i][j]) != NULL)
			{
				return 0;
			}
		}
	}
}

int output(void)
{
	printf("\n\n");
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
			printf("\n");
			return 0;
		}

		printf("\n");
	}
}

int swapFirstAndSecondWords(void)
{
	
}
