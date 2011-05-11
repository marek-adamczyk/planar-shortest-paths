#include "linkcut/linkcut.h"
#include "linkcut/linkcut_viz.h"
#include "common/macros.h"


int main( int argc, char ** argv) {
  /* A sample use of these functions.  Start with the empty tree,         */
  /* insert some stuff into it, and then delete it                        */
  viz_set_args( argc, argv);


  int n = 10;

  Linkcut_vertex ** vertex = new Linkcut_vertex*[n];

  mark();
  loop(i,n){
    vertex[i] = make_tree(i);
  }
  mark();

  linkcut_draw(vertex, n);
  mark();


  delete []vertex;

  return 0;
}
