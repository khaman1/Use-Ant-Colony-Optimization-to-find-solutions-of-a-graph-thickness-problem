/* randomly flip edges of a triangulation */

#include <triang.h>

void ran_flip_triang(struct triang *t, int ntimes)
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
	
    /* if it is really an edge and can be flipped, flip it. */
	
    /* if it is really an edge ... */
	
    if (t->edge[v1][v2] != -1) {
	  
      /* ... and can be flipped, ... */
	  
      if (find_flip(t,v1,v2,&v3,&v4)) {
	nflips++;
	flip_edge(t,v1,v2,v3,v4);
      }
    }
  }
}
