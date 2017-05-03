// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#ifndef SPHERE_H
#define SPHERE_H

#include "ray.h"
#include "Vector3D.h"
#include "object.h"

class SPHERE : public OBJECT{
private:
	Vector3D center;
	double radius;

public:
	SPHERE(double x, double y, double z, double radius, double reflection);

	bool intersect(RAY_T ray, Vector3D *int_pt, Vector3D *normal, double *t);
};

#endif 
