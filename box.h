// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#ifndef BOX_H
#define BOX_H

#include "ray.h"
#include "Vector3D.h"
#include "object.h"

class BOX : public OBJECT{
private:
	Vector3D lowl;
	Vector3D upr;

public:
	BOX(void);
	BOX(double xl, double yl, double zl, double xu, double yu, double zu);
	bool intersect(RAY_T ray, Vector3D *int_pt,
                       Vector3D *normal, double *t);

};

#endif 

