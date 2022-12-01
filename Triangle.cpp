#include <cstdlib>
#include "Triangle.h"

Triangle::Triangle() : a_(Point()), b_(Point()), c_(Point()) {}
Triangle::Triangle(Point a, Point b, Point c) : a_(a), b_(b), c_(c) {}
Triangle::Triangle(const Triangle& t) : a_(t.a_), b_(t.b_), c_(t.c_) {}
Triangle::~Triangle() = default;

void Triangle::setA(Point a) { a_ = a; }
void Triangle::setB(Point b) { b_ = b; }
void Triangle::setC(Point c) { c_ = c; }
Point Triangle::getA() const { return a_; }
Point Triangle::getB() const { return b_; }
Point Triangle::getC() const { return c_; }

double Triangle::Square() {
    return 0.5 * abs(a_.getX() * (b_.getY() - c_.getY()) +
                     b_.getX() * (c_.getY() - a_.getY()) +
                     c_.getX() * (a_.getY() - b_.getY()));
}

bool Triangle::isTriangle() {
    return (this->Square() != 0);
}

void Triangle::move(double k) {
    a_.move(k);
    b_.move(k);
    c_.move(k);
}

double Triangle::getPerimeter() {
    return (a_.getDistance(b_) + a_.getDistance(c_) + b_.getDistance(c_));
}

bool Triangle::isEqual(Triangle& t) {
    return (a_.isEqual(t.getA())) && b_.isEqual(t.getB()) && c_.isEqual(t.getC());
}