/* randomly flip edges of a triangulation without increasing the degree of the last vertex */

#include <triang.h>
#include <triang_utils.h>

void ran_flip_triang_exclude(struct triang *t, int ntimes)
{
  int v1,v2,v3,v4;   /* vertex numbers */
  int nflips;        /* number of successful flips */
  int nran;          /* number of random pairs generated */

  /* pick a random edge */
  
  nflips = 0;
  nran = 0;
      
  while (nflips<ntimes && (nran<ntimes || nflips>0)) {
    v1 = rand() % t->nv;
    v2 = rand() % t->nv;
    nran++;
	
    /* if it is really an edge, can be flipped, and 
       does not increase the degree of the last vertex then flip it. */
	
    /* if it is really an edge, ... */
	
    if (t->edge[v1][v2] != -1) {
	  
      /* ... can be flipped, ... */
	  
      if (find_flip(t,v1,v2,&v3,&v4)) 

	/* ... and does not increase the degree of the last vertex ... */

	if (v3 != t->nv - 1 && v4 != t->nv - 1) {
	  nflips++;
	  flip_edge(t,v1,v2,v3,v4);
	  if (v1 == t->nv - 1 || v2 == t->nv - 1)
	    nflips = 0;
	}
    }
  }
}
