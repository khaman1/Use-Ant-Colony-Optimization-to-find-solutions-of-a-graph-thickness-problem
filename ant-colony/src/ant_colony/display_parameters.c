#include <ant_colony.h>
#include <stdlib.h>
#define DEBUG 0

void display_parameters(char *argv[])
{
  if(DEBUG) printf("ANT COLONY Parameters\n");
	if(load_mode==0)
		printf("nv: %d\ngenus: %d\norient: %d\nthickness: %d\n",t[1].nv, genus, orient, thickness);

  /* printf("alpha: %s\nbeta: %s\nrho: %s\nClique: K%s\nnAnt: %s\nEDGE_LIMIT: %s\nQ0: %s\nXi: %s\nMAX_ITER: %s\n",argv[7],argv[8],argv[9],argv[10],argv[11],argv[12], argv[13], argv[14], argv[17]); */
	printf("alpha: %.1f\nbeta: %.1f\nrho: %.4f\nClique: K%d\nnAnt: %d\nEDGE_LIMIT: %d\nQ0: %.2f\nXi: %.2f\nMAX_ITER: %d\n",alpha,beta,rho,num_of_vertices_in_cliques,nAnt,EDGE_LIMIT, Q0, Xi, MAX_ITER);
}