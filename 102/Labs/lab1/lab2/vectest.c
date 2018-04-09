#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "vector.h"

vector_t v1 = {2.0, 4.0, 7.0};
vector_t v2 = {1.0, -3.0, 2.0};

int main(int argc, char* argv[])
{
   vector_t v3;
   vector_t v4;
   vector_t v5;
   vector_t v6;
   double val;

   vec_print("v1", v1);
   printf("\n");
   vec_print("v2", v2);
   printf("\n");

   v3 = vec_subtract(v1, v2);
   vec_print("v1 - v2 = ", v3);
   printf("\n");

   vec_copy(&v4, v2);
   vec_print("Copy of v2: ",v4);
   printf("\n");
   
   val = vec_dot(v1, v2);
   printf("v1 dot v2 is %8.3lf \n", val);
   val = vec_len(v1);
   printf("Length of v1 is %8.3lf \n", val);

   v3 = vec_scale(v1, 6);
   vec_print("v1 scaled by its 6: ", v3);
   printf("\n");

   v6 = vec_normalize(v1);
   vec_print("v1 normalized:", v6);
   printf("\n");

   v5 = vec_add(v1,v2);
   vec_print("v1 + v2 = ", v5);
   printf("\n");

  
   return 0;
} // end main
