// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#ifndef OBJECT_H
#define OBJECT_H

#include "ray.h"
#include "Vector3D.h"

class OBJECT{
protected:
	COLOR_T color, color2;
	bool checker;
	//double reflection;

public:
	double reflection;
	virtual bool intersect (RAY_T ray, Vector3D *int_pt, Vector3D *normal, double *t) {};
	COLOR_T get_color(Vector3D int_pt);
	void set_color(COLOR_T color);
	void set_color(COLOR_T color, COLOR_T color2);
	void set_checker(bool checker);
	double get_reflection();
};

#endif
