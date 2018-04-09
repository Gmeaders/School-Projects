/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/1/14
	Project 2
	light.c
*/
#include <stdio.h>
#include <math.h>
#include "ray.h"
#include "vector.h"
#include "light.h"



COLOR_T light(PV_T source, PV_T int_pt, PV_T normal, RAY_T ray, COLOR_T object_color, OBJ_T objs[], int closest, double T)
{
	PV_T L;  
	PV_T R;	  
	COLOR_T new_color;
	PV_T distance;
	double Dl;
	double atten;
	double c1 = .002;
	double c2 = .02;
	double c3 = .2;


	//Calculating distance for attenuation
	distance.x = source.x - int_pt.x;
	distance.y = source.y - int_pt.y;
	distance.z = source.z - int_pt.z;

	Dl = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
	atten = 1/((c1 * pow(Dl, 2)) + (c2 * Dl) + c3);

	//making sure attenuation is 
	if( atten > 1)
	{
		atten = 1;
	}
	

	//Making the checkerboard pattern for the plane
	if(objs[closest].type == 2)
	{
		if(((int)floor(int_pt.x) + (int)floor(int_pt.y) + (int)floor(int_pt.z)) & 1)
		{
			object_color.r = 1;
			object_color.g = 1;
			object_color.b = 1;
		}
		else
		{
			object_color.r = 0;
			object_color.g = 0;
			object_color.b = 0;
		}
	}


	//making the ambient light.
	new_color.r = (object_color.r * 0.1);
	new_color.g = (object_color.g * 0.1); 
	new_color.b = (object_color.b * 0.1);

	//Checks if the object is in shadow, if it is then only ambient is used
	if((shadow(source, int_pt, closest, objs, normal, T)) == 0)
	{

		//Calculating L and then normalizing 					
		L.x = source.x - int_pt.x;
		L.y = source.y - int_pt.y;
		L.z = source.z - int_pt.z;
		L = normalize(L);

		
		
	
		//checking if dot product is above 0 to use for diffused ligthing
		if(dot(normal, L) > 0)
		{
			//Calculating and normalizing R for the specular lighting
			R.x = (L.x - (2 * (dot(normal, L) * normal.x)));
			R.y = (L.y - (2 * (dot(normal, L) * normal.y)));
			R.z = (L.z - (2 * (dot(normal, L) * normal.z)));
			R = normalize(R);

			new_color.r += (dot(normal, L) * object_color.r * atten);
			new_color.g += (dot(normal, L) * object_color.g * atten);
			new_color.b += (dot(normal, L) * object_color.b * atten);
		
			//If the dot product for R vector is above 1 do the specular lighting
			if(dot(ray.direction, R) > 0)
			{
				new_color.r += pow(dot(ray.direction, R), 100);
				new_color.g += pow(dot(ray.direction, R), 100);
				new_color.b += pow(dot(ray.direction, R), 100);
			}
	
		}
	}	

	return new_color;

}

int shadow(PV_T source, PV_T intersect, int closest, OBJ_T objs[], PV_T normal, double T)
{	
	//calculating the direction for the shadow ray
	RAY_T shadow_ray;
	shadow_ray.direction.x = source.x - intersect.x;
	shadow_ray.direction.y = source.y - intersect.y;
	shadow_ray.direction.z = source.z - intersect.z;
	shadow_ray.direction = normalize(shadow_ray.direction);
	shadow_ray.origin = intersect;
	int i;

	//checking if the object is in shadow
	for(i = 0; i < MAX_OBJS; i++)
	{
		if(i != closest)
		{
			if(objs[i].intersect(shadow_ray, objs[i], &intersect, &normal, &T))
			{
				return 1;
			}
		}
	}
	return 0;
}


