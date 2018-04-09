/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/12/14
	Project 3
	box.c
*/
#include <math.h>
#include "ray.h"
#include "vector.h"
#include "box.h"


//Intercept function for the box
int intersect_box(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T)
{
	
	double tnear = -1000;
	double tfar = 1000;
	double t1, t2;
	int test;
	int i = 0;
	int j = 0;
		
	PV_T planes[6];
	
	double ray_dir[3];
	double ray_org[3];
	double box_lower[3];
	double box_upper[3];
	
	// setting all the planes, box locations, and ray dir and org into arrays.
	box_lower[0] = obj.geom.box.ll.x;
	box_lower[1] = obj.geom.box.ll.y;
	box_lower[2] = obj.geom.box.ll.z;

	box_upper[0] = obj.geom.box.ur.x;
	box_upper[1] = obj.geom.box.ur.y;
	box_upper[2] = obj.geom.box.ur.z;

	ray_dir[0] = ray.direction.x;
	ray_dir[1] = ray.direction.y;
	ray_dir[2] = ray.direction.z;

	ray_org[0] = ray.origin.x;
	ray_org[1] = ray.origin.y;
	ray_org[2] = ray.origin.z;	

	planes[0].x = -1;
	planes[0].y = 0;
	planes[0].z = 0;

	planes[1].x = 1;
	planes[1].y = 0;
	planes[1].z = 0;

	planes[2].x = 0;
	planes[2].y = -1;
	planes[2].z = 0;

	planes[3].x = 0;
	planes[3].y = 1;
	planes[3].z = 0;

	planes[4].x = 0;
	planes[4].y = 0;	
	planes[4].z = -1;

	planes[5].x = 0;
	planes[5].y = 0;
	planes[5].z = 1;

	//for each set of planes
	for(i = 0; i < 3; i++)
	{
		j = 0;

		if (ray_dir[i] == 0)
		{
			if(ray_org[i] < box_lower[i] || ray_org[i] > box_upper[i])
			{
				return 0;
			}
		}
		
		t1 = (box_lower[i] - ray_org[i]) / ray_dir[i];
		t2 = (box_upper[i] - ray_org[i])/ ray_dir[i];

		if(t1 > t2)
		{
			swap(&t1, &t2);
			j = 1;
		}
		if(t1 > tnear)
		{
			tnear = t1;
			test = 2 * i + j;
		}
		if(t2 < tfar)
		{
			tfar = t2;
		}
		if(tnear > tfar)
		{
			return 0;
		}
		if(tfar < 0)
		{
			return 0;
		}
		
	}

	*T = tnear;

	int_pt->x = ray_org[0] + ray_dir[0] * (*T);
	int_pt->y = ray_org[1] + ray_dir[1] * (*T);
	int_pt->z = ray_org[2] + ray_dir[2] * (*T);

	normal->x = planes[test].x;
	normal->y = planes[test].y;
	normal->z = planes[test].z;

		
	return 1;
}

//swap function
void swap(double *x, double *y)
{
	double temp;
	temp = *x;
	*x = *y;
	*y = temp;	
}
