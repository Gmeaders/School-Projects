/*complex.c

This program holds functions to perform various calculations on complex numbers.

CPSC 102
Lab 1
Name: Greg Meaders
Date: 5/19/14

*/


#include "complex.h"

//Absolute value of a complex number
double c_abs(complex_r c)
{
	double abs;

	abs = sqrt((c.a * c.a) + (c.b * c.b));

	return abs;
}

//Multiplication of two complex numbers
//Think: foil
void c_mult(complex_r c1, complex_r c2, complex_r *result_c)
{
	double ac,bd,bc,ad;
	//computations for ac (first), ad (outer), bc (inner), bd (last)
	
   	ac = (c1.a * c2.a);
	ad = (c1.a * c2.b);
	bc = (c1.b * c2.a);
	bd = (c1.b * c2.b);
   
   
   
   //result_c ->a = ?
   	result_c->a = (ac - bd);
   //result_c ->b = ?
   	result_c->b = (bc + ad);
}


//Division of complex numbers
void c_div(complex_r c1, complex_r c2, complex_r *result_c)
{
	double ac, bd, bc, ad;
	double denomator, numerator1, numerator2;
	//coumputations for ac,bd,bc,ad -- same as FOIL from the multiplication above!
	
  	ac = (c1.a * c2.a);
	ad = (c1.a * c2.b);
	bc = (c1.b * c2.a);
	bd = (c1.b * c2.b);
	
	numerator1 = (ac + bd);
	numerator2 = (bc - ad);
	denomator = ((pow(c2.a, 2)) + (pow(c2.b, 2)));

	
   //calculate denomator, numerator1, numerator2
   //Reminder: pow(4,2) = 4^2 [ built in math function ]
   	
	result_c->a = numerator1/denomator;
	result_c->b = numerator2/denomator;   
   
	//result_c->a = ?
	//result_c->b = ?
}

//Copying a complex number into another variable
void c_copy(complex_r c, complex_r *result_c)
{
	result_c->a = c.a;
  	result_c->b = c.b; 
}

//Reading complex numbers from user input
void c_load(complex_r *result_c)
{
	scanf("%lf %lf", &result_c->a, &result_c->b);
	  //using scanf is fine to load into *result_c
}

//Printing as on the example output.txt
void c_print(char *label, complex_r c)
{
	printf("%s: %8.3lf %8.3lf", label, c.a, c.b);
}

//Conversion from rectangular to polar
//First calculate r, secondly ang
complex_p c_convert_to_polar(complex_r c)
{
	complex_p ans;
	ans.r = sqrt((c.a * c.a) + (c.b * c.b));
	ans.ang = atan(c.b / c.a);
	//Reminder: atan(num) calculates arctan
	//Return complex_p ans
	return ans;
}

//Conversion from polar to rectangular
complex_r c_convert_to_rectangular(complex_p p)
{
	complex_r ans;
	
	ans.a = (p.r * cos(p.ang));
	ans.b = (p.r * sin(p.ang));
   //Reminder: sin(num) and cos(num) are math functions included
   //Return complex_r ans
	return ans;
}
