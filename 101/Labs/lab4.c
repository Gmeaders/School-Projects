#include <stdio.h>

int main()
{
	int A, B, C, i, F;	
	int count;
	printf("Please enter the number of scores: ");
	scanf("%d", &count);
	A = 0;
	B = 0;
	C = 0;
	i = 0;
	F = 0;
	
	for(i = 0; i < count; i++){
		
		F = 0;
		printf("Please enter a score: ");
		scanf("%d", &F);

		if(F>=90){
			A++;}
		else if(F>=80){
			B++;}
		else if(F<=79){
			C++;}

		}
	printf("There were %i A's, %i B's and %i C's", A, B, C);
	return 0;
}
