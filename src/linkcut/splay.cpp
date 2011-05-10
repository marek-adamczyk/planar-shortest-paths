#include <stdlib.h>
#include <stdio.h>
#include "linkcut/splay.h"
#include "linkcut/splay_viz.h"
#include "common/macros.h"

extern "C"{

Splay_tree * splay_new_node( Splay_tree * parent, int key){
        Splay_tree * new_node = (Splay_tree *) malloc(sizeof(Splay_tree));
        new_node->key = key;
        new_node->parent = parent; 
        new_node->left = NULL;
        new_node->right = NULL;
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
	v->left = u->right;
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
	v->right = u->left;
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

Splay_tree * root( Splay_tree * v){
	Splay_tree * i = v;
	while( i->parent != NULL){
		i = i->parent;
	}
	return i;
}

void splay( Splay_tree * v){
	Splay_tree * r = root(v);
	Splay_tree * w, * u;
	while( (w = v->parent) != NULL){
	//		splay_draw(r,v->key);
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


Splay_tree * insert( Splay_tree * v, int x){
	Splay_tree * i = root(v);
	Splay_tree * s;

	while( i != NULL){
		s = i;
		if( x <= i->key ){
			i = i->left;
		} else{
			i = i->right;
		}
	}
	splay_draw(root(v), s->key);
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



}
#ifdef _NIEWAZNE_H_
Path * path( Path_vertex * v){
}

Path_vertex * head( Path * p);

Path_vertex * tail( Path * p);

/*
   Return the vertex before v on path(v). If v is the head of the
   path, return null.
 */
Path_vertex * before( Path_vertex * p);

/*
   Return the vertex after v on path(v). If v is the tail of the
   path, return null.
 */
Path_vertex * after( Path_vertex * p);


int cost( Path_vertex * v);

/*
   Return the vertex u closest to tuil(p) such that (u, uffer(u))has
   minimum cost among edges on p . This operation assumes that p contains more than
   one vertex.
 */
int pmincost( Path * p);

/*
   Add x to the cost of every edge on p.
 */
void pupdate( Path * p, int x);

/*
   Reverse the direction of p , making the head the tail and vice
   versa.
 */
void reverse( Path * p);

/*
   Combine p and q by adding the edge (tuil(p),
   heud(q)) of cost x. Return the combined path.
 */
Path * concatenate( Path * p, Path * q, int x);

/*
   Divide puth(v) into (up to) three parts by deleting the edges
   incident to p. Return a list [ p , q, x, y ] , where p is the subpath consisting of all vertices
   from head(puth(u)) to before(u), q is the subpath consisting of all vertices from
   ufter(v) to tuil(puth(u)),x is the cost of the deleted edge(before(u), u), and y is the
   cost of the deleted edge(u, ufter(u)).If u is originally the head of puth(u),p is null and
   x is undefined; if u is originally the tail of puth(u), q is null and y is undefined.
 */
void split( Path_vertex * v, Path * p, Path * q, int * x, int * y);





#endif
