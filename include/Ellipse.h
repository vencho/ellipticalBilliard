#include<Point.h>
#include<MovingPoint.h>

#ifndef ELLIPSE_H_DEFINED
#define ELLIPSE_H_DEFINED

class Ellipse {
public:
  double a, b, c, e;
  Ellipse(double a, double b);
  bool isInternal(Point & p);
  void reflect(MovingPoint & p);
  Point tangentVector(Point &p);
  Point stdParam(double angle);
  Point leftFocusParam(double angle);
  Point rightFocusParam(double angle);
  Point centreParam(double angle);
  double leftFocusArm(double angle);
  double rightFocusArm(double angle);
  double centreArm(double angle);
  Point getLeftFocus();
  Point getRightFocus();
};
#endif
