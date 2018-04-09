
#include "matrix.h"

#define MATRIX_SIZE 3

int matrix_load(matrix_t* mat)
{
   //read in matrix values one at a time
 	int x, y;
	for(x = 0; x < MATRIX_SIZE; x++)
  	{
		for(y = 0; y < MATRIX_SIZE; y++)
		{
			scanf("%lf", &(mat->row[x][y]));
		}
	}
  
  
  
   return 1;
}

void matrix_print(char* label, matrix_t* mat)
{
   //printing label [already completed]
   printf("%s", label);
   
   //printing elements of the matrix one at a time
   int x; 
   int y;   
   for(x = 0; x < MATRIX_SIZE; x++)
   {
	for(y = 0; y < MATRIX_SIZE; y++)
	{
		printf("\t%.3lf\t", mat->row[x][y]);
	}
		printf("\n");
   }

}
   

void matrix_copy(matrix_t* dest, matrix_t* src)
{
   //copying elements from src to dest one at a time
  	int x;
	int y;
	for(x = 0; x < MATRIX_SIZE; x++)
	{
		for(y =  0; y < MATRIX_SIZE; y++)
		{
			dest->row[x][y] = src->row[x][y];
		}
	}
  
}

void matrix_sum(matrix_t* result, matrix_t m1, matrix_t m2)
{
   //adding elements of m1 and m2 one at a time
  	int x;
	int y;
	for(x = 0; x < MATRIX_SIZE; x++)
	{
		for(y =  0; y < MATRIX_SIZE; y++)
		{
			result->row[x][y] = m1.row[x][y] + m2.row[x][y]; 
		}
	}
}
void matrix_diff(matrix_t* result, matrix_t m1, matrix_t m2)
{
   //subtracting m2 from m1
	int x;
	int y;
	for(x = 0; x < MATRIX_SIZE; x++)
	{
		for(y =  0; y < MATRIX_SIZE; y++)
		{
			result->row[x][y] = m1.row[x][y] - m2.row[x][y]; 
		}
	}
  
}

void matrix_scale(matrix_t* result, matrix_t m1, double scale)
{
   //scaling each component by the given scale factor
	int x;
	int y;
	for(x = 0; x < MATRIX_SIZE; x++)
	{
		for(y =  0; y < MATRIX_SIZE; y++)
		{
			result->row[x][y] = 5 * m1.row[x][y];
		}
	}
   
}

void matrix_mult(matrix_t* result, matrix_t m1, matrix_t m2)
{
		//must multiply rows of m1 by the cols of m2 and sum them
	int x;
	int y;
	int z;
	int sum = 0;
	for(x = 0; x < MATRIX_SIZE; x++)
	{
		for(y =  0; y < MATRIX_SIZE; y++)
		{
			for(z = 0; z < MATRIX_SIZE; z++)
			{
			sum += m1.row[x][z] * m2.row[z][y];
			}
			result->row[x][y] = sum;
			sum = 0;
		}
	}
         
       
}

