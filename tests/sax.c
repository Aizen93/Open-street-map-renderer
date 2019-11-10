#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<glib.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

#define MAX_REF_LEN 6
#define PRIX_MAX 10.0

typedef struct Map Map;

struct Map{
   struct bounds {
    float minlat;
    float minlon;
    float maxlat;
    float maxlon;
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

enum {
    AUTRE
};


static int elem_courant;
static Map *map;

/**
* Initialisation
**/
void debut_document(void *user_data) {
  map = malloc(sizeof(Map));
  map->nodes = g_hash_table_new (g_str_hash,g_str_equal);
  map->ways = g_hash_table_new (g_str_hash,g_str_equal);
  elem_courant = AUTRE;
}

/**
* Si l'élément courant est :
* _ produit : on conserve la référence
* _ intitule ou prix : on marque l'ouverture d'une telle balise
**/
void debut_element(void *user_data, const xmlChar *name, const xmlChar **attrs) {
    if (xmlStrEqual(name, BAD_CAST "bounds")) {
        if (NULL != attrs) {
            int i;
            for (i = 0; attrs[i] != NULL; i+=2) {
                if (xmlStrEqual(attrs[i], BAD_CAST "minlat")) {
		  map->bounds.minlat = strtof((char *)attrs[i+1],NULL);
		  printf("%.7f\n", map->bounds.minlat);
                }
		else if (xmlStrEqual(attrs[i], BAD_CAST "minlon")) {
		  map->bounds.minlon = strtof((char *)attrs[i+1],NULL);
		  printf("%.7f\n", map->bounds.minlon);
		}
		else if (xmlStrEqual(attrs[i], BAD_CAST "maxlat")) {
		  map->bounds.maxlat = strtof((char *)attrs[i+1],NULL);
		  printf("%.7f\n", map->bounds.maxlat);
		}
		else if (xmlStrEqual(attrs[i], BAD_CAST "maxlon")) {
		  map->bounds.maxlon = strtof((char *)attrs[i+1],NULL);
		  printf("%.7f\n", map->bounds.maxlon);
		}
            }
        }
    }
}

/**
* Réinitialisation du marqueur qui nous sert à savoir
* où l'on est dans le document XML
**/
void fin_element(void *user_data, const xmlChar *name) {
  elem_courant = AUTRE;
}

int main(int argc,char **argv) {
    // Initialisation à zéro de tous les membres (NULL pour un pointeur par conversion)
    xmlSAXHandler sh = { 0 };

    // Affectation des fonctions de rappel
    sh.startDocument = debut_document;
    sh.startElement = debut_element;
    sh.endElement = fin_element;

    // Parsing du document XML
    if (xmlSAXUserParseFile(&sh, NULL, "map2.osm") != 0) {
        fprintf(stderr, "Une erreur est survenue lors du parsing\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
