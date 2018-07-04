#ifndef _V3_H
#define _V3_H 
class v3
{
private:
	double v[3];
public:
	v3(double a =0,double b =0, double c=0);
	~v3();
	v3(const v3& rhs);                  //Copy Constructor 
	v3 & operator=(const v3 & rhs); 	//assignment operator 
	v3 operator +(const v3 & rhs);      // sum operator
	const v3 operator +(const v3 & rhs) const;      // sum operator
	v3 operator -( const v3 & rhs);     // subtract operator 
	const v3 operator -( const v3 & rhs) const;     // subtract operator 
	v3 operator /(double a)	;		// divide operatorr
	v3 operator * (double a);
	v3 & operator-=(const v3 & rhs);
	double dot(const v3 & rhs) const;      // dot product
	v3  cross(const v3 & rhs);		// cross product
	double getX() const;
	double getY() const;
	double getZ() const;
	// void tranform(glm::mat4 &mat);

};

#endif