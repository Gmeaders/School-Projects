/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/12/14
	Project 3
	vector.h
*/
#ifndef VECTOR_H
#define VECTOR_H

#include "ray.h"

typedef struct
{
	double x;
	double y;
	double z;
}PV_T;

PV_T normalize(PV_T v);
double dot(PV_T N, PV_T L);

#endif
