/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	5/21/15
	Project 1
	Ray.c
*/
#include "ray.h"
#include "vector.h"

int main()
{
	
	PV_T int_pt; //when call use &int_pt
	//making the variables to use later
	int w = 500;
	int h = 500;
	int x = 0;
	int y = 0;
	int intercept;
	unsigned char red;
	unsigned char blue;	//Characters for the color
	unsigned char green;
	
	//3 things to be used for later calculations
	PV_T center;
	RAY_T ray;
	PV_T normal;

	//making the color that will be changed by lighting
	COLOR_T object_color = {0, 0, 0};

	//Making a seperate color that will stay red
	COLOR_T default_color = {1, 0, 0};

	//Creating and setting the Sphere
	SPHERE_T sphere;
	sphere.center.x = 0;
	sphere.center.y = 0;
	sphere.center.z = 10;
	sphere.radius = 3;

	//Creating and setting the light source
	PV_T lighting;
	lighting.x = -10;
	lighting.y = 10;
	lighting.z = 5;
	
	//write out ppm header
	printf("P6\n%i %i\n255\n", h, w);

	//for each pixel
	for(y = 0; y < w; y++)
	{
		for(x = 0; x < h; x++)
		{
			//compute the ray origin and direction
			ray.origin.x = 0;
			ray.origin.y = 0;
			ray.origin.z = 0;

			//calculations for ray direction
			double x3d = (-0.5 + (x/500.0));
			double y3d = (0.5 - (y/500.0));

			//Setting the ray direction to the calculations
			ray.direction.x = x3d;
			ray.direction.y = y3d;
			ray.direction.z = 1;

			//normalise ray direction (use normalize function)	
			ray.direction = Normalize(ray.direction);
			
			//Getting the intercept points on the sphere			
			intercept = intersect_Sphere(ray, sphere, &int_pt, &normal);

			//if intercept = 1 print shade of red, else print black
			if(intercept == 1)
			{	
				//Get the color from the lighting function
				object_color = light(lighting, int_pt, normal, ray, default_color);

				//cap color, if its greater than 1 set back to 1
				if (object_color.r > 1)
					object_color.r = 1;
				if (object_color.g > 1)
					object_color.g = 1;
				if (object_color.b > 1)
					object_color.b = 1;
				//Set the colors back to characters to be used in the printf statement
				red = (unsigned char)(object_color.r * 255);
				green = (unsigned char)(object_color.g * 255);
				blue = (unsigned char)(object_color.b * 255);

				//printf("%c%c%c", red, blue, green); // prints the color. 
			}
			//else
				//printf("%c%c%c", 0, 0, 0);  // prints the black background.

		}

	}
		
		return 0;
}

//function for making normal line and finding intercepts with calculations from class.
int intersect_Sphere(RAY_T ray, SPHERE_T sphere, PV_T *int_pt, PV_T *normal)
{
	//variables that will be used for computing the intersect.
	double a = 1;
	double b;
	double c;
	double t1;	//The lower of the positive T will be used after calculated
	double t0;           
	
	//calculating B
	b = 2 * ((ray.direction.x * (ray.origin.x - sphere.center.x)) + 
		(ray.direction.y * (ray.origin.y - sphere.center.y)) + 
		(ray.direction.z * (ray.origin.z - sphere.center.z)));
	
	
	//calculating C
	c = (pow(ray.origin.x - sphere.center.x, 2) + pow(ray.origin.y -
	     sphere.center.y, 2) + pow(ray.origin.z - sphere.center.z, 2) -
	     pow(sphere.radius, 2));
	printf("%lf\n", b);

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
		return 0; //returning 0 to show that there was no intersect and should print black
	}
	
	if(t1 < 0 && t0 > 0) //checks for the one that isn't negative
	{
		int_pt->x = ray.origin.x + (ray.direction.x * t0);
		int_pt->y = ray.origin.y + (ray.direction.y * t0);
		int_pt->z = ray.origin.z + (ray.direction.z * t0);
	}

	if(t1 > 0 && t0 < 0) // Checks for the one that isn't negative.
	{
		int_pt->x = ray.origin.x + (ray.direction.x * t1);
		int_pt->y = ray.origin.y + (ray.direction.y * t1);
		int_pt->z = ray.origin.z + (ray.direction.z * t1);
	}

	if(t1 > t0)    //Checks for which one is the smaller and uses it.
	{
		int_pt->x = ray.origin.x + (ray.direction.x * t0);
		int_pt->y = ray.origin.y + (ray.direction.y * t0);
		int_pt->z = ray.origin.z + (ray.direction.z * t0);
	}
	
	else	//uses the other 
	{ 
		int_pt->x = ray.origin.x + (ray.direction.x * t1);
		int_pt->y = ray.origin.y + (ray.direction.y * t1);
		int_pt->z = ray.origin.z + (ray.direction.z * t1);
	}
	
	//calculating normal line.
	normal->x = ((int_pt->x - sphere.center.x)/sphere.radius);
	normal->y = ((int_pt->y - sphere.center.y)/sphere.radius);
	normal->z = ((int_pt->z - sphere.center.z)/sphere.radius);
	return 1;

}

//function for getting the lighting with formulas from class
COLOR_T light(PV_T source, PV_T int_pt, PV_T normal, RAY_T ray, COLOR_T object_color)
{
	PV_T L;   //This is for diffuse
	PV_T R;	  //This is for specular
	COLOR_T new;

	new.r = (object_color.r * 0.1);
	new.g = (object_color.g * 0.1); //making the ambient light.
	new.b = (object_color.b * 0.1);
					//starting diffused light.

	//Calculating L and then normalizing 					
	L.x = source.x - int_pt.x;
	L.y = source.y - int_pt.y;
	L.z = source.z - int_pt.z;
	L = Normalize(L);

	//Calculating and normalizing R for the specular lighting
	R.x = (L.x - (2 * (dot(normal, L) * normal.x)));
	R.y = (L.y - (2 * (dot(normal, L) * normal.y)));
	R.z = (L.z - (2 * (dot(normal, L) * normal.z)));
	R = Normalize(R);
	
	//checking if dot product is above 0 to use for diffused ligthing
	if(dot(normal, L) > 0)
	{
		new.r += (dot(normal, L) * object_color.r);
		new.g += (dot(normal, L) * object_color.g);
		new.b += (dot(normal, L) * object_color.b);
	
		//If the dot product for R vector is above 1 do the specular lighting
		if(dot(ray.direction, R) > 0)
		{
			new.r += pow(dot(ray.direction, R), 100);
			new.g += pow(dot(ray.direction, R), 100);
			new.b += pow(dot(ray.direction, R), 100);
		}
	
	}	

	return new;

}









