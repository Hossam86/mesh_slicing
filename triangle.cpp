#include "triangle.h"

triangle::triangle(const v3 & p0, const v3 & p1, const v3 & p2)
{
p[0]=p0;
p[1]=p1;
p[2]=p2;
}

triangle::~triangle()
{

}

void triangle::setNormal(const v3 & n)
{
	this->normal= n;
}

v3& triangle:: getNormal()
{
 return this->normal;	
}
