/* find the other diagonal of the quadralateral created when the
   edge is removed */

#include <triang.h>

int find_flip(struct triang *t, int v1, int v2, int *o1, int *o2)
{

  /* find the other two corners */

#if DEBUG
  if (t->edge[v1][v2] == -1 || t->edge[v2][v1] == -1) {
    printf("find_flip: corrupted faces at edge (%d,%d)\n",v1,v2);
    exit(0);
  }
#endif
  
  *o1 = t->edge[v1][v2];
  *o2 = t->edge[v2][v1];

  /* check for the possibility that the other two corners already 
     form an edge */
  
  if (t->edge[*o1][*o2] != -1)
    return 0;
  
  return 1;
}
