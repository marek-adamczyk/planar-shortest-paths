#ifndef _SPLAY_H_
#define _SPLAY_H_

typedef struct splay_tree_node Splay_tree;
struct splay_tree_node {
    Splay_tree * left;
    Splay_tree * right;
    int key;
    int size;   /* maintained to be the number of nodes rooted here */
};

#define node_size(x) (((x)==NULL) ? 0 : ((x)->size))
/* This macro returns the size of a node.  Unlike "x->size",     */
/* it works even if x=NULL.  The test could be avoided by using  */
/* a special version of NULL which was a real node with size 0.  */


Splay_tree * splay( int i, Splay_tree * t);
Splay_tree * splay_insert( int i, Splay_tree * t);
Splay_tree * splay_delete( int i, Splay_tree * t);

#endif
