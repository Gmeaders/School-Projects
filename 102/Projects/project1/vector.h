/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	5/21/15
	Project 1
	Vector.h
*/
#ifndef vector_h
#define vector_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
	double x;
	double y;
	double z;
}PV_T;
PV_T Normalize(PV_T v);
double dot(PV_T N, PV_T L);
#endif
