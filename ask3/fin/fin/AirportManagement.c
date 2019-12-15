/************************************************************************
Programma pelaths	: AirportManagement.c
Syggrafeas			: Antonis Kalamakis SDI1800056
Skopos				: skeleton main for askhsh 3
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Evretirio.h"
#include <sys/time.h>                /* for gettimeofday() */

int ProgramSorted(char* airport, char* routes);
int ProgramRandom(char* airport, char* routes);

int main(int argc, char *argv[])
{
  printf("Sorted: \n");
      /*Enter airports sorted txt file path here*/    /*Enter routes path here*/
  ProgramSorted("DATA/Linux/airportsLinuxSorted.txt", "DATA/Linux/routesLinux.txt");
  printf("\nRandom: \n");
      /*Enter airports Random txt file path here*/    /*Enter routes path here*/
  ProgramRandom("DATA/Linux/airportsLinuxRandom.txt", "DATA/Linux/routesLinux.txt");
  printf("Program Ended.\n");
  getchar();
  return 0;
}


int ProgramSorted(char* airport, char* routes){
    EvrPtr E;

    E=EvrConstruct(7200);
    FILE *airports;
    airports = fopen(airport, "r");
    FILE *roots;
    roots = fopen(routes, "r");
    FILE *out;
    #if(Simple)
    out = fopen("OUTPUTSortedBST.txt", "w");
    #else
    out = fopen("OUTPUTSortedAVL.txt", "w");
    #endif

    /*timer */
    struct timeval t1, t2;
    double elapsedTime;


    /*ER 2 timer */
    elapsedTime = 0.0;
    /*start*/
    gettimeofday(&t1, NULL);

    /*do this */
    if(EvrInsert(E,airports)){
      return 1;
    }
    fclose(airports);
    /*</>*/

    /* stop*/
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("ER 2: elapsedTime=%g msec\n", elapsedTime);
    /*ER 2 timer </> */


    /*ER 3 timer */
    elapsedTime = 0.0;

    /* start*/
    gettimeofday(&t1, NULL);

    /*do this */
    if(InOutFill(E, roots)){
      return 1;
    }
    fclose(roots);
    /* </> */

    /* stop*/
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("ER 3: elapsedTime=%g msec\n", elapsedTime);
    /*ER 3 timer </>*/


    int counter;
    /*ER 4 timer */
    elapsedTime = 0.0;

    /* start*/
    gettimeofday(&t1, NULL);

    /*do this */
    EvrPrintAll(E, out, &counter);
    fprintf(out, "counter: %d\n", counter);
    /* </> */

    /* stop*/
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("ER 4: elapsedTime=%g msec\n", elapsedTime);
    fprintf(out, "time= %g msec\n", elapsedTime);
    fclose(out);
    /*ER 4: timer </> */

    EvrDestruct(&E);
}

int ProgramRandom(char* airport, char* routes){
  EvrPtr E;

    E=EvrConstruct(7200);
    FILE *airports;
    airports = fopen(airport, "r");
    FILE *roots;
    roots = fopen(routes, "r");
    FILE *out;
    #if(Simple)
    out = fopen("OUTPUTRandomBST.txt", "w");
    #else
    out = fopen("OUTPUTRandomAVL.txt", "w");
    #endif

    /*timer */
    struct timeval t1, t2;
    double elapsedTime;

    /*ER 2 timer */
    elapsedTime = 0.0;

    /* start*/
    gettimeofday(&t1, NULL);

    /*do this */
    if(EvrInsert(E,airports)){
      return 1;
    }
    fclose(airports);
    /*</>*/

    /* stop*/
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("ER 2:elapsedTime=%g msec\n", elapsedTime);
    /*ER 2 timer </> */

    /*ER 3 timer */
    elapsedTime = 0.0;

    /* start*/
    gettimeofday(&t1, NULL);

    /*do this */
    if(InOutFill(E, roots)){
      return 1;
    }
    fclose(roots);
    /* </> */

    /* stop*/
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("ER 3:elapsedTime=%g msec\n", elapsedTime);
    /*ER 3 timer </>*/


    int counter;
    /*ER 4 timer */

    elapsedTime = 0.0;

    /* start*/
    gettimeofday(&t1, NULL);

    /*do this */
    EvrPrintAll(E, out, &counter);
    fprintf(out, "counter: %d\n", counter);
    /* </> */

    /* stop*/
    gettimeofday(&t2, NULL);

    /* compute and print the elapsed time in millisec */
    elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
    printf("ER 4: elapsedTime=%g msec\n", elapsedTime);
    fprintf(out, "time = %g msec\n", elapsedTime);
    fclose(out);
    /*ER 4 timer </> */

    EvrDestruct(&E);
}
