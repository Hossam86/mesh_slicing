#ifndef _LINESEGMENT_H
#define _LINESEGMENT_H 
#include "v3.h"
class lineSegment
{
public:
	lineSegment(const v3 & p0, const v3 & p1);
	~lineSegment();
	v3 & getVertex(int i);
	void setVertex(const v3 & v, int i);

private: 
	v3 v[2];
};

#endif

