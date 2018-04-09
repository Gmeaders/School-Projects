/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/12/14
	Project 3
	sphere.h
*/
#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"
#include "ray.h"

int intersect_Sphere(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T);

#endif
