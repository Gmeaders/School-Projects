#include "matrix.h"

int main(){
   matrix_t m1={
              {
                {1, 2, 3}, 
                {4, 5, 6}, 
                {7, 8, 9}
              }
            };
   matrix_t m2;
   matrix_t m3;
   int counter;
   matrix_print("The matrix m1 is: \n", &m1);
   matrix_copy(&m2,&m1);
   matrix_print("The matrix copied is:\n ", &m2);
   
   printf("Please input 9 numbers for m2:\n");
   counter=matrix_load(&m2);
   matrix_print("The matrix loaded is:\n ", &m2);
   
   matrix_sum(&m3, m1, m2);
   matrix_print("The sum of m1 and m2 is: \n", &m3);

   matrix_scale(&m3, m1, 5);
   matrix_print("The result of scale m1 by 5 is: \n", &m3);

   matrix_diff(&m3, m1, m2);
   matrix_print("The difference between m1 and m2 is: \n", &m3);

   matrix_mult(&m3, m1, m2);
   matrix_print("The product of m1 and m2 is: \n", &m3);

   printf("*************Allied Parm Test*************\n");
   matrix_mult(&m1, m1, m2);
   matrix_print("Alias test, the product of m1 and m2 is: \n", &m1);
   return 0;
}


