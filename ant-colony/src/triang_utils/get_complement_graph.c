#include <stdio.h>
#include <triang_utils.h>

struct triang get_complement_graph (struct triang *t)
{
	struct triang c;
	int v1,v2;
	
	clear_triang(&c, t->nv);
	c.nv = t->nv;
	c.ne = t->ne;
	c.nf = t->nf;
	c.orient = t->orient;
	c.genus = t->genus;
	
	
	for (v1=0;v1<t->nv;v1++)
     for (v2=0;v2<t->nv;v2++)
	    if (v1!=v2 && t->edge[v1][v2] == -1)
	      add_edge(&c,v1,v2);
	  
	return c;
}
