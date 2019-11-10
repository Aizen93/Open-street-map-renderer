#include<glib.h>
#include<libxml/parser.h>
#include<libxml/xpath.h>

#ifndef _WAY_H
#define _WAY_H

typedef struct Way Way;

//La structure way
struct Way {
  const char *id;
  const char *visible;
  int version;
  const char *changeset; //ou long/int?!
  const char *timestamp;
  const char *user;
  int uid;
  GArray *nd; //array liste de nd ,contenant que des chaines de caracteres
} way;


#endif
