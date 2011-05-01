#include <stdio.h>
#include <time.h>
#include "common/viz.h"
#include "splay/splay.h"
#include "splay/splay_draw.h"


int main( int argc, char ** argv) {
/* A sample use of these functions.  Start with the empty tree,         */
/* insert some stuff into it, and then delete it                        */
    Viz_set_args( argc, argv);

    Splay_tree * root;
    int i;

    int n = 1 << 5;
    int nmod = n-1;
    srand(1234);
    int a = (2*rand() + 1) & nmod;

    root = NULL;              /* the empty tree */
    for (i = 0; i < n; i++) {
        root = splay_insert((541*i) & nmod, root);
        splay_draw(root);
    }
    for (i = 0; i < n; i++) {
        root = splay_delete((541*i) & nmod, root);
        splay_draw(root);
    }
    return 0;
}
      