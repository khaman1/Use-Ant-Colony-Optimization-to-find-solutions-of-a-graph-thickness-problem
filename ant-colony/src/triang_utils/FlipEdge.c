#include <stdio.h>
#include <triang_utils.h>

/* int FlipEdge(struct triang *t, int v1, int v2)
{
	int v3,v4;

	if(t->edge[v1][v2]!=-1 && find_flip(t,v1,v2,&v3,&v4))
	{
		flip_edge(t,v1,v2,v3,v4);
		return 1;
	}
	
	return 0;
} */
 
 
int FlipEdge(struct triang *t, int v1, int v2)
{
	int v3,v4;

	if(t->edge[v1][v2]==-1)
	{
		printf("no such edge [%d][%d]\n",v1,v2);
		return 0;
	}
	else
	{
		if (!find_flip(t,v1,v2,&v3,&v4))
		{
			printf("can't flip the edge [%d][%d]\n",v1,v2);
			return 0;
		}
		else
		{
			//printf("Flip [%d][%d]=>[%d][%d]\n",v1,v2,v3,v4);
			flip_edge(t,v1,v2,v3,v4);
			return 1;
		}
	}
}