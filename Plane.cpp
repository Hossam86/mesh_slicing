#include "Plane.h"
Plane::Plane(double d, const v3 & normal)
{
	this->mDistance;
	this->normal=normal;
}

Plane::~Plane()
{

}

double Plane::distanceToPoint(const v3 & point) const
{
	double result=point.dot(normal);
	return result;
}