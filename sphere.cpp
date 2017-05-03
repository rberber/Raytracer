// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#include "sphere.h"
#include <math.h>

SPHERE::SPHERE(double x, double y, double z, double radius, double reflection)
  {
    center = Vector3D(x, y, z);
    this->radius = radius;
    this -> reflection = reflection;
  }

bool SPHERE::intersect(RAY_T ray, Vector3D *int_pt, Vector3D *normal, double *t)
{
   double A, B, C;
   double disc, t_0, t_1;
   Vector3D temp1;

   A = 1;

   temp1 = ray.origin - center;
   B = 2 * (temp1.dot_product(ray.dir));

   C = temp1 * temp1 - radius * radius;
   
   disc = (B * B) - 4 * A * C;

   //Check for positive discriminant
   if(disc<0)
   {
      return(false);
   }

   //Calculate quadratic formula
   t_0 = (-B - sqrt((B * B) - 4 * A * C)) /( 2 * A);
   t_1 = (-B + sqrt((B * B) - 4 * A * C)) / (2 * A);
         
   //Find smaller positive value of t_0 or t_1 to store as 't'
   if(t_0 < 0 && t_1 < 0)
   {
      return(false);
   }
   else
   {
      if(t_1 < 0)
      {
         *t = t_0;
      }
      else if(t_0 < 0)
      {
         *t = t_1;
      }
      else if(t_0 < t_1)
      {
         *t = t_0;
      }
      else
      {
         *t = t_1;
      }
   }
 
   //Calculate the intersection point
   *int_pt = ray.origin + ray.dir * *t;


   //Calculate the normal at the intersection point
   *normal = (*int_pt - center) / radius;

   return(true);
}
