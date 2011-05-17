#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <algorithm>
#include "linkcut/linkcut.h"
#include "linkcut/linkcut_viz.h"
#include "common/viz.h"
#include "common/macros.h"
using namespace std;

#define foreachrow(r) for( int r = 1; r <= n1; r++)
#define foreachcol(c) for( int c = n1+1; c < N; c++)
#define foreachadj(it,vert) for( unsigned int i = 0, it; (i < graph[vert].size()) && ((it = graph[vert][i]) || true); i++)

static int n1,n2,N,M;
vector<int> *graph;
Linkcut_vertex ** tree;

int * coldeg;
int domsnum;
int leafnum;

inline bool iscol( int v){  return n1 < v;}
inline bool isrow( int v){  return n1 >= v;}

inline void addedge( int a, int b){
  graph[a].push_back(b);
  graph[b].push_back(a);
}

void createtree(){
  coldeg = new int[N];
  memset( coldeg, 0, sizeof(int)*N);

  tree = new Linkcut_vertex*[N];
  for( int i = 0; i <= N; i++){
    tree[i] = make_tree(i);
  }
  
  domsnum = 0;
  leafnum = n2;
  foreachrow(r){
    if( graph[r].size() > 0){
      int c = graph[r][0];
      link_tree(tree[r], tree[c]);
      coldeg[c]++;
      if( coldeg[c] == 1)
        leafnum--;
      if( coldeg[c] == 2)
        domsnum++;
    }
  }
}

int * rakestate;
/*wynik mowi czy drzewo jest zaczesane, tzn nie znalezlismy krawedzi do jakiejs kolumny liscia*/
bool rakeat( int v, int dom){
  int rootu;
  bool res = true;

  rakestate[v] = 1;
  if( isrow(v)){
    foreachadj(u,v){
      rootu = root(tree[u])->key;
      if( rootu != dom){
        if( coldeg[rootu] == 0){
          res = false;
        };
        if( coldeg[rootu] == 1){
          cut_tree(tree[u]);
          link_tree(tree[u],tree[v]);
        }
      }
    }
  }

  foreachadj(u,v){
    rootu = root(tree[u])->key;
    if( rootu == dom){
      if( rakestate[u] == 0){
        res &= rakeat(u, dom);
      }
    }
  }

  rakestate[v] = 2;
  return res;
}

bool rake(){
  memset( rakestate, 0, sizeof(int)*N);
  linkcut_draw( tree, N);
  bool res = true;
  foreachcol(c){
    if( coldeg[c] > 1){
      res &= rakeat(c,c);
    }
  }
  linkcut_draw( tree, N);
  return res;
}

void proceed(){
  //Drawing::drawgraph(graph,tree,0,graph.v2()-leafnum);
  if( ! leafnum )
    return;

  if( ! domsnum)
    return;

//  tree.checkorder();

  vector<int> leafres;

  vector<pair<int,int> > edges;
  foreachcol(col)
    foreachadj(row,col)
      edges.push_back(pair<int,int>(row,col));

  int obroty = 0;
//  tree.checkconsistence();
//  tree.checkorder();

//  enable_drawing();
  disable_drawing();
  linkcut_draw( tree, N);
  while(1){

//    if( tree.rake(graph))
    if( rake()){
      goto koniec;
    }

    obroty++;

    random_shuffle( all(edges));

//    Drawing::disable();
    for( vector<pair<int,int> >::iterator it = edges.begin(); it != edges.end(); it++){ 
      int row = it->first;
      int col = it->second;
//      cerr << "______________________________________________________________________" << endl; 

      int rowroot = root(tree[row])->key;
      int colroot = root(tree[col])->key;

      if( coldeg[rowroot] > 1){
        vector<int> color;
        color.push_back(row);
        color.push_back(col);
        linkcut_draw(tree, N, color);
        if( coldeg[colroot] == 1){
          cut_tree(tree[col]);
          link_tree(tree[col], tree[row]);
        } else if( coldeg[colroot] == 0){
          leafnum--;
          coldeg[colroot] = 1;
          coldeg[rowroot]--;

          evert(tree[row]);
          if( coldeg[rowroot] == 1){
            domsnum--;
          } else{
            cut_tree(tree[rowroot]);
          }
          link_tree(tree[row], tree[colroot]);
        };
        linkcut_draw( tree, N, color);
      }
    }
    leafres.push_back(leafnum);
  }
koniec:

//  Drawing::enable();
  cerr << "SKONCZYLEM\nobrotow " << obroty << endl;
  cerr << "lisci: " << leafnum << " dominatorow: " << domsnum << endl;
  long double ratio = 0.0;
  loop(i,leafres.size()){
    cerr << "obrot\t" << i+1 << "\tspadek\t" << leafres[i]-leafnum;
    if( i > 0){
      ratio = max( ratio, (leafres[i]-leafnum)/((long double)leafres[i-1]-leafnum));
      cerr << "\tratio\t" << (leafres[i]-leafnum)/((long double)leafres[i-1]-leafnum);
    }
    cerr << endl;
  }
//  Drawing::drawgraph(graph, tree, obroty+1,0);
}

int main( int argc, char ** argv){
  viz_set_args( argc, argv);

  int seed = 1289773635;
  //int seed = 987654321;
  srand(seed);

  if( scanf("%d %d %d", &n1, &n2, &M) < 0)
    exit(1);
  N = n1+n2 + 1;//+1 zeby indeksowac od jedynki

  graph = new vector<int>[N];
  rakestate = new int[N];
  cerr << n1 << " " << n2 << " " << M << endl;

  bool swp = false;
  if( n1 < n2){
    swap( n1,n2);
    swp = true;
  }

  int a,b;
  loop(i,M){
    if( scanf("%d %d",&a,&b) < 0)
      exit(1);
    if( swp)
      swap( a,b);
    addedge(a,n1+b);
  };

  createtree();
  proceed();
  printf("%d\n", n2 - leafnum);
  return 0;
}
