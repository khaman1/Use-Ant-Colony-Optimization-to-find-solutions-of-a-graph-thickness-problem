/*
  triang.h
  A paired down version of the sulanke code
  Include only the functions that we need
*/

#ifndef TRIANG_H
#define TRIANG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ant_structs.h>

#define MAX_V 128
#define MAX_E (MAX_V*(MAX_V-1)/2)
#define MAX_F ((MAX_E/3)*2)
#define MAX_CODE (MAX_E+MAX_E+MAX_V+4)

/***** VARIABLE DEFINITIONS *****/
FILE *log_file, *prunelog_file;
int nAnt, load_mode, EDGE_LIMIT,num_of_vertices_in_cliques, NNSolution;
int genus, orient, thickness;
int want_to_print_tour, want_to_print_tau, it;
float Q0, alpha, beta, rho, Xi;		
int MAX_ITER, RUNNING_MODE;
long double **tau;
double tau0;
struct triang *t;
struct triang *t_temp;

struct triang {      /* triangulation */
  int nv;						 /* number of vertices */
  int ne;						 /* number of edges */
  int nf;						 /* number of faces */
  int orient;        /* oriented? (not same as orientable), 
			-1 not yet determined */
  int genus;         /* genus of surface 
			(= number of handles or = number of crosscaps 
			-1 not yet determined */
  int edge[MAX_V][MAX_V];
  int nfe; // number of flippable edges
};

static int a2i[128] = {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,-1,-1,-1,-1,-1,
  -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1};

static char i2a[52] = {
  'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
  'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

/***** FUNCTION SIGNATURES *****/

void add_edge(struct triang *t, int v1, int v2);

// add one face to a triangulation
void add_face(struct triang *t, int v1, int v2, int v3);

int  check_triang(struct triang *t, char *caller);

// remove all edges from a triangulation
void clear_triang(struct triang *t, int v);

// Generate a triangulation
void create_triang(struct triang *t, int nv, int genus, int orient);

void generate_triangs(int num_vertices);

/* create a triangulation using lex format input */
int  decode_triang_lex(char *text, struct triang *t);

void get_int(char prompt[], int *integer);

/* find the other diagonal of the quadralateral created when the
   edge is removed */
int find_flip(struct triang *t, int v1, int v2, int *o1, int *o2);

/* interchange an edge for the other diagonal of the quadralateral created 
   when the edge is removed */
void flip_edge(struct triang *t, int v1, int v2, int o1, int o2);

/* randomly flip edges of a triangulation without increasing the degree of the last vertex */
void ran_flip_triang_exclude(struct triang *t, int ntimes);

/* reduce the number of vertices in a triangulation to nv */
/* flip edges until vertex has degree 3 then remove it, repeat */
/* return 1 if successful, return 0 if can't reduce to nv */
int reduce_triang(struct triang *t, int nv);

// Remove an edge
void remove_edge(struct triang *t, int v1, int v2 );

// Remove a face
void remove_face(struct triang *t, int v1, int v2, int v3);

int dsatur_coloring(int edge[128][128], int nv, int DEBUG);

void initialize_log_function();

void write_log(char text_to_write[], int file_to_write);

void print_triang(struct triang *t);

int dharwadker_coloring(struct triang t, int MODE_TEST);

void scramble_triang(struct triang *t);

void permute_triang(struct triang *t, int v1, int v2);

void ran_flip_triang(struct triang *t, int ntimes);

// reference c++ function
// function signature must match
int vertex_coloring(int N, int edge[MAX_V][MAX_V], int C, int PRINTOUT);

#endif 
