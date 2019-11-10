#include<glib.h>
#include<libxml/parser.h>
#include<libxml/xpath.h>

#ifndef _NODES_H
#define _NODES_H

typedef struct Node Node;

//La structure Node
struct Node {
  char *id;
  char *visible;
  int version;
  const char *changeset; //ou long/int?!
  const char *timestamp;
  const char *user;
  int uid;
  double lat;
  double lon;
} ;

/* fonction qui va remplir la structure node 
arg: xmlNodePtr n
retour: la structure node remplie */
Node *new_node(xmlNodePtr n) {
 Node *node; 
 node = malloc(sizeof(Node));
 
 node->id = (char *) (xmlGetProp(n, (const xmlChar *)"id"));
 node->visible = (char *)(xmlGetProp(n, (const xmlChar *)"visible"));
 node->version = atol((const char *) (xmlGetProp(n, (const xmlChar *)"version")));
 node->changeset = (char *) (xmlGetProp(n, (const xmlChar *)"changeset"));
 node->timestamp = (char *) (xmlGetProp(n, (const xmlChar *)"timestamp"));
 node->user = (char *) (xmlGetProp(n,(const xmlChar *) "user"));
 node->uid = atol((const char *) (xmlGetProp(n, (const xmlChar *) "uid")));
 node->lat = strtof((char *) (xmlGetProp(n, (const xmlChar *) "lat")),NULL);
 node->lon = strtof((char*) (xmlGetProp(n, (const xmlChar *) "lon")),NULL); 
	
 return node;

}

void delete_node(Node *node) {
 free(node);
}

#endif
