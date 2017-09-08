#include<Ellipse.h>
#include<MovingPoint.h>
#include<vector>

#ifndef MODEL_H_DEFINED
#define MODEL_H_DEFINED
class Model {
 private:
  Ellipse e;
  std::vector<MovingPoint> points;

 public:
  Model(double a, double b);
  Ellipse &getEllipse();
  void setEllipse(Ellipse & other);
  MovingPoint & getPointByIndex(int i);
  int getPointCount();
  void addMovingPoint(MovingPoint &p);
  void tick();
};

#endif
