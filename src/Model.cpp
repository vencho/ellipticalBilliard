#include<Model.h>

Model::Model(double a, double b) : e(a, b) {

}

void Model::setEllipse(Ellipse &other) {
  e = other;
}

void Model::addMovingPoint(MovingPoint &p) {
  points.push_back(p);
}

void Model::tick() {
  for(int i = 0; i < points.size(); i++) {
    points[i].move();
    if(!e.isInternal(points[i])) {
      e.reflect(points[i]);
    }
  }
}

MovingPoint & Model::getPointByIndex(int i) {
  return points[i];
}

int Model::getPointCount() {
  return points.size();
}

Ellipse & Model::getEllipse() {
  return e;
}
