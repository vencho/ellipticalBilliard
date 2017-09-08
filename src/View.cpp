#include<View.h>
#include<Global.h>

View::View(Model &model, SDL_Renderer *gRenderer) : model(model) {
  this -> gRenderer = gRenderer;
  SDL_SetRenderDrawColor( gRenderer, 0, 0xFF, 0, 0 );
  offsetx = SCREEN_WIDTH/2; // - model.getEllipse().a;
  offsety = SCREEN_HEIGHT/2; // - model.getEllipse().b;
}


void View::draw(bool drawEllipse, bool drawPoints) {
  if(drawEllipse) {
    Ellipse &e = model.getEllipse();
    for(double angle = 0; angle < 2*M_PI; angle += 0.001) {
      Point p = e.rightFocusParam(angle);
      drawPoint(p);
    }
  }

  if(drawPoints) {
    for(int i = 0; i < model.getPointCount(); i++) {
      drawPoint(model.getPointByIndex(i));
    }
  }
  SDL_RenderPresent(gRenderer);
}

void View::drawPoint(Point & p) {
  int x = (int) p.x + offsetx;
  int y = (int) p.y + offsety;
  int tmp = x; x = y; y = tmp;
  SDL_RenderDrawPoint(gRenderer, x, y);
}
