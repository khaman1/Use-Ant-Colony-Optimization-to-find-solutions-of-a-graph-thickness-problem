/*
  ant_colony.h
  ant colony system function signature
  this file only contains one function whose purpose is to run ant colony system algorithm
*/

#ifndef ANT_COLONY_H
#define ANT_COLONY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <triang.h>
#include <triang_utils.h>
#include <ant_structs.h>

/***** functions in ant_colony.c *****/
void ant_colony_system(int argc, char *argv[]);

/***** functions in ant_colony_system_stages.c *****/
// the following are not in alphabetical order, are in order of execution stage instead

/*
  Intialize parameters used in ant colony system such as alpha, beta etc...
  Some parameter explanations:
  nAnt -> number of ants to explore with
  Q0 -> constant used in ant colony system edge selection
  Xi -> constant used in ant colony system local pheromone update
  num_vertices -> number of vertices in the graph
*/
void initialize_ant_parameters(int argc, char* argv[], int num_vertices);

// Display the parameters used in the any colony system algorithm
void display_parameters(char *argv[]);

// reset ant values?
void reset_ant(Ant* MyAnt);

double calculate_initial_pheromone(Ant MyAnt);

// Initialize dynamic arrays
void initialize_arrays(Ant **MyAnt);

// Before beginning, determine what a baseline best solution is for comparison
// edge_limit: max # of edges in flippable edge list
void initialize_best_solution(Solution *Sol);

void ant_colony_system_save_selection(Ant *MyAnt, int idx_to_save);

void print_tau(long double **tau, int length);

// Print the tour cost
void print_the_tour_cost(Ant MyAnt, int idx);

int RouletteWheelSelection(Ant MyAnt, int dupTimes);

int are_triang_equal(struct triang triang1, struct triang triang2);

void write_log_if_found_solution(Ant MyAnt, int PRINT_OUT);

void write_data(Ant *MyAnt, int PRINT_OUT);

// determine the heuristic cost of every possible edge flip available to an ant
void ant_colony_system_tour_construction(Ant* MyAnt);

// select an edge using ant colony system formulas
int ant_colony_system_selection(Ant *MyAnt);

// find the best subset of an ant's tour
void prune_tours(Ant *MyAnt);

// find the best tour among a group of tours
void find_best_tour(Ant MyAnt, Solution *BestSol);

// update the pheromone matrix shared among all ants
void global_pheromone_update(Solution BestSol);

// check if a solution with 0 complements exist
void check_for_solution();

// clean up pointers
void free_arrays(Ant *MyAnt, Solution *sol, int num_vertices);

// write triangulation in lex format
void triang_lex(struct triang *t, int PRINT_OUT, int WRITE_TO_FILE, int FILE_TO_WRITE);

void local_pheromone_update(int v1, int v2);

void reset_tau(int num_vertices);

#endif
