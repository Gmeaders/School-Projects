#include <stdio.h>

int main()
{

int width, length, area;
int a, b, c, d;

printf("\nEnter an integer for the width: ");
scanf("%d", &width);

printf("\nEnter an integer for the length:  ");
scanf("%d", &length);


area = length * width;

printf("\n The area of your rectangle is: \n %4i in decimal \n %4x in hexadecimal \n %4o in octal  \n \n", area, area, area);

for(a = 0; a < width; a++)
{
	printf("*");
}
printf("\n");

for(b = 0; b < (length-2); b++)
{
	printf("*");
		for(c = 0; c < (width-2); c++)
		{
			printf(" ");
		}
	printf("*");
	printf("\n");
}

for( d = 0; d < width; d++)
{
	printf("*");
}	

return 0;
}
