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
#include "box.h"

int main()
{
	int w = 1024;
	int h = 768;
	int x = 0;
	int y = 0;
	int level = 0;
	unsigned char red;
	unsigned char blue;	
	unsigned char green;

	RAY_T ray;
	PV_T normal;
	PV_T int_pt;
	OBJ_T objs[MAX_OBJS];
	LIGHT_T lights[MAX_LIGHTS];
	init(objs, lights);

	//making the color that will be changed by lighting
	COLOR_T obj_color = {0, 0, 0};


	//Creating and setting the light source
	PV_T lighting;
	lighting.x = -10;
	lighting.y = 10;
	lighting.z = -5;
	
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
			ray.direction.x = (-0.67 + (x/768.0));
			ray.direction.y = (0.5 - (y/768.0));
			ray.direction.z = 1;

			//normalise ray direction (use normalize function)	
			ray.direction = normalize(ray.direction);
			
			obj_color = trace(lights, ray, int_pt, normal, objs, level);
	
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
void init(OBJ_T objs[], LIGHT_T lights[])
{
	objs[0].geom.sphere.center.x = .5;
	objs[0].geom.sphere.center.y = .8;
	objs[0].geom.sphere.center.z = 4;
	objs[0].geom.sphere.radius = .5;
	objs[0].intersect = &intersect_Sphere;
	objs[0].color.r = .8;
	objs[0].color.g = 0; 
	objs[0].color.b = 0;
	objs[0].reflect = 0.7;
	objs[0].getcolor = &solid;

	objs[1].geom.sphere.center.x = -.5;
	objs[1].geom.sphere.center.y = .15;
	objs[1].geom.sphere.center.z = 4.2;
	objs[1].geom.sphere.radius = .6;
	objs[1].intersect = &intersect_Sphere;
	objs[1].color.r = 0;
	objs[1].color.g = .8;
	objs[1].color.b = 0;
	objs[1].reflect = 0.0;
	objs[1].getcolor = &solid;
	

	objs[2].geom.plane.normal.x = 0;
	objs[2].geom.plane.normal.y = 1;
	objs[2].geom.plane.normal.z = 0;
	objs[2].geom.plane.d = .9;
	objs[2].intersect = &intersect_plane;
	objs[2].reflect = 0.1;
	objs[2].getcolor = &checker;

	objs[3].geom.box.ll.x = 0.3;
	objs[3].geom.box.ll.y = -0.6;
	objs[3].geom.box.ll.z = 2.3;
	objs[3].geom.box.ur.x = 0.7;
	objs[3].geom.box.ur.y = -0.2;
	objs[3].geom.box.ur.z = 3;
	objs[3].intersect = &intersect_box;
	objs[3].reflect = 0.0;
	objs[3].color.r = 0;
	objs[3].color.g = 0;
	objs[3].color.b = 1;
	objs[3].getcolor = &solid;

	lights[0].light_location.x = -10;
	lights[0].light_location.y = 10;
	lights[0].light_location.z = -5;
	lights[0].light_color.r = 0.7;
	lights[0].light_color.g = 0.7;
	lights[0].light_color.b = 0.7;

	lights[1].light_location.x = 0;
	lights[1].light_location.y = 10;
	lights[1].light_location.z = -10;
	lights[1].light_color.r = 1;
	lights[1].light_color.g = 1;
	lights[1].light_color.b = 1;
	
}

//The trace function to find the closest intersect and call the light function. Returns the color
COLOR_T trace(LIGHT_T lights[], RAY_T ray, PV_T intersect, PV_T normal, OBJ_T objs[], int level)
{
	COLOR_T color = {0.3, 0.3, 0.5};
	COLOR_T object_color;
	COLOR_T final_color;
	COLOR_T ref_color;
	COLOR_T black = {0, 0, 0};
	double closest_t = 1000;
	double T;
	int closest_obj = -1;
	int i, j;
	PV_T R;
	RAY_T new_ray;
	
	level = 0;

	final_color = color;

	PV_T closest_int, closest_normal;

	if(level > MAX_LEVEL)
	{
		return black;
	}

	for(i = 0; i < MAX_OBJS; i++)
	{
		if(objs[i].intersect(ray, objs[i], &intersect, &normal, &T))
		{
			if(T > .01)
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
	}

	if(closest_obj >= 0)
	{
		
		for(j = 0; j < MAX_LIGHTS; j++)
		{
			if(objs[closest_obj].reflect > 0)
			{

				R.x = (ray.direction.x - (2 * (dot(normal, ray.direction) * normal.x)));
				R.y = (ray.direction.y - (2 * (dot(normal, ray.direction) * normal.y)));
				R.z = (ray.direction.z - (2 * (dot(normal, ray.direction) * normal.z)));
				R = normalize(R);

				new_ray.origin.x = intersect.x;
				new_ray.origin.y = intersect.y;
				new_ray.origin.z = intersect.z;
				new_ray.direction.x = R.x;
				new_ray.direction.y = R.y;
				new_ray.direction.z = R.z;
				
				ref_color = trace(lights, new_ray, intersect, normal, objs, level + 1);
			}

			object_color = objs[closest_obj].getcolor(objs[closest_obj], intersect);
			color = light(lights, closest_int, closest_normal, ray, object_color, objs, closest_obj, T);
		}
	
		final_color.r = ref_color.r * objs[closest_obj].reflect + color.r * (1 - objs[closest_obj].reflect);
		final_color.g = ref_color.g * objs[closest_obj].reflect + color.g * (1 - objs[closest_obj].reflect);
		final_color.b = ref_color.b * objs[closest_obj].reflect + color.b * (1 - objs[closest_obj].reflect);
	}
	return final_color;
}











