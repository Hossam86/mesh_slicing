#include "lineSegment.h"
lineSegment::lineSegment()
{
	v[0]=v3(0,0,0);
	v[1]=v3(0,0,0);
}
lineSegment::lineSegment(const v3& p0=v3(0, 0, 0), const v3& p1=v3(0, 0, 0))
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