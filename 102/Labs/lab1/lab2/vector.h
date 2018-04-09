/* vector.h */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>
#include <memory.h>

/* This header file contains vector definitions and     */
/* prototype statements for 3 - D vector  operations    */

/* Three dimensional coordinate structures */
  // To  do:  define your vector_t struct here, with three double type members x, y and z
   typedef struct 
{
   double x;
   double y;
   double z;

}vector_t;


/* Prototype Statements */
double    vec_len (vector_t  v);
vector_t  vec_normalize (vector_t v);
vector_t  vec_scale (vector_t v,  double scale);
double    vec_dot (vector_t v1, vector_t v2);
vector_t  vec_add (vector_t  v1, vector_t  v2);
vector_t  vec_subtract (vector_t  v1, vector_t  v2);
void      vec_copy (vector_t *result_v, vector_t v);
void      vec_print (char  *label, vector_t v);

#endif

