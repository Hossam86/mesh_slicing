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

}
