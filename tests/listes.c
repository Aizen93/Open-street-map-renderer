#include<stdlib.h>
#include<glib.h>

// NB: gcc listes.c -o listes `pkg-config --cflags --libs glib-2.0`
int main() {
  GHashTable* table ;
  //de toute facon on recupere ces donnees en chaine de caracteres depuis .xml
  gpointer key = "id";
  gpointer val1 = "3331514";
 
  table = g_hash_table_new (NULL,NULL);

  //ajouter une cle et la valeur correspondante a la cle
  g_hash_table_insert(table,key,val1);
  
  //recuperer la valeur d'une cle
  gpointer rep = g_hash_table_lookup(table,key);

  // pour afficher la valeur mais il faut caster
  g_printf((gchar const *)rep); 
  g_printf("\n");

  return 0;
}
