/*
ant_colony_system_stages.c
implementation of functions defined in ant_colony.h
*/

#include <ant_colony.h>
#include <math.h>

#define DEBUG 0

void reset_ant(Ant* MyAnt)
{
	int i;
	MyAnt->TourCnt 	= 0;
	for(i=1;i<=thickness;i++)
		MyAnt->t[i]=t[i];
	
	
	MyAnt->minCost = NNSolution;
	
	merge_triangs2(MyAnt);
}

void reset_tau(int num_vertices)
{
	int i,j;
	
	for(i = 0; i < num_vertices - 1; i++)
    for(j =i + 1; j < num_vertices; j++)
      tau[i][j] = tau0;

  for(i = 0; i < num_vertices; i++)				
    tau[i][i] = 0;
}

void initialize_best_solution(Solution *Sol)
{
  if(DEBUG) printf("initialize best solution\n");
	
	int i;
	Sol->TourCnt = 0;
	Sol->Cost = NNSolution;//count_cliques(get_complement_graph(&t), num_of_vertices_in_cliques, 0);;
	Sol->idx = -1;
	Sol->ListFE = (int **) malloc(EDGE_LIMIT * sizeof(int*));
	
	for(i = 0; i < EDGE_LIMIT; i++)
		Sol->ListFE[i] 	= (int *) malloc(2 * sizeof(int));
}

void ant_colony_system_save_selection(Ant *MyAnt, int idx_to_save)
{
	int i;
	int j = idx_to_save;
	
	if(j!=-1)
	{
		FlipEdge(&(MyAnt->t[MyAnt->ListFE_Layer[j]]), MyAnt->ListFE_TMP[j][0], MyAnt->ListFE_TMP[j][1]);
		merge_triangs2(MyAnt);
		
		MyAnt->Cost[MyAnt->TourCnt] 			= MyAnt->FECost[j];   // Add new Cost
		MyAnt->ListFE[MyAnt->TourCnt][0] 	= MyAnt->ListFE_TMP[j][0]; // Update new flippable edge
		MyAnt->ListFE[MyAnt->TourCnt][1] 	= MyAnt->ListFE_TMP[j][1];
		
		MyAnt->TourCnt++;

		//printf("TourCnt: %d\n", MyAnt->TourCnt);
	}
	
}

void print_the_tour_cost(Ant MyAnt, int idx)
{
	int i;
	
	printf("MyAnt[%d].Cost - TourCnt %d: ",idx, MyAnt.TourCnt);
	for(i=0;i<MyAnt.TourCnt;i++)
		printf(" %d", MyAnt.Cost[i]);
	printf("\n");
}


void print_tau(long double **tau, int length)
{
	int i,j;
	
	for(i=0;i<length-1;i++)
		for(j=i+1;j<length;j++)
			printf("tau[%d][%d]: %Lf\n", i,j,tau[i][j]);	
}