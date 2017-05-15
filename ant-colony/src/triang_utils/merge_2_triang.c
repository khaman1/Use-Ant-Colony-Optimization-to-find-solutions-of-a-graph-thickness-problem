#include <stdio.h>
#include <triang_utils.h>

void merge_2_triang(struct triang *t, struct triang *t1, struct triang *t2)
{
	int v1,v2;
	
	for(v1=0;v1<t1->nv-1;v1++)
	{
		t->edge[v1][v1] = -1;
		for(v2=v1+1; v2<t1->nv; v2++)
		{
			if(t1->edge[v1][v2]!=-1 || t1->edge[v2][v1]!=-1 || t2->edge[v1][v2]!=-1 || t2->edge[v2][v1]!=-1)
			{
				t->edge[v1][v2]=1;
				t->edge[v2][v1]=1;
			}
				
			else
			{
				t->edge[v1][v2]=-1;
				t->edge[v2][v1]=-1;
			}
				
		}
	}		
	
	t->edge[t1->nv-1][t1->nv-1]=-1;
	
	t->nv = t1->nv;
}

/* struct triang flip_and_merge_triangs(Ant MyAnt, int triangtoflip_idx)
{
	Ant Ant_temp = MyAnt;
	int Layer = Ant_temp.ListFE_Layer[triangtoflip_idx];
	int i;
	
	//printf("Layer: %d\n",Layer);
	printf("Flip the edge [%d][%d][%d]\n", Ant_temp.ListFE_TMP[triangtoflip_idx][0], Ant_temp.ListFE_TMP[triangtoflip_idx][1], Layer);
	printf("Before flip\n");
	for(i=1;i<=thickness;i++)
	{
		printf("Layer %d: \n",i);
		print_neighbors2(&Ant_temp.t[i]);
	}
	merge_triangs2(&Ant_temp);
	printf("Layer 0:\n");
	print_neighbors2(&Ant_temp.t[0]);
	
	
	
	
	if(FlipEdge(&(Ant_temp.t[Layer]), Ant_temp.ListFE_TMP[triangtoflip_idx][0], Ant_temp.ListFE_TMP[triangtoflip_idx][1]))
		merge_triangs2(&Ant_temp);
	
	
	
	printf("After flip!!!!!!!!!!!!!!!!!\n");
	for(i=1;i<=thickness;i++)
	{
		printf("Layer %d: \n",i);
		print_neighbors2(&Ant_temp.t[i]);
	}
	merge_triangs2(&Ant_temp);
	printf("Layer 0:\n");
	print_neighbors2(&Ant_temp.t[0]);
	
	return Ant_temp.t[0];
} */


struct triang flip_and_merge_triangs(Ant MyAnt, int triangtoflip_idx)
{
	
}