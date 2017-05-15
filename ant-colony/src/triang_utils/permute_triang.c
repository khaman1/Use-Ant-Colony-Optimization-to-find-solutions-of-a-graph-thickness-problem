/* interchange two vertices of a triangulation */

#include <triang.h>

void permute_triang(struct triang *t, int v1, int v2)
{

  int v3,v4;
  int tmp;

  for (v3=0;v3<t->nv;v3++) {
    tmp = t->edge[v1][v3];
    t->edge[v1][v3] = t->edge[v2][v3];
    t->edge[v2][v3] = tmp;
  }

  for (v3=0;v3<t->nv;v3++) {
    tmp = t->edge[v3][v1];
    t->edge[v3][v1] = t->edge[v3][v2];
    t->edge[v3][v2] = tmp;
  }
  
  for (v3=0;v3<t->nv;v3++)
    for (v4=0;v4<t->nv;v4++) 
      if (t->edge[v3][v4] == v1)
	t->edge[v3][v4] = v2;
      else if (t->edge[v3][v4] == v2)
	t->edge[v3][v4] = v1;
}
