/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	5/21/15
	Project 1
	Ray.h
*/
#ifndef ray_h
#define ray_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"
typedef struct
{
	PV_T origin;
	PV_T direction;
}RAY_T;
typedef struct
{
	PV_T center;
	double radius;
}SPHERE_T;
typedef struct color
{
	double r;
	double g;
	double b;
}COLOR_T;
int intersect_Sphere(RAY_T ray, SPHERE_T sphere, PV_T *int_pt, PV_T *normal);
COLOR_T light(PV_T source, PV_T int_pt, PV_T normal, RAY_T ray, COLOR_T object_color);
#endif

