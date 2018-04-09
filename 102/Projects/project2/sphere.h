/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/1/14
	Project 2
	sphere.h
*/
#ifndef sphere_h
#define sphere_h
#include "vector.h"
#include "ray.h"

int intersect_Sphere(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T);

#endif
