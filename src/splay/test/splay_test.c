#include <stdio.h>
#include <splay/splay.h>


int main() {
/* A sample use of these functions.  Start with the empty tree,         */
/* insert some stuff into it, and then delete it                        */
    Splay_tree * root;
    int i;
    root = NULL;              /* the empty tree */
    for (i = 0; i < 1024; i++) {
        root = splay_insert((541*i) & (1023), root);
    }
    for (i = 0; i < 1024; i++) {
        root = splay_delete((541*i) & (1023), root);
    }
    return 0;
}
      
