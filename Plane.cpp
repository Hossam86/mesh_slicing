#include "Plane.h"
Plane::Plane(double d, const v3 & normal)
{
	this->mDistance;
	this->normal=normal;
}

Plane::~Plane()
{

}

double Plane::distanceToPoint(v3 & point)
{
	double result=point.dot(normal);
	return result;
}