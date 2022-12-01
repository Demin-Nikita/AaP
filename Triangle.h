#pragma once
#include "Point.h"

class Triangle
{
public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	Triangle(const Triangle& t);
	~Triangle();
		
	void setA(Point a);
	void setB(Point b);
	void setC(Point c);
	Point getA() const;
	Point getB() const;
	Point getC() const;

	double Square();
		
	bool isTriangle();
		
	void move(double k);
		
	double getPerimeter();
		
	bool isEqual(Triangle& t);
private:
	Point a_, b_, c_;
};