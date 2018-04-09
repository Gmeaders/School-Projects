/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/1/14
	Project 2
	vector.h
*/
#ifndef vector_h
#define vector_h
#include "cray.h"

typedef struct
{
	double x;
	double y;
	double z;
}PV_T;

PV_T normalize(PV_T v);
double dot(PV_T N, PV_T L);

#endif
