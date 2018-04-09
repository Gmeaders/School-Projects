/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/1/14
	Project 2
	plane.h
*/
#ifndef plane_h
#define plane_h
#include "cray.h"

int intersect_plane(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T);

#endif
