#include <stdio.h>
#include "common/err.h"
#include "common/viz.h"
#include "linkcut/splay_viz.h"
#include "common/macros.h"

extern "C"{

void create_splay_tree_viz( Splay_tree * tree, Agraph_t *g, Agnode_t **node){
  if( ! tree){
    syserr("tree jest nullem");
  };
  node[tree->key] = agnnode( g, tree->key);
  if( ! tree->reversed){

    agsafeset(node[tree->key], "color", "green", "");
  } else{
    agsafeset(node[tree->key], "color", "blue", "");
  }
  if( tree->parent != NULL){
    Agedge_t * e = agedge(g, node[tree->parent->key], node[tree->key]);
    if( tree == tree->parent->left){

      agsafeset(e, "color", "green", "");
    } else{
      agsafeset(e, "color", "blue", "");
    }
  };
  if( tree->left){
    create_splay_tree_viz( tree->left, g, node);
  }
  if( tree->right){
    create_splay_tree_viz( tree->right, g, node);
  }
}

void splay_draw( Splay_tree * tree){
  if( ! drawing_on()){
    return;
  }
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
  //  int max_key = viz_find_max(tree);
  Agnode_t ** node = (Agnode_t **)malloc( 1000 * sizeof(Agnode_t *));/*zakladamy, ze uniwersum kluczy jest nieduze i mozemy indeksowac jego elementami*/
  //tutaj dodaj krawedzie i wierzcholki
  Splay_tree * r = tree;
  while( r->parent != NULL) { r = r->parent; };
  create_splay_tree_viz( r, g, node);

  if( viz_draw( gvc, g)){
    syserr("blad rysowania");/*to nie jest blad systemowy; potem zdefiniowac wlasna obsluge*/
  }
}
}
