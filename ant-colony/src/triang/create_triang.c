/* create a triangulation of a sphere with handles and/or crosscaps with nv 
   vertices */

#include <triang.h>

void create_triang(struct triang *t, int nv, int genus, int orient)
{
  int v1,v2,v3,v4,v5,v6,v7;
  int ih;
  int handles, crosscaps, ec;
  int ne;
  
  if (genus < 0) {
    printf("create_triang: The genus (%d) must be non-negative.\n",
	   genus);
    exit(0);
  }
  if (orient) {
    orient = 1;
    handles = genus;
    crosscaps = 0;
    ec = 2-2*genus;
  }
  else {
    orient = 0;
    handles = (genus-1)/2;
    crosscaps = ((genus-1) % 2) + 1;
    ec = 2-genus;
  }

  /* test that input is in range */
  
  ne = 3*(nv-ec);
  if (ne > MAX_E) {
    printf("create_triang: number of edges too large (%d). increase MAX_E.\n",
	   ne);
    exit(0);
  }
  if ((nv*(nv-1))/2 < ne) {
    printf("create_triang: The number of vertices (%d) is too small to create a triangulation\n\
on a surface with Euler characteristic %d.\n\
The number of edges in K%d is %d but the number of edges in a triangulations is %d.\n",
	   nv,ec,nv,(nv*(nv-1))/2,ne);
    exit(0);
  }

  /*
  if (nv < 4 + 3*handles + 2*crosscaps)
    {
      printf("create_triang: The number of vertices (%d) is too small create a triangulation\n\
on a surface with %d handles and %d crosscaps.\n\
I only know how to make triangulations with %d (4+3*h+2*c) vertices.\n",
	     nv,handles,crosscaps,4+3*handles+2*crosscaps);
      exit(0);
    }
  */

  if (nv + 3 > MAX_V) {
    printf("create_triang: number of vertices too large (%d). increase MAX_V.\n",
	   nv);
    exit(0);
  }

  clear_triang(t,nv+3);
  
  /* create tetrahedron */
  
  t->orient = 1;
  t->genus = 0;
  t->nv = 4;
  
  add_face(t,0,1,2);
  add_face(t,0,2,3);
  add_face(t,0,3,1);
  add_face(t,1,3,2);
  
  t->ne = 6;

  /* add handles */
  
  for (ih=0;ih<handles;ih++) {
    
    /* pick a random edge.  add handle to connect the adjacent faces */

    /*
           sew this         onto this

      7.../.././....7
      .\_ | /  |   /|
      .  \|/   |  / |
      .   1   /  / /.
      .  /|\_ | /  |.
      . / |  \|/   |.         \|/                
      ./ /    4   / .          1 
      .  |    |\_ | /         /:\
      .  |    |  \|/.        / : \
      . /    /    6 .     \ /  :  \ /
      . |    |   /|\_     -4   :   3-
      .\|    |  / | .     / \  :  / \
      . 3   /  / /  .        \ : /   
      ./|\_ | /  |  .         \:/    
      . |  \|/   |  /          2     
      ./    2   /  /.         /|\
      .|   /|\_ | / .
      .|  / |  \|/  .
      .  / /    5   /
      . /  |   /|\_ |
      ./   |  / |  \|
      7.............7

     */
    
    t->genus += 1;

    v1 = 0;
    v2 = 0;
    while ((v3=t->edge[v2][v1]) == -1) {
      v1 = rand() % (t->nv);
      v2 = rand() % (t->nv);
    }
    v4 = t->edge[v1][v2];
    v5 = (t->nv)++;
    v6 = (t->nv)++;
    v7 = (t->nv)++;
    remove_face(t,v1,v2,v4);
    remove_face(t,v2,v1,v3);
    
    add_face(t,v1,v7,v2);
    add_face(t,v1,v2,v5);
    add_face(t,v1,v5,v4);
    add_face(t,v4,v5,v7);
    add_face(t,v4,v7,v6);
    add_face(t,v1,v6,v7);
    add_face(t,v1,v3,v6);
    add_face(t,v2,v4,v6);
    add_face(t,v2,v6,v5);
    add_face(t,v3,v5,v6);
    add_face(t,v3,v7,v5);
    add_face(t,v2,v7,v3);

    t->ne += 15;
    reduce_triang(t,nv);
  }
  
  /* add crosscaps */

  if (!orient) {
    t->orient = 0;
    t->genus = 2*(t->genus);
  }

  for (ih=0;ih<crosscaps;ih++) {
    
    /* pick a random edge.  
       add crosscap in whole left by removing adjacent faces */

    /*
           sew this         onto this


  6---------1---------5       \|/                
  |\       / \       /|        1 
  | \     /   \     / |       /:\
  |  \   /     \   /  |      / : \
  |   \ /       \ /   |   \ /  :  \ /
  |    3         4    |   -4   :   3-
  |   / \       / \   |   / \  :  / \
  |  /   \     /   \  |      \ : /   
  | /     \   /     \ |       \:/    
  |/       \ /       \|        2     
  5---------2---------6       /|\
   \        |        /
    \       |       /
     \      |      /   
      \     |     /
       \    |    /   
        \   |   /    
         \  |  /
          \ | /
           \|/
            1
     */
    
    (t->genus)++;

    v1 = 0;
    v2 = 0;
    while ((v3=t->edge[v2][v1]) == -1) {
      v1 = rand() % (t->nv);
      v2 = rand() % (t->nv);
    }
    v4 = t->edge[v1][v2];
    v5 = (t->nv)++;
    v6 = (t->nv)++;
    remove_face(t,v1,v2,v4);
    remove_face(t,v2,v1,v3);
    
    add_face(t,v1,v3,v6);
    add_face(t,v1,v5,v4);
    add_face(t,v3,v5,v6);
    add_face(t,v4,v5,v6);
    add_face(t,v2,v5,v3);
    add_face(t,v2,v4,v6);
    add_face(t,v1,v5,v2);
    add_face(t,v1,v2,v6);

    t->ne += 9;
    reduce_triang(t,nv);
  }

  /* add additional vertex, n, by placing it inside random face */
  
  while (t->nv < nv) {
    v1 = rand() % (t->nv);
    v2 = rand() % (t->nv);
    if ((v3=t->edge[v1][v2]) != -1) {
      v4 = (t->nv)++;
      remove_face(t,v1,v2,v3);
      add_face(t,v1,v2,v4);
      add_face(t,v1,v4,v3);
      add_face(t,v2,v3,v4);
      t->ne += 3;
    }
  } 
}
