/*
  ant_structs.c
*/

#include <stdlib.h>
#include <ant_structs.h>
#include <triang_utils.h>

#define DEBUG 0

Ant init_ant()
{
  int i;
  Ant myAnt;
  
  // t[0] will be the union
  // t[1], t[2], ..., t[i], ... t[thickness] will be the triangulation in the layer i	
	// That's why we malloc (thickness+1) of size triang
	myAnt.t = (struct triang*) malloc((thickness+1)*sizeof(struct triang));
	
  myAnt.TourCnt = 0; 
  myAnt.Cost = 0;
  
	// Because we have EDGE_LIMIT that limits the number of flipping we are going to do, so we've just created the size of arrays sufficient to store results from EDGE_LIMIT flippings.
  myAnt.Cost = malloc(EDGE_LIMIT * sizeof(int));
  myAnt.FECost = malloc(EDGE_LIMIT * sizeof(int));
  myAnt.P = malloc(EDGE_LIMIT * sizeof(long double));
  myAnt.ListFE_Layer = malloc(EDGE_LIMIT * sizeof(int));
        
  myAnt.ListFE = (int **) malloc(EDGE_LIMIT * sizeof(int*));
  myAnt.ListFE_TMP = (int **) malloc(EDGE_LIMIT * sizeof(int*));
  

  // ListFE[i][0] and ListFE[i][1] stores the endpoints of the flipping edge.
  for(i = 0; i < EDGE_LIMIT; i++)
  {
    myAnt.ListFE[i] = (int *) malloc(2 * sizeof(int));
    myAnt.ListFE_TMP[i] = (int *) malloc(2 * sizeof(int));
  }
	
  return myAnt;
}


void initialize_solution(Solution *Sol, struct triang t1, struct triang t2)
{
  if(DEBUG) printf("initialize best solution\n");
	
	struct triang t;
	merge_2_triang(&t,&t1,&t2);
	
	int i;
	Sol->TourCnt = 0;
	Sol->Cost = count_cliques(get_complement_graph(&t), num_of_vertices_in_cliques, 0);;
	Sol->idx = -1;
	Sol->ListFE = (int **) malloc(EDGE_LIMIT * sizeof(int*));
  Sol->ListFEMax = EDGE_LIMIT;
	
	for(i = 0; i < EDGE_LIMIT; i++)
		Sol->ListFE[i] 	= (int *) malloc(2 * sizeof(int));
}

void free_ant(Ant *ant)
{
  int i;

  // free Cost
  free(ant->Cost);

  // ListFE and ListFE_TMP are pointer to pointer of size = edge limit
  // free inner pointers
  for(i = 0; i < EDGE_LIMIT; i++)
  {
      free(ant->ListFE[i]);
      free(ant->ListFE_TMP[i]);
  }
  
  // free pointer to pointer
  free(ant->ListFE);
  free(ant->ListFE_TMP);

  // free ListFE_Layer
  free(ant->ListFE_Layer);

  // free ListFE_TMP
  // free FECost
  free(ant->FECost);
}

void free_solution(Solution *sol)
{
  int i;

  // free inner pointers
  for(i = 0; i < EDGE_LIMIT; i++)
		free(sol->ListFE[i]);
  
  // free pointer to pointers
  free(sol->ListFE);
}
