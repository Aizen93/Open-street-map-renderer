#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_ttf.h>

#ifndef _DRAW_H
#define _DRAW_H

//definitions des fonctions : area
void drawbeach(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH);
void drawWater(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH);
void drawLeisure(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH);
void drawLanduse(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH);
void drawNatural(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH);
void drawNaturalCoast (SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH);
void drawBuilding(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH);
void drawBarrier(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH);
void drawBare_rock(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH);
void drawWaterStream(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH, double gffx);
void drawNaturalRelation(SDL_Renderer *ecran,Map *map, double ratio,int HEIGHT,int WIDTH);

//definitions des fonctions : ways
void drawUnclassifiedWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawSecondaryWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawTertiaryWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawPrimaryWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawResidentialWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawServiceWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawFerries(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx);

//definitions des fonctions : relations
void drawRouteTrain(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawRouteSubway(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawRouteHiking(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawRouteBus(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawRouteBicycle(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawRiver(SDL_Renderer *ecran,Map *map, double ratio,int HEIGHT,int WIDTH,double gffx);
void drawRouteRoad(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawRouteRailway(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx);
void drawRouteRailroad(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx);



#endif

