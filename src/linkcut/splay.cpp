#include <stdlib.h>
#include "linkcut/splay.h"

extern "C"{

#define is_left(v) ((v)->parent->left == (v))
#define is_leaf(v) ((v->left == NULL) && (v->right == NULL))

/*
   We assume in below rotation operations that v has a parent.
 */
void rotate_right( Splay_tree * v){
  Splay_tree * w = v->parent;

  if( w->parent != NULL){
    if( is_left(w)){
      w->parent->left = v;
    } else{
      w->parent->right = v;
    }
  }
  v->parent = w->parent;
  w->parent = v;

  w->left = v->right;
  w->left->parent = w;
  v->right = w;
}

void rotate_left( Splay_tree * v){
  Splay_tree * w = v->parent;

  if( w->parent != NULL){
    if( is_left(w)){
      w->parent->left = v;
    } else{
      w->parent->right = v;
    }
  }
  v->parent = w->parent;
  w->parent = v;

  w->right = v->left;
  w->right->parent = w;
  v->left = w;
}

/*
   Perform appropriate rotation on the parent of v.
 */

void rotate( Splay_tree * v){
  if( is_left(v)){
    rotate_right(v->parent);
  } else{
    rotate_left(v->parent);
  }
}

void splay( Splay_tree * v){
  Splay_tree * w, * u;
  while( (w = v->parent) != NULL){
    if( (u = w->parent) == NULL){
      rotate(v);
    } else{ /* u != NULL*/
      if( is_left(v) ^ is_left(w)){/* both different */
        rotate(v);
        rotate(v);
      } else{ /* both sameside children */
        rotate(w);
        rotate(v);
      }
    }
  }
}

Splay_tree * root( Splay_tree * v){
  Splay_tree * i = v;
  while( i->parent != NULL){
    i = i->parent;
  }
  return i;
}

void insert( Splay_tree * v, int x){
  Splay_tree * i = root(v);
  Splay_tree * s;

  while( ! (i != NULL)){
    s = i;
    if( x <= i->key ){
      i = i->left;
    } else{
      i = i->right;
    }
  }

  splay(s);
  Splay_tree * new_node = (Splay_tree *) malloc(sizeof(Splay_tree));
}



}
#ifdef _NIEWAZNE_H_
Path * path( Path_vertex * v){
}

Path_vertex * head( Path * p);

Path_vertex * tail( Path * p);

/*
  Return the vertex before v on path(v). If v is the head of the
  path, return null.
*/
Path_vertex * before( Path_vertex * p);

/*
  Return the vertex after v on path(v). If v is the tail of the
  path, return null.
*/
Path_vertex * after( Path_vertex * p);


int cost( Path_vertex * v);

/*
                  Return the vertex u closest to tuil(p) such that (u, uffer(u))has
minimum cost among edges on p . This operation assumes that p contains more than
one vertex.
*/
int pmincost( Path * p);

/*
Add x to the cost of every edge on p.
*/
void pupdate( Path * p, int x);

/*
       Reverse the direction of p , making the head the tail and vice
versa.
*/
void reverse( Path * p);

/*
   Combine p and q by adding the edge (tuil(p),
heud(q)) of cost x. Return the combined path.
*/
Path * concatenate( Path * p, Path * q, int x);

/*
  Divide puth(v) into (up to) three parts by deleting the edges
incident to p. Return a list [ p , q, x, y ] , where p is the subpath consisting of all vertices
from head(puth(u)) to before(u), q is the subpath consisting of all vertices from
ufter(v) to tuil(puth(u)),x is the cost of the deleted edge(before(u), u), and y is the
cost of the deleted edge(u, ufter(u)).If u is originally the head of puth(u),p is null and
x is undefined; if u is originally the tail of puth(u), q is null and y is undefined.
*/
void split( Path_vertex * v, Path * p, Path * q, int * x, int * y);





#endif
