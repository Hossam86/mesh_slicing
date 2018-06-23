#include "v3.h"
v3::v3( double a = 0 , double b = 0, double c = 0)
{
 this-> v[0]=a;
 this-> v[1]=b;
 this-> v[2]=c;
}

v3 :: v3 (const v3 & rhs)
{

}

v3::~v3()
{

}

v3 & v3::operator = (const v3 & rhs)
{
 	v[0]=rhs.v[0];
 	v[1]=rhs.v[1];
 	v[2]=rhs.v[2];
 	return * this;
}

v3 v3::operator+(const v3 & rhs)
{

}

v3 v3 ::operator-(const v3 & rhs)
{

}

v3 v3 :: operator* (const double a)
{

}

v3 v3 :: operator / (const double a)
{

}

v3 & v3::operator-= (const v3 & rhs)
{

}

double v3::dot(const v3 & rhs)
{

}

v3 v3::cross(const v3 & rhs)
{

}