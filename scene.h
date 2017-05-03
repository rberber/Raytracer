// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#ifndef SCENE_H
#define SCENE_H

#include "ray.h"
#include "object.h"
#include "Vector3D.h"

typedef struct{
	OBJECT *objs[4];
	LIGHT *light;
	int num_objs;
	COLOR_T back_color;
}SCENE_T;

#endif
