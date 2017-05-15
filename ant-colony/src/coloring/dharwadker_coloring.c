#include <triang.h>
#include <triang_utils.h>

int dharwadker_coloring(struct triang t, int MODE_TEST)
{
	int i,j,temp,temp2;
	int nv = t.nv;
	
	/* 
	FILE *fp = fopen("graph.txt", "w");
	
	fprintf(fp, "%d\n", nv);
	
	for(i=0;i<nv;i++)
	{
		for(j=0;j<nv;j++)
		{
			if(t.edge[i][j]==1)
				fprintf(fp, " 1");
			else
				fprintf(fp, " 0");
		}
		if(i!=(nv-1))
			fprintf(fp, " \n");
	}
	
	fclose(fp); 
	*/
	
	if(MODE_TEST)
	{
		get_int("the color to test: ", &temp);
		get_int("DEBUG MODE (1/0)?: ", &temp2);
	}
	
	temp = vertex_coloring(t.nv, t.edge, temp,temp2);
	
	if(MODE_TEST)
		printf("Color received: %d\n", temp);
	
	return temp;
}