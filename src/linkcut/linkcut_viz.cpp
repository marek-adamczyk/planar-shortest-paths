#include <stdio.h>
#include "common/err.h"
#include "common/viz.h"
#include "linkcut/linkcut_viz.h"
#include "common/macros.h"

extern "C"{

void create_linkcut_forest_viz( Linkcut_vertex ** forest, int size, Agraph_t *g, Agnode_t ** node){
  loop(i,size){
    mark();
    node[i] = agnnode( g, i);
    mark();
    Agedge_t * e;
    mark();
    if( forest[i]->parent != NULL){
      mark();
      e = agedge(g, node[forest[i]->parent->key], node[i]);
      //      agsafeset(e, "style", "green", "");
    } else{
      if( forest[i]->bparent != NULL){
        mark();
        e = agedge(g, node[forest[i]->bparent->key], node[i]);
        mark();
        agsafeset(e, "style", "dashed", "");
      }
    }
  }
}

void linkcut_draw( Linkcut_vertex ** forest, int size){
  GVC_t *gvc = gvContext();
  viz_set_gvc( gvc, "linkcut");

  Agraph_t *g = agopen("aa", AGDIGRAPH);
  Agnode_t *node[size];

  create_linkcut_forest_viz( forest, size, g, node);

  if( viz_draw( gvc, g)){
    syserr("blad rysowania");/*to nie jest blad systemowy; potem zdefiniowac wlasna obsluge*/
  }
}
}
