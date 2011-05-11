#ifndef _LINKCUT_H_
#define _LINKCUT_H_
#include "linkcut/splay.h"

extern "C" {
  typedef splay_tree_node Linkcut_vertex;

  Linkcut_vertex * make_tree( int id);
  void cut( Linkcut_vertex * v);
  void link( Linkcut_vertex * v, Linkcut_vertex * w);
  Linkcut_vertex * root( Linkcut_vertex * v);

}

#ifdef _NIEWAZNE_
/*
   Return the parent of u. If u has no parent (it is a tree root),
   return a special value null.
 */
Linkcut_vertex * parent( Linkcut_vertex * v);

/*
   Return the root of the tree containing u.
 */
Linkcut_vertex * root( Linkcut_vertex * v);

/*
   Return the cost of the edge (u,parenf(u)).This operation assumes
   that u is not a tree root.
 */
int cost( Linkcut_vertex * v);

/*
   Return the vertex w closest to root(u) such that the edge (w,parent(w)) has minimum cost among edges on the tree path from u to root(u).
   This operation assumes that v is not a tree root.
 */
int mincost( Linkcut_vertex * v);

/*
   Modify the costs of all edges on the tree path from u to
   roof(u)by adding x to the cost of each edge.
 */
void update( Linkcut_vertex * v, int x);

/*
   Combine the trees containing u and w by adding the edge
   (u, w ) of cost x, making w the parent of v. This operation assumes that u and w are in
   different trees and v is a tree root.
 */
void link( Linkcut_vertex * v, Linkcut_vertex * w, int x);

/*
   Divide the tree containing vertex v into two trees by deleting the
   edge (v,parent(v)); return the cost of this edge. This operation assumes that v is not a tree root.
 */
int cut( Linkcut_vertex * v);

/*
   Modify the tree containing vertex v by making v the root. (This
   operation can be regarded as reversing the direction of every edge on the path from v
   to the original root.)
 */
void evert( Linkcut_vertex * v);

#endif

#endif
