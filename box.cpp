// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015

#include "box.h"

BOX::BOX(void){
	lowl = Vector3D(0, 0, 0);
	upr = Vector3D(0, 0, 0);
}

BOX::BOX(double xl, double yl, double zl, double xu, double yu, double zu){
   lowl = Vector3D(xl, yl, zl);
	upr = Vector3D(xu, yu, zu);
}

bool BOX::intersect(RAY_T ray, Vector3D *int_pt,
                       Vector3D *normal, double *t)
{
	double t_near = -100;
	double t_far = 100;
	double t1, t2, temp;
	int count = -1;
	bool swap = false;

	static double lowl[3] = {this->lowl.getx(), this->lowl.gety(), this->lowl.getz()};

	static double upr[3] = {this->upr.getx(), this->upr.gety(), this->upr.getz()};

	double origin[3] = {ray.origin.getx(), ray.origin.gety(), ray.origin.getz()};

	double dir[3] = {ray.dir.getx(), ray.dir.gety(), ray.dir.getz()};

	const Vector3D normals[6] = {Vector3D(-1, 0, 0), Vector3D(1, 0, 0),
								  Vector3D(-1, 0, 0), Vector3D(1, 0, 0),
								  Vector3D(1, 0, 0), Vector3D(-1, 0, 0)};

	int i = 0;
	for(i = 0; i < 3; i++)
	{
		if(dir[i] == 0)
		{
			if(origin[i] < lowl[i] || origin[i] > upr[i])
			{
				return(false);
			}
		}
		swap = false;
		t1 = (lowl[i] - origin[i]) / (dir[i]);
		t2 = (upr[i] - origin[i]) / (dir[i]);
			
		if(t1 > t2)
		{
			temp = t2;
			t2 = t1;
			t1 = temp;
			swap = true;
		}
		if(t1 > t_near)
		{
			t_near = t1;
			if(swap == true)
			{
				count = 2 * i + 1;
			}
			else
			{
				count = 2 * i;
			}
		}
		if(t2 < t_far)
		{
			t_far = t2;
		}
		if(t_near > t_far)
		{
			return(false);
		}
		if(t_far < 0)
		{
			return(false);
		}
	}
	
	*t = t_near;
	*int_pt = ray.origin + ray.dir * *t;
	*normal = normals[count];

   return(true);
}




