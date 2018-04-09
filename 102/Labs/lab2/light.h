#ifndef light_h
#define light_h
#include "ray.h"
#include "vector.h"



COLOR_T light(PV_T source, PV_T int_pt, PV_T normal, RAY_T ray, COLOR_T object_color, OBJ_T objs[], int closest, double T);
int shadow(PV_T source, PV_T intersect, int closest, OBJ_T objs[], PV_T normal, double T;);


#endif
