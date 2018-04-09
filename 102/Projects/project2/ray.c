/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/1/14
	Project 2
	Ray.c
*/
#include <stdio.h>
#include <math.h>
#include "ray.h"
#include "vector.h"
#include "light.h"
#include "plane.h"
#include "sphere.h"

int main()
{
	int w = 640;
	int h = 480;
	int x = 0;
	int y = 0;
	unsigned char red;
	unsigned char blue;	
	unsigned char green;

	RAY_T ray;
	PV_T normal;
	PV_T int_pt;
	OBJ_T objs[MAX_OBJS];
	init(objs);

	//making the color that will be changed by lighting
	COLOR_T obj_color = {0, 0, 0};


	//Creating and setting the light source
	PV_T lighting;
	lighting.x = 5;
	lighting.y = 10;
	lighting.z = -2;
	
	//write out ppm header
	printf("P6\n%i %i\n255\n", w, h);


	//for each pixel
	for(y = 0; y < h; y++)
	{
		for(x = 0; x < w; x++)
		{
			//compute the ray origin and direction
			ray.origin.x = 0;
			ray.origin.y = 0;
			ray.origin.z = 0;

			//calculations for ray direction
			ray.direction.x = (-0.67 + (x/480.0));
			ray.direction.y = (0.5 - (y/480.0));
			ray.direction.z = 1;

			//normalise ray direction (use normalize function)	
			ray.direction = normalize(ray.direction);
			
			obj_color = trace(lighting, ray, int_pt, normal, objs);
	
			if (obj_color.r > 1)
				obj_color.r = 1;
			if (obj_color.g > 1)
				obj_color.g = 1;
			if (obj_color.b > 1)
				obj_color.b = 1;

			//Set the colors back to characters to be used in the printf statement
			red = (unsigned char)(obj_color.r * 255);
			green = (unsigned char)(obj_color.g * 255);
			blue = (unsigned char)(obj_color.b * 255);

			printf("%c%c%c", red, green, blue);

		}
	}

	
		
	return 0;
}

//Function to initialize all objects
void init(OBJ_T objs[])
{
	objs[0].geom.sphere.center.x = .5;
	objs[0].geom.sphere.center.y = .8;
	objs[0].geom.sphere.center.z = 4;//4
	objs[0].geom.sphere.radius = .5;
	objs[0].type = 0;
	objs[0].intersect = &intersect_Sphere;
	objs[0].color.r = .8;
	objs[0].color.g = 0; 
	objs[0].color.b = 0;

	objs[1].geom.sphere.center.x = -.5;
	objs[1].geom.sphere.center.y = .15;
	objs[1].geom.sphere.center.z = 4.2;
	objs[1].geom.sphere.radius = .6;
	objs[1].type = 1;
	objs[1].intersect = &intersect_Sphere;
	objs[1].color.r = 0;
	objs[1].color.g = .8;
	objs[1].color.b = 0;
	

	objs[2].geom.plane.normal.x = 0;
	objs[2].geom.plane.normal.y = 1;
	objs[2].geom.plane.normal.z = 0;
	objs[2].geom.plane.d = .9;
	objs[2].intersect = &intersect_plane;
	objs[2].type = 2;
}

//The trace function to find the closest intersect and call the light function. Returns the color
COLOR_T trace(PV_T source, RAY_T ray, PV_T intersect, PV_T normal, OBJ_T objs[])
{
	COLOR_T color = {0.3, 0.3, 0.5};
	double closest_t = 1000;
	double T;
	int closest_obj = -1;
	int i;

	PV_T closest_int, closest_normal;

	for(i = 0; i < MAX_OBJS; i++)
	{
		if(objs[i].intersect(ray, objs[i], &intersect, &normal, &T))
		{
			if(T < closest_t)
			{
				closest_t = T;
				closest_obj = i;
				closest_int = intersect;
				closest_normal = normal;
			}
		}
	}
	
	if(closest_obj >= 0)
	{
		

		color = light(source, closest_int, closest_normal, ray, objs[closest_obj].color, objs, closest_obj, T);
	}
	
	return color;
}











