#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fullrect.h"
#include "parseur.h"
#include "draw.h"
#include "function_math.h"
#include <SDL2/SDL_ttf.h>


SDL_Window* pWindow;
SDL_Renderer* renderer;

void pause(){
  //Maintien la fenetre ouverte
  int continuer = 1;
  SDL_Event event;
  
  while (continuer){
    SDL_WaitEvent(&event);
    switch(event.type)
      {
      case SDL_QUIT:
	continuer = 0;
      }
  }
}

int main(int argc, char** argv){  
  /*-------------Création de la fenêtre-----------------*/
  //TTF_Init();
  //TTF_Font *police = NULL;
  Coordinate plan;
  Map *map = initMap(argv[1]);

  /************test de relations***********/
  /*Relation *r = g_hash_table_lookup(map->relations,"411405");
  printf("*******test relations pour le fichier vosges.osm**********\n");
  printf("Specifications de la relation n° %s\n",r->id);
  printf("visible : %s\n",r->visible);
  printf("nb ways : %d\n",r->nb_ways);
  printf("nb tags : %d\n",r->nb_tags);
  printf("ref way : %s\n",(char *)g_list_nth_data(r->member,0));
  printf("k: %s v: %s\n","type",(char *)g_hash_table_lookup(r->tag,"type"));
  //pour les types de routes si ce tag existe alors v different de (null)
  printf("k: %s v: %s\n","route",(char *)g_hash_table_lookup(r->tag,"route"));
  printf("*******************************\n\n");*/
  /***************************************/

  double min_lat = map->bounds.minlat;
  double min_lon = map->bounds.minlon;
  double max_lat = map->bounds.maxlat;
  double max_lon = map->bounds.maxlon;
  double gfx_route_taille_14;
  double gfx_route_taille_10;
  double gfx_route_taille_0;
  double gfx_route_taille_16;

  int test = g_hash_table_size(map->nodes);
  int test2 = g_hash_table_size(map->ways);
  printf("hashtable node size: %d\n", test);
  printf("hashtable ways size: %d\n", test2);
  
  double max_xr = ((max_lon - min_lon)/360) * cos_deg(max_lat);
  double max_yr =  (max_lat - min_lat)/360;

  double k;
  if (max_xr > max_yr) {
    k = MAX_DIM/max_xr;
    plan.ecranx = MAX_DIM;
    plan.ecrany = max_yr * k;
    gfx_route_taille_14 = Proportionner(min_lon, max_lon, OTHERWAY);
    gfx_route_taille_10 = Proportionner(min_lon, max_lon, SERVICEWAY);
    gfx_route_taille_0 = Proportionner(min_lat, max_lat, LITLEWAY);
    gfx_route_taille_16 = Proportionner(min_lon, max_lon, PRIMARYWAY);
  }
  else {
    k = MAX_DIM/max_yr;
    plan.ecrany = MAX_DIM;
    plan.ecranx = max_xr * k;
    gfx_route_taille_14 = Proportionner(min_lat, max_lat, OTHERWAY);
    gfx_route_taille_0 = Proportionner(min_lat, max_lat, LITLEWAY);
    gfx_route_taille_10 = Proportionner(min_lat, max_lat, SERVICEWAY);
    gfx_route_taille_16 = Proportionner(min_lat, max_lat, PRIMARYWAY);
  }

  printf("k = %lf ecranx = %lf ecrany = %lf\n", k, plan.ecranx, plan.ecrany);
  printf("gfx_route_taille_14: %lf, gfx_route_taille_10: %lf, gfx_route_taille_16: %lf\n",gfx_route_taille_14,gfx_route_taille_10,gfx_route_taille_16);
  
  /*-----------------FIN de la creation de la fenetre-------------------*/

  /*---------------------Affichage de la fenetre-----------------------*/
  pWindow = SDL_CreateWindow("SDL2 OpenStreetMap LaMiOu",SDL_WINDOWPOS_UNDEFINED,
			     SDL_WINDOWPOS_UNDEFINED,
			     plan.ecranx,
			     plan.ecrany,
			     SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
   
  SDL_SetRenderDrawColor(renderer, 181, 208, 208, 255);
  SDL_RenderClear(renderer);

 //************************fonction de dessin*************************//
  double WIDTH = plan.ecranx;
  double HEIGHT = plan.ecrany;
  double ratio = WIDTH / (lon2x_m(map->bounds.maxlon) - lon2x_m(map->bounds.minlon));
 
  printf("maxlon: %lf, minlon: %lf\n", max_lon, min_lon);
  drawNaturalCoast(renderer,map,ratio,HEIGHT,WIDTH);
  drawNaturalRelation(renderer,map,ratio,HEIGHT,WIDTH);
  drawWater(renderer,map,ratio,HEIGHT,WIDTH);
  drawLeisure(renderer,map,ratio,HEIGHT,WIDTH);
  drawLanduse(renderer,map,ratio,HEIGHT,WIDTH);
  drawNatural(renderer,map,ratio,HEIGHT,WIDTH);
  drawBarrier(renderer,map,ratio,HEIGHT,WIDTH);
  drawBuilding(renderer,map,ratio,HEIGHT,WIDTH);
  drawbeach(renderer,map,ratio,HEIGHT,WIDTH);
  drawBare_rock(renderer,map,ratio,HEIGHT,WIDTH);
  drawWaterStream(renderer,map,ratio,HEIGHT,WIDTH,gfx_route_taille_16);
  drawRiver(renderer,map,ratio,HEIGHT,WIDTH,gfx_route_taille_0);
  
  //traiter key: parking cle: surface

  //fonction qui va afficher les ways
  void drawWays(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;
    if (g_hash_table_contains(w->tag,"highway")) {
      Node* tab[w->nb_nodes];
      int i;
      for (i = 0; i < w->nb_nodes ; i++ ) {
	char *id = (char *) g_list_nth_data(w->nd,i);
	tab[i] = g_hash_table_lookup(map->nodes,id);
      }
      for (i=0; i< (w->nb_nodes) - 1 ; i ++) {
	double x_d = (lon2x_m(tab[i]->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	double y_d = HEIGHT - ((lat2y_m(tab[i]->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	double x_f = (lon2x_m(tab[i+1]->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	double y_f = HEIGHT - ((lat2y_m(tab[i+1]->lat) - lat2y_m(map->bounds.minlat)) * ratio);

	//mettre les appels aux fonctions de dessins de chemins ici
	
	drawSecondaryWay(renderer,w,x_d,y_d,x_f,y_f,gfx_route_taille_14);
	drawTertiaryWay(renderer,w,x_d,y_d,x_f,y_f,gfx_route_taille_14);
	drawResidentialWay(renderer,w,x_d,y_d,x_f,y_f,gfx_route_taille_14);
	drawServiceWay(renderer,w,x_d,y_d,x_f,y_f,gfx_route_taille_10);
	drawUnclassifiedWay(renderer,w,x_d,y_d,x_f,y_f,gfx_route_taille_14);
	drawPrimaryWay(renderer,w,x_d,y_d,x_f,y_f,gfx_route_taille_16);
	drawFerries(renderer,w,x_d,y_d,x_f,y_f,gfx_route_taille_0);
      }
    }
  }
  g_hash_table_foreach (map->ways,drawWays,map);
  
  void drawRelations(gpointer key,gpointer value,gpointer user_data)  {
    Relation *r = value;
    if (g_hash_table_contains(r->tag,"route")) {
      int i;
      int nb = 0;
      for (i = 0; i < r->nb_ways ; i++ ) {
	char *id = (char *) g_list_nth_data(r->member,i);
	if (g_hash_table_contains(map->ways,id)) {
	  nb++;
	  Way *w = g_hash_table_lookup(map->ways,id);
	  Node* tab[w->nb_nodes];
	  int i;
	  for (i = 0; i < w->nb_nodes ; i++ ) {
	    char *id = (char *) g_list_nth_data(w->nd,i);
	    tab[i] = g_hash_table_lookup(map->nodes,id);
	  }
	  for (i=0; i< (w->nb_nodes) - 1 ; i ++) {
	    double x_d = (lon2x_m(tab[i]->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	    double y_d = HEIGHT - ((lat2y_m(tab[i]->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	    double x_f = (lon2x_m(tab[i+1]->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	    double y_f = HEIGHT - ((lat2y_m(tab[i+1]->lat) - lat2y_m(map->bounds.minlat)) * ratio);

	    drawRouteRoad(renderer,r,x_d,y_d,x_f,y_f,gfx_route_taille_10);
	    drawRouteRailway(renderer,r,x_d,y_d,x_f,y_f,gfx_route_taille_10);
	    drawRouteRailroad(renderer,r,x_d,y_d,x_f,y_f,gfx_route_taille_10);
	    drawRouteTrain(renderer,r,x_d,y_d,x_f,y_f,gfx_route_taille_0);
	    drawRouteSubway(renderer,r,x_d,y_d,x_f,y_f,gfx_route_taille_0);
	    drawRouteHiking(renderer,r,x_d,y_d,x_f,y_f,gfx_route_taille_0);
	    drawRouteBus(renderer,r,x_d,y_d,x_f,y_f,gfx_route_taille_0);
	    drawRouteBicycle(renderer,r,x_d,y_d,x_f,y_f,gfx_route_taille_0);
	  }
	}
      }
    }
  }

  g_hash_table_foreach (map->relations,drawRelations,map);

  SDL_RenderPresent(renderer);
  delete_map(map);
  
  pause();
  SDL_Quit();
  return EXIT_SUCCESS;
  /*-----------------FIN de l'affichage de la fenetre-----------------*/
}

