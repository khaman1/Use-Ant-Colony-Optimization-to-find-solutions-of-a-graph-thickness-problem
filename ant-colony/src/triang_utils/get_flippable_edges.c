#include <stdio.h>
#include <triang_utils.h>

/* void get_flippable_edges(Ant *MyAnt)
{	
	int v1,v2,v3,v4;
	struct triang t1 = MyAnt->t1;
	struct triang t2 = MyAnt->t2;
	
	MyAnt->ListFECnt = 0; // Reset the counter of the temporary FE list
	
	for (v1=0;v1<MyAnt->t.nv-1;v1++)
	  for (v2=v1+1;v2<MyAnt->t.nv;v2++)
	  {
			if (find_flip(&t1,v1,v2,&v3,&v4))
			{
				MyAnt->ListFE_TMP[MyAnt->ListFECnt][0]=v1; 	// Get 1st endpoint
				MyAnt->ListFE_TMP[MyAnt->ListFECnt][1]=v2; 	// Get 2nd endpoint
				MyAnt->ListFE_Layer[MyAnt->ListFECnt]=1;						// The layer to follow = 1
				MyAnt->ListFECnt++;																	// Increment the index
			}
			
			if (find_flip(&t2,v1,v2,&v3,&v4))
			{
				MyAnt->ListFE_TMP[MyAnt->ListFECnt][0]=v1; 	// Get 1st endpoint
				MyAnt->ListFE_TMP[MyAnt->ListFECnt][1]=v2; 	// Get 2nd endpoint
				MyAnt->ListFE_Layer[MyAnt->ListFECnt]=2;						// The layer to follow = 2
				MyAnt->ListFECnt++;																	// Increment the index
			}
	  }	
} */

void get_flippable_edges(Ant *MyAnt)
{
	int i,j,v1,v2,v3,v4;
	int num_vertices = MyAnt->t[1].nv;
	
	MyAnt->ListFECnt = 0; // Reset the counter of the temporary FE list
	
	for (v1=0;v1<num_vertices-1;v1++)
		for (v2=v1+1;v2<num_vertices;v2++)
			for(i=1;i<=thickness;i++)
			{
				if (find_flip(&(MyAnt->t[i]),v1,v2,&v3,&v4))
				{
					MyAnt->ListFE_TMP[MyAnt->ListFECnt][0]=v1; 		// Get 1st endpoint
					MyAnt->ListFE_TMP[MyAnt->ListFECnt][1]=v2; 		// Get 2nd endpoint
					MyAnt->ListFE_Layer[MyAnt->ListFECnt]=i;			// The layer to follow = 1
					MyAnt->ListFECnt++;
					
					//printf("[%d][%d][%d][%d]-[%d] ", v1,v2,v3,v4, MyAnt->ListFE_Layer[MyAnt->ListFECnt-1]);
				}
			}
	
	//printf("\n");
}