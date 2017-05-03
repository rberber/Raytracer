// Ryan Berberian
// CPSC 1020
// Project 3
// 06-09-2015


#include "Vector3D.h"
#include <math.h>

using namespace std;

Vector3D Vector3D::add(const Vector3D v){
	return *(new Vector3D(x + v.x, y + v.y, z + v.z));
}

Vector3D Vector3D::operator+(const Vector3D v){
	return add(v);
}

Vector3D Vector3D::subtract(const Vector3D v){
	return *(new Vector3D(x - v.x, y - v.y, z - v.z));
}

Vector3D Vector3D::operator-(const Vector3D v){
	return subtract(v);
}

double Vector3D::dot_product(const Vector3D v){
	return (x * v.x + y * v.y + z * v.z);
}

double Vector3D::operator*(const Vector3D v){
	return dot_product(v);
}

Vector3D Vector3D::scalar_mult(double s){
	return *(new Vector3D(x * s, y * s, z * s));
}

Vector3D Vector3D::operator*(double s){
	return scalar_mult(s);
}

Vector3D Vector3D::scalar_divide(double s){
	return *(new Vector3D(x / s, y / s, z / s));
}

Vector3D Vector3D::operator/(double s){
	return scalar_divide(s);
}

int Vector3D::floor_function(){
	return((int)floor(x) + (int)floor(y) + 
        (int)floor(z));
}

void Vector3D::normal(){
	double len;
	len = length();
	x /= len;
	y /= len;
	z /= len;
}

double Vector3D::length(){
	return(sqrt(x * x + y * y + z * z));
}

double Vector3D::getx(){
	return(this->x);
}
	

double Vector3D::gety(){
	return(this->y);
}
	

double Vector3D::getz(){
	return(this->z);
}








