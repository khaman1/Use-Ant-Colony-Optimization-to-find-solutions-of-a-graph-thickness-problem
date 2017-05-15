/* output a triangulation in lex format (not necessarily minimum (canonical)) */

#include <stdio.h>
#include <triang.h>
#include <string.h>

#define LINELEN 2000

void triang_lex(struct triang *t, int PRINT_OUT, int WRITE_TO_FILE, int FILE_TO_WRITE)
{
  char text[LINELEN];
  int ichar;
  int v0,v1;
	char buffer[1000];
	

  for (v0=0; v0<t->nv-2; v0++)
    for (v1=v0+1; v1<t->nv-1; v1++)
      if (t->edge[v0][v1] != -1)
	if (t->edge[v0][v1] < t->edge[v1][v0]) {
	  if (t->edge[v0][v1] > v1)
		{
	    if(PRINT_OUT)			
				printf("%c%c%c",i2a[v0],i2a[v1],i2a[t->edge[v0][v1]]);
			
			if(WRITE_TO_FILE)
			{
				sprintf(buffer, "%c%c%c",i2a[v0],i2a[v1],i2a[t->edge[v1][v0]]);
				write_log(buffer,FILE_TO_WRITE);
			}
		}
	  if (t->edge[v1][v0] > v1)
		{
	    if(PRINT_OUT)
				printf("%c%c%c",i2a[v0],i2a[v1],i2a[t->edge[v1][v0]]);
			
			if(WRITE_TO_FILE)
			{
				sprintf(buffer, "%c%c%c",i2a[v0],i2a[v1],i2a[t->edge[v1][v0]]);
				write_log(buffer,FILE_TO_WRITE);
			}
		}
	}
	else {
	  if (t->edge[v1][v0] > v1)
		{
	    if(PRINT_OUT)
				printf("%c%c%c",i2a[v0],i2a[v1],i2a[t->edge[v1][v0]]);
			
			if(WRITE_TO_FILE)
			{
				sprintf(buffer, "%c%c%c",i2a[v0],i2a[v1],i2a[t->edge[v1][v0]]);
				write_log(buffer,FILE_TO_WRITE);
			}
		}
	  if (t->edge[v0][v1] > v1)
		{
	    if(PRINT_OUT)
				printf("%c%c%c",i2a[v0],i2a[v1],i2a[t->edge[v0][v1]]);
			
			if(WRITE_TO_FILE)
			{
				sprintf(buffer, "%c%c%c",i2a[v0],i2a[v1],i2a[t->edge[v1][v0]]);
				write_log(buffer,FILE_TO_WRITE);
			}
		}
	}
	
  if(PRINT_OUT)
		printf("\n");
}
