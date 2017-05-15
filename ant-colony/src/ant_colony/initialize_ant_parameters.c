#include <ant_colony.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h>

#define DEBUG 0

void initialize_ant_parameters(int argc, char* argv[], int num_vertices)
{
  // for loop variable declaration
  int i;
	
	
	
	/************************************/
	// Load the mode. If load_mode is 1, a set of triangulations would be loaded
	// Not completed yet
	load_mode = (int) strtol(argv[1], NULL, 10);	
	if(load_mode == 1) // MISSING
	{
		// To do: Load default Triangs
		return;
	}	
	/************************************/
	
	
	
	
	
  // allocate first level of tau
  tau = (long double **) malloc(num_vertices * sizeof(long double*));

  // allocate second level of tau
  for(i=0; i<num_vertices; i++)
    tau[i] = (long double *) malloc(num_vertices * sizeof(long double));

  // initialize parameters to default values
	thickness 	= 2;					// thickness
  alpha 			= 1;        	// Phromone Exponential Weight
  beta 				= 30;        	// Heuristic Exponential Weight
	rho 				= 0.01;     	// Evaporation Rate
	num_of_vertices_in_cliques = 3;
  nAnt 				= 1;					// Number of ants
  EDGE_LIMIT 	= (num_vertices)*(num_vertices - 1) * thickness;
	Q0 					= 0.1;				// Q0 in ACS for Tour Construction
  Xi 					= 0.1;				// Parameter for Local Pheromone Update
	want_to_print_tour	=0; 
	want_to_print_tau		=0;
	MAX_ITER		=1000;				// Number of iterations to reach for stop
	RUNNING_MODE=0;						// MODE to run
	
	//printf("LOADING\n");
  // if command line arguments provided, use those instead of defaults
  if(argc>=5)
		for(i = 5; i <= argc; i++)
			switch(i)
			{	
				case 5:
					genus	 		= (int) strtol(argv[i-1], NULL, 10);
					break;
				case 6:
					orient 		= (int) strtol(argv[i-1], NULL, 10);
					break;
				case 7:
					thickness	= (int) strtol(argv[i-1], NULL, 10);
					break;
				case 8:
					num_of_vertices_in_cliques = (int) strtol(argv[i-1], NULL, 10);
					break;
				case 9:
					alpha 		= atof(argv[i-1]);
					break;
				case 10:
					beta 			= atof(argv[i-1]);
					break;
				case 11:
					rho 			= atof(argv[i-1]);
					break;
				case 12:
					nAnt 			= (int) strtol(argv[i-1], NULL, 10);
					break;
				case 13:
					if(((int) strtol(argv[i-1], NULL, 10))!=0)
						EDGE_LIMIT = ((int) strtol(argv[i-1], NULL, 10));
					break;
				case 14:
					Q0 				= atof(argv[i-1]);
					break;
				case 15:
					Xi 				= atof(argv[i-1]);	
					break;
				case 16:
					want_to_print_tour = (int) strtol(argv[i-1], NULL, 10);
					break;
				case 17:
					want_to_print_tau 	= (int) strtol(argv[i-1], NULL, 10);
					break;
				case 18:
					MAX_ITER	= (int) strtol(argv[i-1], NULL, 10);
					break;
				default:
					break;
			}
	
	generate_random_triang(num_vertices);
}