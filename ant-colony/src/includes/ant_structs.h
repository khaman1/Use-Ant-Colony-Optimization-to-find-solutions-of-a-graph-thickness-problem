/*
  ant_structs.h
  struct definitions for ant algorithms
*/

#ifndef ANT_STRUCTS_H
#define ANT_STRUCTS_H

#define ARRAY_SIZE 100

#include <triang.h>

typedef struct Ant{
  struct triang *t;

  //int *Tour;
  int TourCnt;
  int *Cost; // Cost for FE list in every step
  int **ListFE; // FE List in every step
  int *ListFE_Layer;
  
  long double *P;
  int **ListFE_TMP;
  int *FECost;
  
	int minCost;
  int ListFECnt;
} Ant;

typedef struct Solution{
  struct triang *t;
  int **ListFE;
  int TourCnt;
  int idx;
  int Cost;
  int ListFEMax;
  
  //int **ListFE;
} Solution;

// edge_limit: maximum number of edges in flippable edge list 
Ant init_ant();

void free_ant(Ant *ant);

void free_solution(Solution *sol);

#endif
