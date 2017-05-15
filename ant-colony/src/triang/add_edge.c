#include <triang.h>

void add_edge(struct triang *t, int v1, int v2)
{
	t->edge[v1][v2]=1;
	t->edge[v2][v1]=1;
}
