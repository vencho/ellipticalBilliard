#ifndef POINT_H_DEFINED
#define POINT_H_DEFINED

class Point {
 public:
  double x, y;
  Point();
  Point(double x, double y);
  double norm();
  void normalise();
  double dot(Point &other);
};
#endif
