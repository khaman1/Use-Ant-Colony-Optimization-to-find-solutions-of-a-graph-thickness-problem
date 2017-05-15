#include <ant_colony.h>
#include <math.h>

#define DEBUG 0

void free_arrays(Ant *MyAnt, Solution *sol, int num_vertices)
{
  int i;

  // free each ant
  for(i = 0; i < nAnt; i++)
    {
      free_ant(&MyAnt[i]);
    }
  
  free(MyAnt);
  
  for(i = 0; i < num_vertices; i++)
    {
      free(tau[i]);
    }
  
  free(tau);
  
  free_solution(sol);
  
	fclose(log_file);
	fclose(prunelog_file);
}
