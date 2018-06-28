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