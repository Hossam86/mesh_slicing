#include "Plane.h"
Plane::Plane(double d, const v3 & normal)
{
	this->mDistance=d;
	this->normal=normal;
}

Plane::~Plane()
{

}

double Plane::distanceToPoint(const v3 & point) const
{
	const v3 & n =this->normal;
	double result=point.dot(n);
	return result;
}

void Plane::setNormal(const v3 & n)
{
	this->normal= n;
}

void Plane::setDistance(double a)