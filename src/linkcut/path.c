#include "linkcut/path.h"

void initialize_paths( int n){
	__dparent = (Path_vertex **)malloc( n * sizeof(Path_vertex *));
	__dcost = (int *)malloc( n * sizeof(int));
}

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





