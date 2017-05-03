// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#include <stdio.h>
#include <stdlib.h>
#include "light.h"
#include "Vector3D.h"
#include "ray.h"
#include "sphere.h"
#include "plane.h"
#include "scene.h"
#include "object.h"
#include "box.h"


void init(SCENE_T *scene)
{
   COLOR_T color, color2;
   color.r = 0.8;
   color.g = 0;
   color.b = 0;
   SPHERE * sphere1;
   sphere1 = new SPHERE(0.5, 0.8, 4, 0.5, 0.7);
   sphere1->set_checker(false);
   sphere1->set_color(color);
   scene -> objs[0] = sphere1;

   color.r = 0;
   color.g = 0.8;
   color.b = 0;
   SPHERE * sphere2;
   sphere2 = new SPHERE(-0.5, 0.15, 4.2, 0.6, 0.0);
   sphere2->set_color(color);
   sphere2->set_checker(false);
   scene -> objs[1] = sphere2;


   color.r = 1;
   color.g = 1;
   color.b = 1;
   color2.r = 0.1;
   color2.g = 0.1;
   color2.b = 0.1;
   PLANE * plane;
   plane = new PLANE(0, 1, 0, 0.9, 0.1);
   plane->set_color(color, color2);
   plane->set_checker(true);
   scene -> objs[2] = plane;

   color.r = 0;
   color.g = 0;
   color.b = 1;
   BOX * box;
   box = new BOX(0.3, -0.6, 2.3, 0.7, -0.2, 3.0);
   box->set_color(color);
   box->set_checker(false);
   scene->objs[3] = box;
   

	

   scene -> light = new LIGHT();
   scene -> light -> set_location(5.0, 10, -2);

   scene->num_objs = 4;
   
}


COLOR_T trace(SCENE_T scene, RAY_T ray, int level)
{
   double closest_t, reflection_val, t=1001;
   int closest_i;
   Vector3D closest_int_pt;
   Vector3D closest_normal;
   Vector3D int_pt, normal;
   RAY_T reflect;
   COLOR_T color, reflect_color, local_color;

   closest_i = -1;
   closest_t = 1000;
   color.r = 0.3;
   color.g = 0.3;
   color.b = 0.5;

   int i = 0;

   if(level > 5)
   {
      return(color);
   }

   for(i = 0; i < scene.num_objs; i++)
   {
      if(scene.objs[i] -> intersect(ray, &int_pt, &normal, &t) == true)
      {
         if(t < closest_t && t > 0.01)
         {
            closest_t = t;
            closest_i = i;
            closest_int_pt = int_pt;
            closest_normal = normal;
         }
      }
   }

   if(closest_i >= 0)
   {
      reflection_val = scene.objs[closest_i]->reflection;
      if(reflection_val > 0)
      {
         reflect.origin = closest_int_pt;
         reflect.dir = ray.dir - closest_normal * closest_normal.dot_product(ray.dir)* 2;
         reflect.dir.normal();

         reflect_color = trace(scene, reflect, level +1);

      }

      if(reflection_val < 1)
      {
         local_color = scene.light->illuminate(scene.objs, closest_i, closest_normal,
                            closest_int_pt, ray, color);
      }

      if(reflection_val > 0 && reflection_val <1)
      {
         color.r = reflection_val * reflect_color.r + (1 - reflection_val) * local_color.r;
         color.g = reflection_val * reflect_color.g + (1 - reflection_val) * local_color.g;
         color.b = reflection_val * reflect_color.b + (1 - reflection_val) * local_color.b;
      }
      else
      {
         color = scene.light->illuminate(scene.objs, closest_i, closest_normal, closest_int_pt, ray, color);
      }
   }
   return(color);
}


int main(void)
{
   int x, y, level = 0;
   int width, height;
   float aspect[2], denom;
   RAY_T ray;
   Vector3D int_pt, normal, light;
   COLOR_T color;
   unsigned char R, G, B;
   SCENE_T scene;
   init(&scene);

   width = 1024;
   height = 768;

   if (width < height)
   {
      aspect[0] = 1;
      aspect[1] = (float) height / width;
      denom = width;
   }
   else
   {
      aspect[0] = (float) width / height;
      aspect[1] = 1;
      denom = height;
   }


   //PPM file header
   printf("P6\n%d %d\n255\n", width, height);
   for(y = 0; y <= height -1; y++)
   {
      for (x = 0; x <= width -1; x++)
      {
         ray.origin = Vector3D(0, 0, 0);
         ray.dir = Vector3D((-aspect[0] / 2) + (x/denom), (aspect[1] / 2) - (y/denom), 1);
         ray.dir.normal();
            
         color = trace(scene, ray, level);

         //Cap color
         if(color.r > 1)
         {
            color.r = 1;
         }
         if(color.g > 1)
         {
            color.g = 1;
         }
         if(color.b > 1)
         {
            color.b = 1;
         }

         R = (unsigned char)(color.r * 255);
         G = (unsigned char)(color.g * 255);
         B = (unsigned char)(color.b * 255);
         printf("%c%c%c", R, G, B);
      }
   }
   return(0);
}
