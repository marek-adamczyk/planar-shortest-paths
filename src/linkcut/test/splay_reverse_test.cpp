#include <iostream>
#include <algorithm>
#include <vector>
#include "linkcut/splay.h"
#include "linkcut/splay_viz.h"
#include "common/macros.h"
#include "common/viz.h"
#include "common/err.h"
using namespace std;

vector<int> order_splay( Splay_tree * v){
  vector<int> res;
  if( v == NULL){
    return res;
  }

  vector<int> left(order_splay(v->left));
  vector<int> right(order_splay(v->right));
  res.insert(res.end(),all(left));
  res.push_back(v->key);
  res.insert(res.end(),all(right));

  if( v->reversed){
    reverse(all(res));
  }
  return res;
}


void check_order( Splay_tree * r){
  int a = 0;
  int b = 0;
    vector<int> ord = order_splay(r);
/* 
    loop(j, ord.size()){
      cerr << ord[j] << " ";
    }
    cerr << endl;*/
  loopfrom(i,1,ord.size()){
    if( ord[i-1] < ord[i]){
      a++;
    } else{
      b++;
    }
  }
  myassert( a*b == 0);
}

int main( int argc, char ** argv) {
  /* A sample use of these functions.  Start with the empty tree,         */
  /* insert some stuff into it, and then delete it                        */
  viz_set_args( argc, argv);


  int n = 1024;

  Splay_tree ** v = new Splay_tree*[n];
  loop(i,n){
    v[i] = splay_new_node( NULL, i);
  }

  loopfrom(i,1,n){
    append_left( v[i], v[i-1]);
  }
  
  disable_drawing();
  splay_draw( v[0]);

  loop(i,n){
    int r = i*7 % n;
    cerr << r << endl;
    splay(v[r]);
    reverse( v[r]);
    splay_draw(v[r]);

    check_order(v[r]);
/*    vector<int> ord = order_splay(v[r]);
    loop(j, ord.size()){
      cerr << ord[j] << " ";
    }
    cerr << endl;*/

    int l = i*3 % n;
    cerr << l << endl;
    alter( v[r]);
    splay_draw(v[r]);

    check_order(v[r]);
/*    ord = order_splay(v[r]);
    loop(j, ord.size()){
      cerr << ord[j] << " ";
    }
    cerr << endl;*/
  }



  delete[] v;
  return 0;
}
