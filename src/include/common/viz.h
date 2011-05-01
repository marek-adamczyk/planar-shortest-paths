#ifndef _VIZ_H_
#define _VIZ_H_
#include <graphviz/gvc.h>

static const int LABEL_LEN = 12;

static int draw_num = 0;

static int viz_argc;
static char ** viz_argv;
int Viz_set_args( int argc, char ** argv);
int Viz_set_gvc( GVC_t *gvc, const char * name);

Agnode_t * agnnode (Agraph_t * g, int n);

#endif
