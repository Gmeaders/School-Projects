/*
	Greg Meaders
	gmeader@g.clemson.edu
	cpsc 102 summer 2014
	6/12/14
	Project 3
	light.h
*/
#ifndef LIGHT_H
#define LIGHT_H

COLOR_T light(PV_T int_pt, PV_T normal, RAY_T ray, COLOR_T object_color, SCENE_T scene, OBJ_T* closest, double T);
COLOR_T checker(OBJ_T obj, PV_T close);
COLOR_T solid(OBJ_T obj, PV_T int_pt);

#endif
