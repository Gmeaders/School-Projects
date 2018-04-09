/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/17/14
	Project 4
	light.h
*/ 
#ifndef LIGHT_H
#define LIGHT_H

class LIGHT
{

	VECTOR source;

public:
	LIGHT() {};

	LIGHT(VECTOR location)
	{
		this->source = location;
	}

	COLOR_T light(VECTOR int_pt, VECTOR normal, RAY_T ray, COLOR_T object_color);
};


#endif
