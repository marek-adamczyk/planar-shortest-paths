#include <stdlib.h>
#include "common/err.h"
#include "common/macros.h"
#include "linkcut/linkcut.h"
#include "linkcut/splay.h"
#include "linkcut/linkcut_viz.h"

extern "C"{

Linkcut_vertex * make_tree( int id){
  Linkcut_vertex * res = (Linkcut_vertex *)splay_new_node( NULL, id);
  if( ! res){
    syserr("Ran out of space");
  }
  return res;
}

/*right child cutoff */
void lc_cut( Linkcut_vertex * v){
  if( ! v->reversed){
    if( v->right == NULL){
      return;
    }
    v->right->parent = NULL;
    v->right->bparent = v;
    v->right = NULL;
  } else{
    if( v->left == NULL){
      return;
    }
    v->left->parent = NULL;
    v->left->bparent = v;
    v->left->reversed = ! v->left->reversed;
    v->left = NULL;
  }
}

Linkcut_vertex * splice( Linkcut_vertex * v){
  Linkcut_vertex * w = v->bparent;
  splay(w);
  lc_cut(w);

  if( ! w->reversed){
    w->right = v;
  } else{
    w->left = v;
    v->reversed = ! v->reversed;
  }
  v->parent = w;
  v->bparent = NULL;
  return w;
}

void expose( Linkcut_vertex * v){
  splay(v);
  lc_cut(v);

  Linkcut_vertex * vit = v;
  while( vit->bparent != NULL){
    vit = splice(vit);
  }
  splay(v);
}

void link_tree( Linkcut_vertex * v, Linkcut_vertex * w){
  expose(v);

  myassert( v->left == NULL);
  myassert( v->bparent == NULL);

  expose(w);
  myassert(w->right == NULL);
  w->right = v;
  v->parent = w;
  v->bparent = NULL;
}

Linkcut_vertex * root( Linkcut_vertex * v){
  expose(v);
  Linkcut_vertex * r = v;
  while( r->left != NULL){
    r = r->left;
  }
  splay(r);
  return r;
}

void cut_tree( Linkcut_vertex * v){
  expose(v);
  if( v->left != NULL){
    v->left->bparent = v->bparent;
    v->left->parent = NULL;
    v->left = NULL;
  }
  v->bparent = NULL;
}

void evert( Linkcut_vertex * v){
  expose(v);
  reverse(v);
}

}
