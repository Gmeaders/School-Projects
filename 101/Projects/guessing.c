#include "defs.h"
#include "project3.c"


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
			}
			else if (compared == -1){
				printf("Guess Higher: ");
				scanf("%d", &guess);
				compared = compareNumbers(randomNumber, guess);
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
