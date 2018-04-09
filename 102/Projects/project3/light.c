/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/12/14
	Project 3
	light.c
*/
#include <stdio.h>
#include <math.h>
#include "ray.h"
#include "vector.h"
#include "light.h"


static int shadow(PV_T intersect, OBJ_T* closest, SCENE_T scene, LIGHT_T* current)
{	
	
	LIGHT_T *curr;
	OBJ_T *o_curr;
	PV_T norm;
	double t;

	//calculating the direction for the shadow ray
	RAY_T shadow_ray;

	shadow_ray.direction.x = current->light_location.x - intersect.x;
	shadow_ray.direction.y = current->light_location.y - intersect.y;
	shadow_ray.direction.z = current->light_location.z - intersect.z;
	shadow_ray.direction = normalize(shadow_ray.direction);

	shadow_ray.origin = intersect;
	//int i;
	
	//checking if the object is in shadow
	for(o_curr = scene.objs; o_curr != NULL; o_curr = o_curr->next)
	{
		
		if(o_curr != closest)
		{
			
			if(o_curr->intersect(shadow_ray, *o_curr, &intersect, &norm, &t))
			{
				
				return 1;
			}
		}
	}
	return 0;
}

COLOR_T light(PV_T int_pt, PV_T normal, RAY_T ray, COLOR_T object_color, SCENE_T scene, OBJ_T* closest, double T)
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
	int i;
	LIGHT_T *curr;
	

	//making the ambient light.
	new_color.r = (object_color.r * 0.1);
	new_color.g = (object_color.g * 0.1); 
	new_color.b = (object_color.b * 0.1);

	

	for(curr = scene.light; curr != NULL; curr = curr->next)
	{

		//Checks if the object is in shadow, if it is then only ambient is used
		if((shadow(int_pt, closest, scene, curr)) == 0)
		{
			//Calculating distance for attenuation
			distance.x = curr->light_location.x - int_pt.x;
			distance.y = curr->light_location.y - int_pt.y;
			distance.z = curr->light_location.z - int_pt.z;
	
			Dl = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
			atten = 1/((c1 * pow(Dl, 2)) + (c2 * Dl) + c3);

			//making sure attenuation is 
			if( atten > 1)
			{
				atten = 1;
			}
			
			//Calculating L and then normalizing 					
			L.x = curr->light_location.x - int_pt.x;
			L.y = curr->light_location.y - int_pt.y;
			L.z = curr->light_location.z - int_pt.z;
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
					
					new_color.r += pow(dot(ray.direction, R), 100) * atten;
					new_color.g += pow(dot(ray.direction, R), 100) * atten;
					new_color.b += pow(dot(ray.direction, R), 100) * atten;
				}
				
				
			
			}
			
		}
		
	}	
	
	return new_color;

}


COLOR_T solid(OBJ_T obj, PV_T close)
{
	COLOR_T new;
	new = obj.color;
	return new;
}

COLOR_T checker(OBJ_T obj, PV_T int_pt)
{
	COLOR_T new;
	
	if(((int)floor(int_pt.x) + (int)floor(int_pt.y) + (int)floor(int_pt.z)) & 1)
			{
				new = obj.color;	
			}
			else
			{
				new = obj.color2;
			}
	return new;
}



