#include <triang.h>
#include <triang_utils.h>

#define DEBUG 1

struct triang VertexDelete(struct triang t, int vertex)
{
	struct triang t_temp = t;
	int i;

	for(i=0;i<t.nv;i++)
	{
		t_temp.edge[vertex][i]=-1;
		t_temp.edge[i][vertex]=-1;
	}
	
	return t_temp;
}

struct triang EdgeDelete(struct triang t, int v1, int v2)
{
	struct triang t_temp = t;
	
	t_temp.edge[v1][v2]=-1;
	t_temp.edge[v2][v1]=-1;
	
	return t_temp;
}

 
void get_edge_critical_graph(Ant *MyAnt, int PRINT_OUT)
{
	int i,j,k,current_color;
	struct triang t_temp;
	int color = dsatur_coloring(MyAnt->t[0].edge, t[1].nv, 0);
	
	for(i=0;i<t->nv-1;i++)		
		for(j=i+1;j<t->nv;j++)
			if(MyAnt->t[0].edge[i][j] != -1)
			{
				t_temp 				= EdgeDelete(MyAnt->t[0],i,j);
				current_color	= dsatur_coloring(t_temp.edge, t_temp.nv, 0);
				
				if(current_color==color)
				{
					if(PRINT_OUT) printf("Deleted edge[%d][%d]!\n",i,j);
					
					for(k=1;k<=thickness;k++)
						MyAnt->t[k] = EdgeDelete(MyAnt->t[k],i,j);
				}
				/* else
				{
					if(PRINT_OUT) printf("NOT Deleted edge[%d][%d]!\n",i,j);
				} */
			}
	
	/* struct triang t_temp;
	int i,it,j,flag;
	int color = dsatur_coloring(t->edge, t->nv, 0);
	int el 		= t->nv*(t->nv-1)/2;
	int current_color;
	
	for(i=0;i<t->nv-1;i++)		
		for(j=i+1;j<t->nv;j++)
		{
			if(t->edge[i][j]!=-1)
			{
				t_temp 				= EdgeDelete(*t,i,j);
				current_color	= dsatur_coloring(t_temp.edge, t_temp.nv, 0);
				
				//printf("Delete edge[%d][%d] => chromatic number: %d\n", i,j, current_color);
				
				if(current_color==color)
				{
					if(PRINT_OUT) printf("Deleted edge[%d][%d]!\n",i,j);
					*t 	= EdgeDelete(*t,i,j);
					*t1 = EdgeDelete(*t1,i,j);
					*t2 = EdgeDelete(*t2,i,j);
				}
			}
		} */
}

void get_vertex_critical_graph(Ant* MyAnt, int PRINT_OUT)
{
	int i, k, current_color;
	int num_vertices = MyAnt->t[1].nv;
	int color = dsatur_coloring(MyAnt->t[0].edge, num_vertices, 0);
	struct triang t_temp;
	
	for(i=0;i<num_vertices;i++)
	{
		t_temp = VertexDelete(MyAnt->t[0],i);
		current_color = dsatur_coloring(t_temp.edge, t_temp.nv, 0);
		if(current_color==color)
		{
			if(PRINT_OUT) printf("Deleted vertex %d!\n",i);
			
			for(k=1;k<=thickness;k++)
				MyAnt->t[k] = VertexDelete(MyAnt->t[k],i);
			
			/* *t		= VertexDelete(*t,i);
			*t1		= VertexDelete(*t1,i);
			*t2		= VertexDelete(*t2,i); */
		}
		/* else{
			if(PRINT_OUT) 
				printf("NOT Deleted vertex %d!\n",i);
		} */
	}
}



void get_critical_graph(Ant* MyAnt, int PRINT_OUT)
{
	int color = dsatur_coloring(MyAnt->t[0].edge, MyAnt->t[0].nv, 0);
	printf("Chromatic number: %d\n",color);
	
	merge_triangs2(MyAnt);
	get_vertex_critical_graph(MyAnt, 1);
	get_edge_critical_graph(MyAnt, 1);
}