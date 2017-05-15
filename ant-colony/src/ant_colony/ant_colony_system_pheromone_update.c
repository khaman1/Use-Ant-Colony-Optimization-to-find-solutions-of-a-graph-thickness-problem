/*
ant_colony_system_stages.c
implementation of functions defined in ant_colony.h
*/

#include <ant_colony.h>
#include <math.h>

#define DEBUG 0

void local_pheromone_update(int v1, int v2)
{
	tau[v1][v2] = (1-Xi)*tau[v1][v2] + Xi*tau0;
}

void global_pheromone_update(Solution BestSol)
{
  int i;

  for(i = 0; i < BestSol.TourCnt; i++) // Global Pheromone Trail Update
    tau[BestSol.ListFE[i][0]][BestSol.ListFE[i][1]] = (1 - rho) * tau[BestSol.ListFE[i][0]][BestSol.ListFE[i][1]] + (long double) rho / BestSol.Cost;
}