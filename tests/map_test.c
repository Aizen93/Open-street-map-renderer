#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

// version qui va extraire tous les points constituants un chemin
void extraire (xmlDocPtr doc, xmlNodePtr cur) {

	xmlChar *cle;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	   if ((!xmlStrcmp(cur->name, (const xmlChar *)"nd"))) { // nom du noeud ou on veut retrouver l'attribut
		    cle = xmlGetProp(cur, "ref"); //va retrouver l'attribut correspondant au noeud
		    printf("ref: %s\n", cle);
		    xmlFree(cle);
	    } 
	    cur = cur->next;
	}
}


static void parseDoc(char *docname) {

	xmlDocPtr doc;
	xmlNodePtr cur;

	doc = xmlParseFile(docname);
	
	// traitement d'erreur
	if (doc == NULL ) {
		fprintf(stderr,"le document n'a pas ete parser correctement\n");
	}
	
	cur = xmlDocGetRootElement(doc); //attribution de la balise principale

	
	if (cur == NULL) {
		fprintf(stderr,"document vide\n");
		xmlFreeDoc(doc);
	}
	
	if (xmlStrcmp(cur->name, (const xmlChar *) "osm")) { // nom de la balise principale
		fprintf(stderr,"document ne correspondant pas a ce qui est attendu");
		xmlFreeDoc(doc);
	}
	
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"way"))){
			extraire (doc, cur);
		}
		 
	cur = cur->next;
	}
	xmlFreeDoc(doc);
}

int main(int argc, char **argv) {

	char *docname;

	if (argc <= 1) {
		printf("Usage: %s doc_name\n", argv[0]);
	}

	docname = argv[1];
	parseDoc (docname);
	
	return (1);
}


