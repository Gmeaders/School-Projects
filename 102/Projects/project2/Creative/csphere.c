/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/1/14
	Project 2
	sphere.c
*/
#include <math.h>
#include "cray.h"
#include "cvector.h"
#include "csphere.h"

int intersect_Sphere(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T)
{
	double a = 1;
	double b;
	double c;
	double t1;
	double t0;           
	

	b = 2 * ((ray.direction.x * (ray.origin.x - obj.geom.sphere.center.x)) + 
		(ray.direction.y * (ray.origin.y - obj.geom.sphere.center.y)) + 
		(ray.direction.z * (ray.origin.z - obj.geom.sphere.center.z)));
	
	
	c = (pow(ray.origin.x - obj.geom.sphere.center.x, 2) + pow(ray.origin.y -
	     obj.geom.sphere.center.y, 2) + pow(ray.origin.z - obj.geom.sphere.center.z, 2) -
	     pow(obj.geom.sphere.radius, 2));

	//Checking that the discriminant is not negative
	if((b * b) - (4 * a * c) < 0 )
	{
		return 0;
	}
	
	//Calculating T1 and T0 with quadratic equation
	t0 = ((-b - sqrt((b * b) - (4 * a * c))) / 2.0);
	t1 = ((-b + sqrt((b * b) - (4 * a * c))) / 2.0);
	
	//Checking that t1 and t0 are not negative
	if( t1 < 0 && t0 < 0)
	{
		return 0; //returning 0 to show that there was no intersect
	}
	
	if(t1 < 0 && t0 > 0) //checks for the one that isn't negative
	{
		*T = t0;
	}

	if(t1 > 0 && t0 < 0) // Checks for the one that isn't negative.
	{
		*T = t1;
	}

	if(t1 > t0)    //Checks for which one is the smaller and uses it.
	{
		*T = t0;
	}
	
	else	//uses the other 
	{ 
		*T = t1;
	}
	
	int_pt->x = ray.origin.x + (ray.direction.x * *T);
	int_pt->y = ray.origin.y + (ray.direction.y * *T);
	int_pt->z = ray.origin.z + (ray.direction.z * *T);
	
	//calculating normal line.
	normal->x = ((int_pt->x - obj.geom.sphere.center.x)/obj.geom.sphere.radius);
	normal->y = ((int_pt->y - obj.geom.sphere.center.y)/obj.geom.sphere.radius);
	normal->z = ((int_pt->z - obj.geom.sphere.center.z)/obj.geom.sphere.radius);

	return 1;

}
