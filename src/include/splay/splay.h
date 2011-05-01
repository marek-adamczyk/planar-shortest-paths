#ifndef _SPLAY_H_
#define _SPLAY_H_

typedef struct splay_tree_node Splay_tree;
struct splay_tree_node {
    Splay_tree * left;
    Splay_tree * right;
    int item;
};

Splay_tree * splay( int i, Splay_tree * t);
Splay_tree * splay_insert( int i, Splay_tree * t);
Splay_tree * splay_delete( int i, Splay_tree * t);

#endif
