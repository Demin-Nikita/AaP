#include <iostream>
#include "Point.h"

Point::Point() : x_(0.0), y_(0.0) {}
Point::Point(double x, double y) : x_(x), y_(y) {}
Point::Point(const Point& p): x_(p.x_), y_(p.y_) {}
Point::~Point() = default;
	
void Point::setXY(double x, double y) { x_ = x; y_ = y; }
void Point::setX(double x) { x_ = x; }
void Point::setY(double y) { y_ = y; }
double Point::getX() const { return x_; }
double Point::getY() const { return y_; }
	
void Point::move(double k) {
	this->setX(this->getX() + k);
	this->setY(this->getY() + k);
}

bool Point::isEqual(const Point& p) {
	return (this->getX() == p.getX()) && (this->getY() == p.getY());
}

double Point::getDistance(const Point& p) {
	return sqrt((p.getX() - this->getX()) * (p.getX() - this->getX()) +
	            (p.getY() - this->getY()) * (p.getY() - this->getY()));
}