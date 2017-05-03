// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#ifndef PLANE_H
#define PLANE_H

#include "ray.h"
#include "Vector3D.h"
#include "object.h"

class PLANE : public OBJECT{
private:
	Vector3D normal;
	double D;

public:
PLANE(void);
PLANE(double x, double y, double z, double D, double reflection);
bool intersect(RAY_T ray, Vector3D *int_pt,
                       Vector3D *normal, double *t);

};

#endif 
