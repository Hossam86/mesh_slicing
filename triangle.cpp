#include "triangle.h"

triangle::triangle(const v3 & n, const v3 & p0, const v3 & p1, const v3 & p2)
{
this->normal=n;
p[0]=p0;
p[1]=p1;
p[2]=p2;
}

triangle::~triangle()
{

}
triangle& triangle::operator-=(const v3 & p)
{
	this->p[0]-=p;
	this->p[1]-=p;
	this->p[2]-=p;
	return * this;
}

void triangle::setNormal(const v3 & n)
{
	this->normal= n;
}

v3& triangle:: getNormal()
{
 return this->normal;	
}
// void triangle::transform(const glm::mat4 & mat)
// {
// 	p[0].transform(mat);
// 	p[1].transform(mat);
// 	p[2].tranform(mat);
// }

int triangle::intersectPlane(const Plane & pl ,lineSegment & seg) const
{
 // 0 plane intersect the triangle 
 // 1 all triangle points on front side of the plane 
 //-1 all triangle points on the back of the plane 
 //-2 error 

	size_t cntFront=0, cntBack=0, onplane=0;	
	for (size_t i = 0; i < 3; ++i)
	{
		double distance = pl.distanceToPoint(this->p[0]);
		if (distance<0) ++cntBack;
		else if (distance >0) ++cntFront;
		else  ++onplane;
	}

 	if (cntFront==3) return 1;
 	if (cntBack==3) return -1;

 	size_t lines[] = {0,1,1,2,2,0};
 	std::vector<v3> intersectPoints;
 	for (size_t i = 0;i < 3; ++i)
 	{
 		 const v3 &a = this->p[lines[i*2]];
 		 const v3 &b = this->p[lines[i*2+1]];

 		const float da = pl.distanceToPoint(a);
 		const float db = pl.distanceToPoint(b);

 		if (da * db < 0) 
 		{
 			const float s = da/(da-db);  //intersection factor 
 			v3 bMinusa = b-a;
 			intersectPoints.push_back(a+bMinusa*s);
 		}

 		else if (da == 0)	// plane falls exacalty on one of three Triangle 
 		{
 			if (intersectPoints.size() < 2) intersectPoints.push_back(a);
 		}   
 		else if (db == 0)
 		{
 			if (intersectPoints.size() < 2) intersectPoints.push_back(b);
 		}
 	}
 	if (intersectPoints.size()==2)	// output the intersecting line segment object 
 	{
 		seg.setVertex(intersectPoints[0],0);
 		seg.setVertex(intersectPoints[1],1);
 		return 0;
 	}

 	return -2;
}