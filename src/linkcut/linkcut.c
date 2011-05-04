#include "linkcut/linkcut.h"
#include "linkcut/path.h"


Path * splice( Path * p){
	Path * q,r;
	int x,y;
	Path_vertex * v = dparent(tail(p));
	split( p, q, r, &x, &y);
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
}



