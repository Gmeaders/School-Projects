/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/17/14
	Project 4
	Ray.cpp
*/

#include <iostream>
#include "ray.h"
#include "vector.h"
#include "sphere.h"
#include "light.h"

using namespace std;

int main()
{
	int w = 500;
	int h = 500;
	int x = 0;
	int y = 0;
	bool intersect;
	unsigned char red;
	unsigned char blue;	
	unsigned char green;
	unsigned char black = (unsigned char)(0);
	
	RAY_T ray;

	VECTOR int_pt;
	VECTOR normal;
	VECTOR center(0, 0, 10);
	VECTOR location(-10, 10, 5);

	//making the color that will be changed by lighting
	COLOR_T object_color = {0, 0, 0};

	//Making a seperate color that will stay red
	COLOR_T default_color = {1, 0, 0};

	//setting the sphere and light VECTOR
	SPHERE sphere(center, 3.0);
	LIGHT source(location);

	//print out the ppm header
	cout << "P6" << endl << h << " " <<  w << " "  << "255" << endl;

	//for each pixel
	for(y = 0; y < w; y++)
	{
		for(x = 0; x < h; x++)
		{
			ray.origin.set(0, 0, 0);

			//setting the ray direction
			ray.direction.set((-0.5 + (x/500.0)), (0.5 - (y/500.0)), 1);

			//normalise ray direction	
			ray.direction = ray.direction.normalize();
			
			//checking for intersect with the sphere			
			intersect = sphere.intersect(ray, int_pt, normal); 

			//if intersect is true, print shade of red, else print black
			if(intersect == true)
			{	
				//Get the color from the light function
				object_color = source.light(int_pt, normal, ray, default_color);

				//cap color, if its greater than 1 set back to 1
				if (object_color.r > 1)
					object_color.r = 1;
				if (object_color.g > 1)
					object_color.g = 1;
				if (object_color.b > 1)
					object_color.b = 1;

				//Set the colors back to characters to be used in the cout statement
				red = (unsigned char)(object_color.r * 255);
				green = (unsigned char)(object_color.g * 255);
				blue = (unsigned char)(object_color.b * 255);

			
				cout << red << blue << green;
			}
			else 
				cout << black << black << black;

		}

	}
		
		return 0;
}












