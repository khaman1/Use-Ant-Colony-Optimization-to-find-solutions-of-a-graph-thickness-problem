/*
  triang_utils.h
  miscellaneous utility functions for working with graphs 
*/

#ifndef TRIANG_UTILS_H
#define TRIANG_UTILS_H

#include <triang.h>
#include <ant_structs.h>

int count_cliques(struct triang t, int num_of_vertices_in_cliques, int PRINT_OUT);

int count_triang2(struct triang *t, int PRINT_TRIANGLES);

// Flip an edge based on the given triang t and 2 endpoints v1, v2
int FlipEdge(struct triang *t, int v1, int v2);

struct triang get_complement_graph (struct triang *t);

// Get the flippable edges list for an Ant
void get_flippable_edges(Ant *MyAnt);

// Get the "Nearest Neighbor" Solution
// That is to keep picking the flippable edges that yield the smallest number of triangles in the complement
int getNNSolution(Ant *MyAnt,int EDGE_LIMIT,int num_of_vertices_in_cliques);

int load_default_triangles(char text_file[], struct triang *t, struct triang *t1, struct triang *t2);

void set_undirected_edge(struct triang *t, int v1, int v2, int value);

void merge_2_triang(struct triang *t, struct triang *t1, struct triang *t2);

struct triang flip_and_merge_triangs(Ant MyAnt, int triangtoflip_idx);

void merge_triangs();

void merge_triangs2(Ant* MyAnt);

void merge_triangs3(Ant* MyAnt, struct triang t_alt, int alt_index);

void get_critical_graph(Ant *MyAnt, int PRINT_OUT);

void remove_edge(struct triang *t, int v1, int v2 );

void print_neighbors2(struct triang *t);

void generate_random_triang(int num_vertices);

#endif
