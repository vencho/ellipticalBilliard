#include<cstdio>
#include<ctime>
#include<SDL.h>
#include<Global.h>
#include<Model.h>
#include<View.h>
#include<cmath>


void runSimulation() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("Ellipse simulation", 
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					SCREEN_WIDTH,
					SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN);

  SDL_Renderer *gRenderer = SDL_CreateRenderer(window, -1, 0);
  SDL_RenderClear(gRenderer);
  
  clock_t t1, t2;
  double secondsspent;
  clock();


  Model M(200, 100);
  MovingPoint ball(-180, 0, 1, 1);
  M.addMovingPoint(ball);
  View V(M, gRenderer);
  bool quit = false;
  V.draw(true, false);

  SDL_Event e;
  int frameCounter = 0;
  while(!quit) {
    // printf("frame %d\n", frameCounter++);
    t1 = clock();

    while(SDL_PollEvent(&e)) {
      if(e.type == SDL_KEYDOWN) {
	if(e.key.keysym.sym == SDLK_q) {
	  quit = true;
	}
      }
    }

    M.tick();
    V.draw(false, true);

    
    t2 = clock();
    double secondsspent = (t2 - t1) / ( (double) CLOCKS_PER_SEC) ;
    int delay = (int)(1000*(SPF - secondsspent));
    SDL_Delay(delay);
  }
  
  SDL_DestroyRenderer(gRenderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}


double getAngle(double x, double y, double x0, double y0) {
  double dx = x - x0;
  double dy = y - y0;
  double angle = atan2(dy, dx);
  return angle;
}


int main() {

  /*
  Ellipse E(200, 100);
  double l = (4*E.e*(1 + E.e*E.e)) / ( 4*E.e*E.e + (1 + E.e*E.e)*(1 + E.e*E.e) );


  for(double angle = 0; angle < M_PI; angle += 0.01) {
    
    Point p = E.rightFocusParam(angle);
    MovingPoint ball(p.x, p.y, E.c - p.x, -p.y);
    E.reflect(ball);
    E.reflect(ball);
    
    double originalcos = cos(angle);
    double predictedcos = (originalcos - l) / (1 - l*originalcos);
    double realcos = cos(getAngle(ball.x, ball.y, E.c, 0));

    printf("cos = %lf maps to %lf, expected %lf\n", originalcos, realcos, predictedcos);
  }
  */

  runSimulation();

  return 0;
}


