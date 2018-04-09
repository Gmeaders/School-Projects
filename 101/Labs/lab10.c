#include <stdio.h>
#include <string.h>

int my_strlen(char s1[]){
	int n=0;
	
	while(s1[n] !=0 || n > 7){
		n++;
	}
	
	return n;

	}

void my_strcat(char s1[], char s2[]){
	while(*s1)
		s1++;
	while(*s2){
		*s1 = *s2;
		s2++;
		s1++;
	}
	*s1 = '\0';
	}

int main(){
	
	int i;
	char v1[16];
	char v2[16];
	int i1, i2;

	printf("Enter first string\n");

	scanf("%7s", v1);
        
	printf("enter second string\n");
	scanf(" %7s", v2);
	
	
	i1 = my_strlen(v1);
        i2 = my_strlen(v2);

	
	printf("len: %3d - string: %s \n", i1, v1);

	printf("len: %3d - string: %s \n", i2, v2);
	
	my_strcat(v1, v2);

	printf("%s", v1);
	
	return 0;
}

