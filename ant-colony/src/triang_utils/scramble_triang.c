/* randomly permute all the vertices of a triangulation */

#include <triang.h>

void scramble_triang(struct triang *t)
{
  int v1,v2;

  for (v1=0;v1<t->nv-1;v1++) {
    v2 = v1 + (rand() % (t->nv-v1));
    if (v1 != v2)
      permute_triang(t,v1,v2);
  }
}
