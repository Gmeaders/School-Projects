#include <stdio.h>

int inner_product(int a[], int b[], int count){

int product = 0;
int i;

for (i = 0; i < count; i++){
	product = product + (a[i] * b[i]);
}

return product;
}

void reverse(int a[], int count){
int i, b = 3;
int temp;
int start = 0;
int end = 3;
temp = a[0];

for(i = 0; i < count/2; i ++){
	temp = a[i];
	a[i] = a[count - i - 1];
	a[count- i - 1] = temp;
	
	

}
}



