#ifndef _SPLAY_H_423_
#define _SPLAY_H_423_

extern "C"{

typedef struct splay_tree_node Splay_tree;
struct splay_tree_node {
  Splay_tree * parent;
  Splay_tree * left;
  Splay_tree * right;

  Splay_tree * bparent;
  bool reversed;

  int key;
};

//#define rev( v) v->reversed = ! v->reversed

Splay_tree * splay_new_node( Splay_tree * parent, int key);

//#define is_left(v) ((v)->parent->left == (v))
//#define is_leaf(v) ((v->left == NULL) && (v->right == NULL))

void splay( Splay_tree * v);
void reverse( Splay_tree * v);

/*tylko do testow*/

void append_left( Splay_tree * v, Splay_tree * w);
void append_right( Splay_tree * v, Splay_tree * w);

}

#endif
