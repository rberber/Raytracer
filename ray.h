// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"
#include <math.h>

typedef struct{
   Vector3D origin;
   Vector3D dir;
} RAY_T;

typedef struct
{
   double r;
   double g;
   double b;  
} COLOR_T;

typedef struct{
	Vector3D normal;
	double D;
} PLANE_T;

#endif
