#include <iostream>
#include "linkcut/splay.h"
#include "linkcut/splay_viz.h"
#include "common/macros.h"
#include "common/viz.h"
using namespace std;

int main( int argc, char ** argv) {
  /* A sample use of these functions.  Start with the empty tree,         */
  /* insert some stuff into it, and then delete it                        */
  viz_set_args( argc, argv);


  int n = 160;

  Splay_tree * t = splay_new_node( NULL, n);

  loop(i,n){
    int x = i*7 % n;
    t = insert(t, x);
//    splay_draw(t, x);
  }

  return 0;
}