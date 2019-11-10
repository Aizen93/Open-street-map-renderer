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
 xmlXPathObjectPtr xpathRes = xmlXPathEvalExpression(BAD_CAST "/osm/way[@id = '32346583']/nd", ctxt);
 /* pour avoir les tag*/
 xmlXPathObjectPtr xpathCat = xmlXPathEvalExpression(BAD_CAST "/osm/way[@id = '32346583']/tag", ctxt);
 if (xpathRes == NULL) {
     fprintf(stderr,"Erreur sur l'expression Xpath\n");
     exit(-1);
 }
 
 // Manipulation du résultat
 if (xpathRes -> type == XPATH_NODESET) {
    int i;
    printf("résultats: \n");
    for ( i = 0; i < xpathRes -> nodesetval -> nodeNr; i++ ) {
        xmlNodePtr n = xpathRes -> nodesetval -> nodeTab[i];
        if (n -> type == XML_TEXT_NODE || n-> type == XML_CDATA_SECTION_NODE
            || n -> type == 1) {
  		//
	  printf("noeud : %s %s\n",n-> name,xmlGetProp(n, "ref"));
	}
      }
 }

  if (xpathCat -> type == XPATH_NODESET) {
    int i;
   // printf("résultats: \n");
    for ( i = 0; i < xpathCat -> nodesetval -> nodeNr; i++ ) {
        xmlNodePtr n = xpathCat -> nodesetval -> nodeTab[i];
        if (n -> type == XML_TEXT_NODE || n-> type == XML_CDATA_SECTION_NODE
            || n -> type == 1) {
  		//
	  printf("noeud : %s %s\n",n-> name,xmlGetProp(n, "k"));
	}
      }
 }
 

 xmlXPathFreeObject(xpathRes);
 xmlXPathFreeObject(xpathCat);
 xmlXPathFreeContext(ctxt);
 return 0;
}

