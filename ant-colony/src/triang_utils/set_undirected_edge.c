#include <stdio.h>
#include <triang_utils.h>

void set_undirected_edge(struct triang *t, int v1, int v2, int value)
{
  t->edge[v1][v2] = value;
	t->edge[v2][v1] = value;
}
