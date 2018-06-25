#include "v3.h"
class Plane
{
public:
	Plane(double distance,const v3 & normal);
	~Plane();
	double distanceToPoint(v3 & point);

private:
	double mDistance;
	v3 normal;

};