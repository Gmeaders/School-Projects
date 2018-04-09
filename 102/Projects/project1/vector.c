/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	5/21/15
	Project 1
	Vector.c
*/
#include "ray.h"
#include "vector.h"

//normalize function taken from notes
PV_T Normalize(PV_T v)
{
	PV_T ret_v;
	double len;
	len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	ret_v.x = v.x / len;
	ret_v.y = v.y / len;
	ret_v.z = v.z / len;
	
	return ret_v;
}

double dot(PV_T N, PV_T L)  //Dot product function taken from lab 2
{
	double ans;
	ans = ((N.x * L.x) + (N.y * L.y) + (N.z * L.z));
	return ans;
}

