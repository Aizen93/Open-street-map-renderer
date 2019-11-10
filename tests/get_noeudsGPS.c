#include<stdlib.h>
#include<libxml/parser.h>
#include<libxml/xpath.h>

xmlDocPtr
getdoc (char *docname) {
	xmlDocPtr doc;
	doc = xmlParseFile(docname);
	
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
		return NULL;
	}

	return doc;
}

int main(int argc, char ** argv) {

 char *docname;
 xmlDocPtr doc;

 docname = argv[1];
 doc = getdoc(docname);
 //initialisation de l'environnement XPath
 xmlXPathContextPtr ctxt = xmlXPathNewContext(doc);
 if (ctxt == NULL) {
     fprintf(stderr,"Erreur lors de la creation du contexte XPath\n");
     exit(-1);
 }

 // evaluation de l'expression
 xmlXPathObjectPtr xpathNode = xmlXPathEvalExpression(BAD_CAST "/osm/node", ctxt);
 if (xpathNode == NULL) {
     fprintf(stderr,"Erreur sur l'expression Xpath\n");
     exit(-1);
 }
 
 // Manipulation du résultat
 if (xpathNode -> type == XPATH_NODESET) {
    int i;
    printf("résultats: \n");
    for ( i = 0; i < xpathNode -> nodesetval -> nodeNr; i++ ) {
        xmlNodePtr n = xpathNode -> nodesetval -> nodeTab[i];
        if (n -> type == XML_TEXT_NODE || n-> type == XML_CDATA_SECTION_NODE
            || n -> type == 1) {
  		//
	  printf("lat:%s lon:%s\n",xmlGetProp(n, "lat"),xmlGetProp(n, "lon"));
	}
      }
 }

 xmlXPathFreeObject(xpathNode);
 xmlXPathFreeContext(ctxt);
 return 0;
}

