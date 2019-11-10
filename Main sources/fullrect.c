#include <SDL2/SDL.h>
#include <stdio.h>
#include "fullrect.h"
#include <math.h>

double cos_deg(double d) {
  return cos((d/360)* 2 * PI);
}

double sin_deg(double d) {
  return sin((d/360) * 2 * PI);
}

double log_deg(double d){
  return log((d/360) * 2 * PI);
}

void drawFullRect(SDL_Renderer* renderer,int posX, int posY, int width, int length, int R, int G, int B, int V){
  //resctangle plein
  SDL_Rect Rect;
  Rect.x = posX;
  Rect.y = posY;
  Rect.w = length-1;
  Rect.h = width-1;
  SDL_SetRenderDrawColor(renderer, R, G, B, V);
  SDL_RenderFillRect(renderer, &Rect);
}

double Proportionner(double minlon, double maxlon, double taille){
  double gffx2 = ((-1 * minlon) - (maxlon*(-1)));
  double gffx3 = gffx2 / PROPORTION;
  double gffx4 = taille / gffx3;
  int caste = (int) gffx4;
  if((gffx4-caste) >= 0.5) return caste+1;
  else return gffx4;
}
