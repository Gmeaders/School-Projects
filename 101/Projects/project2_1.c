/*Name: Greg Meaders
  Username: gmeader
  Course Number and Section: cpsc 101 section 2
  Date: 2/11/14
  Assignment Number: project 1
  Description: This project is to make a program to ask the user which game they would like to play and then perform the necessary tasks associated with that game.*/

#include <stdio.h>
#include <stdlib.h>

void numberGuessing(int seed);
void rockPaperScissors(int seed);
void randomRectangle(int seed);
int compareNumbers(int target, int input);


int main()
{
	int game;
	game = 0;
	while (game < 1 || game > 5)                      //Put this while loop to make sure the user is entering 1, 2, 3, or 4
	{

	printf("Hello and welcome to my babysitting game. \n");
	printf("Please select your option. Your choices are: \n");                                 //Separated these so they would not pass the 80 character statement limit
	printf("     1)  Play the number guessing game \n     2)  Play Rock-Paper-Scissors \n");
	printf("     3)  Area of a Random Rectangle\n     4)  Find the cookie\n     5) Quit\n");
	scanf("%d", &game);

	}

	int seed;
	printf("\nPlease enter the seed: ");
	scanf("%i", &seed);
	srand(seed);
	
	if (game == 1)
	{
		numberGuessing(seed);
	}

	if (game == 2)
	{
		int player;
		int seed;
		printf("\nPlease enter the seed: ");
		scanf("%i", &seed);
		srand(seed);

		int randomNumber = rand() % 3 + 1;

		printf("Press 1 for Rock, 2 for Paper, and 3 for Scissors \n");
		scanf("%d", &player);

		while (player > 3 || player < 1)
		{

			printf("Please press 1, 2, or 3\n");
			scanf("%d", &player);

		}

		if (player == 1 && randomNumber == 1)
		{

			printf("You played Rock, I played Rock. It is a draw. Now exiting.\n");

		}

		else if (player == 1 && randomNumber == 2)

		{

			printf("You played Rock, I played Paper. I won. Now exiting.\n");

		}

		else if (player == 1 && randomNumber == 3)

		{

			printf("You played Rock, I played Scissors. You won. Now exiting.\n");

		}

		else if (player == 2 && randomNumber == 1)

		{

			printf("You played Paper, I played Rock. You won. Now exiting.\n");

		}

		else if (player == 2 && randomNumber == 2)

		{

			printf("You played Paper, I played Paper. It is a draw. Now exiting.\n");

		}

		else if (player == 2 && randomNumber == 3)

		{

			printf("You played Paper, I played Scissors. I won. Now exiting.\n");

		}

		else if (player == 3 && randomNumber == 1)

		{

			printf("You played Scissors, I played Rock. I won. Now exiting.\n");

		}

		else if (player == 3 && randomNumber == 2)

		{

			printf("You played Scissors, I played Paper. You won. Now exiting.\n");

		}

		else if (player == 3 && randomNumber == 3)

		{

			printf("You played Scissors, I played Scissors. It is a draw. Now exiting.\n");

		}

	}
	
	if (game == 3)
	{

		int seed;
		printf("\nPlease enter the seed: ");
		scanf("%i", &seed);
		srand(seed);

		int height = rand() % 20 + 1;
		int width = rand() % 20 + 1;
		int i;
		int j;
		int area;
		int guess;

		area = height * width;
		printf("Now drawing a rectangle: \n");
		printf("Height = %i\n", height);
		printf("Width = %i\n", width);

		for (i = 1; i <= height; i++)                       // The code for the rectangle was given to us in class on the Functions powerpoint

		{

			for (j = 1; j <= width; j++)

			{

				if (i == 1 || i == height || j == 1 || j == width)

				{

					printf("*");

				}

				else

					printf(" ");

			}

			printf("\n");
		}

		printf("\n\nPlease guess the area of the rectangle: ");
		scanf("%d", &guess);

		while (guess != area)
		{

			printf("Incorrect, Please try again: ");
			scanf("%d", &guess);

		}

		printf("Great job.\nNow exiting.\n");

	}

	if (game == 5)
	{
		printf("Now Exiting.\n");
	}

	return 0;
}

	void numberGuessing(int seed)
	{
		int randomNumber = rand() % 20 + 1;
		int guess;
		printf("Please guess a number between 1 and 20: ");  //I used 20 + 1 here so the number generated would never be 0, and would still stop at 20. I did the same thing
		scanf("%d", &guess);								 //for the other games.
		int i = 0;

		while (guess < 0)
		{

			printf("Please enter a positive number: ");
			scanf("%d", &guess);

		}

		while (guess > 20 || guess == 0)
		{

			printf("Please enter a number that is less than or equal to 20: ");
			scanf("%d", &guess);

		}
		int compared = compareNumbers(randomNumber, guess);

		while (compared != 0){

			if (compared == 1){
				printf("Guess Lower: ");
				scanf("%d", &guess);
				compared = compareNumbers(randomNumber, guess);
				printf("%i", randomNumber);
			}
			else if (compared == -1){
				printf("Guess Higher: ");
				scanf("%d", &guess);
				compared = compareNumbers(randomNumber, guess);
				printf("%i", randomNumber);
			}
			
		}
			printf("Congratulations! You guessed the correct number. Now Exiting.\n");
		
	}

int compareNumbers(int target, int input){

	int compared;
	if (target == input)
		compared = 0;
	else if (target < input)
		compared = 1;
	else 
		compared = -1;

		return compared;
}



























