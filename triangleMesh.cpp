#include "triangleMesh.h"
triangleMesh::triangleMesh()
{
bottomLeftVertex=(-1e+6,-1e+6,-1e+6);
topRightVertex=(1e+6,1e+6,1e+6);
}
triangleMesh::~triangleMesh()
{

}

size_t triangleMesh::size()
{
	return mesh.size();
}

void triangleMesh::normalize()
{
	v3 halfbox=(topRightVertex-bottomLeftVertex)/2.0f;
	v3 start =bottomLeftVertex+ halfbox;
	for (size_t i= 0;  i< mesh.size(); i++)
	{
    triangle & t =mesh[i];
	t-= start;
	}
	bottomLeftVertex=halfbox*-1.0f;
	topRightVertex=halfbox;
}
void triangleMesh::push_back(const triangle & t)
{
	mesh.push_back(t);
}

v3 triangleMesh::meshAABBSize()const
{
 return v3(topRightVertex.getX()-bottomLeftVertex.getX(),topRightVertex.getY()-bottomLeftVertex.getY(),topRightVertex.getZ()-bottomLeftVertex.getZ());
}

std::vector<triangle> & triangleMesh::getMesh()
{
	return this->mesh;
}

const std::vector<triangle> & triangleMesh::getMesh() const 
{
	return this->mesh;
}

v3 triangleMesh::getBottomLeftVertex() const
{
	return bottomLeftVertex;
}

v3 triangleMesh::getTopRightVertex() const
{
	return topRightVertex;
}

// int triangleMesh::transform(const lm:: mat4 &mat)
// {
// 	for (size_t i = 0; i < mesh.size(); ++i)
// 	{
// 		triangle & tri=mesh[i];
// 		tri.transform(mat);
// 	}
// 	return 0;
// }