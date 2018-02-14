#include<Point.h>

#ifndef MOVINGPOINT_H_DEFINED
#define MOVINGPOINT_H_DEFINED

class MovingPoint : public Point {
 public:
  Point h;
  MovingPoint();
  MovingPoint(double x, double y, double dx, double dy);
  void move();
};

#endif
