#include "defs.h"
#include "guessing.c"
#include "rockPaperScissors.c"
#include "rectangle.c"
#include "findTheCookie.c"
#include "checkers.c"


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

	

	if (game == 1)
	{
		int seed;
		printf("\nPlease enter the seed: ");
		scanf("%i", &seed);
		srand(seed);
		numberGuessing(seed);
	}

	if (game == 2)
	{
		int seed;
		printf("\nPlease enter the seed: ");
		scanf("%i", &seed);
		srand(seed);
		rockPaperScissors(seed);
	}
	if (game == 3)
	{
		int seed;
		printf("\nPlease enter the seed: ");
		scanf("%i", &seed);
		srand(seed);
		randomRectangle(seed);
	}
	if (game == 4)
	{
		findTheCookie();
	}

	if (game == 5)
	{
		printf("Now Exiting.\n");
	}

	return 0;
}

