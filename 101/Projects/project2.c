/*Name: Greg Meaders
  Username: gmeader
  Course Number and Section: cpsc 101 section 2
  Date: 3/5/14
  Assignment Number: project 2
  Description: This project is to make a program to ask the user which game they would like to play and then perform the necessary tasks associated with that game.*/

#include <stdio.h>
#include <stdlib.h>

void numberGuessing(int seed);
void rockPaperScissors(int seed);
void randomRectangle(int seed);
void findTheCookie();
void initializeMap(char map[10][10], int cookieLoc[1][2],
	int monsterLoc[1][2], int robotLoc[1][2]);
void drawMap(char map[10][10], int robotLoc[1][2]);
int userMove(char map[10][10], char move, int robotLoc[1][2],
	int cookieLoc[1][2], int monsterLoc[1][2]);
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

void rockPaperScissors(int seed){

	int player;
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

void randomRectangle(int seed){

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

	int compared = compareNumbers(area, guess);
	while (compared != 0)
	{

		printf("Incorrect, Please try again: ");
		scanf("%d", &guess);
		compared = compareNumbers(area, guess);

	}

	printf("Great job.\nNow exiting.\n");


}

void findTheCookie(){

	int go;							//This function startrs the cookie game and calls the other functions.
	char map[10][10];				//at the end it gets a return from userMove and sets it to check, and then 
	int cookieLoc[1][2];			//prints the answer if the returned number is 1 or -1.
	int monsterLoc[1][2];
	int robotLoc[1][2];
	char move;

	initializeMap(map, cookieLoc, monsterLoc, robotLoc);

	int check = userMove(map, move, robotLoc, cookieLoc, monsterLoc);

	if (check == 1)
		printf("Congratulations!! You found the Cookie! Now exiting. \n");
	else if (check == -1)
		printf("Oh no!! The cookie monster got you! Now exiting. \n");

}

void initializeMap(char map[10][10], int cookieLoc[1][2],
	int monsterLoc[1][2], int robotLoc[1][2]) {
	int x, y, a, b;
	robotLoc[0][0] = 0;                                                    //This function will first set up the monster robot and cookie locations
	robotLoc[0][1] = 0;													   //and then call drawMap for the first time.
	printf("Please enter the X and Y coordinates of the cookie: ");
	scanf("%d %d", &x, &y);
	printf("\nPlease enter the X and Y coordinates of the monster: ");
	scanf("%d %d", &a, &b);

	monsterLoc[0][0] = a;
	monsterLoc[0][1] = b;

	monsterLoc[0][0]--;
	monsterLoc[0][1]--;

	cookieLoc[0][0] = x;	
	cookieLoc[0][1] = y;
									//The -- after the cookieLocs and MonsterLocs are to move it on the map back one,	
	cookieLoc[0][0]--;				//so if you put 1 1 it would appear at 0 0 on the array. Just so things line up because
	cookieLoc[0][1]--;				//the array is 0-9

	drawMap(map, robotLoc);

}

void drawMap(char map[10][10], int robotLoc[1][2]){

	int row, col;
	
	printf("\nNow drawing map \n");

	for (row = 0; row < 10; row++){
		for (col = 0; col < 10; col++)
		{
			if (row == robotLoc[0][0] && col == robotLoc[0][1])			//prints out the map array while assigning R to the robot location or
				map[row][col] = 'R';									//. for everywhere else.
			else
				map[row][col] = '.';
			printf(" %c", map[row][col]);
		}
		printf("\n");
		
	}
	printf("\n");
	
}

int userMove(char map[10][10], char move, int robotLoc[1][2],
	int cookieLoc[1][2], int monsterLoc[1][2])
{
	int go = 0;
	while (go == 0){									//This function will ask the user which direction they want to move,
		int flag = 1;									// then move the robotLoc in the direction specified. It will then check
		while (flag == 1){								//if the robotLoc is at the location of the cookie or monster, then return 1 or -1

			printf("Where would you like to move? ");
			scanf(" %c", &move);
			flag = 0;

			if (robotLoc[0][0] == 0 && move == 'U'){
				printf("\nInvalid Move. \n");
				drawMap(map, robotLoc);
				flag = 1;
			}
			else if (robotLoc[0][0] == 9 && move == 'D'){
				printf("\nInvalid Move. \n");
				drawMap(map, robotLoc);
				flag = 1;
			}
			else if (robotLoc[0][1] == 0 && move == 'L'){
				printf("\nInvalid Move. \n");
				drawMap(map, robotLoc);
				flag = 1;
			}
			else if (robotLoc[0][1] == 9 && move == 'R'){
				printf("\nInvalid Move. \n");
				drawMap(map, robotLoc);
				flag = 1;
			}


		}

		if (move == 'D')
			robotLoc[0][0]++;
		else if (move == 'U')				//This is the spot that moves the R up down left or right depending on what the user input.
			robotLoc[0][0]--;
		else if (move == 'L')
			robotLoc[0][1]--;
		else if (move == 'R')
			robotLoc[0][1]++;

		drawMap(map, robotLoc);

		if ((robotLoc[0][0] == monsterLoc[0][0]) && 
			(robotLoc[0][1] == monsterLoc[0][1])){
			go = -1;
			
		}
		else if ((robotLoc[0][0] == cookieLoc[0][0]) && 
			(robotLoc[0][1] == cookieLoc[0][1])){
			go = 1;
			
	}

	}
	
	return go;
}





























