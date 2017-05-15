#include <ant_colony.h>
#include <math.h>

#define DEBUG 0

double calculate_initial_pheromone(Ant MyAnt)
{
  // Get the tau0 based on the cost of the given NNSolution;
	int i,k,idx,l,min, temp;
	struct triang t_temp;
	
	for(l=0;l<EDGE_LIMIT;l++)
	{
		min=10000; // Reset the variable min
		
		get_flippable_edges(&MyAnt); // Get the list of flippable edges
		
		for(i=0;i<MyAnt.ListFECnt;i++)
		{
			t_temp = MyAnt.t[MyAnt.ListFE_Layer[i]];
			FlipEdge(&t_temp, MyAnt.ListFE_TMP[i][0], MyAnt.ListFE_TMP[i][1]);
			merge_triangs3(&MyAnt, t_temp, MyAnt.ListFE_Layer[i]);
			MyAnt.FECost[i] = count_cliques(get_complement_graph(&(MyAnt.t[0])), num_of_vertices_in_cliques, 0);
			
			if(min>MyAnt.FECost[i])
			{
				min = MyAnt.FECost[i];
				idx = i;
			}
		}
		//get_int("\nNext?: ",&temp);  
		// Save for the tour
		ant_colony_system_save_selection(&MyAnt, idx);
	}
	
	// Get the best part of the tour
	idx=0;
	for(i=0;i<MyAnt.TourCnt;i++)
		if(MyAnt.Cost[idx]>MyAnt.Cost[i]) // Still accept value that equals to min
			idx  = i;		
	
	MyAnt.TourCnt = idx+1;
	
	
	NNSolution = MyAnt.Cost[MyAnt.TourCnt-1];
	//printf("NNSolution: %d - Cnt: %d\n", NNSolution, MyAnt.TourCnt-1);
	
	if((MyAnt.TourCnt-1)!=0)
		return 1/(double)((MyAnt.TourCnt-1) * NNSolution);
  else
		return 1; // Default pheromone
}