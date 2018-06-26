#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H 
#include <vector>
#include "triangle.h"

class triangleMesh
{
public:
	triangleMesh();
	~triangleMesh();
	size_t size();
	void normalize();

protected:
double bottomLeftVertex;
double topRightVertex;
std::vector<triangle> mesh;
};

#endif
