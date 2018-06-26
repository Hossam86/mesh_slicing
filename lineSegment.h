#include "v3.h"
class lineSegment
{
public:
	lineSegment(const v3 & p0, const v3 & p1);
	~lineSegment();
	v3 & getVertex(int i);

private: 
	v3 v[2];
};