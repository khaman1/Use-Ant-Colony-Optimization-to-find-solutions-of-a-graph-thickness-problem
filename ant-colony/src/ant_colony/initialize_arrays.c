#include <ant_colony.h>
#include <math.h>

#define DEBUG 0


// In this function, we mainly assign default values to Ants
void initialize_arrays(Ant **MyAnt_ptr)
{
  int i, j; // loop control
	int num_vertices = t[0].nv;
	
	///// Allocate memory space to Ants
	(*MyAnt_ptr) = malloc(nAnt * sizeof(Ant)); 
	for(i=0; i < nAnt; i++)
    (*MyAnt_ptr)[i] = init_ant(); // Initial default values to a new ant
	
	reset_ant(&(*MyAnt_ptr)[0]); // Reset the value of Ant0
	tau0 = calculate_initial_pheromone((*MyAnt_ptr)[0]); // Calculate the initial pheromone by "NN method" and store it to Ant0
	
	// initialize tau to tau0
  reset_tau(num_vertices); // reset Ant0 again
}