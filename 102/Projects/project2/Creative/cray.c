/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/1/14
	Project 2 creative
	cRay.c
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "cray.h"
#include "cvector.h"
#include "clight.h"
#include "csphere.h"

int main()
{
	int w = 1024;
	int h = 768;
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
	lighting.x = 0;
	lighting.y = 0;
	lighting.z = 1;
	
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
			ray.direction.x = (-0.67 + (x/728.0));
			ray.direction.y = (0.5 - (y/728.0));
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
	//sun
	objs[0].geom.sphere.center.x = 0.05;
	objs[0].geom.sphere.center.y = 0;
	objs[0].geom.sphere.center.z = 4;//4
	objs[0].geom.sphere.radius = .5;
	objs[0].type = 0;
	objs[0].intersect = &intersect_Sphere;
	objs[0].color.r = 1;
	objs[0].color.g = .66; 
	objs[0].color.b = 0;

	//mercury
	objs[1].geom.sphere.center.x = .18;
	objs[1].geom.sphere.center.y = 0;
	objs[1].geom.sphere.center.z = 1;
	objs[1].geom.sphere.radius = .01;
	objs[1].type = 1;
	objs[1].intersect = &intersect_Sphere;
	objs[1].color.r = 1;
	objs[1].color.g = .5;
	objs[1].color.b = 0;

	//venus
	objs[2].geom.sphere.center.x = .3;
	objs[2].geom.sphere.center.y = 0;
	objs[2].geom.sphere.center.z = 1.3;
	objs[2].geom.sphere.radius = .015;
	objs[2].type = 1;
	objs[2].intersect = &intersect_Sphere;
	objs[2].color.r = .28;
	objs[2].color.g = .28;
	objs[2].color.b = .28;
	
	//earth
	objs[3].geom.sphere.center.x = -.04;
	objs[3].geom.sphere.center.y = 0;
	objs[3].geom.sphere.center.z = .3;
	objs[3].geom.sphere.radius = .01;
	objs[3].type = 1;
	objs[3].intersect = &intersect_Sphere;
	objs[3].color.r = 0;
	objs[3].color.g = 1;
	objs[3].color.b = 0;

	//mars
	objs[4].geom.sphere.center.x = .06;
	objs[4].geom.sphere.center.y = 0;
	objs[4].geom.sphere.center.z = .5;
	objs[4].geom.sphere.radius = .017;
	objs[4].type = 1;
	objs[4].intersect = &intersect_Sphere;
	objs[4].color.r = 1;
	objs[4].color.g = 0;
	objs[4].color.b = 0;

	//jupiter
	objs[5].geom.sphere.center.x = -3;
	objs[5].geom.sphere.center.y = 0;
	objs[5].geom.sphere.center.z = 12;
	objs[5].geom.sphere.radius = .7;
	objs[5].type = 1;
	objs[5].intersect = &intersect_Sphere;
	objs[5].color.r = .95;
	objs[5].color.g = 0.3;
	objs[5].color.b = 0.07;
	
	//saturn
	objs[6].geom.sphere.center.x = 2.5;
	objs[6].geom.sphere.center.y = 0;
	objs[6].geom.sphere.center.z = 12;
	objs[6].geom.sphere.radius = .6;
	objs[6].type = 1;
	objs[6].intersect = &intersect_Sphere;
	objs[6].color.r = .6;
	objs[6].color.g = 0.5;
	objs[6].color.b = 0.07;

	//uranus
	objs[7].geom.sphere.center.x = 0.4;
	objs[7].geom.sphere.center.y = 0;
	objs[7].geom.sphere.center.z = 1;
	objs[7].geom.sphere.radius = .15;
	objs[7].type = 1;
	objs[7].intersect = &intersect_Sphere;
	objs[7].color.r = 0;
	objs[7].color.g = 1;
	objs[7].color.b = 1;
	
	//neptune
	objs[8].geom.sphere.center.x = -.7;
	objs[8].geom.sphere.center.y = 0;
	objs[8].geom.sphere.center.z = .9;
	objs[8].geom.sphere.radius = .2889;
	objs[8].type = 1;
	objs[8].intersect = &intersect_Sphere;
	objs[8].color.r = .1;
	objs[8].color.g = 0;
	objs[8].color.b = 1;

	//pluto R.I.P.
	objs[9].geom.sphere.center.x = 0;
	objs[9].geom.sphere.center.y = -1;
	objs[9].geom.sphere.center.z = .75;
	objs[9].geom.sphere.radius = .8;
	objs[9].type = 1;
	objs[9].intersect = &intersect_Sphere;
	objs[9].color.r = .3;
	objs[9].color.g = .3;
	objs[9].color.b = .3;


}

//The trace function to find the closest intersect and call the light function. Returns the color
COLOR_T trace(PV_T source, RAY_T ray, PV_T intersect, PV_T normal, OBJ_T objs[])
{
	COLOR_T color = {0, 0, 0};
	if((rand()%100) == 1)
	{
		color.r = 1;
		color.g = 1;
		color.b = 1;
	}
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











