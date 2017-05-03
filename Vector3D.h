// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015


#ifndef Vector3D_H
#define Vector3D_H
#include <iostream>

using namespace std;

class Vector3D {
private:
	double x, y, z;

public:
	Vector3D()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Vector3D(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3D add(const Vector3D v);
	Vector3D operator+(const Vector3D v);

	Vector3D subtract(const Vector3D v);
	Vector3D operator-(const Vector3D v);

	double dot_product(const Vector3D v);
	double operator*(const Vector3D v);

	Vector3D scalar_mult (double s);
	Vector3D operator*(double s);

	Vector3D scalar_divide(double s);
	Vector3D operator/(double s);

	int floor_function();

	void normal();
	double length();

	double getx();
	double gety();
	double getz();
};

#endif
