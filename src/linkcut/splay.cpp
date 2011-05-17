#include <stdlib.h>
#include <stdio.h>
#include "linkcut/splay.h"
#include "linkcut/splay_viz.h"
#include "common/macros.h"
#include "common/err.h"

extern "C"{

Splay_tree * splay_new_node( Splay_tree * parent, int key){
  Splay_tree * new_node = (Splay_tree *) malloc(sizeof(Splay_tree));
  new_node->key = key;
  new_node->parent = parent; 
  new_node->bparent = NULL;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->reversed = false;
  return new_node;
}

#define print_tree( s) __print_tree(s,0)

  void __print_tree( Splay_tree * v, int indent){
    if( v == NULL)
      return;

    loop(i,indent)
      printf(" ");
    printf("pt: %d", v->key);
    if( v->parent != NULL)
      printf(" %d", v->parent->key);

    printf("\n");

    __print_tree(v->left, indent+2);
    __print_tree(v->right, indent+2);
  }



#define is_left(v) ((v)->parent->left == (v))
#define is_leaf(v) ((v->left == NULL) && (v->right == NULL))
#define revert(v) if( v != NULL){ v->reversed = ! v->reversed; }

Splay_tree * path_tail( Splay_tree * v){
  if( ! v->reversed){
    if( v->right == NULL){
      return v;
    } else{
      return path_tail(v->right);
    }
  } else{
    if( v->left == NULL){ 
      return v;
    } else{
      return path_head(v->left);
    }
  } 
}   
Splay_tree * path_head( Splay_tree * v){
  if( ! v->reversed){
    if( v->left == NULL){
      return v;
    } else{
      return path_head(v->left);
    }
  } else{
    if( v->right == NULL){
      return v;
    } else{
      return path_tail(v->right);
    }
  }
}


void alter( Splay_tree * v){
  v->reversed = ! v->reversed;
  Splay_tree * tmp = v->left;
  v->left = v->right;
  v->right = tmp;

  revert( v->left);
  revert( v->right);
}

void rotate_right( Splay_tree * v){

  Splay_tree * w = v->parent;
  Splay_tree * u = v->left;

  if( w != NULL){
    if( is_left(v)){
      w->left = u;
    } else{
      w->right = u;
    }
  }
  u->parent = w;
  v->parent = u;

  if( v->reversed == false && u->reversed == false){
    v->left = u->right;
  } else if( v->reversed == true && u->reversed == false){
    v->left = u->right;

    u->reversed = true;
    v->reversed = false;
  } else if( v->reversed == false && u->reversed == true){
    v->left = u->left;
    u->left = u->right;

    u->reversed = false;
    revert(u->left);
    revert(v->left);
  } else if( v->reversed == true && u->reversed == true){
    v->left = u->left;
    u->left = u->right;

    v->reversed = false;
    revert(u->left);
    revert(v->left);
  };

  u->right = v;
  if( v->left != NULL){
    v->left->parent = v;
  }
}

void rotate_left( Splay_tree * v){

  Splay_tree * w = v->parent;
  Splay_tree * u = v->right;

  if( w != NULL){
    if( is_left(v)){
      w->left = u;
    } else{
      w->right = u;
    }
  }
  u->parent = w;
  v->parent = u;

  if( v->reversed == false && u->reversed == false){
    v->right = u->left;
    //v->left = u->right;
  } else if( v->reversed == true && u->reversed == false){
    v->right = u->left;
    //v->left = u->right;

    u->reversed = true;
    v->reversed = false;
  } else if( v->reversed == false && u->reversed == true){
    v->right = u->right;
    u->right = u->left;

    u->reversed = false;
    revert(u->right);
    revert(v->right);
  } else if( v->reversed == true && u->reversed == true){
    v->right = u->right;
    u->right = u->left;

    v->reversed = false;
    revert(u->right);
    revert(v->right);
  };

  u->left = v;
  if( v->right != NULL){
    v->right->parent = v;
  }
}

/*
   Perform appropriate rotation on the parent of v.
 */

void rotate( Splay_tree * v){
  if( is_left(v)){
    rotate_right(v->parent);
  } else{
    rotate_left(v->parent);
  }
}

Splay_tree * splay_root( Splay_tree * v){
  Splay_tree * i = v;
  while( i->parent != NULL){
    i = i->parent;
  }
  return i;
}

void splay( Splay_tree * v){
  /* bparent pointer is always stored in the root*/
  Splay_tree * r = splay_root(v);
  if( r != v){
    v->bparent = r->bparent;
    r->bparent = NULL;
  }

  Splay_tree * w, * u;
  while( (w = v->parent) != NULL){
    if( (u = w->parent) == NULL){
      rotate(v);
    } else{ /* u != NULL*/
      if( is_left(v) ^ is_left(w)){/* both different */
        rotate(v);
        rotate(v);
      } else{ /* both sameside children */
        rotate(w);
        rotate(v);
      }
    }
  }
}

void reverse( Splay_tree * v){
  v->reversed = ! v->reversed;
}

////////////////

void append_left( Splay_tree * v, Splay_tree * w){
  myassert( v->left == NULL);
  myassert( w->parent == NULL);
  v->left = w;
  w->parent = v;
}

void append_right( Splay_tree * v, Splay_tree * w){
  myassert( v->right == NULL);
  myassert( w->parent == NULL);
  v->right = w;
  w->parent = v;
}

/*
Splay_tree * insert( Splay_tree * v, int x){
  Splay_tree * i = splay_root(v);
  Splay_tree * s;

  while( i != NULL){
    s = i;
    if( x <= i->key ){
      i = i->left;
    } else{
      i = i->right;
    }
  }
  splay(s);
  if( s->key == x){
    return s;
  }

  Splay_tree * new_node = splay_new_node( s, x);
  if( x < s->key){
    new_node->left = s->left;
    s->left = new_node;    
    if( new_node->left != NULL){
      new_node->left->parent = new_node;
    }
  } else{
    new_node->right = s->right;
    s->right = new_node;    
    if( new_node->right != NULL){
      new_node->right->parent = new_node;
    }
  }
  return s;
}
*/
}
