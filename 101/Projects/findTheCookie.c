#include "defs.h"
#include "project3.c"

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

