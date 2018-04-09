/* lab6.c - Spring 2014
	practice with functions 

	fill in the missing code in the main() function
	also fill in the missing code in each of the
		other three functions
*/

#include <stdio.h>

// prototypes
int factorial(int x);
int sumOfOdds(int y);
int pythagorean(int a, int b);


int main(void) {
	int input1, input2;
	int fact, sumOdd, pyth;

	// Ask user to enter an integer and save it into input1 
	printf("Please Input an integer for Input 1: ");
	scanf("%d", &input1);
	
	// Ask user to enter another integer and save it into input2 
	printf("Please input an integer for Input 2: ");
	scanf("%d", &input2);

	// Call the factorial function sending it input1; assign the
	// return value of the function call into the variable called fact
	int factorial(int input1);	

	// Call the sumOfOdds function sending it input2; assign the
	// return value of the function call into the variable called sumOdd
	sumOfOdds( input2);

	// Call the pythagorean function sending it both input1 & input2; 
	// assign the return value of the function call into the variable 
	// called pyth
	pythagorean(input1, input2);

	// Print the results of each of the three function calls
	printf("\nThe factorial of %i is %i", input1,  factorial(input1));
	printf("\nThe odd sum of %i  is %i.", input2,  sumOfOdds(input2));
	printf("\nc Squared is %i\n", pythagorean(input1, input2));

	return 0;
}


// factorial function:  5 factorial is 5 * 4 * 3 * 2 * 1
int factorial(int x) {
	int i;
	
	if(x == 1){
		return x;
	}
	else{
		x = x * factorial(x-1);
	

	return x;
	}

}


// sumOfOdds function:  sum of all odd numbers from 1 to b
// 	if the input is 12, sumOfOdds is 1 + 3 + 5 + 7 + 9 + 11
// 	if input is 7, sumOfOdds is 1 + 3 + 5 + 7
int sumOfOdds(int y) {
int i;
int b=0;


	for( i = 1; i <= y; i++){
	if( i % 2 != 0){
		 
		b = b + i;
		
	}
 
		
	
}
return b;
}


// pythagorean function: c squared = (a squared) + (b squared)
int pythagorean(int a, int b) {
int pythag = 0;

pythag = (a*a)+(b*b);

return pythag;
}

