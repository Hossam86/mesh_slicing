#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H 
#include<iostream>
#include<fstream>
#include <vector>
#include <exception>
#include "triangle.h"

class triangleMesh
{
public:
	triangleMesh();
	triangleMesh(const char * stlFile,bool isBinary);
	~triangleMesh();
	size_t size();
	void normalize();
	void push_back(const triangle & tri);
	v3 meshAABBSize()const;
	//int transform(const glm::mat4 & mat) // Mesh COG point should be at (0,0,0)
	std::vector<triangle> & getMesh();
	const std::vector<triangle> & getMesh() const;
	v3 getBottomLeftVertex() const;
	v3 getTopRightVertex() const;

protected:
v3 bottomLeftVertex ;
v3 topRightVertex ;
std::vector<triangle> mesh;
};
#endif
