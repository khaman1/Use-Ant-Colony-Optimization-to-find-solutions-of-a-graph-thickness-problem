#include <stdio.h>
#include <triang_utils.h>

// Generate a set of random triangulations based on the given thickness
void generate_random_triang(int num_vertices)
{
	int i;
	// Create (thickness) triangulations
	t = (struct triang*) malloc((thickness+1)*sizeof(struct triang)); // Allocate the memory for t
			
	for(i=1;i<=thickness;i++)
	{
		create_triang(&t[i],num_vertices,genus,orient); // Sulanke's function
		scramble_triang(&t[i]);													// Sulanke's function
		ran_flip_triang(&t[i],50);											// Sulanke's function
	}

	merge_triangs(); // Make the union from the random triangulations
}