/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/12/14
	Project 3
	plane.h
*/
#ifndef PLANE_H
#define PLANE_H

#include "ray.h"

int intersect_plane(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T);

#endif
