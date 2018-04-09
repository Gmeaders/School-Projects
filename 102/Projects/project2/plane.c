/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/1/14
	Project 2
	plane.c
*/
#include "ray.h"
#include "vector.h"
#include "light.h"
#include "plane.h"


//Checking for intersect with the plane, setting the int_pt and normal if it does
int intersect_plane(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T)
{
	double d;
	PV_T N;
	
	d = obj.geom.plane.d;
	N = obj.geom.plane.normal;
	
	if(dot(N, ray.direction) == 0)
	{
		return 0;
	}
	
	*T = (-(dot(N, ray.origin) + d))/(dot(N, ray.direction));

	if(*T < 0)
	{
		return 0;
	}
	else
	{
		int_pt->x = ray.origin.x + (ray.direction.x * *T);
		int_pt->y = ray.origin.y + (ray.direction.y * *T);
		int_pt->z = ray.origin.z + (ray.direction.z * *T);
		*normal = obj.geom.plane.normal;
		
		return 1;
	}
}
