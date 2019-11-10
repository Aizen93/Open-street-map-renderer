#include<glib.h>
#include<libxml/parser.h>
#include<libxml/xpath.h>
#include"nodes.h"
#include"ways.h"

#ifndef _MAP_H
#define _MAP_H

// La structure Map
typedef struct Map Map;

struct Map{
   struct bounds {
    float minlat;
    double minlon;
    double maxlat;
    double maxlon;
  } bounds;
  
  /*hash_table correspondant a un node:
    - cle : string -> if
    - valeur : struct nodes
  */
  GHashTable* nodes;

  /* hash_table correspondant a un way:
     - cle : string -> ref
     - valeur : struct ways
  */
  GHashTable *ways;
} ;
//les fonctions 
xmlDocPtr getdoc (char *docname); 
int getInfoNode(const char *xpath,xmlDocPtr doc,GHashTable *tabnoeud);
int getBounds(xmlXPathContextPtr ctxt,const char *xpath,xmlDocPtr doc,Map *m);

/* La fonction qui se charge de la declaration et des initialisations de variables 
arg: nom_fichier -> le fichier .osm 
retour : une structure map */
Map * new_map( char *nom_fichier) {
  char * docname;
  xmlDocPtr doc;

  Map *map ;

  map = malloc(sizeof(Map));

  map->nodes = g_hash_table_new (g_str_hash,g_str_equal);
  docname = nom_fichier;
  doc = getdoc(docname);
  xmlXPathContextPtr ctxt = xmlXPathNewContext(doc);
  
  getBounds(ctxt,"/osm/bounds",doc,map);
  getInfoNode("/osm/node",doc,map->nodes);
	
  return map;

}

/* La fonction qui supprime la map 
arg : map 
retour: void */
void delete_map(Map *map) {
 g_hash_table_remove_all(map->nodes);
 g_hash_table_remove_all(map->ways);
 free(map);
}

#endif
