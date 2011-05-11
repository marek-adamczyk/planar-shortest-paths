#include <stdio.h>
#include "common/err.h"
#include "common/viz.h"
#include "linkcut/linkcut_viz.h"
#include "common/macros.h"

/* function returns a tail of the path represented by v's left subtree*/

Linkcut_vertex * before( Linkcut_vertex * v){
  if( v->left != NULL){
    Linkcut_vertex * it = v->left;
    while( it->right != NULL){
      it = it->right;
    }
    return it;
  } else{
    Linkcut_vertex * it = v;
    while( (it->parent != NULL) && (it == it->parent->left)){
      it = it->parent;
    }   
    return it->parent;
  }
}

void create_linkcut_forest_viz( Linkcut_vertex ** forest, int size, Agraph_t *g, Agnode_t ** node){
  loop(i,size){
    node[i] = agnnode( g, i);
  }

  
  loop(i,size){
    Agedge_t * e;
    if( before(forest[i]) != NULL){
      agedge(g,node[ before(forest[i])->key], node[i]);
    }

    if( forest[i]->bparent != NULL){
      Linkcut_vertex * it = forest[i];
      while( it->left != NULL){
        it = it->left;
      }
      e = agedge(g, node[forest[i]->bparent->key], node[it->key]);
      agsafeset(e, "style", "dashed", "");
    }
  }
/*
    if( forest[i]->parent != NULL){
      printf("parkey: %d\n", forest[i]->parent->key);
      e = agedge(g, node[forest[i]->parent->key], node[i]);
      //      agsafeset(e, "style", "green", "");
    } else{
      if( forest[i]->bparent != NULL){
        Linkcut_vertex * it = forest[i];
        while( it->left != NULL){
          it = it->left;
        }
        e = agedge(g, node[forest[i]->bparent->key], node[it->key]);
        agsafeset(e, "style", "dashed", "");
      }
    }
  }
*/
}

void linkcut_draw( Linkcut_vertex ** forest, int size){
  vector<int> empty;
  linkcut_draw(forest,size,empty);
}
void linkcut_draw( Linkcut_vertex ** forest, int size, vector<int> &colverts){
  GVC_t *gvc = gvContext();
  viz_set_gvc( gvc, "linkcut");

  Agraph_t *g = agopen("aa", AGDIGRAPH);
  Agnode_t *node[size];

  create_linkcut_forest_viz( forest, size, g, node);
  loop(i,colverts.size()){
    agsafeset( node[colverts[i]], "color", "red", "");
  }

  if( viz_draw( gvc, g)){
    syserr("blad rysowania");/*to nie jest blad systemowy; potem zdefiniowac wlasna obsluge*/
  }
}
