#include<cstdio>
#include<ctime>
#include<SDL.h>
#include<Global.h>
#include<Model.h>
#include<View.h>
#include<cmath>
#include<ctime>

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

Point arbitraryPoint(Ellipse &e);
bool trajectoryWithProperty(Point &p, Ellipse &e, double T, MovingPoint &mp);
double momentumProduct(MovingPoint &mp, Ellipse &e);
double property(MovingPoint &mp, Ellipse &e);

int main() {
  runSimulation();

  /*
  Ellipse e(64, 15);
  Point leftFocus = e.getLeftFocus();
  Point rightFocus = e.getRightFocus();

  for(double angle = 0; angle < M_PI/4; angle += 0.01) {
    Point p = e.centreParam(angle);
    Point tv = e.tangentVector(p);
    tv.normalise();

    double momentumA = (p - leftFocus)^tv;
    double momentumB = (p - rightFocus)^tv;
    double momentumProduct = momentumA * momentumB;

    double property = (p.x * tv.x / (e.a*e.a) + p.y * tv.y / (e.b*e.b));
    printf("Point at angle %.2lf has product of momenta %lf and property %lf\n", angle, momentumProduct, property);
  }
  */
  /*
  srand(time(0));

  Ellipse e(2, 1);
  double T;
  MovingPoint mp;

  for(double T = -0.1; T >= -0.95; T -= 0.1) {
    Point p;
    do {
      p = arbitraryPoint(e); 
    } while(!trajectoryWithProperty(p, e, T, mp));
    // printf("p(%.2lf, %.2lf) v(%.2lf, %.2lf) ", mp.x, mp.y, mp.h.x, mp.h.y);
    double momentum = momentumProduct(mp, e);
    double prop = property(mp, e);
    printf("T = %lf ", prop);
    printf("momenta = %lf\n", momentum);
  }
  return 0;
  */
}

double property(MovingPoint &mp, Ellipse &e) {
  double ans = mp.x * mp.h.x / (e.a*e.a) + mp.y * mp.h.y / (e.b*e.b);
  return ans;
}

double momentumProduct(MovingPoint &mp, Ellipse &e) {
  Point leftFocus = e.getLeftFocus();
  Point rightFocus = e.getRightFocus();

  Point other = mp + mp.h;
  double momentumA = (mp - leftFocus)^(other - leftFocus);
  double momentumB = (mp - rightFocus)^(other - rightFocus);
  return momentumA * momentumB;
}

bool trajectoryWithProperty(Point &p, Ellipse &e, double T, MovingPoint &mp) {
  double A = (1 + (e.b*e.b*e.b*e.b*p.x*p.x) / (e.a*e.a*e.a*e.a*p.y*p.y));
  double B = -2*T*p.x*e.b*e.b*e.b*e.b / (e.a*e.a*p.y*p.y);
  double C = (T*T*e.b*e.b*e.b*e.b) / (p.y*p.y) - 1;
  double discriminant = B*B - 4*A*C;
  if(discriminant < 0.1) return false;
  double vx = (-B + sqrt(discriminant)) / (2*A);
  double vy = (T - p.x*vx / (e.a*e.a))*(e.b*e.b) / p.y;
  mp.x = p.x;
  mp.y = p.y;
  mp.h = Point(vx, vy);
  return true;
}

Point arbitraryPoint(Ellipse &e) {
  double angle = 2*M_PI * (rand() % 1000) / 1000.;
  return e.rightFocusParam(angle);
}

