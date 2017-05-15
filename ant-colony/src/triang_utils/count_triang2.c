#include <stdio.h>
#include <triang_utils.h>

int count_triang2(struct triang *t, int PRINT_TRIANGLES)
{
  int v1,v2,v3;
  int count;

  //printf("************************\n");
  //printf("Finding Complement ...\n");
  
  
  
  count = 0;
  for (v1=0;v1<t->nv-2;v1++)
    for (v2=v1+1;v2<t->nv-1;v2++)
	  for (v3=v2+1;v3<t->nv;v3++)
	    if((t->edge[v1][v2] != -1) &&
			(t->edge[v2][v3] != -1) &&
			(t->edge[v3][v1] != -1))
		{
			if(PRINT_TRIANGLES==1)
				printf("Triangle: %d %d %d\n",v1,v2,v3);
			else if(PRINT_TRIANGLES==2)
				printf("%d %d %d\n",v1,v2,v3);

			count++;
		}
   
	if(PRINT_TRIANGLES==1)
	  if(count <= 1)
		printf("There is %d triangle.\n", count);  
	  else
		printf("There are %d triangles.\n", count);

  //printf("************************\n");   
  return count;
}
