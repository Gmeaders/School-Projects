/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/1/14
	Project 2
	Ray.h
*/
#ifndef ray_h
#define ray_h
#include "cvector.h"
#define MAX_OBJS 10

typedef struct
{
	PV_T origin;
	PV_T direction;
}RAY_T;

typedef struct
{
	PV_T center;
	double radius;
}SPHERE_T;

typedef struct color
{
	double r;
	double g;
	double b;
}COLOR_T;

typedef struct plane
{
	PV_T normal;
	double d;
}PLANE_T;

typedef struct obj
{
	int type;
	COLOR_T color;
	union{
		SPHERE_T sphere;
		PLANE_T plane;
		}geom;
	int(*intersect)(RAY_T , struct obj, PV_T *, PV_T *, double*);
}OBJ_T;

int intersect_Sphere(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T);
COLOR_T trace(PV_T source, RAY_T ray, PV_T intersect, PV_T normal, OBJ_T objs[]);
void init(OBJ_T objs[]);


#endif

