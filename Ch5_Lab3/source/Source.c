#include <stdio.h>
#include <stdlib.h>
#define issues 5
#define ratings 10

void recordResponse(int i, int response);
void highestRatings();
void lowestRatings();
float averageRating(int issue);
void displayResults();

int responses[issues][ratings];
const char *topics[issues] = { "Global Warming","The Economy", "War", "Health Care","Education" };
int main()
{
	int i, response;


		do
		{
			printf("Please rate the following topics on a scale form 1 - 10"
					"\n 1 = least important, 10 = most important\n");
			for (i = 0; i < issues; i++)
			{
				do
				{
					printf("%s", topics[i]);
					printf("? ");
					scanf_s("%d", &response);
				} while (response < 1 || response>10);

				recordResponse(i, response);
			}
			printf("Enter 1 to stop. Enter 0 to rate the issues again. ");
			scanf_s("%d", &response);
		} while (response !=1);

		
		displayResults();

	system("pause");
	return 0;
}

void recordResponse(int issue, int rating)
{
	responses[issue][rating - 1]++;
}

void highestRatings()
{
	int i, j, highRating = 0, highTopic = 0;

	for (i = 0; i <issues; i++)
	{
		int topicRating = 0;

		for (j = 0; j < ratings; j++)
			topicRating = topicRating + responses[i][j] * (j + 1);

		if (highRating< topicRating)
		{
			highRating = topicRating;
			highTopic = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s",topics[highTopic]);
	printf(" with a total rating of %d\n", highRating);
}

void lowestRatings()
{
	int i, j, lowRating = 0, lowTopic = 0;
	for (i = 0; i < issues; i++)
	{
		int topicRating = 0;

		for (j = 0; j < ratings; j++)
			topicRating = topicRating + responses[i][j] * (j + 1);

		if (i == 0)
			lowRating = topicRating;

		if (lowRating > topicRating)
		{
			lowRating = topicRating;
			lowTopic = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", topics[lowTopic]);
	printf(" with a total rating of %d\n", lowRating);
}

float averageRating(int issue)
{
	float total = 0;
	int counter = 0, j;

	for (j = 0; j < ratings; j++)
	{
		if (responses[issue][j] != 0)
		{
			total = total + responses[issue][j] * (j + 1);
			counter = counter + responses[issue][j];
		}
	}
	return total / counter;
}

void displayResults()
{
	int i, j;
	printf("%20s\n", "Topic");

	for (i = 1; i <= ratings; i++)
		printf("%4d", i);

	printf("%20s\n", "Average Rating");

	for (i = 0; i < issues; i++)
	{
		printf("%20s\n", topics[i]);
		
		for(j=0;j<ratings;j++)
			printf("%4d", responses[i][j]);

		printf("%20.2f\n", averageRating(i));
	
	}
	highestRatings();
	lowestRatings();

}