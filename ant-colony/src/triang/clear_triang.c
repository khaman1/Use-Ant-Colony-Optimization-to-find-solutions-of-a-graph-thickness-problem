/* remove all edges from a triangulation */

#include <triang.h>

void clear_triang(struct triang *t, int nv)
{
  int v1,v2;

  if (nv < 0 || nv > MAX_V) {
    printf("clear_triang: nv (%d) out of range.  must be between 0 and %d.\n",
	   nv,MAX_V);
    exit(0);
  }

  t->nv = 0;
  t->ne = 0;
  t->nf = 0;

  for (v1=0;v1<nv;v1++)
    for (v2=0;v2<nv;v2++)
      t->edge[v1][v2] = -1;

}
