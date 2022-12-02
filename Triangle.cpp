#include <cstdlib>
#include "Triangle.h"

Triangle::Triangle() : a_(Point()), b_(Point()), c_(Point()) {}
Triangle::Triangle(Point a, Point b, Point c) : a_(a), b_(b), c_(c) {}
Triangle::Triangle(const Triangle& t) : a_(t.a_), b_(t.b_), c_(t.c_) {}
Triangle::~Triangle() = default;

void Triangle::setA(Point a) { a_.setX(a.getX()); a_.setY(a.getY()); }
void Triangle::setB(Point b) { b_.setX(b.getX()); b_.setY(b.getY()); }
void Triangle::setC(Point c) { c_.setX(c.getX()); c_.setY(c.getY()); }
Point Triangle::getA() const { return a_; }
Point Triangle::getB() const { return b_; }
Point Triangle::getC() const { return c_; }

double Triangle::Square() const {
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
    return (a_.isEqual(t.getA()) && b_.isEqual(t.getB()) && c_.isEqual(t.getC())) || (a_.isEqual(t.getA()) && b_.isEqual(t.getC()) && c_.isEqual(t.getB())) ||
           (a_.isEqual(t.getB()) && b_.isEqual(t.getC()) && c_.isEqual(t.getA())) || (a_.isEqual(t.getB()) && b_.isEqual(t.getA()) && c_.isEqual(t.getC())) ||
           (a_.isEqual(t.getC()) && b_.isEqual(t.getA()) && c_.isEqual(t.getA())) || (a_.isEqual(t.getC()) && b_.isEqual(t.getB()) && c_.isEqual(t.getA()));
}