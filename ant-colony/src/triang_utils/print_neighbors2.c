#include <stdio.h>
#include <triang_utils.h>

void print_neighbors2(struct triang *t)
{
  int i,j;
  
  for(i=0;i<t->nv;i++)
  {
	printf("%d:",i);
	for(j=0;j<t->nv;j++)
	{
	  if(t->edge[i][j]!=-1 || t->edge[j][i]!=-1)
		  printf(" %d",j);
	}
	printf("\n");
  }
}
