#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "linkcut/linkcut.h"
#include "linkcut/linkcut_viz.h"
#include "linkcut/splay_viz.h"
#include "common/macros.h"
using namespace std;

void print_linkcut( Linkcut_vertex ** vertex, int size){
  loop(i,size){
    int k = -1;
    int p = -1;
    int bp = -1;
    int l = -1;
    int r = -1;
    Linkcut_vertex * v =vertex[i];
    k = v->key;
    if( v->parent != NULL)
      p = v->parent->key;

    if( v->bparent != NULL)
      bp = v->bparent->key;

    if( v->left != NULL)
      l = v->left->key;

    if( v->right != NULL)
      r = v->right->key;

    printf("key: %d\tparent: %d\tbparent: %d\tleft: %d\tright:%d\n", k, p, bp, l, r);
  }
}

int main( int argc, char ** argv) {
  /* A sample use of these functions.  Start with the empty tree,         */
  /* insert some stuff into it, and then delete it                        */
  viz_set_args( argc, argv);
  srand(1234);


  int n = 20;

  Linkcut_vertex ** vertex = new Linkcut_vertex*[n];

  vector<int> r;
  loop(i,n){
    vertex[i] = make_tree(i);
    r.push_back(i);
  }


  random_shuffle( all(r));
  disable_drawing();

  linkcut_draw(vertex, n);
  int c = n;
  while(1){
//    print_linkcut(vertex,n);
    int v = rand()%n;
    int w = rand()%n;
    int vr = root(vertex[v])->key;
    int wr = root(vertex[w])->key;
    vector<int> rs;
    rs.push_back(v);
    rs.push_back(w);
    rs.push_back(vr);
  
//    printf("root of %d is %d\n", v, i);
    if( vr != wr){
      printf("link v:%d w:%d\n", vr, w);
      vector<int> color;
      color.push_back(vr);
      color.push_back(w);

      linkcut_draw(vertex, n, color);
      link_tree(vertex[vr], vertex[w]);
      linkcut_draw(vertex, n, color);
      c--;
      if( c == 1){
        break;
      }
    }
  }
  enable_drawing();

  linkcut_draw(vertex, n);
  {
/*
    int r;
    r = 12;
    vector<int> color;
    color.push_back(r);
    evert(vertex[r]);
    linkcut_draw(vertex, n, color);

    {
      int r = 12;
      vector<int> color;
      color.clear();
      color.push_back(r);
      splay_draw( vertex[r]);
      splay( vertex[r]);
      splay_draw( vertex[r]);
      linkcut_draw(vertex, n, color);
      expose( vertex[r]);
      linkcut_draw(vertex, n, color);
      evert(vertex[r]);
      linkcut_draw(vertex, n, color);
    };
    {
      int r = 10;
      vector<int> color;
      color.clear();
      color.push_back(r);
      splay_draw( vertex[r]);
      splay( vertex[r]);
      splay_draw( vertex[r]);
      linkcut_draw(vertex, n, color);
      expose( vertex[r]);
      linkcut_draw(vertex, n, color);
      evert(vertex[r]);
      linkcut_draw(vertex, n, color);
    };
*/
  };

  while(1){
    int r;
    scanf("%d", &r);
    if( r < 0){
      break;
    }
    vector<int> color;
    color.push_back(r);
    expose( vertex[r]);
    linkcut_draw(vertex, n, color);
    evert(vertex[r]);
    linkcut_draw(vertex, n, color);
    print_linkcut( vertex, n);
  }


  loop(i,n){
    vector<int> color;
    color.push_back(i);
    linkcut_draw(vertex, n, color);
    printf("cut v:%d\n", i);
    cut_tree(vertex[i]);
  }
  

  delete []vertex;

  return 0;
}
