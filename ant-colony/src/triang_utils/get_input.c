#include <stdio.h>

void get_int(prompt, integer)
char prompt[];
int *integer;
{
  /* read an integer value from standard input. or letter a=0, b=1, etc */

  char line[10];
  char charint;

  while ( 1 )
    {
      printf("Enter %s: ",prompt);
      line[9] = 0;
      if ( fgets(line,10,stdin) )
	if ( line[9] == 0 ) {
	  if ( sscanf(line,"%d",integer) == 1 )
	    break;
	  if ( sscanf(line,"%c",&charint) == 1 ) {
	    *integer = charint - 'a';
	    break;
	  }
	}
      //printf("\nEnter a single integer (or character). \n");
    }
  //printf("%s = %d\n",prompt,*integer);
}

void get_hex(prompt, integer)
char prompt[];
int *integer;
{
  /* read an HEX integer value from standard input. */

  char line[10];

  while ( 1 )
    {
      printf("Enter %s (in HEX): ",prompt);
      line[9] = 0;
      if ( fgets(line,10,stdin) )
	if ( line[9] == 0 )
	  if ( sscanf(line,"%x",integer) == 1 )
	    break;
      printf("\nEnter a single HEX value. \n");
    }
  printf("%s = %x\n",prompt,*integer);
}
