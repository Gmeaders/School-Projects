/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/17/14
	Project 4
	sphere.cpp
*/
#include <math.h>
#include <iostream>
#include "vector.h"
#include "ray.h"
#include "sphere.h"

using namespace std;


//function for making normal line and finding intercepts with calculations from class.
bool SPHERE::intersect(RAY_T ray, VECTOR& int_pt, VECTOR& normal)
{
	
	double a = 1;
	double b;
	double c;
	double t1;	
	double t0; 
	double T;
	VECTOR temp;
	
	//temp vector
	temp = ray.origin - this->center;  
	
	b = ray.direction.calculate_b(temp);
	
	c = ray.origin.calculate_c(this->center, this->radius);
	

	//Checking that the 2nd part of quadratic is not negative
	if((b * b) - (4 * a * c) < 0 )
	{
		
		return false;
	}
	
	//Calculating T1 and T0 with quadratic equation
	t0 = ((-b - sqrt((b * b) - (4 * a * c))) / 2.0);
	t1 = ((-b + sqrt((b * b) - (4 * a * c))) / 2.0);
	
	
	if( t1 < 0 && t0 < 0)
	{
		return false; //returning false to show that there was no intersect
	}
	
	if(t1 < 0 && t0 > 0) //checks for the one that isn't negative
	{
		T = t0;
	}

	if(t1 > 0 && t0 < 0) // Checks for the one that isn't negative.
	{
		T = t1;
	}

	if(t1 > t0)    //Checks for which one is the smaller and uses it.
	{
		T = t0;
	}
	
	else	//uses the other 
	{ 
		T = t1;
	}

	int_pt = ray.origin + (ray.direction * T);

	normal = ((int_pt - this->center)/this->radius);

	return true;

}
