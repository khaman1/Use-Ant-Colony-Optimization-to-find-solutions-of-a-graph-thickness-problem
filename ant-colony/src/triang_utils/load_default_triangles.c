#include <stdio.h>
#include <triang_utils.h>

int load_default_triangles(char text_file[], struct triang *t, struct triang *t1, struct triang *t2)
{
  char line[1024];
  int pos=0;

  //FILE *fp = fopen("./Data/17_0.txt", "r");
	
	char filename[100];
	sprintf(filename, "./../Data/%s.txt", text_file);
	FILE *fp = fopen(filename, "r");
	
  if( fp == NULL )
    return 1;
  while( fgets(line,1024,fp) ) {
    switch(pos)
      {
      case 0:
        decode_triang_lex(line,t1);
        break;
      case 1:
        decode_triang_lex(line,t2);
        break;
      default:
        break;
      }
    pos++;
  }
  merge_2_triang(t, t1, t2);
}
