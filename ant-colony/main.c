/*
  main.c
  This is just a test file for verifying ant colony code is working
*/

#include <triang.h>
#include <triang_utils.h>
#include <ant_colony.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void sigint_handler(int);

void main(int argc, char* argv[])
{
  int test, v, num_of_vertices_in_cliques,v1,v2,v3,v4,count,temp,temp2;
	int load_triang=0;
	int i,j;
	Ant Ant_temp;
	
	signal(SIGINT, sigint_handler); // register the interrupt sigint_handler
	srand(time(NULL)); // initialization for generating random numbers
	
	if(argc>2) // If the number of parameters is greater than 1
	{
		initialize_log_function(); // Open the log file
		initialize_ant_parameters(argc, argv, (int) strtol(argv[3], NULL, 10)); // Initialize the ant colony parameters
		ant_colony_system(argc, argv); // Run Ant Colony
	}
	else // Otherwise, it will display some testing cases
	{
		while(1)
		{
			printf(" 1 : Starts with 2 random triangulations\n");
			printf(" 2 : Show number of Kt in the complement of the union\n");
			printf(" 3 : Print out all triangulation information in lex format\n");
			printf(" 4 : Print the neighbors of all triangulation information\n");
			printf(" 5 : Prune the triangulations\n");
			printf(" 6 : Flip an edge in layer 1\n");
			printf(" 7 : Flip an edge in layer 2\n");
			printf(" 8 : Run vertex coloring\n");
			printf(" 9 : Print the neighbors for the test\n");
			printf(" 30: Run Ant Colony System\n");
			printf(" 0 : Exit\n");

      get_int("test number",&test);
			switch(test) 
			{
				case 0:
					return;
				case 1:
					get_int("Number of vertices",&v); // Get the number of vertices 
					get_int("Thickness",&thickness);  // Get the number of thickness
					get_int("Genus of surface (number of handles or crosscaps",&genus); // Get genus
					get_int("Surface is orientable? (0/1)",&orient);  // Get the orientable of the surface
					
					generate_random_triang(v); // Based on the thickness, generate exactly (thickness) random triangulations
					load_triang=1;
					break;
				case 4:
					for(i=1;i<=thickness;i++)
					{
						printf("****** output from print_triang of layer %d:\n\n",i);
						print_triang(&t[i]);
					}
					
					for(i=1;i<=thickness;i++)
					{
						printf("****** output from print_neighbors of layer %d:\n\n",i);
						print_neighbors2(&t[i]);
					}
					
					break;
				case 5:
					Ant_temp.t = (struct triang*) malloc((thickness+1)*sizeof(struct triang)); // Allocate memory to save all triangulations
					for(i=1;i<=thickness;i++)
						Ant_temp.t[i]=t[i];
					
					get_critical_graph(&Ant_temp,1); // Get critical graphs from triangulation
					break;
					
				case 9:
					printf("LAYER 1\n");
					for(i=0;i<t[1].nv;i++)
						for(j=0;j<t[1].nv;j++)
							if(t[1].edge[i][j]!=-1)
								printf("%d,%d=%d\n",i,j,t[1].edge[i][j]);

				default:
					break;
			}
		}
	}
}

// This function handles the actions when the process is stopped unexpectedly by ctrl+c
void sigint_handler(int sig)
{
		//fclose(log_file);
		fclose(prunelog_file);  // Close the log file
    exit(0); // End the process
}