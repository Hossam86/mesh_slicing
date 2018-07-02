#include "lineSegment.h"
lineSegment::lineSegment(const v3& p0, const v3& p1)
{
	v[0]=p0;
	v[1]=p1;
}

lineSegment::~lineSegment()
{

}

v3 &lineSegment:: getVertex(int i)
{
	return v[i];
}

void lineSegment::setVertex(const v3 & v, int i)
{
 this->v[i]=v;
}