// Yovel Hadad And Yarin Rahamim
//ID 207125329, ID 205833668
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#include <assert.h>

/* Function declarations */
void Ex1();
void Ex2();
void Ex3();


/* Declarations of other functions */
char* hexadecimal_base(char* str);
void createF(char** addresses, int numOfElements);
void createFile(char* input);
char commonestLetter(char* filename);

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 3; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-3 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 4));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;


			}
		} while (all_Ex_in_loop && select);
		return 0;
}

/*.............................*/
void Ex1()
{
	char *newString = hexadecimal_base("abcd2 34fty    78 jurt#A");
	puts(newString);
	free(newString);
}

char* hexadecimal_base(char* str)
{
	int i = 0;
	int j = 0;
	int count = 0;
	char* res = NULL;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F') || str[i] >= '0' && str[i] <= '9')
		{
			count++;
		}
		i++;
	}
	res = (char*)malloc(count * sizeof(char));
	assert(res);
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F') || str[i] >= '0' && str[i] <= '9')
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return &res[0];
}

void Ex2()
{
	char* addresses[] = { "Ben Gurion 32, Tel Aviv",
					   "Bugrashov 8, Rehovot",
						"Sokolov 9, Hedera",
						"Jabotinsky 31, Haifa",
						"Hertzl 14, Netanya" };
	int numOfElements = sizeof(addresses) / sizeof(addresses[0]);
	createF(&addresses, numOfElements);
}

void createF(char** addresses, int numOfElements)
{
	FILE *f = fopen("fileName.txt", "w");
	if (f == NULL)
	{
		printf("Failed opening the file.Exiting\n");
		return;
	}

	int i;
	for (i = 0; i < numOfElements; i++)
	{
		fprintf(f, "%d. ", i + 1);
		fputs(addresses[i], f);
		fputs("\n", f);
	}
	fclose(f);
}

void Ex3()
{
	FILE* input;
	input = fopen("input.txt", "w");
	if (!input) exit(1);
	createFile("input.txt");
	fclose(input);
	printf("The letter with max shows is : %c\n", commonestLetter("input,txt"));
}

void createFile(char* input)
{
	FILE* input1 = fopen("input.txt", "w");
	if (!input) exit(1);
	char c = NULL;
	printf("Enter char:  ***for finish press Enter*** \n");
	c = getchar();
	do
	{
		fprintf(input1, "%c", c);
		rewind(stdin);
	} while (((c = getchar()) != '\n'));
	fclose(input1);
}

char commonestLetter(char* filename)
{
	int ref, flag = 0;
	int i, refIndex;
	char c;
	int alphaBeta[26] = { 0 };
	FILE* read = fopen("input.txt", "r");
	if (!read) exit(1);
	while ((c = fgetc(read)) != EOF)
	{
		if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		{
			flag = 1;
			if ((c <= 'Z' && c >= 'A'))
			{
				alphaBeta[c - 'a' + 32]++;
				continue;
			}
			alphaBeta[c - 'a']++;
		}
	}
	fclose(read);
	if (flag)
	{
		for (i = 0; i < 26; i++)
		{
			if (i == 0)
			{
				ref = alphaBeta[0];
				refIndex = 0;
				continue;
			}
			if (ref < alphaBeta[i])
			{
				ref = alphaBeta[i];
				refIndex = i;
			}
			if (ref == alphaBeta[i])
			{
				ref = alphaBeta[i];
				refIndex = i;
			}
		}
		return (refIndex + 'A');
	}
	return ('0');
}



