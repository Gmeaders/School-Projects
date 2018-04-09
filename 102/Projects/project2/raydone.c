/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	5/21/15
	Project 1
	Ray.c
*/
#include <stdio.h>
#include <math.h>
#include "ray.h"
#include "vector.h"

int intersect_plane(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T);
int shadow(PV_T source, PV_T intersect, int closest, OBJ_T objs[], PV_T normal, double T;);

void init(OBJ_T objs[])
{
	//Creating and setting the Spheres

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

int main()
{
	
	 //when call use &int_pt
	//making the variables to use later
	int w = 640;
	int h = 480;
	int x = 0;
	int y = 0;
	int intercept;
	unsigned char red;
	unsigned char blue;	//Characters for the color
	unsigned char green;
	int i = 0;

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

//function for making normal line and finding intercepts with calculations from class.
int intersect_Sphere(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T)
{
	//variables that will be used for computing the intersect.
	double a = 1;
	double b;
	double c;
	double t1;	//The lower of the positive T will be used after calculated
	double t0;           
	
	//calculating B
	b = 2 * ((ray.direction.x * (ray.origin.x - obj.geom.sphere.center.x)) + 
		(ray.direction.y * (ray.origin.y - obj.geom.sphere.center.y)) + 
		(ray.direction.z * (ray.origin.z - obj.geom.sphere.center.z)));
	
	//calculating C
	c = (pow(ray.origin.x - obj.geom.sphere.center.x, 2) + pow(ray.origin.y -
	     obj.geom.sphere.center.y, 2) + pow(ray.origin.z - obj.geom.sphere.center.z, 2) -
	     pow(obj.geom.sphere.radius, 2));

	//Checking that the 2nd part of quadratic is not negative
	if((b * b) - (4 * a * c) < 0 )
	{
		return 0;
	}
	
	//Calculating T1 and T0 with quadratic equation
	t0 = ((-b - sqrt((b * b) - (4 * a * c))) / 2.0);
	t1 = ((-b + sqrt((b * b) - (4 * a * c))) / 2.0);
	
	//Checking that t1 and t0 are not negative
	if( t1 < 0 && t0 < 0)
	{
		return 0; //returning 0 to show that there was no intersect and should print background
	}
	
	if(t1 < 0 && t0 > 0) //checks for the one that isn't negative
	{
		*T = t0;
	}

	if(t1 > 0 && t0 < 0) // Checks for the one that isn't negative.
	{
		*T = t1;
	}

	if(t1 > t0)    //Checks for which one is the smaller and uses it.
	{
		*T = t0;
	}
	
	else	//uses the other 
	{ 
		*T = t1;
	}
	
	int_pt->x = ray.origin.x + (ray.direction.x * *T);
	int_pt->y = ray.origin.y + (ray.direction.y * *T);
	int_pt->z = ray.origin.z + (ray.direction.z * *T);
	
	//calculating normal line.
	normal->x = ((int_pt->x - obj.geom.sphere.center.x)/obj.geom.sphere.radius);
	normal->y = ((int_pt->y - obj.geom.sphere.center.y)/obj.geom.sphere.radius);
	normal->z = ((int_pt->z - obj.geom.sphere.center.z)/obj.geom.sphere.radius);
	return 1;

}

//function for getting the lighting with formulas from class
COLOR_T light(PV_T source, PV_T int_pt, PV_T normal, RAY_T ray, COLOR_T object_color, OBJ_T objs[], int closest, double T)
{
	PV_T L;   //This is for diffuse
	PV_T R;	  //This is for specular
	COLOR_T new;
	PV_T distance;
	double Dl;
	double atten;
	double c1 = .002;
	double c2 = .02;
	double c3 = .2;

	distance.x = source.x - int_pt.x;
	distance.y = source.y - int_pt.y;
	distance.z = source.z - int_pt.z;

	Dl = sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2));
	//fprintf(stderr, "%lf", Dl);

	atten = 1/((c1 * pow(Dl, 2)) + (c2 * Dl) + c3);
	if( atten > 1)
	{
		atten = 1;
	}
	//fprintf(stderr, "%lf", atten);

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

	new.r = (object_color.r * 0.1);
	new.g = (object_color.g * 0.1); //making the ambient light.
	new.b = (object_color.b * 0.1);

	if((shadow(source, int_pt, closest, objs, normal, T)) == 0)
	{

		//Calculating L and then normalizing 					
		L.x = source.x - int_pt.x;
		L.y = source.y - int_pt.y;
		L.z = source.z - int_pt.z;
		L = normalize(L);

		//Calculating and normalizing R for the specular lighting
		R.x = (L.x - (2 * (dot(normal, L) * normal.x)));
		R.y = (L.y - (2 * (dot(normal, L) * normal.y)));
		R.z = (L.z - (2 * (dot(normal, L) * normal.z)));
		R = normalize(R);
	
		//checking if dot product is above 0 to use for diffused ligthing
		if(dot(normal, L) > 0)
		{
			new.r += (dot(normal, L) * object_color.r * atten);
			new.g += (dot(normal, L) * object_color.g * atten);
			new.b += (dot(normal, L) * object_color.b * atten);
		
			//If the dot product for R vector is above 1 do the specular lighting
			if(dot(ray.direction, R) > 0)
			{
				new.r += pow(dot(ray.direction, R), 100);
				new.g += pow(dot(ray.direction, R), 100);
				new.b += pow(dot(ray.direction, R), 100);
			}
	
		}
	}	

	return new;

}

COLOR_T trace(PV_T source, RAY_T ray, PV_T intersect, PV_T normal, OBJ_T objs[])
{
	COLOR_T color = {0.3, 0.3, 0.5};
	double closest_t = 1000;
	int closest_obj = -1;
	PV_T closest_int, closest_normal;
	double T;
	int i;

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

int intersect_plane(RAY_T ray, OBJ_T obj, PV_T *int_pt, PV_T *normal, double *T)
{
	double d;
	PV_T N;
	
	d = obj.geom.plane.d;
	N = obj.geom.plane.normal;
	
	if(dot(N, ray.direction) == 0)
	{
		return 0;
	}
	
	*T = (-(dot(N, ray.origin) + d))/(dot(N, ray.direction));

	if(*T < 0)
	{
		return 0;
	}
	else
	{
		int_pt->x = ray.origin.x + (ray.direction.x * *T);
		int_pt->y = ray.origin.y + (ray.direction.y * *T);
		int_pt->z = ray.origin.z + (ray.direction.z * *T);
		*normal = obj.geom.plane.normal;
		
		return 1;
	}
}

int shadow(PV_T source, PV_T intersect, int closest, OBJ_T objs[], PV_T normal, double T)
{
	RAY_T shadow_ray;
	shadow_ray.direction.x = source.x - intersect.x;
	shadow_ray.direction.y = source.y - intersect.y;
	shadow_ray.direction.z = source.z - intersect.z;
	shadow_ray.direction = normalize(shadow_ray.direction);
	shadow_ray.origin = intersect;
	int i;
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















