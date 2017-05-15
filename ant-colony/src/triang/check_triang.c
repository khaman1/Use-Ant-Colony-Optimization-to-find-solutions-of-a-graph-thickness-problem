/* check triangulation */

/* return 0 if no problems, 1 otherwise */

#include <triang.h>

int check_triang(struct triang *t, char *caller)
{
  int v1,v2,v3;
  int bad;
  int ne;
  int found[MAX_V], search[MAX_V], nsearch, nfound;

  bad = 0;

	// check that number of vertices in bounds
  if (t->nv < 4 || t->nv > MAX_V) {
    printf("%s: nv (%d) out of range\n",caller,t->nv);
    bad = 1;
    return bad;
  }

  /* check that no edge is a loop */

  for (v1=0;v1<t->nv;v1++)
    if (t->edge[v1][v1] != -1) {
      printf("%s: loop edge at %d\n",caller,v1);
      bad = 1;
    }
  
  /* check that each edge is in 0 or 2 triangles */

  for (v1=0;v1<t->nv;v1++)
    for (v2=0;v2<t->nv;v2++) 
      if (v1 != v2)
	if (t->edge[v1][v2] != -1 && t->edge[v2][v1] == -1) {
	  printf("%s: (%d,%d) is on a face but (%d,%d) is not\n",
		 caller,v1,v2,v2,v1);
	  bad = 1;
	}
  
  /* check that orientable */

  ne = 0;
  for (v1=0;v1<t->nv;v1++)
    for (v2=0;v2<t->nv;v2++) 
      if (t->edge[v1][v2] != -1) {
	ne++;
	v3 = t->edge[v1][v2];
	if (t->edge[v2][v3] != v1) 
	  if (t->orient == 1) {
	    printf("%s: (%d,%d,%d) is a face but (%d,%d,%d) is not\n",
		   caller,v1,v2,v3,v2,v3,v1);
	    bad = 1;
	  }
	  else {
	    if (t->edge[v3][v2] != v1) {
	      printf("%s: (%d,%d,%d) is a face but (%d,%d,%d) is not\n",
		     caller,v1,v2,v3,v2,v3,v1);
	      bad = 1;
	    }
	  }
      }
  ne = ne/2;
  
  /* check that connected */

  for (v1=0;v1<t->nv;v1++)
    found[v1] = 0;
  found[0] = 1;
  search[0] = 0;
  nsearch = 0;
  nfound = 1;
  while (nfound < t->nv && nsearch < nfound) {
    v1 = search[nsearch++];
    for (v2=0;v2<t->nv;v2++)
      if (t->edge[v1][v2] != -1 && !found[v2]) {
	found[v2] = 1;
	search[nfound++] = v2;
      }
  }
  if (nfound != t->nv) {
    printf("%s: not connected\n",caller);
    bad = 1;
  }
  
  /* check scalars */

  if (ne != t->ne) {
    printf("%s: calculated ne (%d) not equal to stored ne (%d)\n",
	   caller,ne,t->ne);
    bad = 1;
  }

  if (ne*2/3 != t->nf) {
    printf("%s: calculated nf (%d) not equal to stored nf (%d)\n",
	   caller,ne*2/3,t->nf);
    bad = 1;
  }

  if (t->genus != -1)
    if (t->orient == 1 && (2-(t->nv-ne/3))/2 != t->genus) {
      printf("%s: calculated genus (%d) not equal to stored genus (%d)\n",
	     caller,(2-(t->nv-ne/3))/2 ,t->genus);
      bad = 1;
    }
  
  if (t->genus != -1)
    if (t->orient == 0 && (2-(t->nv-ne/3)) != t->genus) {
      printf("%s: calculated genus (%d) not equal to stored genus (%d)\n",
	     caller,(2-(t->nv-ne/3)) ,t->genus);
      bad = 1;
    }
  
  return bad;
}
