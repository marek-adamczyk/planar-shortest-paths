#include <stdio.h>
#include "common/err.h"
#include "common/viz.h"
#include "splay/splay_viz.h"

extern "C"{

void create_splay_tree_viz( Splay_tree * parent, Splay_tree * tree, Agraph_t *g, Agnode_t **node){
  if( ! tree){
    syserr("tree jest nullem");
  };
  node[tree->key] = agnnode( g, tree->key);
  if( parent){
    agedge(g, node[parent->key], node[tree->key]);
  };
  if( tree->left){
    create_splay_tree_viz( tree, tree->left, g, node);
  };
  if( tree->right){
    create_splay_tree_viz( tree, tree->right, g, node);
  };
}

int viz_find_max( Splay_tree * tree){
  Splay_tree * it = tree;
  while( it->right){
    it = it->right;
  }
  return it->key;
}

void splay_draw( Splay_tree * tree, int colnode){
  /*
     if( tree){
     printf("dem root is %d\n", tree->item);
     } else{
     printf("dem tree is empty\n");
     }
   */
  if( ! tree){
    return;
  }
  GVC_t *gvc = gvContext();
  viz_set_gvc( gvc, "splay");

  Agraph_t *g = agopen("aa", AGDIGRAPH);
  int max_key = viz_find_max(tree);
  Agnode_t *node[max_key];/*zakladamy, ze uniwersum kluczy jest nieduze i mozemy indeksowac jego elementami*/

  //tutaj dodaj krawedzie i wierzcholki
  create_splay_tree_viz( NULL, tree, g, node);
  agsafeset( node[colnode], "color", "red", "");

  printf("jestem tu\n");

  if( viz_draw( gvc, g)){
    syserr("blad rysowania");/*to nie jest blad systemowy; potem zdefiniowac wlasna obsluge*/
  }
}
}
