CC = gcc
COBJS = main.o  
OFILES = main.o

ANT_COLONY_OBJS = ant_colony.o ant_colony_system_initialization.o ant_colony_system_pheromone_update.o ant_colony_system_stages.o ant_structs.o calculate_initial_pheromone.o display_parameters.o free_arrays.o initialize_ant_parameters.o initialize_arrays.o triang_lex.o 
ANT_COLONY_O_FILES = build/ant_colony.o build/ant_colony_system_initialization.o build/ant_colony_system_pheromone_update.o build/ant_colony_system_stages.o build/ant_structs.o build/calculate_initial_pheromone.o build/display_parameters.o build/free_arrays.o build/initialize_ant_parameters.o build/initialize_arrays.o build/triang_lex.o
TRIANG_OBJS =  add_edge.o add_face.o check_triang.o clear_triang.o create_triang.o decode_triang_lex.o find_flip.o flip_edge.o ran_flip_triang_exclude.o reduce_triang.o remove_face.o 
TRIANG_O_FILES =  build/add_edge.o build/add_face.o build/check_triang.o build/clear_triang.o build/create_triang.o build/decode_triang_lex.o build/find_flip.o build/flip_edge.o build/ran_flip_triang_exclude.o build/reduce_triang.o build/remove_face.o
TRIANG_UTILS_OBJS = count_cliques.o count_triang2.o FlipEdge.o generate_random_triang.o get_complement_graph.o get_flippable_edges.o get_input.o load_default_triangles.o log_function.o merge_2_triang.o merge_triangs.o print_neighbors2.o print_triang.o dsatur_coloring.o dharwadker_coloring.o get_critical_graph.o coloring_lib set_undirected_edge.o scramble_triang.o permute_triang.o ran_flip_triang.o
TRIANG_UTILS_O_FILES = build/count_cliques.o build/count_triang2.o build/FlipEdge.o build/generate_random_triang.o build/get_complement_graph.o build/get_flippable_edges.o build/get_input.o build/load_default_triangles.o build/log_function.o build/merge_2_triang.o build/merge_triangs.o build/print_neighbors2.o build/print_triang.o build/dsatur_coloring.o build/dharwadker_coloring.o build/get_critical_graph.o build/vertex_extern.o build/set_undirected_edge.o build/scramble_triang.o build/permute_triang.o build/ran_flip_triang.o

DEBUG = -g
CFLAGS = -O0 $(DEBUG) -c
INCLUDES_PATH = -I./src/includes -I.

ant_colony: $(ANT_COLONY_OBJS) $(TRIANG_OBJS) $(TRIANG_UTILS_OBJS) $(COBJS) 
	g++ -g -Wall -L. $(INCLUDES_PATH) $(ANT_COLONY_O_FILES) $(TRIANG_O_FILES) $(TRIANG_UTILS_O_FILES) $(OFILES) -lm -o build/ant_colony

add_edge.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/add_edge.c  -o build/add_edge.o

add_face.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/add_face.c  -o build/add_face.o

ant_colony.o: 
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/ant_colony.c  -o build/ant_colony.o

ant_colony_system_initialization.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/ant_colony_system_initialization.c  -o build/ant_colony_system_initialization.o
	
ant_colony_system_pheromone_update.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/ant_colony_system_pheromone_update.c  -o build/ant_colony_system_pheromone_update.o
	
ant_colony_system_stages.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/ant_colony_system_stages.c  -o build/ant_colony_system_stages.o

ant_structs.o: 
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/ant_structs.c  -o build/ant_structs.o

calculate_initial_pheromone.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/calculate_initial_pheromone.c  -o build/calculate_initial_pheromone.o

check_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/check_triang.c  -o build/check_triang.o

clear_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/clear_triang.c  -o build/clear_triang.o

count_cliques.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/count_cliques.c  -o build/count_cliques.o

count_triang2.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/count_triang2.c  -o build/count_triang2.o

create_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/create_triang.c  -o build/create_triang.o

decode_triang_lex.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/decode_triang_lex.c  -o build/decode_triang_lex.o

dsatur_coloring.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/coloring/dsatur_coloring.c  -o build/dsatur_coloring.o

dharwadker_coloring.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/coloring/dharwadker_coloring.c  -o build/dharwadker_coloring.o	
	
display_parameters.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/display_parameters.c  -o build/display_parameters.o

FlipEdge.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/FlipEdge.c  -o build/FlipEdge.o

find_flip.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/find_flip.c  -o build/find_flip.o

flip_edge.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/flip_edge.c  -o build/flip_edge.o

free_arrays.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/free_arrays.c  -o build/free_arrays.o

generate_random_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/generate_random_triang.c  -o build/generate_random_triang.o
	
get_complement_graph.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/get_complement_graph.c  -o build/get_complement_graph.o

get_critical_graph.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/coloring/get_critical_graph.c  -o build/get_critical_graph.o
	
get_flippable_edges.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/get_flippable_edges.c  -o build/get_flippable_edges.o

get_input.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/get_input.c  -o build/get_input.o
	
initialize_ant_parameters.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/initialize_ant_parameters.c  -o build/initialize_ant_parameters.o

initialize_arrays.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/initialize_arrays.c  -o build/initialize_arrays.o

load_default_triangles.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/load_default_triangles.c  -o build/load_default_triangles.o

log_function.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/log_function.c  -o build/log_function.o
	
merge_2_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/merge_2_triang.c  -o build/merge_2_triang.o
	
merge_triangs.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/merge_triangs.c  -o build/merge_triangs.o

print_neighbors2.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/print_neighbors2.c  -o build/print_neighbors2.o

print_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/print_triang.c  -o build/print_triang.o
	
ran_flip_triang_exclude.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/ran_flip_triang_exclude.c  -o build/ran_flip_triang_exclude.o

reduce_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/reduce_triang.c  -o build/reduce_triang.o

remove_face.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/remove_face.c  -o build/remove_face.o

set_undirected_edge.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/set_undirected_edge.c  -o build/set_undirected_edge.o

scramble_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/scramble_triang.c  -o build/scramble_triang.o

permute_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/permute_triang.c  -o build/permute_triang.o

ran_flip_triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/ran_flip_triang.c  -o build/ran_flip_triang.o
	
triang.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang/triang.c  -o build/triang.o	

triang_utils.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/triang_utils/triang_utils.c  -o build/triang_utils.o

triang_lex.o:
	$(CC) $(CFLAGS) $(INCLUDES_PATH) src/ant_colony/triang_lex.c  -o build/triang_lex.o

extern: coloring_lib ant_colony
	$(CC) -g -Wall -L. $(INCLUDES_PATH) $(ANT_COLONY_O_FILES) $(TRIANG_O_FILES) $(TRIANG_UTILS_O_FILES) $(OFILES) -lm -Wl,-rpath=./src/includes -o build/ant_colony2
	
vertex_extern.o: 
	g++ -c -g -fPIC $(CFLAGS) src/coloring/vertex_coloring_extern.cpp  -o build/vertex_extern.o
	
coloring_lib: vertex_extern.o
	g++ -g -shared -o build/libvertex.so build/vertex_extern.o
	
.c.o :
	$(CC) $(CFLAGS) $(INCLUDES_PATH) $<  
.SUFFIXES: .o .c .f

clean:
	rm build/*.o ./*.o
