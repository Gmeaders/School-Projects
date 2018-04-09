/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/12/14
	Project 3
	box.h
*/
#ifndef BOX_H
#define BOX_H

#include "vector.h"
#include "ray.h"


int intersect_box(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T);
void swap(double *x, double *y);



#endif
