/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/12/14
	Project 3
	Ray.c
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "ray.h"
#include "vector.h"
#include "light.h"
#include "plane.h"
#include "sphere.h"
#include "box.h"

//Function to initialize all objects
static void init(SCENE_T *scene, IMG_T *img, char *filename)
{
	int i;
	FILE *fp;
	char line[100];
	char token[20];

	OBJ_T *new_obj;
	LIGHT_T *new_light;
	
	if((fp = fopen(filename, "r")) == NULL)
	{
		printf("File not found");
		exit (0);	
	}
	
	scene->objs = NULL;
	scene->light = NULL;

	while(fgets(line, 100, fp) != NULL)
	{
		token[0] = '\0';
		sscanf(line, "%s", token);
		
		if(strcmp(token, "width") == 0)
		{
			fgets(line, 100, fp);
			sscanf(line, "%d", &img->width);
			
		}
		
		if(strcmp(token, "height") == 0)
		{
			fgets(line, 100, fp);
			sscanf(line, "%d", &img->height);
			
		}  
		
		if(strcmp(token, "background") == 0)
		{
			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &scene->background.r, 
			&scene->background.g, &scene->background.b);
		}  
		
		if(strcmp(token, "sphere") == 0)
		{
			new_obj = (OBJ_T *)malloc(sizeof(OBJ_T));
			fgets(line, 100, fp);

			sscanf(line, "%lf %lf %lf", &new_obj->geom.sphere.center.x,
			&new_obj->geom.sphere.center.y, &new_obj->geom.sphere.center.z);

			fgets(line, 100, fp);
			sscanf(line, "%lf", &new_obj->geom.sphere.radius);

			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &new_obj->color.r, &new_obj->color.g, &new_obj->color.b);

			fgets(line, 100, fp);
			sscanf(line, "%lf", &new_obj->reflect);

			new_obj->getcolor = solid;
			new_obj->intersect = intersect_Sphere;
			new_obj->next = scene->objs;
			scene->objs = new_obj;	
		}  

		if(strcmp(token, "plane") == 0)
		{
			new_obj = (OBJ_T *)malloc(sizeof(OBJ_T));

			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &new_obj->geom.plane.normal.x,
			&new_obj->geom.plane.normal.y, &new_obj->geom.plane.normal.z);

			fgets(line, 100, fp);
			sscanf(line, "%lf", &new_obj->geom.plane.d);

			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &new_obj->color.r, &new_obj->color.g, &new_obj->color.b);

			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &new_obj->color2.r, &new_obj->color2.g, &new_obj->color2.b);

			fgets(line, 100, fp);
			sscanf(line, "%lf", &new_obj->reflect);

			new_obj->getcolor = checker;
			new_obj->intersect = intersect_plane;
			new_obj->next = scene->objs;
			scene->objs = new_obj;		
		}  
		
		if(strcmp(token, "box") == 0)
		{
			new_obj = (OBJ_T *)malloc(sizeof(OBJ_T));

			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &new_obj->geom.box.ll.x,
			&new_obj->geom.box.ll.y, &new_obj->geom.box.ll.z);

			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &new_obj->geom.box.ur.x,
			&new_obj->geom.box.ur.y, &new_obj->geom.box.ur.z);

			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &new_obj->color.r, &new_obj->color.g, &new_obj->color.b);

			fgets(line, 100, fp);
			sscanf(line, "%lf", &new_obj->reflect);

			new_obj->getcolor = solid;
			new_obj->intersect = intersect_box;
			new_obj->next = scene->objs;
			scene->objs = new_obj;	
		}  
	
		if(strcmp(token, "light") == 0)
		{
			new_light = (LIGHT_T *)malloc(sizeof(LIGHT_T));

			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &new_light->light_location.x,
			&new_light->light_location.y, &new_light->light_location.z);

			fgets(line, 100, fp);
			sscanf(line, "%lf %lf %lf", &new_light->light_color.r,
			&new_light->light_color.g, &new_light->light_color.b);

			new_light->next = scene->light;
			scene->light = new_light;
		} 	
	}
	
	
	img->img = (COLOR_T**)malloc(img->height*sizeof(COLOR_T*));
	for(i = 0; i < img->width; i++)
	{
		img->img[i] = (COLOR_T*)malloc(img->width*sizeof(COLOR_T));
	}
	fclose(fp);
}

//The trace function to find the closest intersect and call the light function. Returns the color
static COLOR_T trace(RAY_T ray, PV_T intersect, PV_T normal, SCENE_T scene, int level)
{
	
	COLOR_T color;
	COLOR_T object_color;
	COLOR_T final_color;
	COLOR_T ref_color;
	COLOR_T black = {0, 0, 0};
	
	double closest_t = 1000;
	double T;
	int i, j;
	
	RAY_T new_ray;
	OBJ_T *curr = NULL;
	LIGHT_T *l_curr = NULL;
	OBJ_T *closest_obj = NULL;	
	
	level = 0;

	final_color = scene.background;

	PV_T closest_int; 
	PV_T closest_normal;
	PV_T R;

	if(level > MAX_LEVEL)
	{
		return black;
	}
	
	for(curr = scene.objs; curr != NULL; curr = curr->next)
	{
		if(curr->intersect(ray, *curr, &intersect, &normal, &T))
		{
			if(T > .01)
			{
				if(T < closest_t)
				{
					closest_t = T;
					closest_obj = curr;
					closest_int = intersect;
					closest_normal = normal;
					
				}
			}
		}
	}
	if(closest_obj != NULL)
	{
		//For each light source
		for(l_curr = scene.light; l_curr != NULL; l_curr = l_curr->next)
		{
			if(closest_obj->reflect > 0)
			{
				//Reflection ray
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
				
				ref_color = trace(new_ray, intersect, normal, scene, level + 1);	
			}

			object_color = closest_obj->getcolor(*closest_obj, closest_int);
			color = light(closest_int, closest_normal, ray, object_color, scene, closest_obj, T);
		}

		final_color.r = ref_color.r * closest_obj->reflect + color.r * (1 - closest_obj->reflect);
		final_color.g = ref_color.g * closest_obj->reflect + color.g * (1 - closest_obj->reflect);
		final_color.b = ref_color.b * closest_obj->reflect + color.b * (1 - closest_obj->reflect);
	
	}

	return final_color;
}

int main(int argc, char *argv[])
{
	int x = 0;
	int y = 0;
	int level = 0;
	unsigned char red;
	unsigned char blue;	
	unsigned char green;
	FILE * filepointer;
	char filename[20];
	char out[20];
	RAY_T ray;
	PV_T normal;
	PV_T int_pt;
	SCENE_T scene;
	IMG_T img;
	FILE * outfile;
	
	
	if(argc == 1)
	{
		sprintf(filename, "scene.txt");
		sprintf(out, "img.ppm");

	}
	else if(argc == 2)
	{
		sprintf(filename, "%s", argv[1]);
		sprintf(out, "img.ppm");
		//opening the ppm image for writing
		filepointer = fopen(argv[2], "w");
	}
	else if(argc == 3)
	{
		sprintf(filename, "%s", argv[1]);
		sprintf(out, "%s", argv[2]);
	}

	filepointer = fopen(out, "w");

	
	init(&scene, &img, filename);
	
	//getting x_start, y_start, and pixel width
	scene.x_start = ((-(float)img.width / (float)img.height)/2);
	scene.y_start = .5;
	scene.pixel_width = img.height;

	//making the color that will be changed by trace
	COLOR_T obj_color = {0, 0, 0};

	//write out ppm header
	fprintf(filepointer, "P6\n%i %i\n255\n", img.width, img.height);

	//for each pixel
	for(y = 0; y < img.height; y++)
	{
		for(x = 0; x < img.width; x++)
		{
			//compute the ray origin and direction
			ray.origin.x = 0;
			ray.origin.y = 0;
			ray.origin.z = 0;

			//calculations for ray direction
			ray.direction.x = (scene.x_start + ((double)x/ scene.pixel_width));
			ray.direction.y = (scene.y_start - ((double)y/ scene.pixel_width));
			ray.direction.z = 1;

			//normalise ray direction (use normalize function)	
			ray.direction = normalize(ray.direction);
			
			obj_color = trace(ray, int_pt, normal, scene, level);

			
			if (obj_color.r > 1)
				obj_color.r = 1;
			if (obj_color.g > 1)
				obj_color.g = 1;
			if (obj_color.b > 1)
				obj_color.b = 1;

			img.img[y][x].r = obj_color.r;
			img.img[y][x].g = obj_color.g;
			img.img[y][x].b = obj_color.b;
			
			//Set the colors back to characters to be used in the printf statement
			red = (unsigned char)(obj_color.r * 255);
			green = (unsigned char)(obj_color.g * 255);
			blue = (unsigned char)(obj_color.b * 255);

			fprintf(filepointer, "%c%c%c", red, green, blue);
		}
	}
	fclose(filepointer);
	//freeing the linked list
	OBJ_T *curr;
	curr = scene.objs; 
	while(curr != NULL)
	{
		scene.objs = scene.objs->next;
		free(curr);
		curr = scene.objs;
	}

	return 0;
}














