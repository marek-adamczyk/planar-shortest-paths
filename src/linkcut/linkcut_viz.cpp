#include <stdio.h>
#include <algorithm>
#include "common/err.h"
#include "common/viz.h"
#include "linkcut/linkcut_viz.h"
#include "common/macros.h"


vector<int> create_linkcut_path( Linkcut_vertex * v){
  vector<int> res;
  if( v == NULL){
    return res;
  }

  vector<int> left(create_linkcut_path(v->left));
  vector<int> right(create_linkcut_path(v->right));
  res.insert(res.end(),all(left));
  res.push_back(v->key);
  res.insert(res.end(),all(right));

  if( v->reversed){
    reverse(all(res));
  }
  return res;
}

void create_linkcut_splay_viz( Linkcut_vertex * v, Agraph_t * g, Agnode_t ** node){
  vector<int> path( create_linkcut_path( v));
  loopfrom(i,1,path.size()){
    Agedge_t * e = agedge(g, node[path[i-1]], node[path[i]]);
    agsafeset(e, "style", "solid", "");
  }
}


void create_linkcut_forest_viz( Linkcut_vertex ** forest, int size, Agraph_t *g, Agnode_t ** node){
  loop(i,size){
    node[i] = agnnode( g, i);
  }
  loop(i,size){
    if( forest[i]->parent == NULL){
      create_linkcut_splay_viz( forest[i], g, node);
    }
    if( forest[i]->bparent != NULL){
      Linkcut_vertex * t = path_head(forest[i]);
      Agedge_t * e = agedge(g, node[forest[i]->bparent->key], node[t->key]);
      agsafeset(e, "style", "dashed", "");
    }
  }
}

void linkcut_draw( Linkcut_vertex ** forest, int size){
  vector<int> empty;
  linkcut_draw(forest,size,empty);
}

void linkcut_draw( Linkcut_vertex ** forest, int size, vector<int> &colverts){
  if( ! drawing_on())
    return;

  GVC_t *gvc = gvContext();
  viz_set_gvc( gvc, "linkcut");

  Agraph_t *g = agopen("aa", AGDIGRAPH);
  Agnode_t ** node = new Agnode_t*[1000];
  //  Agnode_t ** node = (Agnode_t **)malloc( 1000  * sizeof(Agnode_t *));

  create_linkcut_forest_viz( forest, size, g, node);
  loop(i,colverts.size()){
    agsafeset( node[colverts[i]], "color", "red", "");
  }

  if( viz_draw( gvc, g)){
    free(node);
    syserr("blad rysowania");/*to nie jest blad systemowy; potem zdefiniowac wlasna obsluge*/
  }
  delete []node;
  //  free(node);
}
