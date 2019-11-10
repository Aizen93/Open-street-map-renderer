#include<stdlib.h>
#include<stdio.h>
#include<glib.h>
#include<libxml/parser.h>
#include<libxml/xpath.h>
#include "map.h"

xmlDocPtr getdoc (char *docname) {
	xmlDocPtr doc;
	doc = xmlParseFile(docname);
	
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return NULL;
	}

	return doc;
}

int getBounds(xmlXPathContextPtr ctxt,const char *xpath,xmlDocPtr doc,Map *m) {
	if (ctxt == NULL) {
	     fprintf(stderr,"Erreur lors de la creation du contexte XPath\n");
	     exit(-1);
	}
	xmlXPathObjectPtr xpathNode = xmlXPathEvalExpression(BAD_CAST xpath, ctxt);
	 if (xpathNode == NULL) {
	     fprintf(stderr,"Erreur sur l'expression Xpath\n");
	     exit(-1);
	 }
	if (xpathNode -> type == XPATH_NODESET) {
	    int i;
	    for ( i = 0; i < xpathNode -> nodesetval -> nodeNr; i++ ) {
		xmlNodePtr n = xpathNode -> nodesetval -> nodeTab[i];
		if (n -> type == XML_TEXT_NODE || n-> type == XML_CDATA_SECTION_NODE
		    || n -> type == 1) {
		  m->bounds.minlat = strtof((char *) (xmlGetProp(n, (const xmlChar *) "minlat")),NULL);
		  m->bounds.minlon = strtof((char *) (xmlGetProp(n, (const xmlChar *) "minlon")),NULL);
		  m->bounds.maxlat = strtof((char *) (xmlGetProp(n, (const xmlChar *) "maxlat")),NULL);
		  m->bounds.maxlon = strtof((char *) (xmlGetProp(n, (const xmlChar *) "maxlon")),NULL); 
		}
	      }
	 }
	 xmlXPathFreeObject(xpathNode);
	 xmlXPathFreeContext(ctxt);
	 return 0;
}

int getInfoNode(const char *xpath,xmlDocPtr doc,GHashTable* tabnoeud ) {
    	xmlXPathContextPtr ctxt = xmlXPathNewContext(doc);
	if (ctxt == NULL) {
	     fprintf(stderr,"Erreur lors de la creation du contexte XPath\n");
	     exit(-1);
	}
	xmlXPathObjectPtr xpathNode = xmlXPathEvalExpression(BAD_CAST xpath, ctxt);
	 if (xpathNode == NULL) {
	     fprintf(stderr,"Erreur sur l'expression Xpath\n");
	     exit(-1);
	 }
	if (xpathNode -> type == XPATH_NODESET) {
	    int i;
	    for ( i = 0; i < xpathNode -> nodesetval -> nodeNr; i++ ) {
		xmlNodePtr n = xpathNode -> nodesetval -> nodeTab[i];
		if (n -> type == XML_TEXT_NODE || n-> type == XML_CDATA_SECTION_NODE
		    || n -> type == 1) {
		  //----------------------------//
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
		 //---------------------------------------//

		 g_hash_table_insert(tabnoeud,node->id,node);
		}
	      }
	 }
	 xmlXPathFreeObject(xpathNode);
	 xmlXPathFreeContext(ctxt);
	 return 0;
  }


int main(int argc,char ** argv) {
  Map *map =new_map(argv[1]); 
  /* exemple recuperer lat et lon d'un noeud specifie avec son id*/
  Node *n = g_hash_table_lookup(map->nodes,"331845156");
  printf("lat: %f, lon: %f\n", n->lat,n->lon);
  return 0;
}


