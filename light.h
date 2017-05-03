// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#ifndef LIGHT_H
#define LIGHT_H

#include "ray.h"
#include "Vector3D.h"
#include "object.h"

class LIGHT {
private:
	Vector3D location, direction;

	bool shadow_test(OBJECT *objs[], int closest_i, 
                       Vector3D closest_int_pt);

public:
	LIGHT();

	void set_location(double x, double y, double z);
	COLOR_T illuminate(OBJECT *objs[], int closest_i, Vector3D normal, 
                     Vector3D int_pt, RAY_T ray, COLOR_T color);
};
#endif 
