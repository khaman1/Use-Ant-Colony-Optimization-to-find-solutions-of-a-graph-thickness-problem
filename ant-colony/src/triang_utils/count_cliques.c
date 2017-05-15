#include <stdio.h>
#include <triang_utils.h>

int count_cliques(struct triang t, int num_of_vertices_in_cliques, int PRINT_OUT)
{
	int v1,v2,v3,v4,v5;
	int count=0;
	
	switch(num_of_vertices_in_cliques)
	{
			
		case 3:
			for (v1=0;v1<t.nv-2;v1++)
				for (v2=v1+1;v2<t.nv-1;v2++)
					for (v3=v2+1;v3<t.nv;v3++)
						if((t.edge[v1][v2] != -1) && (t.edge[v2][v3] != -1) && (t.edge[v1][v3] != -1))
						{
							count++;
							if(PRINT_OUT)
								printf("%d %d %d\n",v1,v2,v3);
						}
			break;
		case 4:
			for (v1=0;v1<t.nv-3;v1++)
				for (v2=v1+1;v2<t.nv-2;v2++)
					for (v3=v2+1;v3<t.nv-1;v3++)
						for (v4=v3+1;v4<t.nv;v4++)
							if((t.edge[v1][v2] != -1) && (t.edge[v1][v3] != -1) && (t.edge[v1][v4] != -1) &&
								 (t.edge[v2][v3] != -1) && (t.edge[v2][v4] != -1) && (t.edge[v3][v4] != -1))
							{
								count++;
								if(PRINT_OUT)
									printf("%d %d %d %d\n",v1,v2,v3,v4);
							}
			break;
		case 5:
			for (v1=0;v1<t.nv-4;v1++)
				for (v2=v1+1;v2<t.nv-3;v2++)
					for (v3=v2+1;v3<t.nv-2;v3++)
						for (v4=v3+1;v4<t.nv-1;v4++)
							for (v5=v4+1;v5<t.nv;v5++)
								if((t.edge[v1][v2] != -1) && (t.edge[v1][v3] != -1) && (t.edge[v1][v4] != -1) && (t.edge[v1][v5] != -1) &&
									 (t.edge[v2][v3] != -1) && (t.edge[v2][v4] != -1) && (t.edge[v2][v5] != -1) && (t.edge[v3][v4] != -1) &&
								   (t.edge[v3][v5] != -1) && (t.edge[v4][v5] != -1))
								{
									count++;
									if(PRINT_OUT)
										printf("%d %d %d %d %d\n",v1,v2,v3,v4,v5);
								}
			break;
		default:
			break;
	}
	
	if(PRINT_OUT)
		if(count==1)
			printf("There is %d K%d in the complement\n", count, num_of_vertices_in_cliques);
		else
			printf("There are %d K%d in the complement\n", count, num_of_vertices_in_cliques);
	return count;
}
