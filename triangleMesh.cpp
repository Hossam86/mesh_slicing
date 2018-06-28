#include "triangleMesh.h"
triangleMesh::triangleMesh()
{
bottomLeftVertex=(-1e+6,-1e+6,-1e+6);
topRightVertex=(1e+6,1e+6,1e+6);
}

triangleMesh::triangleMesh(const char * stlFile, bool isBinary)
{
	if(!isBinary)
{
	std::ifstream in(stlFile);
	if(!in.good()) std::cout << "invalid file";
	char title[80];
	std::string s0 ,s1;
	double n0 , n1 , n2, f0, f1, f2, f3, f4, f5, f6, f7, f8;
	in.read(title,80);
	while(!in.eof())
	{
		in >> s0 ;
		if(s0 =="facet")
		{
			in >> s1 >> n0 >> n1 >> n2;
			in >> s0 >> s1;
			in >> s0 >> f0 >> f1 >> f2;     //vertex
			in >> s0 >> f3 >> f4 >> f5;		//vertex	
			in >> s0 >> f6 >> f7 >> f8; 	//vertex
			in >> s0 ;						//endloop
			in >> s0 ;						//endFacet
			// generate s new triagnle and push it back to the mesh 
			triangle t (v3(n0,n1,n2), v3(f0,f1,f2), v3(f3,f4,f5), v3(f6,f7,f8));
			mesh.push_back(t);
		}
		else break;
	}
	in.close();
}
else
{
//binary STL format
/*UINT8[80] – Header
UINT32 – Number of triangles

The information about the triangles follow subsequently. The file simply ends after the last triangle.

Each triangle is represented by twelve 32-bit floating point number. Just like the ASCII STL file, 3 numbers are for the 3D Cartesian co-ordinates of the normal to the triangle. The remaining 9 numbers are for the coordinates of the vertices (three each). Here’s how this looks like:

foreach triangle
REAL32[3] – Normal vector
REAL32[3] – Vertex 1
REAL32[3] – Vertex 2
REAL32[3] – Vertex 3
UINT16 – Attribute byte count
end*/

	FILE *f = fopen(stlFile,"rb");
	if (!f) std::cout << "invalid file";
	char title[80];
	int nFaces;
	fread(title, 80, 1, f);
	fread((void*)&nFaces, 4, 1, f);
	float v[12]; // normal=3, vertices=3*3 = 12
	unsigned short uint16;
	// Every Face is 50 Bytes: Normal(3*float), Vertices(9*float), 2 Bytes Spacer
	for (size_t i=0; i<nFaces; ++i) {
	for (size_t j=0; j<12; ++j) {
	fread((void*)&v[j], sizeof(float), 1, f);
	}
	fread((void*)&uint16, sizeof(unsigned short), 1, f); // spacer between successive faces
	triangle t(v3(v[0], v[1], v[2]), v3(v[3], v[4], v[5]), v3(v[6], v[7], v[8]), v3(v[9], v[10], v[11]));
	mesh.push_back(t);
	}
fclose(f);
}
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