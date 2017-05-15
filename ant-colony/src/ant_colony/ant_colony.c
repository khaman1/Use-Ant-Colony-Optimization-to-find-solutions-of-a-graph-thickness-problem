/*
ant_colony.c
main file for running ant colony program
more comments to come
*/

#include <triang.h>
#include <ant_colony.h>
// Returns nothing, best solution should be logged or written to console


// The main function of Ant Colony
void ant_colony_system(int argc, char *argv[])
{
  // ant_colony parameters
  // TODO: need comments for what each variable is
  int i,k,idx,min;
	Ant *MyAnt; 
  Solution BestSol;
	
	it=1;
	
  printf("Start of ant_colony\n");
  display_parameters(argv); // Display the number of parameters inserted
  initialize_arrays(&MyAnt); // Create the size of arrays for Ant
	 
	printf("Current cost: %d\n", count_cliques(get_complement_graph(&t[0]), num_of_vertices_in_cliques, 0));
	printf("NNSolution: %d\n", NNSolution);
	printf("tau0: %.5f\n", tau0);
	
	initialize_best_solution(&BestSol); // Kha
	printf("Initial Best Solution: %d\n", BestSol.Cost);
	
	printf("***************************\n");
	
	while(1)
	{
		for(k=0;k<nAnt;k++)
		{
				reset_ant(&MyAnt[k]);     
				ant_colony_system_tour_construction(&MyAnt[k]);
				 
				//write_log_if_found_solution(MyAnt[k],0);
				
				prune_tours(&MyAnt[k]); // prune tours, store the results in a shared, global array
				
				write_data(&MyAnt[k],0);
				
				find_best_tour(MyAnt[k], &BestSol); // calculate the cost of each tour, determine best tour cost sequentially
				
				if(want_to_print_tour)
					print_the_tour_cost(MyAnt[k], k);
		}
		
		// update the global pheromone
		global_pheromone_update(BestSol);

		if(want_to_print_tau)
			print_tau(tau,t[1].nv);
		
		printf("Iteration %d: Best Cost = %d\n", it, BestSol.Cost);
		
		
		///////////////////////////////////////
		///////////////////////////////////////
		it++;
		if((BestSol.Cost==0 && RUNNING_MODE==0) || it > MAX_ITER)
		{
			/* ///////////////////////////////////////
			///////////////////////////////////////
			if(BestSol.Cost!=0)
			{
				idx=0;
				min=10000;
				for(i = 1; i < nAnt; i++)
					if(min>MyAnt[k].Cost[MyAnt[k].TourCnt-1])
					{
						min = MyAnt[k].Cost[MyAnt[k].TourCnt-1];
						idx = i;
					}
				
				write_data(&MyAnt[idx],0);
			}
			 */
			///////////////////////////////////////
			///////////////////////////////////////
			
			
			printf("Resetting ...\n");
			
			generate_random_triang(t[1].nv);
			///////////////////////////////////////
			///////////////////////////////////////
			for(i = 0; i < nAnt; i++)
				free_ant(&MyAnt[i]);
			free_solution(&BestSol);
				
			initialize_best_solution(&BestSol);
			initialize_arrays(&MyAnt);
			it=1;
		}
	}
	
  //free_arrays(MyAnt, &BestSol, t[0].nv);
}
