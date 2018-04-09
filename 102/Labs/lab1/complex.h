/* complex.h */

#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>
#include <memory.h>

/* This header file contains the definition of a complex number and */
/* prototype statements for operations on complex numbers    */

/* Structure for a complex number in rectangular form */
typedef struct ComplexRectangular
{
   double a;
   double b;
}  complex_r;

/* Structure for a complex number in polar form */
typedef struct ComplexPolar
{
   double r;
   double ang;
}  complex_p;

/* Prototype Statements */
double c_abs(complex_r c);
void   c_mult(complex_r  c1, complex_r  c2, complex_r *result_c);
void   c_div(complex_r  c1, complex_r  c2, complex_r *result_c);
void   c_copy(complex_r c, complex_r *result_c);
void c_load(complex_r *resultc);
void   c_print(char  *label, complex_r c);
complex_p c_convert_to_polar(complex_r c);
complex_r c_convert_to_rectangular(complex_p p);
#endif

