// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#include "object.h"

COLOR_T OBJECT::get_color(Vector3D int_pt) 
{
	if(checker == 1)
	{
      	if(int_pt.floor_function() & 1)
      	{
         	return(color);
      	}
      	else
      	{
         	return(color2);
      	}
   	}
		return (color);
}

void OBJECT::set_color(COLOR_T color)
{
	this -> color = color;
}

void OBJECT::set_color(COLOR_T color, COLOR_T color2)
{
	this -> color = color;
	this -> color2 = color2;
}

void OBJECT::set_checker(bool checker)
{
	this -> checker = checker;
}

double OBJECT::get_reflection()
{
   return(this-> reflection);
}