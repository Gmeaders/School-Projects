#include "lab3.h"

int main() {
	unsigned short h_format;
	unsigned int a;
	printf("Enter the first number to convert: ");
	scanf("%hu", &h_format);
	printf("Enter the second number to count the number of 1s: ");
	scanf("%u",&a);
	printf("first number in host format: %hu\n", h_format);
	printf("first number in network format: %hu\n", my_htons(h_format));
	printf("The number of 1s in %u : %d\n", a, count_ones(a));
	//printf("1\n");
	return (1);
}
