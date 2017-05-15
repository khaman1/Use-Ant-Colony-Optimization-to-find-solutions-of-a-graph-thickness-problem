# ant-colony
To run the ant_colony, firstly you have to go into the folder build. Then, execute the ant_colony by the following command:

./ant_colony [load_default_triangs?] [File Path] [nv] [genus] [orientable?] [thickness] [vertices_in_cliques] [alpha] [beta] [rho] [number of Ants] [EDGE_LIMIT] [Qo] [Xi] [want to print every tour] [want to print tau] [number of iterations]



Here are the details for the parameters:
- [load_default_triangs?] : This is to recognize that you want to reload some previous data or not. VALUE should be 0 or 1. If you choose 0, you don't have to define path (or leave it any value you want) but [nv], [genus] and [orientable?] must be specified. EXAMPLE VALUE: 0

- [File Path]: the path to the file you want to load in the Data folder at root directory. The file consists of 2 triangulations in lex format that is what Sulanke's loading function needs. EXAMPLE VALUE: 17_93 => Load the file 17_93.txt in the Data folder.

- [nv]: number of vertices to generate in case that [load_default_triangs?] = 0. If [load_default_triangs?] = 1, leave it as any value. EXAMPLE VALUE: 17

- [genus]: number of genus in a triangulation you want to generate in case that [load_default_triangs?] = 0. If [load_default_triangs?] = 1, leave it as any value. EXAMPLE VALUE: 0

- [orientable?]: the surface is orientable or not in case that [load_default_triangs?] = 0. If [load_default_triangs?] = 1, leave it as any value. EXAMPLE VALUE: 0

- [thickness]: the number of planar graphs you try to get from decomposing the original graph.

- [vertices_in_cliques]: number of vertices in the cliques you want to count in the complement of the union. EXAMPLE VALUE: 3

- [alpha], [beta], [rho]: these are 3 parameters alpha, beta and pheromone evaporation needed for ant_colony. EXAMPLE VALUE: 1 30 0.01

- [number of Ants]: Number of ants to run. EXAMPLE VALUE: 50

- [EDGE_LIMIT]: The maximum number of edges you can flip for an ant. DEFAULT VALUE is nv*(nv-1)*50. If you leave 0, the application will load the DEFAULT VALUE.

- [Qo], [Xi]: 2 parameters for Ant Colony System. EXAMPLE VALUE: 0.1 0.1

- [want to print every tour]: The value is 0 or 1. Default value is 0. If you set 1, the tour of every ant will be printed out in every iteration.

- [want to print tau]: Its value is 0 or 1. If you set 1, the tau or pheromone of all edges will be printed out at the end of every iteration.

- [number of iterations]: Number of iterations for the execution.


Example call: 
./ant_colony 0 0 15 0 0 2 3 1 30 0.01 1 10000 0.1 0.1 0 0 100
./ant_colony 0 0 17 0 0 2 3 1 30 0.01 1 10000 0.1 0.1 0 0 100
./ant_colony 0 0 23 1 1 2 3 1 30 0.01 1 10000 0.1 0.1 0 0 100
./ant_colony 0 0 25 3 1 2 3 1 30 0.01 1 10000 0.1 0.1 0 0 100
