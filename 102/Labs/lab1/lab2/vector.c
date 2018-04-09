/**********************************************************************
vector.c
**********************************************************************/
#include "vector.h"

//Find the length (magnitude) of the vector
//Square x, y, and z and return the square root
double vec_len(vector_t v)
{
	double ans;
	ans = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	return ans;
}

//subtraction: x1 - x2, y1-y2, z1-z2
//return a new vector with new results
vector_t  vec_subtract (vector_t  v1, vector_t  v2)
{
	vector_t v3;
	v3.x = (v1.x - v2.x);
	v3.y = (v1.y - v2.y);
	v3.z = (v1.z - v2.z);
	return v3;
}

//Take each x, y , and z and divide by the length for each
//ex. newX = x/vec.len(v)
vector_t  vec_normalize (vector_t v)
{
	vector_t ret_v;
	double len;
	len = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	ret_v.x = v.x / len;
	ret_v.y = v.y / len;
	ret_v.z = v.z / len;
	
	return ret_v;
	
}

//Multiply x,y,and z by a constant called 'scale'
vector_t  vec_scale (vector_t v,  double scale)
{
	vector_t mult;	
	mult.x = v.x * scale;
	mult.y = v.y * scale;
	mult.z = v.z * scale;
	return mult;
}

//Same as yesterday, but printing vectors instead.
void vec_print (char  *label, vector_t v)
{
	printf("%s: %8.3lf %8.3lf %8.3lf", label, v.x, v.y, v.z);
}

//Dot product
//Multiply x1*x2, y1*y2, z1*z2, and then sum all the results
double    vec_dot (vector_t v1, vector_t v2)
{
	double v3;
	v3 = ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
	return v3;
}

//Add two vectors x1+x2, y1+y2, z1+z2
vector_t  vec_add (vector_t  v1, vector_t  v2)
{
	vector_t v3;
	v3.x = (v1.x + v2.x);
	v3.y = (v1.y + v2.y);
	v3.z = (v1.z + v2.z);
	return v3;
}

//Copy vector into another
void      vec_copy (vector_t *result_v, vector_t v){
	result_v->x = v.x;
  	result_v->y = v.y;
	result_v->z = v.z;	
}


