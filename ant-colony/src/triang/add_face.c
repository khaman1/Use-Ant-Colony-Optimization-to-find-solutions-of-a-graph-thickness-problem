/* add one face to a triangulation */

#include <triang.h>

void add_face(struct triang *t, int v1, int v2, int v3)
{

#if DEBUG
  if (v1 == v2 || v1 == v3 || v2 == v3) {
    printf("add_face: vertices (%d, %d and %d) must be distinct.\n",
	   v1,v2,v3);
    exit(0);
  }

  if (v1 < 0 || v1 >= t->nv || 
      v2 < 0 || v2 >= t->nv || 
      v3 < 0 || v3 >= t->nv) {
    printf("add_face: vertex (%d, %d or %d) out of range. must be between 0 and %d.\n",
	   v1,v2,v3,t->nv);
    exit(0);
  }
#endif

  if (t->orient == 1) {
#if DEBUG
    if (t->edge[v1][v2] != -1) {
      printf("add_face: can't add face (%d,%d,%d). a face (%d,%d,%d) already exists.\n",
	     v1,v2,v3,v1,v2,t->edge[v1][v2]);
      exit(0);
    }
    if (t->edge[v2][v3] != -1) {
      printf("add_face: can't add face (%d,%d,%d). a face (%d,%d,%d) already exists.\n",
	     v1,v2,v3,v2,v3,t->edge[v2][v3]);
      exit(0);
    }
    if (t->edge[v3][v1] != -1) {
      printf("add_face: can't add face (%d,%d,%d). a face (%d,%d,%d) already exists.\n",
	     v1,v2,v3,v3,v1,t->edge[v3][v1]);
      exit(0);
    }
#endif
    
    t->edge[v1][v2] = v3;
    t->edge[v2][v3] = v1;
    t->edge[v3][v1] = v2;
  }
  else {
#if DEBUG
    if (t->edge[v1][v2] != -1 && t->edge[v2][v1] != -1) {
      printf("add_face: can't add face (%d,%d,%d). faces (%d,%d,%d) and (%d,%d,%d) already exist.\n",
	     v1,v2,v3,v1,v2,t->edge[v1][v2],v2,v1,t->edge[v2][v1]);
      exit(0);
    }
    if (t->edge[v2][v3] != -1 && t->edge[v3][v2] != -1) {
      printf("add_face: can't add face (%d,%d,%d). faces (%d,%d,%d) and (%d,%d,%d) already exist.\n",
	     v1,v2,v3,v2,v3,t->edge[v2][v3],v3,v2,t->edge[v3][v2]);
      exit(0);
    }
    if (t->edge[v3][v1] != -1 && t->edge[v1][v3] != -1) {
      printf("add_face: can't add face (%d,%d,%d). faces (%d,%d,%d) and (%d,%d,%d) already exist.\n",
	     v1,v2,v3,v3,v1,t->edge[v3][v1],v1,v3,t->edge[v1][v3]);
      exit(0);
    }
#endif
    
    if (t->edge[v1][v2] == -1)
      t->edge[v1][v2] = v3;
    else
      t->edge[v2][v1] = v3;
    
    if (t->edge[v2][v3] == -1)
      t->edge[v2][v3] = v1;
    else
      t->edge[v3][v2] = v1;
    
    if (t->edge[v3][v1] == -1)
      t->edge[v3][v1] = v2;
    else
      t->edge[v1][v3] = v2;
    
  }
  
  (t->nf)++;
}
