#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

#define BUFFER_SIZE 20

void reset_str(char *str, int num);
unsigned int my_strncmp(char *str1, char *str2, unsigned int num);
void printCharArray(char *str, int str_size);

int main()
{
	char *str = "Hello, world!";
	char buffer1[BUFFER_SIZE];
	char buffer2[BUFFER_SIZE];
	size_t s;
	
	printf("Testing my_strcpy... ");
	
	reset_str(buffer1, BUFFER_SIZE);
	reset_str(buffer2, BUFFER_SIZE);
	
	strcpy(buffer1, str);
	my_strcpy(buffer2, str);
	
	if (my_strncmp(buffer1, buffer2, BUFFER_SIZE) == 0)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	
	printf("Testing my_strncpy (padding)... ");
	
	reset_str(buffer1, BUFFER_SIZE);
	reset_str(buffer2, BUFFER_SIZE);
	
	strncpy(buffer1, str, BUFFER_SIZE);
	my_strncpy(buffer2, str, BUFFER_SIZE);
	
	if (my_strncmp(buffer1, buffer2, BUFFER_SIZE) == 0)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	
	printf("Testing my_strncpy (truncate)... ");
	
	reset_str(buffer1, BUFFER_SIZE);
	reset_str(buffer2, BUFFER_SIZE);
	
	strncpy(buffer1, str, 10);
	my_strncpy(buffer2, str, 10);
	
	if (my_strncmp(buffer1, buffer2, BUFFER_SIZE) == 0)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	
	printf("Testing my_strlcpy... ");
	
	reset_str(buffer1, BUFFER_SIZE);
	reset_str(buffer2, BUFFER_SIZE);
	
	strncpy(buffer1, str, 9);
	buffer1[9] = '\0';
	s = my_strlcpy(buffer2, str, 10);
	
	if (s == strlen(str) && my_strncmp(buffer1, buffer2, BUFFER_SIZE) == 0)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("FAIL\n");
	}
	
	return 0;
}

void reset_str(char *str, int num)
{
	int i;
	for (i = 0; i < num; ++i)
	{
		str[i] = 'a';
	}
}

unsigned int my_strncmp(char *str1, char *str2, unsigned int num)
{
	unsigned int i;
	for (i = 0; i < num; ++i)
	{
		if (str1[i] != str2[i])
		{
			return 1;
		}
	}
	return 0;
}

void printCharArray(char *str, int str_size)
{
	int i;
	for (i = 0; i < str_size; ++i)
	{
		if (str[i] == '\0')
		{
			printf("0");
		}
		else
		{
			printf("%c", str[i]);
		}
	}
	printf("\n");
}
