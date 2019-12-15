#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Demonstrate errno and perror */

FILE * open_sesame (char *name)
{
  FILE *stream;

  errno = 0;
  stream = fopen (name, "r");
  if (stream == NULL)
    { perror("File open Failure");
	  fprintf (stderr, "on file '%s' errno=%d \n", name, errno);
      exit (EXIT_FAILURE);
    }
  else
    return stream;
}

int main()
{	char str[10]="xxxx";
	FILE * F = open_sesame(str);
}
