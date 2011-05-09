#include <stdlib.h>
#include "common/err.h"
#include "linkcut/linkcut.h"
#include "linkcut/splay.h"

extern "C"{

Linkcut_vertex * make_tree(){
  Linkcut_vertex * res = (Linkcut_vertex *)malloc(sizeof(Linkcut_vertex));
  if( ! res){
    syserr("Ran out of space");
  }
  return res;
}

void expose( Linkcut_vertex * v){
  splay(v);
}

/*

Path * splice( Path * p){
  Path *q, *r;
  int x,y;
  Path_vertex * v = dparent(tail(p));
  split( v, q, r, &x, &y);
  if( q != NULL){
    dparent(tail(q)) = v;
    dcost(tail(q)) = x;
  }
  p = concatenate( p, path(v), dcost(tail(p)));
  if( r == NULL){
    return p;
  } else{
    return concatenate( p, r, y);
  }
}

Path * expose( Path_vertex * v){
  Path *p, *q, *r;
  int x,y;
  split( v, q, r, &x, &y);
  if( q != NULL){
    dparent(tail(q)) = v;
    dcost(tail(q)) = x;
  };
  if( r == NULL){
    p = path(v);
  } else{
    p = concatenate( path(v), r, y);
  }
  while( dparent(tail(p)) != NULL){
    p = splice(p);
  }
  return p;
}

Linkcut_vertex * parent( Linkcut_vertex * v){
  if( v == tail( path(v))){
    return dparent(v);
  } else{
    return after(v);
  } 
}

Linkcut_vertex * root( Linkcut_vertex * v){
  return tail(expose(v));
}

int cost( Linkcut_vertex * v){
  if( v == tail( path(v))){
    return dcost(v);
  } else{
    return pcost(v);
  }
}

int mincost( Linkcut_vertex * v){
  return pmincost(expose(v));
}

void update( Linkcut_vertex * v, int x){
  return pupdate(expose(v), x);
}

void link( Linkcut_vertex * v, Linkcut_vertex * w, int x){
  concatenate( path(v), expose(w), x);
}

int cut( Linkcut_vertex * v){
  Path *p, *q;
  int x,y;
  expose(v);
  split( v, p, q, &x, &y);
  dparent(v) = NULL;
  return y;
}	 

void evert( Linkcut_vertex * v){
  reverse( expose(v));
  dparent(v) = NULL;
}
*/

}
