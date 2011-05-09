#include "linkcut/linkcut.h"
#include "common/macros.h"


int main(){
  int n = 1000;

  Linkcut_vertex ** vertex = new Linkcut_vertex*[n];

  loop(i,n){
    vertex[i] = make_tree();
  }

  delete []vertex;

  return 0;
}
