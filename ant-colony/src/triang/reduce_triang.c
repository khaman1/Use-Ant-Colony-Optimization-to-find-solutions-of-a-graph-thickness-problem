/* reduce the number of vertices in a triangulation to nv */
/* flip edges until vertex has degree 3 then remove it, repeat */
/* return 1 if successful, return 0 if can't reduce to nv */

#include <triang.h>

int reduce_triang(struct triang *t, int nv)
{
  int v1,v2,v3,v4;          /* vertex numbers */
  int degree,prev_degree;   /* degree of vertex to be removed */
  int trys;                 /* number of trys so far */
  int nei[MAX_V];           /* neighbors of v1 */
  int inei;                 /* neighbor index */
  int X;                    /* Euler characteristic */
  int vmin;                 /* the minimum n such that there exist a 
			       triangulation on the surface with n vertices */

  /* test if theoretically possible */

  if (t->orient == 1)
    X = 2 - 2*(t->genus);
  else
    X = 2 - t->genus;

  /*
  vmin = ceil((7+sqrt(49-24*X))/2);
  */

  vmin = 4;
  while ((vmin-3)*(vmin-4) < 6*(2-X))
    vmin++;

  if ((t->orient == 1 && t->genus == 2) ||
      (t->orient == 0 && t->genus == 3) ||
      (t->orient == 0 && t->genus == 2))
    vmin++;
  if (nv < vmin) {
    printf("reduce_triang: can't reduce a triangulation on a surface with genus %d and orientation %d to %d vertices.\n",t->genus,t->orient,nv);
    exit(0);
  }

  /* remove extra vertices if possible */

  while (t->nv > nv) {
    v1 = t->nv - 1;
    degree = 0;
    for (v2=0; v2<v1; v2++)
      if (t->edge[v1][v2] != -1)
	nei[degree++] = v2;
    trys = 0;

    while (degree > 3) {
      if (trys++ > 100 * t->ne) return 0;

      inei = rand()%degree;
      v2 = nei[inei];
      if (find_flip(t,v1,v2,&v3,&v4))
	flip_edge(t,v1,v2,v3,v4);
      else
	ran_flip_triang_exclude(t,t->ne);

      prev_degree = degree;
      degree = 0;
      for (v2=0; v2<v1; v2++)
	if (t->edge[v1][v2] != -1)
	  nei[degree++] = v2;
      if (degree < prev_degree) trys = 0;
    }

    v2 = nei[0];
    v3 = t->edge[v1][v2];
    v4 = t->edge[v2][v1];
    remove_face(t,v1,v2,v3);
    remove_face(t,v1,v3,v4);
    remove_face(t,v1,v4,v2);
    add_face(t,v2,v3,v4);
    (t->nv)--;
    t->ne = t->ne - 3;
  }

  return 1;

}
