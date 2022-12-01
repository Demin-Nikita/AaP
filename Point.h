#ifndef POINT_H
#define POINT_H
class Point
{
	public:
		Point();
		Point(double x, double y);
		Point(const Point& p);
		~Point();
	
		void setXY(double x, double y);
		void setX(double x);
		void setY(double y);
		double getX() const;
		double getY() const;
	
		void move(double k);
		bool isEqual(const Point& p);
		double getDistance(const Point& p);
	private:
	    double x_, y_;
};
#endif