#include <iostream>
#include "Point.h"
#include "Triangle.h"


bool isPointInCircle(double r, const Point& p);

void input(std::istream& s, Point& p);

void output(std::ostream& s, const Point& p);

void triangleOutput(std::ostream& s, const Triangle& t);

bool isEqualSquare(const Triangle& t1, const Triangle& t2);


int main()
{
    //---------------------------------------------POINT-----------------------------------------------//
    std::cout << "Test for class Point \n";
    double mn = 1e20, dist = 0;
    Point p(1, 1), p0(0, 0), resP, testP(5, 5);

    while (true) {
        input(std::cin, p);
        
        try {
            if (!std::cin || std::cin.peek() != '\n') {
                throw std::runtime_error("bad input, coords must be float only!");
            }
        } 
        catch (std::exception const& e) {
            std::cerr << "Error: " << e.what() << "\n";
            return 1;
        }

        if (p.getX() == 0 and p.getY() == 0) {
            break;
        }

        dist = p.getDistance(p0);
        if (dist < mn) {
            mn = dist;
            resP = p;
        }
    }

    std::cout << "Nearest to (0, 0): ";  output(std::cout, resP); std::cout << '\n';
    std::cout << "Is equal with (5; 5)? Result: " << resP.isEqual(testP) << '\n';
    std::cout << "Distance to (5; 5): " << resP.getDistance(testP) << '\n';
    resP.move(7);
    std::cout << "Cords after moving (+7): "; output(std::cout, resP); std::cout << "\n\n";

    p.~Point();
    resP.~Point();
    p0.~Point();
    testP.~Point();
    //-------------------------------------------TRIANGLE----------------------------------------------//
    std::cout << "Tests for class Triangle \n";
    Triangle t1(Point(0, 6), Point(5, 0), Point(0, 0));
    Triangle t2(Point(0, 6), Point(0, -11), Point(0, 0));
    Triangle t3(Point(18, 24), Point(23, 18), Point(18, 18));
    
    std::cout << "t1: "; triangleOutput(std::cout, t1); std::cout << '\n';
    std::cout << "t2: "; triangleOutput(std::cout, t2); std::cout << '\n';
    std::cout << "t3: "; triangleOutput(std::cout, t3); std::cout << "\n\n";

    t1.move(9);
    std::cout << "t1 after moving (+9): "; triangleOutput(std::cout, t1); std::cout << "\n";
    t3.move(-9);
    std::cout << "t3 after moving (-9): "; triangleOutput(std::cout, t3); std::cout << "\n\n";

    std::cout << "Square t1: " << t1.Square() << '\n';
    std::cout << "Perimeter t1: " << t1.getPerimeter() << "\n\n";

    std::cout << "Is triangle t1? Result: " << t1.isTriangle() << '\n';
    std::cout << "Is triangle t2? Result: " << t2.isTriangle() << "\n\n";

    std::cout << "Is equal t1 and t2? Result: " << t1.isEqual(t2) << '\n';
    std::cout << "Is equal t1 and t3? Result: " << t1.isEqual(t3) << "\n\n";

    std::cout << "Is equal square of t1 and square of t2? Result: " << isEqualSquare(t1, t2) << '\n';
    std::cout << "Is equal square of t1 and square of t3? Result: " << isEqualSquare(t1, t3) << "\n\n";
    
    t1.~Triangle();
    t2.~Triangle();
    t3.~Triangle();
    return 0;
}


bool isPointInCircle(double r, const Point& p) {
    return r >= sqrt(p.getX() * p.getX() + p.getY() * p.getY());
}


void input(std::istream& s, Point& p) {
    double x, y;
    s >> x; p.setX(x);
    s >> y; p.setY(y);
}


void output(std::ostream& s, const Point& p) {
    s << "(" << p.getX() << "; " << p.getY() << ") ";
}


void triangleOutput(std::ostream& s, const Triangle& t) {
    output(std::cout, t.getA());
    std::cout << ' ';
    output(std::cout, t.getB());
    std::cout << ' ';
    output(std::cout, t.getC());
}


bool isEqualSquare(const Triangle& t1, const Triangle& t2) {
    return (t1.Square() == t2.Square());
}