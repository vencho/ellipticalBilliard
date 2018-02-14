#ifndef POINT_H_DEFINED
#define POINT_H_DEFINED

class Point {
 public:
  double x, y;

  Point operator+(Point other) const;
  Point operator-(Point other) const;
  double operator^(Point p) const;
  double norm() const;

  Point();
  Point(double x, double y);
  void normalise();
  double dot(Point &other);
};
#endif
