#include <stdio.h>
#include <stdlib.h>
#define students 3
#define exams 4

void mini(int grades[][exams], int pupils, int tests);
void maxi(int grades[][exams], int pupils, int tests);
void average(int grades[][exams], int pupils, int tests);
void printArray(int grades[][exams], int pupils, int tests);
void printMenu();

int main()
{
	void(*processGreades[4])(int[][exams], int, int)
		= { printArray,mini,maxi,average };
	int choice = 0;

	int studentGreades[students][exams] = { {77,68,86,73},
											{96,87,89,78},
										    {70,90,86,81} };
	
	while (choice!=4)
	{
		do
		{
			printMenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

				if (choice != 4)
					(*processGreades[choice])(studentGreades, students, exams);
				else
					printf("Program Ended.\n");

	}

	system("pause");
	return 0;
}

void mini(int grades[][exams], int pupils, int tests)
{
	int i,j,lowGreade = 100;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grades[i][j] < lowGreade)
				lowGreade = grades[i][j];
		}
	}
	printf("\n\tThe lowest greade is %d\n", lowGreade);
}
void maxi(int grades[][exams], int pupils, int tests)
{
	int i, j, highGreade = 0;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grades[i][j] > highGreade)
				highGreade = grades[i][j];
		}
	}
	printf("\n\tThe highest greade is %d\n", highGreade);
}

void average(int grades[][exams], int pupils, int tests)
{
	int i, j, total;
	puts("\n");
	for (i = 0; i <= pupils - 1; i++)
	{
		total = 0;
		for (j = 0; j <= tests - 1; j++)
		total=total+ grades[i][j];

		printf("\tThe average for student %d is %.1f\n",i+1,(double)total/tests);
	}
	
}

void printArray(int grades[][exams], int pupils, int tests)
{
	int i, j;
	printf("\n\t                 [0]	[1]    [2]    [3]");
	for (i = 0; i <= pupils - 1; i++)
	{
		printf("\n\tstudentGreades[%d]", i);
		for (j = 0; j <= tests - 1; j++)
			printf("%-7d", grades[i][j]);

	}
	puts("\n");
}

void printMenu()
{
	printf("\n\tEnter a choice:\n"
		"\t 0 print the array of grades\n"
		"\t 1 find the minimum grades\n"
		"\t 2 find the maximum grades\n"
		"\t 3 print the average on all tests for each student\n"
		"\t 4 End program\n"
		"\t?");
}