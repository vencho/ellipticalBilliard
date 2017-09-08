#include<MovingPoint.h>

MovingPoint::MovingPoint(double x, double y, double dx, double dy) : Point(x, y), h(dx, dy) {
  h.normalise();
}

void MovingPoint::move() {
  x += h.x;
  y += h.y;
}
