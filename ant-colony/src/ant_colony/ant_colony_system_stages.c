/*
ant_colony_system_stages.c
implementation of functions defined in ant_colony.h
*/

#include <ant_colony.h>
#include <math.h>

#define DEBUG 0

int RouletteWheelSelection(Ant MyAnt, int dupTimes)
{
	double r = (double)rand() / (double)RAND_MAX; // For different range, follow http://www.eternallyconfuzzled.com/arts/jsw_art_rand.aspx
	
	double *C =  malloc(MyAnt.ListFECnt*sizeof(double));
	
	int i,j,flag;
	for(i=0;i<MyAnt.ListFECnt;i++)
	{
		C[i]=0;
		for(j=0;j<=i;j++)
			C[i]+=MyAnt.P[j]; // Accumulate all the P[j] from the index 0 to index i
		
		
		if(r<C[i])
		{
			flag=0;
			for(j=0;j<MyAnt.TourCnt;j++)
				if(MyAnt.ListFE_TMP[i][0]==MyAnt.ListFE[j][0] && MyAnt.ListFE_TMP[i][1]==MyAnt.ListFE[j][1])
				{
					flag++;
					if(flag>dupTimes)
						break;
				}
			
			if(flag<=dupTimes)
				return i;
			
		}	
	}
	return -1;
}

void write_adjacency_matrix(int edge[128][128], int nv, int FILE_TO_WRITE)
{
	int i,j;
	char buffer[1000];
	
	for(i=0;i<nv-1;i++)
		for(j=i+1;j<nv;j++)
		{
			sprintf(buffer, "%d ",edge[i][j]);
			write_log(buffer,FILE_TO_WRITE);
		}
}

int are_triang_equal(struct triang triang1, struct triang triang2)
{
	int i,j;
	
	for(i=0;i<triang1.nv-1;i++)
		for(j=i+1;j<triang1.nv;j++)
			if(triang1.edge[i][j] != triang2.edge[i][j])
				return 0;
			
	return 1;
}

struct triang triang_s1[1000];
struct triang triang_s2[1000];
int triang_cnt=0;

// RUNNING MODE = 0: Get the solution, write to the log => start with another random pair of triangulations and do the job again.
// RUNNING_MODE = 1: Collect the different pairs of t1,t2
// RUNNING_MODE = 2: Only looking for the union with the chromatic number higher than the bound. For example: 17 vertices with chromatic number 10
void write_log_if_found_solution(Ant MyAnt, int PRINT_OUT)
{
	int color,i,flag;
	double lowerbound;
	char buffer[1000];
	
	if(PRINT_OUT)
	{
		printf("SOLUTION FOUND\n");

		for(i=1;i<=thickness;i++)
		{
			printf("Lex format of t[%d]:\n",i);
			triang_lex(&(MyAnt.t[i]),1,0,0);
		}
	}
	
	if(RUNNING_MODE==0)
	{
		if(MyAnt.Cost[MyAnt.TourCnt-1]==0)
		{
			
			
			
			for(i=1;i<=thickness;i++)
			{
				triang_lex(&(MyAnt.t[i]),0,1,0);
				write_log(",",0);
				
				printf("Triang %d:\n", i);
				print_neighbors2(&(MyAnt.t[i]));
			}

			sprintf(buffer, "%d,%d,%d,%d,%d,%.1f,%.1f,%.4f,%d,%d,%.2f,%.2f\n", t[1].nv,thickness,genus,orient,num_of_vertices_in_cliques,alpha,beta,rho,nAnt,EDGE_LIMIT,Q0,Xi);
			write_log(buffer,0);
		}
	}
	/* else if(RUNNING_MODE==1)
	{
		// Prune the triangulations
		get_critical_graph(&MyAnt.t, &(MyAnt.t1), &(MyAnt.t2), 0);
		
		// Check if they do exist in the saved list
		flag=0;
		
		for(i=0;i<triang_cnt;i++)
			if(are_triang_equal(MyAnt.t1, triang_s1[i]) && are_triang_equal(MyAnt.t2, triang_s2[i]))
			{
				flag=1;
				break;
			}

		// If not, save to the list
		if(flag==0)
		{
			triang_s1[triang_cnt]=MyAnt.t1;
			triang_s2[triang_cnt]=MyAnt.t2;
			triang_cnt++;
			printf("SOLUTIONS SAVED: %d\n", triang_cnt);
		}

	}
	else if(RUNNING_MODE==2)
	{
		color = dsatur_coloring(MyAnt.t.edge, MyAnt.t.nv, 0);
		
		lowerbound = ceil(((double) MyAnt.t.nv)/((double) (num_of_vertices_in_cliques-1)));

		if(color>lowerbound)
		{
			printf("WOW! WE FOUND SOMETHING NEW with chromatic number %d\n",color);
			
			get_critical_graph(&MyAnt.t, &(MyAnt.t1), &(MyAnt.t2), 0);
			
			printf("Lex format of t1:\n");
			triang_lex(&(MyAnt.t1),1,0);
			printf("Lex format of t2:\n");
			triang_lex(&(MyAnt.t2),1,0);
			
			printf("****** output from print_neighbors of layer 1:\n\n");
			print_neighbors2(&(MyAnt.t1));
			printf("****** output from print_neighbors of layer 2:\n\n");
			print_neighbors2(&(MyAnt.t2));
			printf("****** output from print_neighbors of the union:\n\n");
			print_neighbors2(&(MyAnt.t));
		}
	} */
}

void write_data(Ant *MyAnt, int PRINT_OUT)
{
	char buffer[1000];
	
	//merge_2_triang(&MyAnt.t, &(MyAnt.t1), &(MyAnt.t2));
	
	int i,color;
	
	if(PRINT_OUT)
	{
		printf("SOLUTION AFTER PRUNING\n");

		for(i=1;i<=thickness;i++)
		{
			printf("Lex format of t[%d]:\n",i);
			triang_lex(&((*MyAnt).t[i]),1,0,0);
		}
	}
	
	if(RUNNING_MODE==0)
	{
		if(MyAnt->Cost[MyAnt->TourCnt-1]==0)
		{
			printf("FOUND A SOLUTION!\n");
			printf("BEFORE PRUNING!\n");
			for(i=1;i<=thickness;i++)
			{
				printf("Triang %d\n", i);
				print_neighbors2(&(MyAnt->t[i]));
				printf("\n\n");
			}
			
			get_critical_graph(MyAnt, 0);
			color = dsatur_coloring((*MyAnt).t[0].edge, (*MyAnt).t[0].nv, 0);
			
			
			for(i=1;i<=thickness;i++)
			{
				printf("Triang %d\n", i);
				print_neighbors2(&(MyAnt->t[i]));
				printf("\n\n");
			}
			
			
			sprintf(buffer, "%d,%d,%d,%d,%d,%d,%d,%.1f,%.1f,%.4f,%d,%d,%.2f,%.2f", color,MyAnt->Cost[MyAnt->TourCnt-1],t[1].nv,thickness,genus,orient,num_of_vertices_in_cliques,alpha,beta,rho,nAnt,EDGE_LIMIT,Q0,Xi);
			write_log(buffer,1);
			
			/* for(i=1;i<=thickness;i++)
			{
				//triang_lex(&(MyAnt->t[i]),0,1,1);
				write_log(",",1);
				write_adjacency_matrix((*MyAnt).tmin[i].edge, (*MyAnt).t[i].nv, 1);	
			} */
			
			write_log("\n",1);
		}
	}
}

void ant_colony_system_tour_construction(Ant* MyAnt)
{
  int i,idx,l,min, temp,v1,v2,v3,v4;
	struct triang t_temp;
	int num_vertices = t[1].nv;
	
	for(l=0;l<EDGE_LIMIT;l++)
	{		
		//printf("l: %d\n",l);
		get_flippable_edges(MyAnt); // Get the list of flippable edges
		
		
		for(i=0;i<MyAnt->ListFECnt;i++)
		{
			
			t_temp = MyAnt->t[MyAnt->ListFE_Layer[i]];
			FlipEdge(&t_temp, MyAnt->ListFE_TMP[i][0], MyAnt->ListFE_TMP[i][1]);
			merge_triangs3(MyAnt, t_temp, MyAnt->ListFE_Layer[i]);
			MyAnt->FECost[i] = count_cliques(get_complement_graph(&(MyAnt->t[0])), num_of_vertices_in_cliques, 0);
			
			if(MyAnt->FECost[i]==0)
			{
				ant_colony_system_save_selection(MyAnt, i);
				return;
			}
		}
		
		idx = ant_colony_system_selection(MyAnt);
		
		ant_colony_system_save_selection(MyAnt, idx);
		
		if(idx!=-1)
			local_pheromone_update(MyAnt->ListFE_TMP[idx][0], MyAnt->ListFE_TMP[idx][1]);
	}
}

int ant_colony_system_selection(Ant *MyAnt)
{
  if(DEBUG) printf("ant colony system selection\n");
	
	int i,j=0,argmax_idx;
	double sum;
	double temp,argmax;
	
	temp = (long double)rand() / (long double)RAND_MAX; // Generate a random number between 0<temp<1
					
	// if temp<= Q0: Calculate the argmax and do the edge selection
	// else: calculate the probabilities and do the edge selection
	if(temp<=Q0)
	{
		argmax=0;
		for(i=0;i<MyAnt->ListFECnt;i++)
		{
			// Choose the maximum of tau_i^beta
			temp = tau[MyAnt->ListFE_TMP[i][0]][MyAnt->ListFE_TMP[i][1]]*pow((long double)1/MyAnt->FECost[i],beta);
			if(argmax<temp)
			{
				argmax = temp;
				argmax_idx = i;
			}
		}
		j = argmax_idx;
	}
		
	else
	{
		//sum=0;
	
		for(i=0;i<MyAnt->ListFECnt;i++)
		{
			// Calculate P[i] = tau0^alpha * cost^beta
			MyAnt->P[i] = pow((long double)tau[MyAnt->ListFE_TMP[i][0]][MyAnt->ListFE_TMP[i][1]],alpha)*pow((long double)1/MyAnt->FECost[i],beta);
			
			
			sum += MyAnt->P[i]; // Accumulate for the sum
		}
		
		 
		for(i=0;i<MyAnt->ListFECnt;i++)
			MyAnt->P[i] = MyAnt->P[i]/sum; // Divide to the sum to get P[i] = tau0^alpha * cost^beta / sum
		
		j = RouletteWheelSelection(*MyAnt,10); // Do the roulette wheel selection. 10 means to allow 10 duplicates in the tour
	}
	
	return j;
}


void prune_tours(Ant *MyAnt)
{
  if(DEBUG) printf("prune tours\n");
	
	int i,final_idx=0;
	
	// Figure out the best part of the tour
	for(i=1;i<MyAnt->TourCnt;i++)
		if(MyAnt->Cost[final_idx]>MyAnt->Cost[i])
			final_idx  = i;		
	
	// Save the best part to the counter of the tour
	MyAnt->TourCnt = final_idx+1;
}

void find_best_tour(Ant MyAnt, Solution *BestSol)
{
  if(DEBUG) printf("find best tour\n");
	
	int i;
	
	if(BestSol->Cost > MyAnt.Cost[MyAnt.TourCnt-1])
	{
		BestSol->Cost 		= MyAnt.Cost[MyAnt.TourCnt-1];
		BestSol->TourCnt  = MyAnt.TourCnt;
		
		for(i=0;i<MyAnt.TourCnt;i++)
		{			
			BestSol->ListFE[i][0] = MyAnt.ListFE[i][0];
			BestSol->ListFE[i][1] = MyAnt.ListFE[i][1];
		}
	}
}