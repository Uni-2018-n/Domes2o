#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* demonstrate errno and perror on opening a directory */

FILE * open_sesame (char *name)
{
  FILE *stream;

  errno = 0;
  stream = fopen (name, "r");
  if (stream == NULL)
    { perror("File open Failure:");
	  fprintf (stderr, " errno=%d, on file '%s'; \n", errno, name);
      exit (EXIT_FAILURE);
    }
  else
    return stream;
}

int main()
{	char str[10]="YYYY";
	FILE * F = open_sesame(str);
}
