/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/17/14
	Project 4
	vector.cpp
*/
#include "ray.h"
#include "vector.h"
#include <math.h>

VECTOR VECTOR::normalize()
{
	double len;
	len = sqrt( x * x + y * y + z * z);
	
	x /= len;
	y /= len;
	z /= len;
	
	return *this;
}

VECTOR VECTOR::add(VECTOR v2)
{
	VECTOR v3;
	v3.x = x + v2.x;
	v3.y = y + v2.y;
	v3.z = z + v2.z;
	return v3;
}

VECTOR VECTOR::operator+(VECTOR v2)
{
	return(this->add(v2));
}

VECTOR VECTOR::scalar_divide(double s)
{
	VECTOR divide;	
	divide.x = x / s;
	divide.y = y / s;
	divide.z = z / s;
	return divide;
}

VECTOR VECTOR::operator/(double s)
{
	return(this->scalar_divide(s));
}

VECTOR VECTOR::scalar_mult(double s)
{
	VECTOR mult;	
	mult.x = x * s;
	mult.y = y * s;
	mult.z = z * s;
	return mult;
}

VECTOR VECTOR::operator* (double s)
{
	return(this->scalar_mult(s));
}

double VECTOR::dot(VECTOR v2)
{
	return(x * v2.x + y * v2.y + z * v2.z);
}

double VECTOR::calculate_b(VECTOR v2)
{
	double ret;
	ret = 2 * ((x * (v2.x)) + (y * (v2.y)) + (z * (v2.z)));
	return ret;
}

double VECTOR::calculate_c(VECTOR v2, double r)
{
	double ret;
	ret = pow(x - v2.x, 2) + pow(y - v2.y, 2) + pow(z - v2.z, 2) - pow(r, 2);
	return ret;
}

VECTOR VECTOR::calculate_r(VECTOR normal, double temp)
{
	VECTOR v3;
	v3.x = (x - (2 * temp * normal.x));
	v3.y = (y - (2 * temp * normal.y));
	v3.z = (z - (2 * temp * normal.z));
	return v3; 
} 

double VECTOR::length(void)
{
	return sizeof(this);
}

VECTOR VECTOR::multiply(VECTOR v2)
{
	VECTOR v3;
	
	v3.x = x * v2.x;
	v3.y = y * v2.y;
	v3.z = z * v2.z;

	return v3;
}

VECTOR VECTOR::operator*(VECTOR v2)
{
	return(this->multiply(v2));
}

VECTOR VECTOR::subtract (VECTOR v2)
{
	VECTOR v3;
	v3.x = (x - v2.x);
	v3.y = (y - v2.y);
	v3.z = (z - v2.z);
	return v3;
}

VECTOR VECTOR::operator- (VECTOR v2)
{
	return(this->subtract(v2));
}




