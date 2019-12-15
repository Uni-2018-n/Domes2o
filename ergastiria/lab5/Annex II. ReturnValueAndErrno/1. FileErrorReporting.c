#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* demonstrate errno and strerror */

FILE * open_sesame (char *name)
{
  FILE *stream;

  errno = 0;
  stream = fopen (name, "r");
  if (stream == NULL)
    { fprintf (stderr, "Did not open file %s errno=%d cause=%s\n", name, errno, strerror (errno));
      exit (EXIT_FAILURE);
    }
  else
    return stream;
}

int  main()
{FILE * F = open_sesame("xxxx"); /* file xxxx does not exist */
}
