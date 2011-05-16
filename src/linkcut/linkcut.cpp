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
    v->left = NULL;
    v->reversed = ! v->reversed;
  }
}

Linkcut_vertex * splice( Linkcut_vertex * v){
  Linkcut_vertex * w = v->bparent;
  splay(w);
  lc_cut(w);

  if( ! v->reversed){
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
  mark();
  splay(v);
  mark();
  lc_cut(v);
  mark();

  Linkcut_vertex * vit = v;
  mark();
  while( vit->bparent != NULL){
  mark();
    vit = splice(vit);
  }
  mark();
  splay(v);
  mark();
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
  mark();
  expose(v);
  mark();
  Linkcut_vertex * r = v;
  mark();
  while( r->left != NULL){
  mark();
    r = r->left;
  }
  mark();
  splay(r);
  mark();
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
