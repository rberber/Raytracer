// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#include "light.h"
#include "ray.h"
#include <math.h>
#include "object.h"

LIGHT::LIGHT()
{
	location = Vector3D(0,0,0);
	direction = Vector3D(0,0,0);
}

void LIGHT::set_location(double x, double y, double z)
{
   location = Vector3D(x, y, z);
}

//This function, shadow_test, checks to see if there is any points where
//another object in the scene is blocking it from direct light.
bool LIGHT::shadow_test(OBJECT *objs[], int closest_i, 
                       Vector3D closest_int_pt)
{
   RAY_T ray;
   Vector3D dummy_normal, dummy_int_pt;
   double dummy_t;
   
   ray.origin = closest_int_pt;

   ray.dir = location - ray.origin;

   ray.dir.normal();

   int i = 0;
   for(i = 0; i < 3; i++)
   {
      if (i != closest_i)
      {
         if ((objs[i] -> intersect)(ray, 
              &dummy_int_pt, &dummy_normal, &dummy_t))
         {
            return(true);
         }
      }
   }
   return(false);
}

//This function, do lighting, calculates the three different 
//lighting elements(ambient, diffuse, and specular) and adds 
//them to the scene if they are applicable.
COLOR_T LIGHT::illuminate(OBJECT *objs[], int closest_i, Vector3D normal, 
                     Vector3D int_pt, RAY_T ray, COLOR_T color)
{
   COLOR_T obj_color;
   Vector3D L, R;
   double dot_n, dot_r, atten, Dl;
   

   obj_color = objs[closest_i] -> get_color(int_pt);

   //Compute ambient lighting
   color.r = 0.1 * obj_color.r;
   color.g = 0.1 * obj_color.g;
   color.b = 0.1 * obj_color.b;

   if(shadow_test(objs, closest_i, int_pt) == false)
   {
      //Compute Diffuse Lighting
      L = location - int_pt;

      Dl = L.length();

      atten = ( 1 / (.002 * Dl * Dl + .02 * Dl + .2) );

      L.normal();
      dot_n = normal.dot_product(L);

      if(dot_n > 0)
      {
         color.r +=  dot_n * obj_color.r * atten;
         color.g +=  dot_n * obj_color.g * atten;
         color.b +=  dot_n * obj_color.b * atten;

         //Compute Specular Lighting
         R = L - normal * dot_n * 2 * atten;
   
         R.normal();
         dot_r = R.dot_product(ray.dir);

         if(dot_r > 0)
         {
            color.r += pow(dot_r, 100);
            color.g += pow(dot_r, 100);
            color.b += pow(dot_r, 100);
         }
      }

   }
   return(color);
}
