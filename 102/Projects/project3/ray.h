/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/12/14
	Project 3
	Ray.h
*/
#ifndef RAY_H
#define RAY_H

#include "vector.h"
#define MAX_LEVEL 5

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

typedef struct light
{
	PV_T light_location;
	COLOR_T light_color;
	struct light *next;
}LIGHT_T;

typedef struct plane
{
	PV_T normal;
	double d;
}PLANE_T;

typedef struct box
{
	PV_T ll;
	PV_T ur;
}BOX_T;


typedef struct img
{
	int height;
	int width;
	COLOR_T **img;
}IMG_T;

typedef struct obj
{
	COLOR_T color;
	COLOR_T color2;
	double reflect;
	struct obj *next;
	union
	{
		SPHERE_T sphere;
		PLANE_T plane;
		BOX_T box;
	}geom;
	int(*intersect)(RAY_T , struct obj, PV_T *, PV_T *, double*);
	COLOR_T(*getcolor)(struct obj, PV_T);
}OBJ_T;

typedef struct scene
{
	double x_start;
	double y_start;
	double pixel_width;
	OBJ_T *objs;
	LIGHT_T *light;
	COLOR_T background;
}SCENE_T;

#endif

