#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <string.h>
#include<glib.h>
#include"parseur.h"

/*---------------------------------------------------------------------
gcc parseur.c -o parseur `pkg-config --cflags --libs glib-2.0` 
`xml2-config --cflags` `xml2-config --libs` -g -s
---------------------------------------------------------------------*/

void initStruct(xmlNodePtr noeud,Map *m) {
    if (noeud->type == XML_ELEMENT_NODE) {
      
      if(strcmp((char*)noeud->name, "bounds") == 0) {
	//recuperation des bounds pour la fenetre
	m->bounds.minlat = strtof ((char *) (xmlGetProp(noeud, ( xmlChar *) "minlat")),NULL);
	m->bounds.minlon = strtof ((char *) (xmlGetProp(noeud, ( xmlChar *) "minlon")),NULL);
	m->bounds.maxlat = strtof ((char *) (xmlGetProp(noeud, ( xmlChar *) "maxlat")),NULL);
	m->bounds.maxlon = strtof ((char *) (xmlGetProp(noeud, ( xmlChar *) "maxlon")),NULL);
	}

      //recuperation des noeuds et initialisation de leurs champs
      if (strcmp((char*)noeud->name, "node") == 0) {
	Node *node = malloc(sizeof(Node));
	node->id = (char *) (xmlGetProp(noeud, ( xmlChar *) "id"));
	node->visible = (char *) (xmlGetProp(noeud, ( xmlChar *) "visible"));
	node->lat = strtof((char *) (xmlGetProp(noeud, ( xmlChar *) "lat")),NULL);
	node->lon = strtof((char *) (xmlGetProp(noeud, ( xmlChar *) "lon")),NULL);
	g_hash_table_insert(m->nodes,node->id,node);
      }

      //recuperation des ways et initialisation des champs
      if (strcmp((char *)noeud->name, "way") == 0) {
	Way *way = malloc(sizeof(Way));
	way->nd = NULL;
	way->nb_nodes = 0;
	way->tag = g_hash_table_new (g_str_hash,g_str_equal);

	way->id =  (char *) (xmlGetProp(noeud, ( xmlChar *) "id"));
	way->visible = (char *) (xmlGetProp(noeud, ( xmlChar *) "visible"));
	g_hash_table_insert(m->ways,way->id,way);

	/*pour parcourir les ref => id des noeuds qui constituent le way en question */
        xmlNodePtr node;
	for (node = noeud->children; node != NULL; node = node->next) {
	 if(strcmp((char *)node->name, "nd") == 0) {
	   way->nd = g_list_append(way->nd,(char *) xmlGetProp(node, (const xmlChar *)"ref"));
	   way->nb_nodes += 1;
	 }
	}
       
	/*pour remplir la hashmap des tags*/
        for (node = noeud->children; node != NULL; node = node->next) {
	 if(strcmp((char *)node->name, "tag") == 0) {
	   char *key = (char *) (xmlGetProp(node, (xmlChar *)"k"));
	   char *value = (char *) (xmlGetProp(node, (xmlChar *)"v"));
	   g_hash_table_insert(way->tag,key,value);
	   way->nb_tags +=1 ;
	 }
	}
	
      }
    }
}

void parcours_prefixe(xmlNodePtr noeud,fct_parcours_t f,Map *m) {
  xmlNodePtr n;
  for (n=noeud; n != NULL ; n = n -> next) {
    f(n,m);
    if ((n->type == XML_ELEMENT_NODE) && (n->children != NULL)) {
      parcours_prefixe(n->children, f,m);
    }
  }
}

Map * initMap(char *docname) {
    xmlDocPtr doc;
    xmlNodePtr racine;
    Map *map = malloc(sizeof(Map));
    map->nodes = g_hash_table_new (g_str_hash,g_str_equal);
    map->ways = g_hash_table_new (g_str_hash,g_str_equal);

    

    // Ouverture du fichier XML
    doc = xmlParseFile(docname);
    if (doc == NULL) {
        fprintf(stderr, "Document XML invalide\n");
        //return EXIT_FAILURE;
    }
    // Récupération de la racine
    racine = xmlDocGetRootElement(doc);
    if (racine == NULL) {
        fprintf(stderr, "Document XML vierge\n");
        xmlFreeDoc(doc);
        //return EXIT_FAILURE;
    }

    parcours_prefixe(racine,initStruct,map);

    //printf("bounds: %f %f %f %f\n",map->bounds.minlat,map->bounds.minlon,map->bounds.maxlat,map->bounds.maxlon);
  
    // Libération de la mémoire
    xmlFreeDoc(doc);

    return map;
}

//pour libérer la map
//a ameliorer
void delete_map ( Map *map) {
  //g_list_remove_all(way->nd);
  //g_hash_table_remove_all(way->tag);
  g_hash_table_remove_all(map->nodes);
  g_hash_table_remove_all(map->ways);
  //free(map->nodes);
  //free(map->ways);
  free(map);
}
