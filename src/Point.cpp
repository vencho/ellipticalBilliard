#include<Point.h>
#include<cmath>


Point::Point() { 
}

double Point::operator^(Point p) const {
  return x*p.y - y*p.x;
}

Point Point::operator-(Point p) const {
  return Point(p.x - x, p.y - y);
}

Point Point::operator+(Point p) const {
  return Point(p.x + x, p.y + y);
}

Point::Point(double x, double y) {
  this -> x = x;
  this -> y = y;
}

double Point::norm() const {
  return sqrt(x*x + y*y);
}

void Point::normalise() {
  double n = norm();
  x /= n;
  y /= n;
}


double Point::dot(Point &other) {
  return x * other.x + y * other.y;
}
