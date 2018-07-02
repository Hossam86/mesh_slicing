#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "v3.h"
#include<iostream>
#include <vector>
#include "lineSegment.h"
#include "Plane.h"


class triangle
{
public:
	triangle(const v3 & n,const v3 & p0, const v3 & p1, const v3 & p2);
	~triangle();
	triangle & operator-=(const v3 & rhs);
	v3& getNormal();
	void setNormal(const v3 &N);
	//void transform(glm::mat4 & mat);
	int intersectPlane(const Plane & p,lineSegment & seg)const;
private:
	v3 p[3];
    v3 normal;
};
#endif
