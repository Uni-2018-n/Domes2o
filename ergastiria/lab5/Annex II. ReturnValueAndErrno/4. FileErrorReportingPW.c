//#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* demonstrate errno and perror on opening file with wrong permissions */

FILE * open_sesame (char *name)
{
  FILE *stream;

  errno = 0;
  stream = fopen (name, "w"); /* change with r to accept*/
  if (stream == NULL)
    { perror("File open Failure:");
	  fprintf (stderr, "error=%d, on file '%s'; \n", errno, name);
      exit (EXIT_FAILURE);
    }
  else
    return stream;
}

int main()
{	char str[10]="zzzz.txt";
	FILE * F = open_sesame(str); 
	return(0);
}
