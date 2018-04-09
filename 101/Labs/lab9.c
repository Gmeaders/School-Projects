#include <stdio.h>

int sort(int array[], int counter){
	int swaps;
	int i, j;

	for (i = 0; i < counter; i++){
		for(j = 0; j<counter-1; j++){
			if(array[j] > array[j+1]){
				int temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
				swaps++;
				}
			}
		}	
	return swaps;
}

int main(){

	int numArray[100];
	int counter = 0; 
	int go = 1;
	int i;
	int reverse;
	int j;

	while(go == 1){
	
	printf("Please enter a number ");
	scanf("%d", &numArray[counter]);
	counter++;
	
	printf("Are there more numbers?\n1 for yes 0 for no ");
	scanf("%i", &go);
	}

	j = counter;

	printf("There were %i swaps\n", sort(numArray, counter));

	for(i = 0; i < counter; i++){
		
		reverse = sort(numArray, counter);
		if(reverse == 0)
			i = counter;
		counter--;
		
	}


	printf("Count is = %i\n", counter);
	printf("Numbers in the array are \n");
	for(i = 0; i < j; i++){
		printf("%i\n", numArray[i]);
	}

	return 0;
}
