#include <string.h>
#include "common/viz.h"

int Viz_set_args( int argc, char ** argv){
  viz_argc = argc;
  viz_argv = argv;
}

int Viz_set_gvc( GVC_t *gvc, const char * name){
  strcpy( viz_argv[0], "dot");
  char draw_name[30];
  sprintf( draw_name, "draw/%s-%d.png", name, ++draw_num);
  strcpy( viz_argv[viz_argc-1], draw_name);//wydaje sie niebezpieczne
  /* parse command line args - minimally argv[0] sets layout engine */
  gvParseArgs(gvc, viz_argc, viz_argv);
}

int Viz_draw( GVC_t *gvc, Agraph_t *g){
  /* Compute a layout using layout engine from command line args */
  gvLayoutJobs(gvc, g);
  /* Write the graph according to -T and -o options */
  gvRenderJobs(gvc, g);
  /* Free layout data */
  gvFreeLayout(gvc, g);
  /* Free graph structures */
  agclose(g);
  /* close output file, free context, and return number of errors */

  return gvFreeContext(gvc);
}

Agnode_t * agnnode( Agraph_t *g, int n){
  char lbl[LABEL_LEN];
  sprintf( lbl, "%d", n);
  return agnode( g, lbl);
}
