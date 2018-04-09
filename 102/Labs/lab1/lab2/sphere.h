#ifndef sphere_h
#define sphere_h
#include "vector.h"
#include "ray.h"

typedef struct
{
	PV_T center;
	double radius;
}SPHERE_T;


int intersect_Sphere(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T);


#endif
