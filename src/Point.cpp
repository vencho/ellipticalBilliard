#include<Point.h>
#include<cmath>


Point::Point() { 
}

Point::Point(double x, double y) {
  this -> x = x;
  this -> y = y;
}

double Point::norm() {
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
