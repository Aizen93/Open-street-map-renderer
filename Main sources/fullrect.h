//typedef struct Coordinate Coordinate;
typedef struct Coordinate{
  double ecranx;
  double ecrany;
} Coordinate;

//fonction du main
#define PI 3.1415927
#define MAX_DIM 1000

double cos_deg(double d);
double sin_deg(double d);
double log_deg(double d);

void drawFullRect(SDL_Renderer* renderer,int posX, int posY, int width, int length, int R, int G, int B, int V);

#define PROPORTION 0.006341
#define OTHERWAY 14
#define LITLEWAY 0.5
#define PRIMARYWAY 16
#define SERVICEWAY 10
  
double Proportionner(double minlon, double maxlon, double taille);
