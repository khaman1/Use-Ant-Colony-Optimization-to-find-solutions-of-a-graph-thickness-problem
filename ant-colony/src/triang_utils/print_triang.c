/* print a triangulation of a surface */

#include <triang.h>

void print_triang(struct triang *t)
{
  int v1,v2;

  if (t->nv < 4 || t->nv > MAX_V)
    {
      printf("print_triang: number of vertices must be at least 4 and less than %d but is %d.\n",MAX_V,t->nv);
      return;
    }

  printf("vertices: %d, edges: %d, faces: %d, orientable: %d, genus %d\n",
	 t->nv,t->ne,t->nf,t->orient,t->genus);

  printf("\n   ");
  for (v2=0;v2<t->nv;v2++)
    printf("%3d",v2);
  printf("\n");
  
  for (v1=0;v1<t->nv;v1++) {
    printf("\n%2d ",v1);
    for (v2=0;v2<t->nv;v2++)
      if (t->edge[v1][v2] == -1)
	printf("   ");
      else
	printf("%3d",t->edge[v1][v2]);
  }
  printf("\n\n");

}

