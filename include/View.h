#include<Model.h>
#include<SDL.h>

#ifndef VIEW_H_DEFINED
#define VIEW_H_DEFINED
class View {
 private:
  Model & model;
  int offsetx, offsety;
  void drawPoint(Point & p);
  SDL_Renderer *gRenderer;
  
 public:
  View(Model &model, SDL_Renderer *gRenderer);
  void draw(bool drawEllipse, bool drawPoints);
};

#endif
