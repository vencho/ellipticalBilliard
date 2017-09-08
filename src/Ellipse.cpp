#include<Point.h>
#include<MovingPoint.h>
#include<Ellipse.h>
#include<cmath>

#include<cstdio>
#include<cstdlib>

Ellipse::Ellipse(double a, double b) {
  this -> a = a;
  this -> b = b;
  c = sqrt(a*a - b*b);
  e = c / a;
}

bool Ellipse::isInternal(Point & p) {
  return (p.x * p.x) / (a*a) + (p.y*p.y) / (b*b) < 1;
}

void Ellipse::reflect(MovingPoint & p) {
  Point h = p.h;
  double speed = h.norm();

  double A = b*b*h.x*h.x + a*a*h.y*h.y;
  double B = 2*(p.x*h.x*b*b + p.y*h.y*a*a);
  double C = p.x*p.x*b*b + p.y*p.y*a*a - a*a*b*b;
  double D = B*B - 4*A*C;

  double t = (-B + sqrt(D)) / (2*A);
  p.x += t * h.x;
  p.y += t * h.y;

  Point n(-2*p.x / (a*a), -2*p.y / (b*b));
  
  h.normalise();
  n.normalise();
  double coeff = -2 * h.dot(n);
  Point newd(h.x + coeff*n.x, h.y + coeff*n.y);
  p.h = newd;
  p.h.x *= speed;
  p.h.y *= speed;
}

Point Ellipse::stdParam(double angle) {
  return Point(a*cos(angle), b*sin(angle));
}

Point Ellipse::leftFocusParam(double angle) {
  double arm = leftFocusArm(angle);
  return Point(arm*cos(angle) - c, arm*sin(angle));
}

Point Ellipse::rightFocusParam(double angle) {
  double arm = rightFocusArm(angle);
  return Point(arm*cos(angle) + c, arm*sin(angle));
}

Point Ellipse::centreParam(double angle) {
  double arm = centreArm(angle);
  return Point(arm*cos(angle), arm*sin(angle));
}

double Ellipse::leftFocusArm(double angle) {
  return (1 - e*e)*a / (1 - e*cos(angle));
}

double Ellipse::rightFocusArm(double angle) {
  return (1 - e*e)*a / (1 + e*cos(angle));
}

double Ellipse::centreArm(double angle) {
  double cs = cos(angle);
  return b / sqrt(1 - e*e*cs*cs);
}
