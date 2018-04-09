/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/17/14
	Project 4
	light.cpp
*/
#include "vector.h"
#include "ray.h"
#include "sphere.h"
#include <math.h>
#include "light.h"

using namespace std;

//function for getting the lighting with formulas from class
COLOR_T LIGHT::light(VECTOR int_pt, VECTOR normal, RAY_T ray, COLOR_T object_color)
{
	VECTOR L;  
	VECTOR R;	  
	COLOR_T new_color;
	double temp;

	new_color.r = object_color.r * 0.1;
	new_color.g = object_color.g * 0.1; 
	new_color.b = object_color.b * 0.1;
				
	//calculating L for diffused.
	L = this->source - int_pt;
	L = L.normalize();
	temp = L.dot(normal);

	//checking if dot product is above 0 to use for diffused ligthing
	if(L.dot(normal) > 0)
	{
		new_color.r += (L.dot(normal) * object_color.r);
		new_color.g += (L.dot(normal) * object_color.g);
		new_color.b += (L.dot(normal) * object_color.b);
		
		R = L.calculate_r(normal, temp);
		R = R.normalize();
	
		
		//If the dot product for R vector is above 1 do the specular lighting
		if(R.dot(ray.direction) > 0)
		{
			
			new_color.r += pow(R.dot(ray.direction), 100);
			new_color.g += pow(R.dot(ray.direction), 100);
			new_color.b += pow(R.dot(ray.direction), 100);
		}
	
	}	

	return new_color;

}

