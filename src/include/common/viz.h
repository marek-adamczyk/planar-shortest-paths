#ifndef _VIZ_H_
#define _VIZ_H_
#include <graphviz/gvc.h>

extern "C"{
static const int LABEL_LEN = 12;

static int draw_num = 0;


static int viz_argc;
static char ** viz_argv;
int viz_set_args( int argc, char ** argv);
int viz_set_gvc( GVC_t *gvc, const char * name);
int viz_draw( GVC_t *gvc, Agraph_t * g);

bool drawing_on();
void disable_drawing();
void enable_drawing();

Agnode_t * agnnode (Agraph_t * g, int n);
}
#endif
