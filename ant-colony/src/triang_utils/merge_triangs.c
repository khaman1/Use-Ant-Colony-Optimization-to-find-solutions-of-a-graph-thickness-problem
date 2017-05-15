#include <stdio.h>
#include <triang_utils.h>

// Make the union from the triangulations
// The input is the global variable t, t[i]
void merge_triangs()
{
	int i,v1,v2;

	for(v1=0;v1<t[1].nv-1;v1++)
	{
		set_undirected_edge(&t[0], v1, v1, -1);
		for(v2=v1+1; v2<t[1].nv; v2++)
		{
			set_undirected_edge(&t[0], v1, v2, -1);
			for(i=1;i<=thickness;i++)
				if(t[i].edge[v1][v2]!=-1 || t[i].edge[v2][v1]!=-1)
				{
					set_undirected_edge(&t[0], v1, v2, 1);
					break;
				}
		}
	}
	
	set_undirected_edge(&t[0], t[1].nv-1, t[1].nv-1, -1);	
	t[0].nv = t[1].nv;
}


// Make the union from the triangulations
// The input is t, t[i] inside of an Ant structure MyAnt
void merge_triangs2(Ant* MyAnt)
{
	int i,v1,v2;

	for(v1=0;v1<MyAnt->t[1].nv-1;v1++)
	{
		set_undirected_edge(&(MyAnt->t[0]), v1, v1, -1);
		for(v2=v1+1; v2<MyAnt->t[1].nv; v2++)
		{
			set_undirected_edge(&(MyAnt->t[0]), v1, v2, -1);
			for(i=1;i<=thickness;i++)
				if(MyAnt->t[i].edge[v1][v2]!=-1 || MyAnt->t[i].edge[v2][v1]!=-1)
				{
					set_undirected_edge(&(MyAnt->t[0]), v1, v2, 1);
					break;
				}
		}
	}
	
	set_undirected_edge(&(MyAnt->t[0]), MyAnt->t[1].nv-1, MyAnt->t[1].nv-1, -1);	
	MyAnt->t[0].nv = MyAnt->t[1].nv;
}


// Make the union from the triangulations
// The input is t, t[i] inside of an Ant structure MyAnt
// t_alt and alt_index will be replaced to the (alt_index)th triangulation in MyAnt
void merge_triangs3(Ant* MyAnt, struct triang t_alt, int alt_index)
{
	int i,v1,v2;
	
	for(v1=0;v1<MyAnt->t[1].nv-1;v1++)
	{
		set_undirected_edge(&(MyAnt->t[0]), v1, v1, -1);
		for(v2=v1+1; v2<MyAnt->t[1].nv; v2++)
		{
			set_undirected_edge(&(MyAnt->t[0]), v1, v2, -1);
			for(i=1;i<=thickness;i++)
			{
				if(i!=alt_index)
				{
					if(MyAnt->t[i].edge[v1][v2]!=-1 || MyAnt->t[i].edge[v2][v1]!=-1)
					{
						set_undirected_edge(&(MyAnt->t[0]), v1, v2, 1);
						break;
					}
				}
				else
				{
					if(t_alt.edge[v1][v2]!=-1 || t_alt.edge[v2][v1]!=-1)
					{
						set_undirected_edge(&(MyAnt->t[0]), v1, v2, 1);
						break;
					}
				}
			}
		}
	}
	
	set_undirected_edge(&(MyAnt->t[0]), MyAnt->t[1].nv-1, MyAnt->t[1].nv-1, -1);	
	MyAnt->t[0].nv = MyAnt->t[1].nv;
}