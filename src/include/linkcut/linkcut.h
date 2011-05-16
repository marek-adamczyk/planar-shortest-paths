#ifndef _LINKCUT_H_
#define _LINKCUT_H_
#include "linkcut/splay.h"

extern "C" {
  typedef splay_tree_node Linkcut_vertex;

  Linkcut_vertex * make_tree( int id);
  void cut_tree( Linkcut_vertex * v);
  void link_tree( Linkcut_vertex * v, Linkcut_vertex * w);
  Linkcut_vertex * root( Linkcut_vertex * v);
  void evert( Linkcut_vertex * v);
  void expose( Linkcut_vertex * v);

  Linkcut_vertex * parent( Linkcut_vertex * v);
}

#endif
