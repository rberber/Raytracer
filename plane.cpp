// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#include "plane.h"
#include "object.h"
#include "Vector3D.h"

PLANE::PLANE(void){
   normal = Vector3D(0, 0, 0);
   D = 0;
}
PLANE::PLANE(double x, double y, double z, double D, double reflection){
   normal = Vector3D(x, y, z);
   this -> D = D;
   this -> reflection = reflection;
}

//This function, intersect_plane, first finds if there is an intersection 
//point, and if there is one, it computes the intersection point.
bool PLANE::intersect(RAY_T ray, Vector3D *int_pt,
                       Vector3D *normal, double *t)
{
   double denom;

   denom = this -> normal.dot_product(ray.dir);

   if(denom == 0)
   {
      return(false);
   }

   *t = (-(this->normal.dot_product(ray.origin) + D)) / (denom);

   if(*t <= 0)
   {
      return(false);
   }

   *int_pt = ray.origin + (ray.dir * *t);

   *normal = this->normal;

   return(true);
}
