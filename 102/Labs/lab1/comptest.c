#include <stdlib.h>
#include <stdio.h>
#include "complex.h"

complex_r c1 = {3.0, 4.0};
complex_r c2 = {4.0, -1.0};

int main(int argc, char* argv[])
{
   //declare variables for holding complex numbers here
   complex_r c5;
   complex_r c6;
   complex_r c7;
   complex_r c8;
   complex_r c9;
   complex_p p1;

   c_print("c1", c1);
   printf("\n");
   
   c_print("c2", c2);
   printf("\n");

   printf("Absolute value of c1 is %8.3lf \n", c_abs(c1));
   
   c_mult(c1, c2, &c5);
   c_print("c5 = c1 * c2", c5);
   printf("\n");

   c_div(c5, c2, &c6);
   c_print("c1 = c5 / c2", c6);
   printf("\n");

   printf("Enter 2 real numbers: ");
  
   c_load(&c7);
   c_print("Complex number loaded was ", c7);
   printf("\n");

   c_copy(c2, &c8);
   c_print("c8 is a copy of c2 ", c8);
   printf("\n");

   
   p1 = c_convert_to_polar(c1);
   printf("p1 = polar form of c1: r = %8.3lf arg = %8.3lf", p1.r, p1.ang);
   printf("\n");

   c9 = c_convert_to_rectangular(p1);
   c_print("c9 = c1 ",c9);
   printf("\n");


   printf("===Aliased parm test===\n");
   c_mult(c1, c2, &c1);
   c_print("c1 = c1 * c2: ", c1);
   printf("\n");

   return 0;
} // end main
