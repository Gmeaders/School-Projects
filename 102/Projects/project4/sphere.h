/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/17/14
	Project 4
	sphere.h
*/
#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"

class SPHERE
{
	VECTOR center;
	double radius;

public:

	SPHERE() {};

	SPHERE(VECTOR center, double r)
	{
		this->center = center;
		this->radius = r;
	}

	bool intersect(RAY_T ray, VECTOR& int_pt, VECTOR& normal);
};

#endif
