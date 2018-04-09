#include <stdio.h>

int main()
{
	int v1;  // Get inputs for v1 and v2 then make inputs for the equations e1 thru e4
	int v2;
	int e1;
	int e2;
	int e3;
	int e4;
	int value;

	value = scanf(" %d %d", &v1, &v2); // Gets input from the user for v1 and v2
	
	e1 = v1 + 2 * v2 / 3 * v1; // This does the equations for e1 through e4
	e2 = v1 + ((2*v2)/(3*v1));
	e3 = v1 + (2*(v2/3))* v1;
	e4 = (v2 % v1)%(v2/v1);

	printf(" v1 = %i and v2 =%i \n Expression values are \n e1 = %i, e2 = %i, e3 = %i, e4 = %i", v1, v2, e1, e2, e3, e4); // This prints the equations
	
	return 0;
}
