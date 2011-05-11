#ifndef _LINKCUT_DRAW_H_34123_
#define _LINKCUT_DRAW_H_34123_
#include "linkcut/linkcut.h"
#include "common/viz.h"
#include <vector>
using namespace std;

void linkcut_draw( Linkcut_vertex ** forest, int size);
void linkcut_draw( Linkcut_vertex ** forest, int size, vector<int> &colvert);

#endif
