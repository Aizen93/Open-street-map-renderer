#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <string.h>
#include <glib.h>

#ifndef _PARSEUR_H
#define _PARSEUR_H


typedef struct Map Map;
typedef struct Node Node;
typedef struct Way Way;
typedef struct Relation Relation;
 
typedef void (*fct_parcours_t) (xmlNodePtr,Map *) ;

struct Map{
   struct bounds {
    float minlat;
    float minlon;
    float maxlat;
    float maxlon;
  } bounds;
  
  /*hash_table correspondant a un node:
    - cle : string -> id
    - valeur : struct nodes
  */
  GHashTable* nodes;

  /* hash_table correspondant a un way:
     - cle : string -> ref
     - valeur : struct ways
  */
  GHashTable *ways;

  /* hash_table correspodant a une relation*/
  GHashTable *relations;
} ;

//La structure Node
struct Node {
  char *id;
  char *visible;
  float lat;
  float lon;
} ;

enum {
    AUTRE
};


//La structure way
struct Way {
  char *id;
  char *visible;
  int nb_nodes;
  int nb_tags;
  GList *nd; //array liste de nd ,contenant que des chaines de caracteres
  GHashTable *tag; //le hash_table contenant les tags (key and value)
                   /* building, source, wall*/
  
} way;

//La structure relation
struct Relation {
  char *id;
  char *visible;
  int nb_ways;
  int nb_tags;
  GList *member;
  GHashTable *tag;
} relation;

//definitions des fonctions
void initStruct(xmlNodePtr noeud,Map *m);
void parcours_prefixe(xmlNodePtr noeud,fct_parcours_t f,Map *m);
Map* initMap(char *docname);
void delete_map (Map *map);


#endif
