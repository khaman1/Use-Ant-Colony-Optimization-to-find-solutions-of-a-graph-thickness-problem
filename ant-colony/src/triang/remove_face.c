/* remove one face to a triangulation */

#include <triang.h>

void remove_face(struct triang *t, int v1, int v2, int v3)
{

  if (t->orient == 1) {
#if DEBUG
    if (t->edge[v1][v2] != v3 ||
	t->edge[v2][v3] != v1 ||
	t->edge[v3][v1] != v2) {
      printf("remove_face: orientable face (%d,%d,%d) does not exist or is corrupted.\n",
	     v1,v2,v3);
      exit(0);
    }
#endif

    t->edge[v1][v2] = -1;
    t->edge[v2][v3] = -1;
    t->edge[v3][v1] = -1;
  }
  else {
#if DEBUG
    if ((t->edge[v1][v2] != v3 && t->edge[v2][v1] != v3) ||
	(t->edge[v2][v3] != v1 && t->edge[v3][v2] != v1) ||
	(t->edge[v3][v1] != v2 && t->edge[v1][v3] != v2)) {
      printf("remove_face: nonorientable face (%d,%d,%d) does not exist or is corrupted.\n",
	     v1,v2,v3);
      exit(0);
    }
#endif
    
    if (t->edge[v1][v2] == v3)
      t->edge[v1][v2] = -1;
    else
      t->edge[v2][v1] = -1;
    
    if (t->edge[v2][v3] == v1)
      t->edge[v2][v3] = -1;
    else
      t->edge[v3][v2] = -1;
    
    if (t->edge[v3][v1] == v2)
      t->edge[v3][v1] = -1;
    else
      t->edge[v1][v3] = -1;
  }
 
  (t->nf)--;
}
