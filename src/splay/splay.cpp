/*
   An implementation of top-down splaying with sizes
   D. Sleator <sleator@cs.cmu.edu>, January 1994.

   This extends top-down-splay.c to maintain a size field in each node.
   This is the number of nodes in the subtree rooted there.  This makes
   it possible to efficiently compute the rank of a key.  (The rank is
   the number of nodes to the left of the given key.)  It it also
   possible to quickly find the node of a given rank.  Both of these
   operations are illustrated in the code below.  The remainder of this
   introduction is taken from top-down-splay.c.

   "Splay trees", or "self-adjusting search trees" are a simple and
   efficient data structure for storing an ordered set.  The data
   structure consists of a binary tree, with no additional fields.  It
   allows searching, insertion, deletion, deletemin, deletemax,
   splitting, joining, and many other operations, all with amortized
   logarithmic performance.  Since the trees adapt to the sequence of
   requests, their performance on real access patterns is typically even
   better.  Splay trees are described in a number of texts and papers
   [1,2,3,4].

   The code here is adapted from simple top-down splay, at the bottom of
   page 669 of [2].  It can be obtained via anonymous ftp from
   spade.pc.cs.cmu.edu in directory /usr/sleator/public.

   The chief modification here is that the splay operation works even if the
   item being splayed is not in the tree, and even if the tree root of the
   tree is NULL.  So the line:

   t = splay(i, t);

   causes it to search for item with key i in the tree rooted at t.  If it's
   there, it is splayed to the root.  If it isn't there, then the node put
   at the root is the last one before NULL that would have been reached in a
   normal binary search for i.  (It's a neighbor of i in the tree.)  This
   allows many other operations to be easily implemented, as shown below.

   [1] "Data Structures and Their Algorithms", Lewis and Denenberg,
   Harper Collins, 1991, pp 243-251.
   [2] "Self-adjusting Binary Search Trees" Sleator and Tarjan,
   JACM Volume 32, No 3, July 1985, pp 652-686.
   [3] "Data Structure and Algorithm Analysis", Mark Weiss,
   Benjamin Cummins, 1992, pp 119-130.
   [4] "Data Structures, Algorithms, and Performance", Derick Wood,
   Addison-Wesley, 1993, pp 367-375

   The following code was written by Daniel Sleator, and is released
   in the public domain.
 */

#include <stdio.h>
#include <stdlib.h>
#include "splay/splay.h"
#include "common/err.h"

#define compare(i,j) ((i)-(j))
/* This is the comparison.                                       */
/* Returns <0 if i<j, =0 if i=j, and >0 if i>j                   */

extern "C"{

Splay_tree * splay (int i, Splay_tree *t) 
  /* Splay using the key i (which may or may not be in the tree.) */
  /* The starting root is t, and the tree used is defined by rat  */
  /* size fields are maintained */
{
  Splay_tree N, *l, *r, *y;
  int comp, root_size, l_size, r_size;

  if (t == NULL) return t;
  N.left = N.right = NULL;
  l = r = &N;
  root_size = node_size(t);
  l_size = r_size = 0;

  for (;;) {
    comp = compare(i, t->key);
    if (comp < 0) {
      if (t->left == NULL) break;
      if (compare(i, t->left->key) < 0) {
        y = t->left;                           /* rotate right */
        t->left = y->right;
        y->right = t;
        t->size = node_size(t->left) + node_size(t->right) + 1;
        t = y;
        if (t->left == NULL) break;
      }
      r->left = t;                               /* link right */
      r = t;
      t = t->left;
      r_size += 1+node_size(r->right);
    } else if (comp > 0) {
      if (t->right == NULL) break;
      if (compare(i, t->right->key) > 0) {
        y = t->right;                          /* rotate left */
        t->right = y->left;
        y->left = t;
        t->size = node_size(t->left) + node_size(t->right) + 1;
        t = y;
        if (t->right == NULL) break;
      }
      l->right = t;                              /* link left */
      l = t;
      t = t->right;
      l_size += 1+node_size(l->left);
    } else {
      break;
    }
  }
  l_size += node_size(t->left);  /* Now l_size and r_size are the sizes of */
  r_size += node_size(t->right); /* the left and right trees we just built.*/
  t->size = l_size + r_size + 1;

  l->right = r->left = NULL;

  /* The following two loops correct the size fields of the right path  */
  /* from the left child of the root and the right path from the left   */
  /* child of the root.                                                 */
  for (y = N.right; y != NULL; y = y->right) {
    y->size = l_size;
    l_size -= 1+node_size(y->left);
  }
  for (y = N.left; y != NULL; y = y->left) {
    y->size = r_size;
    r_size -= 1+node_size(y->right);
  }

  l->right = t->left;                                /* assemble */
  r->left = t->right;
  t->left = N.right;
  t->right = N.left;

  return t;
}

Splay_tree * splay_insert(int i, Splay_tree * t) {
  /* Insert key i into the tree t, if it is not already there. */
  /* Return a pointer to the resulting tree.                   */
  Splay_tree * new_tree;

  if (t != NULL) {
    t = splay(i,t);
    if (compare(i, t->key)==0) {
      return t;  /* it's already there */
    }
  }
  new_tree = (Splay_tree *) malloc (sizeof (Splay_tree));
  if (new_tree == NULL) {
    syserr("Ran out of space");
  }
  if (t == NULL) {
    new_tree->left = new_tree->right = NULL;
  } else if (compare(i, t->key) < 0) {
    new_tree->left = t->left;
    new_tree->right = t;
    t->left = NULL;
    t->size = 1+node_size(t->right);
  } else {
    new_tree->right = t->right;
    new_tree->left = t;
    t->right = NULL;
    t->size = 1+node_size(t->left);
  }
  new_tree->key = i;
  new_tree->size = 1 + node_size(new_tree->left) + node_size(new_tree->right);
  return new_tree;
}

Splay_tree * splay_delete(int i, Splay_tree *t) {
  /* Deletes i from the tree if it's there.               */
  /* Return a pointer to the resulting tree.              */
  Splay_tree * x;
  int tsize;

  if (t==NULL) return NULL;
  tsize = t->size;
  t = splay(i,t);
  if (compare(i, t->key) == 0) {               /* found it */
    if (t->left == NULL) {
      x = t->right;
    } else {
      x = splay(i, t->left);
      x->right = t->right;
    }
    free(t);
    if (x != NULL) {
      x->size = tsize-1;
    }
    return x;
  } else {
    return t;                         /* It wasn't there */
  }
}
}
