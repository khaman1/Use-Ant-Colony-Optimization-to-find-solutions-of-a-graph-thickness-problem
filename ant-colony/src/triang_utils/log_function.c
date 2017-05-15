#include <stdio.h>
#include <triang.h>
#include <time.h>

void initialize_log_function()
{
	time_t rawtime;
  struct tm * timeinfo;
	char buffer[100];
	char buffer2[100];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime(buffer,100,"%m%d%Y",timeinfo); // Get the date in a specific format
	
	sprintf(buffer2, "./../log/Log%s.txt", buffer);
	prunelog_file = fopen(buffer2, "a");    // Create a log with the name Log(datetime)
	
	printf("Created a log %s.txt.\n", buffer);
}

void write_log(char text_to_write[], int file_to_write)
{
	switch(file_to_write)
	{
		case 0:
			fprintf(log_file, "%s", text_to_write);
			break;
			
		case 1:
			fprintf(prunelog_file, "%s", text_to_write);
			break;
		
		default:
			break;
	}
}