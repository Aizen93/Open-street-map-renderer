#include <SDL2/SDL.h>
#include <stdio.h>
#include <glib.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "function_math.h"
#include "parseur.h"
#include "draw.h"
#include <SDL2/SDL_ttf.h>
#include "pixel.h"


/************ fonction pour dessiner les zones *********************/

void drawWater(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH) {
  void drawWaterway(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;
    if (g_hash_table_contains(w->tag,"waterway")) {
      if (strcmp("riverbank",(char *) g_hash_table_lookup(w->tag,"waterway")) == 0) {
	Sint16 tabX[w->nb_nodes];
	Sint16 tabY[w->nb_nodes];
	int i;
	for (i = 0; i < w->nb_nodes ;i++) {
	  char *id = (char *) g_list_nth_data(w->nd,i);
	  Node *n  = g_hash_table_lookup(map->nodes,id);
	  
	  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	}
	filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,0,51,204,255);
      }
    }
  }
  g_hash_table_foreach (map->ways,drawWaterway,map);
}
  

void drawLeisure(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH) {
  void drawleisure(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;
    if (g_hash_table_contains(w->tag,"leisure")) {
      if (strcmp("park",(char *) g_hash_table_lookup(w->tag,"leisure")) == 0) {
	Sint16 tabX[w->nb_nodes];
	Sint16 tabY[w->nb_nodes];
	int i;
	for (i = 0; i < w->nb_nodes ;i++) {
	  char *id = (char *) g_list_nth_data(w->nd,i);
	  Node *n  = g_hash_table_lookup(map->nodes,id);
	  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	}
	filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,200,249,204,255);
      }
      else{
	if (strcmp("playground",(char *) g_hash_table_lookup(w->tag,"leisure")) == 0) {
	  Sint16 tabX[w->nb_nodes];
	  Sint16 tabY[w->nb_nodes];
	  int i;
	  for (i = 0; i < w->nb_nodes ;i++) {
	    char *id = (char *) g_list_nth_data(w->nd,i);
	    Node *n  = g_hash_table_lookup(map->nodes,id);
	    tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	    tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	  }
	  filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,200,249,204,255);
	}
	else{
	  if (strcmp("recreation_ground",(char *) g_hash_table_lookup(w->tag,"leisure")) == 0) {
	    Sint16 tabX[w->nb_nodes];
	    Sint16 tabY[w->nb_nodes];
	    int i;
	    for (i = 0; i < w->nb_nodes ;i++) {
	      char *id = (char *) g_list_nth_data(w->nd,i);
	      Node *n  = g_hash_table_lookup(map->nodes,id);
	      tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	      tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	    }
	    filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,200,249,204,255);
	  }
	  else{
	    if (strcmp("garden",(char *) g_hash_table_lookup(w->tag,"leisure")) == 0) {
	      Sint16 tabX[w->nb_nodes];
	      Sint16 tabY[w->nb_nodes];
	      int i;
	      for (i = 0; i < w->nb_nodes ;i++) {
		char *id = (char *) g_list_nth_data(w->nd,i);
		Node *n  = g_hash_table_lookup(map->nodes,id);
		tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	      }
	      filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,200,249,204,255);
	    }
	    else{
	      if (strcmp("pitch",(char *) g_hash_table_lookup(w->tag,"leisure")) == 0) {
		Sint16 tabX[w->nb_nodes];
		Sint16 tabY[w->nb_nodes];
		int i;
		for (i = 0; i < w->nb_nodes ;i++) {
		  char *id = (char *) g_list_nth_data(w->nd,i);
		  Node *n  = g_hash_table_lookup(map->nodes,id);
		  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
		}
		filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,172,208,158,255);
	      } else {
                if (strcmp("common",(char *) g_hash_table_lookup(w->tag,"leisure")) == 0) {
		  Sint16 tabX[w->nb_nodes];
		  Sint16 tabY[w->nb_nodes];
		  int i;
		  for (i = 0; i < w->nb_nodes ;i++) {
		    char *id = (char *) g_list_nth_data(w->nd,i);
		    Node *n  = g_hash_table_lookup(map->nodes,id);
		    tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		    tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
		  }
		  filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,207,236,168,255);
	        } else {
                  if (strcmp("marina",(char *) g_hash_table_lookup(w->tag,"leisure")) == 0) {
		    Sint16 tabX[w->nb_nodes];
		    Sint16 tabY[w->nb_nodes];
		    int i;
		    for (i = 0; i < w->nb_nodes ;i++) {
		      char *id = (char *) g_list_nth_data(w->nd,i);
		      Node *n  = g_hash_table_lookup(map->nodes,id);
		      tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		      tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
		    }
		    filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,163,186,211,255);
	          }
                }
              }
	    }
	  }
	}
      }
    }
  }
  g_hash_table_foreach (map->ways,drawleisure,map);
}

void drawLanduse(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH) {
  void drawlanduseforest(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;
    if (g_hash_table_contains(w->tag,"landuse")) {
      if (strcmp("forest",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	Sint16 tabX[w->nb_nodes];
	Sint16 tabY[w->nb_nodes];
	int i;
	for (i = 0; i < w->nb_nodes ;i++) {
	  char *id = (char *) g_list_nth_data(w->nd,i);
	  Node *n  = g_hash_table_lookup(map->nodes,id);
	  
	  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	}
	filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,172,208,158,255);
      }
      else{
	if (strcmp("cemetery",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	  Sint16 tabX[w->nb_nodes];
	  Sint16 tabY[w->nb_nodes];
	  int i;
	  for (i = 0; i < w->nb_nodes ;i++) {
	    char *id = (char *) g_list_nth_data(w->nd,i);
	    Node *n  = g_hash_table_lookup(map->nodes,id);
	    
	    tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	    tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	  }
	  filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,170,203,175,255);
	}
	else{
	  if (strcmp("grass",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	    Sint16 tabX[w->nb_nodes];
	    Sint16 tabY[w->nb_nodes];
	    int i;
	    for (i = 0; i < w->nb_nodes ;i++) {
	      char *id = (char *) g_list_nth_data(w->nd,i);
	      Node *n  = g_hash_table_lookup(map->nodes,id);
	      
	      tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	      tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	    }
	    filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,200,249,204,255);
	  }
	  else{
	    if (strcmp("industrial",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	      Sint16 tabX[w->nb_nodes];
	      Sint16 tabY[w->nb_nodes];
	      int i;
	      for (i = 0; i < w->nb_nodes ;i++) {
		char *id = (char *) g_list_nth_data(w->nd,i);
		Node *n  = g_hash_table_lookup(map->nodes,id);
		
		tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	      }
	      filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,235,219,232,255);
	    }else{
              if (strcmp("residential",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	        Sint16 tabX[w->nb_nodes];
	        Sint16 tabY[w->nb_nodes];
	        int i;
	        for (i = 0; i < w->nb_nodes ;i++) {
		  char *id = (char *) g_list_nth_data(w->nd,i);
		  Node *n  = g_hash_table_lookup(map->nodes,id);
		
		  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	        }
	        filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,224,222,222,255);
	      } else {
                if (strcmp("construction",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	          Sint16 tabX[w->nb_nodes];
	          Sint16 tabY[w->nb_nodes];
	          int i;
	          for (i = 0; i < w->nb_nodes ;i++) {
		    char *id = (char *) g_list_nth_data(w->nd,i);
		    Node *n  = g_hash_table_lookup(map->nodes,id);
		
		    tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		    tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	          }
	          filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,182,181,145,255);
	        } else {
                  if (strcmp("tourism",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	            Sint16 tabX[w->nb_nodes];
	            Sint16 tabY[w->nb_nodes];
	            int i;
	            for (i = 0; i < w->nb_nodes ;i++) {
		      char *id = (char *) g_list_nth_data(w->nd,i);
		      Node *n  = g_hash_table_lookup(map->nodes,id);
		
		      tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		      tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	            }
	            filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,242,239,233,255);
	          } else {
                    if (strcmp("basin",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	              Sint16 tabX[w->nb_nodes];
	              Sint16 tabY[w->nb_nodes];
	              int i;
	              for (i = 0; i < w->nb_nodes ;i++) {
		        char *id = (char *) g_list_nth_data(w->nd,i);
		        Node *n  = g_hash_table_lookup(map->nodes,id);
		
		        tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		        tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	              }
	              filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,183,212,204,255);
	            } else {
                      if (strcmp("village_green",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	                Sint16 tabX[w->nb_nodes];
	                Sint16 tabY[w->nb_nodes];
	                int i;
	                for (i = 0; i < w->nb_nodes ;i++) {
		          char *id = (char *) g_list_nth_data(w->nd,i);
		          Node *n  = g_hash_table_lookup(map->nodes,id);
		
		          tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		          tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	                }
	                filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,204,234,176,255);
	              } else {
                        if (strcmp("railway",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	                  Sint16 tabX[w->nb_nodes];
	                  Sint16 tabY[w->nb_nodes];
	                  int i;
	                  for (i = 0; i < w->nb_nodes ;i++) {
		            char *id = (char *) g_list_nth_data(w->nd,i);
		            Node *n  = g_hash_table_lookup(map->nodes,id);
		
		            tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		            tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	                  }
	                  filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,235,219,232,255);
	                } else {
                          if (strcmp("recreation_ground",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	                    Sint16 tabX[w->nb_nodes];
	                    Sint16 tabY[w->nb_nodes];
	                    int i;
	                    for (i = 0; i < w->nb_nodes ;i++) {
		              char *id = (char *) g_list_nth_data(w->nd,i);
		              Node *n  = g_hash_table_lookup(map->nodes,id);
		
		              tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		              tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	                    }
	                    filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,204,234,176,255);
	                  } else {
                            if (strcmp("commercial",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	                      Sint16 tabX[w->nb_nodes];
	                      Sint16 tabY[w->nb_nodes];
	                      int i;
	                      for (i = 0; i < w->nb_nodes ;i++) {
		                char *id = (char *) g_list_nth_data(w->nd,i);
		                Node *n  = g_hash_table_lookup(map->nodes,id);
		
		                tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		                tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	                      }
	                      filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,242,218,217,255);
	                    } else {
                              if (strcmp("farmland",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	                        Sint16 tabX[w->nb_nodes];
	                        Sint16 tabY[w->nb_nodes];
	                        int i;
	                        for (i = 0; i < w->nb_nodes ;i++) {
		                  char *id = (char *) g_list_nth_data(w->nd,i);
		                  Node *n  = g_hash_table_lookup(map->nodes,id);
		
		                  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		                  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	                        }
	                        filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,250,236,215,255);
	                      } else {
                                if (strcmp("farmyard",(char *) g_hash_table_lookup(w->tag,"landuse")) == 0) {
	                          Sint16 tabX[w->nb_nodes];
	                          Sint16 tabY[w->nb_nodes];
	                          int i;
	                          for (i = 0; i < w->nb_nodes ;i++) {
		                    char *id = (char *) g_list_nth_data(w->nd,i);
		                    Node *n  = g_hash_table_lookup(map->nodes,id);
		
		                    tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
		                    tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	                          }
	                          filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,238,213,180,255);
	                        }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
	  }
	}
      }
    }
  }
  g_hash_table_foreach (map->ways,drawlanduseforest,map);
}


void drawNatural(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH) {
  void drawnatural(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;
    if (g_hash_table_contains(w->tag,"natural")) {
      if (strcmp("water",(char *) g_hash_table_lookup(w->tag,"natural")) == 0) {
	Sint16 tabX[w->nb_nodes];
	Sint16 tabY[w->nb_nodes];
	int i;
	for (i = 0; i < w->nb_nodes ;i++) {
	  char *id = (char *) g_list_nth_data(w->nd,i);
	  Node *n  = g_hash_table_lookup(map->nodes,id);
	  
	  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	}
	filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,51,102,153,255);
      }
      else{
	if (strcmp("wood",(char *) g_hash_table_lookup(w->tag,"natural")) == 0) {
	  Sint16 tabX[w->nb_nodes];
	  Sint16 tabY[w->nb_nodes];
	  int i;
	  for (i = 0; i < w->nb_nodes ;i++) {
	    char *id = (char *) g_list_nth_data(w->nd,i);
	    Node *n  = g_hash_table_lookup(map->nodes,id);
	    
	    tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	    tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	  }
	  filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,172,208,157,255);
	}
      }
    }
  }
  g_hash_table_foreach (map->ways,drawnatural,map);
}

void drawRiver(SDL_Renderer *ecran,Map *map, double ratio,int HEIGHT,int WIDTH,double gffx) {
  void drawriver(gpointer key,gpointer value,gpointer user_data) {
    Relation * r = value;
    if (g_hash_table_contains(r->tag,"waterway")) {
      if (strcmp("river",(char *) g_hash_table_lookup(r->tag,"waterway")) == 0) {
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
	      if (x_f - x_d < 0) {
		thickLineRGBA(ecran,x_f+2,y_f,x_d+2,y_d,gffx, 51, 0, 102,255); 
	      }
	      else {
		thickLineRGBA(ecran,x_d+2,y_d,x_f+2,y_f,gffx, 51, 0, 102,255); 
	      }
	    }
	  }
	}
      }
    }
  }
  g_hash_table_foreach (map->relations,drawriver,map);
}

void drawNaturalRelation(SDL_Renderer *ecran,Map *map, double ratio,int HEIGHT,int WIDTH) {
  void drawnaturalrelation(gpointer key,gpointer value,gpointer user_data) {
    Relation * r = value;
    if (g_hash_table_contains(r->tag,"natural")) {
      if (strcmp("wood",(char *) g_hash_table_lookup(r->tag,"natural")) == 0) {
	int i;
	for (i = 0; i < r->nb_ways ;i++) {
	  char *idw = (char *) g_list_nth_data(r->member,i);
	  if(g_hash_table_contains(map->ways,idw)){
	    Way *w  = g_hash_table_lookup(map->ways,idw);
	    Sint16 tabX[w->nb_nodes];
	    Sint16 tabY[w->nb_nodes];
	    int j;
	    for(j = 0; j < w->nb_nodes; j++) {
	      char *id = (char *) g_list_nth_data(w->nd,j);
	      Node *n  = g_hash_table_lookup(map->nodes,id);
                    
	      tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	      tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	    }
	    filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,172,208,157,255);
	  }
	}
      }
    }
  }
  g_hash_table_foreach (map->relations,drawnaturalrelation,map);
}

void drawNaturalCoast (SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH) {
  //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 51, 102, 153));
  void drawnaturalcoast(gpointer key,gpointer value,gpointer user_data) {
    //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 230, 230, 230));
    Way * w = value;
    if (g_hash_table_contains(w->tag,"natural")) {
      if (strcmp("coastline",(char *) g_hash_table_lookup(w->tag,"natural")) == 0) {
	Sint16 tabX[w->nb_nodes];
	Sint16 tabY[w->nb_nodes];
	int i;
	for (i = 0; i < w->nb_nodes ;i++) {
	  char *id = (char *) g_list_nth_data(w->nd,i);
	  Node *n  = g_hash_table_lookup(map->nodes,id);
	  
	  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	}
	filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,241,238,232,255);
      }
    }
  }
  g_hash_table_foreach (map->ways,drawnaturalcoast,map);
}



void drawBuilding (SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH) {
  void drawbuilding(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;

    if (g_hash_table_contains(w->tag,"building")) {
      Sint16 tabX[w->nb_nodes];
      Sint16 tabY[w->nb_nodes];
      int i;
      for (i = 0; i < w->nb_nodes ;i++) {
	char *id = (char *) g_list_nth_data(w->nd,i);
	Node *n  = g_hash_table_lookup(map->nodes,id);
	
	tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
      }
      filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,216,208,201,255);
    }
  }
  g_hash_table_foreach (map->ways,drawbuilding,map);
}

void drawBarrier(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH) {
  void drawbarrier(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;
    if (g_hash_table_contains(w->tag,"barrier")) {
      if (strcmp("fence",(char *) g_hash_table_lookup(w->tag,"barrier")) == 0) {
	Sint16 tabX[w->nb_nodes];
	Sint16 tabY[w->nb_nodes];
	int i;
	for (i = 0; i < w->nb_nodes ;i++) {
	  char *id = (char *) g_list_nth_data(w->nd,i);
	  Node *n  = g_hash_table_lookup(map->nodes,id);
	  
	  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	}
	filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,254,254,254,80);
      }
    }
  }
  g_hash_table_foreach (map->ways,drawbarrier,map);
}


void drawBare_rock(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH) {
  void drawbare_rock(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;
    if (g_hash_table_contains(w->tag,"natural")) {
      if (strcmp("bare_rock",(char *) g_hash_table_lookup(w->tag,"natural")) == 0) {
	Sint16 tabX[w->nb_nodes];
	Sint16 tabY[w->nb_nodes];
	int i;
	for (i = 0; i < w->nb_nodes ;i++) {
	  char *id = (char *) g_list_nth_data(w->nd,i);
	  Node *n  = g_hash_table_lookup(map->nodes,id);
	  
	  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	}
	filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,208,206,202,255);
      }
    }
  }
  g_hash_table_foreach (map->ways,drawbare_rock,map);
}


/************ fonction pour dessiner les ways *****************/
void drawUnclassifiedWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("unclassified",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
    if (x_f - x_d < 0) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx, 255, 255, 255,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx, 255, 255, 255,255); 
    }
  }
}

void drawTertiaryWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("tertiary",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
    if (x_f - x_d < 0 ) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx, 255, 255, 255,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx, 255, 255, 255,255); 
    }
  }
}


void drawSecondaryWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("secondary",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
    if (x_f - x_d < 0 ) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx+2, 255, 255, 102,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx+2, 255, 255, 102,255); 
    }
  }
  else{
    if (strcmp("track",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
      if (x_f - x_d < 0 ) {
	thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx, 255, 255, 102,255); 
      }
      else {
	thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx, 255, 255, 255,255); 
      }
    }
  }
}


void drawPrimaryWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("primary",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
    if (x_f - x_d < 0 ) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx, 255, 153, 0,255);
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx, 255, 153, 0,255); 
    }
  }
}

void drawResidentialWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("motorway",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
    if (x_f - x_d < 0 ) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx, 0, 102, 204,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx, 0, 102, 204,255); 
    }
  }
  else{
    if (strcmp("residential",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
      if (x_f - x_d < 0 ) {
	thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx, 255, 255, 255,255); 
      }
      else {
	thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx, 255, 255, 255,255); 
      }
    }
    else{
      if (strcmp("trunk",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
	if (x_f - x_d < 0 ) {
	  thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx+2, 172,208,158,255); 
	}
	else {
	  thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx+2, 172,208,158,255); 
	}
      }	
    }
  }
}
  

void drawServiceWay(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("service",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
    if (x_f - x_d < 0 ) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx, 255, 255, 255,255); 
    }
    else { 
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx, 255, 255, 255,255); 
    }
  }
  else{
    if (strcmp("pedestrian",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
      if (x_f - x_d < 0 ) {
	thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx+1, 255, 255, 255,255); 
      }
      else { 
	thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx+1, 255, 255, 255,255); 
      }
    }
  }
}

void drawFerries(SDL_Renderer *ecran,Way *w, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("unclassified",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
    if (x_f - x_d < 0 ) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx+1, 102, 0, 0,255); 
    }
    else { 
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx+1, 102, 0, 0,255); 
    }
  }
  else{
    if (strcmp("footway",(char *) g_hash_table_lookup(w->tag,"highway")) == 0) {
      if (x_f - x_d < 0 ) {
	thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx+1, 255, 0, 0,255); 
      }
      else { 
	thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx+1, 255, 0, 0,255); 
      }
    }
  }
}

void drawWaterStream(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH, double gffx) {
  void drawwaterstream(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;
    if (g_hash_table_contains(w->tag,"waterway")) {
      if (strcmp("stream",(char *) g_hash_table_lookup(w->tag,"waterway")) == 0) {
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
	  
	  if (x_f - x_d < 0 ) {
	    thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx,51,102,153,255); 
	  }
	  else {
	    thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx,51,102,153,255); 
	  }
	}
      }
    }
  }
  g_hash_table_foreach (map->ways,drawwaterstream,map);
}


void drawbeach(SDL_Renderer *ecran,Map *map,double ratio,int HEIGHT,int WIDTH) {
  void drawbeach(gpointer key,gpointer value,gpointer user_data) {
    Way * w = value;
    if (g_hash_table_contains(w->tag,"natural")) {
      if (strcmp("beach",(char *) g_hash_table_lookup(w->tag,"natural")) == 0) {
	Sint16 tabX[w->nb_nodes];
	Sint16 tabY[w->nb_nodes];
	int i;
	for (i = 0; i < w->nb_nodes ;i++) {
	  char *id = (char *) g_list_nth_data(w->nd,i);
	  Node *n  = g_hash_table_lookup(map->nodes,id);
	  tabX[i] = (lon2x_m(n->lon) - lon2x_m(map->bounds.minlon)) * ratio;
	  tabY[i] = HEIGHT - ((lat2y_m(n->lat) - lat2y_m(map->bounds.minlat)) * ratio);
	}
	filledPolygonRGBA(ecran,tabX,tabY,w->nb_nodes,255,241,186,255);
      }
    }
    if (g_hash_table_contains(w->tag,"natural")) {
      
    }
  }
  g_hash_table_foreach (map->ways,drawbeach,map);
}

//fonction pour dessiner les relations
void drawRouteTrain(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("train",(char *) g_hash_table_lookup(r->tag,"route")) == 0) {
    if (x_f - x_d < 0) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx+1, 0, 0, 0,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx+1, 0, 0, 0,255); 
    }
  }
}

void drawRouteSubway(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("subway",(char *) g_hash_table_lookup(r->tag,"route")) == 0) {
    if (x_f - x_d < 0) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx+1, 0, 0, 0,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx+1, 0, 0, 0,255); 
    }
  }
}

void drawRouteHiking(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("hiking",(char *) g_hash_table_lookup(r->tag,"route")) == 0) {
    if (x_f - x_d < 0) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx, 255, 0, 0,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx, 255, 0, 0,255); 
    }
  }
}

void drawRouteBus(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("bus",(char *) g_hash_table_lookup(r->tag,"route")) == 0) {
    if (x_f - x_d < 0) {
      thickLineRGBA(ecran,x_f-1,y_f,x_d-1,y_d,gffx, 255, 51, 153, 255); 
    }
    else {
      thickLineRGBA(ecran,x_d-1,y_d,x_f-1,y_f,gffx, 255, 51, 153, 255); 
    }
  }
}

void drawRouteBicycle(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("bicycle",(char *) g_hash_table_lookup(r->tag,"route")) == 0) {
    if (x_f - x_d < 0) {
      thickLineRGBA(ecran,x_f+2,y_f,x_d+2,y_d,gffx, 153, 51, 255, 255); 
    }
    else {
      thickLineRGBA(ecran,x_d+2,y_d,x_f+2,y_f,gffx, 153, 51, 255, 255); 
    }
  }
}

void drawRouteRoad(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("road",(char *) g_hash_table_lookup(r->tag,"route")) == 0) {
    if (x_f - x_d < 0) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx-2, 0, 0, 0,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx-2, 0, 0, 0,255); 
    }
  }
}

void drawRouteRailway(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("railway",(char *) g_hash_table_lookup(r->tag,"route")) == 0) {
    if (x_f - x_d < 0) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx-2, 0, 0, 0,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx-2, 0, 0, 0,255); 
    }
  }
}

void drawRouteRailroad(SDL_Renderer *ecran,Relation *r, double x_d,double y_d,double x_f,double y_f, double gffx) {
  if (strcmp("railroad",(char *) g_hash_table_lookup(r->tag,"route")) == 0) {
    if (x_f - x_d < 0) {
      thickLineRGBA(ecran,x_f,y_f,x_d,y_d,gffx-2, 0, 0, 0,255); 
    }
    else {
      thickLineRGBA(ecran,x_d,y_d,x_f,y_f,gffx-2, 0, 0, 0,255); 
    }
  }
}

