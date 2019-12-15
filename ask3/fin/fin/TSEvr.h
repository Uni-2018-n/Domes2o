/*Antonis Kalamakis SDI1800056*/
#ifndef __TSEvr__
#define __TSEvr__

#include <stdio.h>
#include "read_data.h"
#include "Evretirio.h"

typedef struct data {
        /*  members for airport data in array */
        char* Name;
        char* City;
        char* Country;
        char* IATA;
        char* ICAO;
        int In;
        int Out;
}TStoixeiouEvr;

int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouAirport source);

TStoixeiouEvr TSEvr_create(int *error);
int TSEvr_copy(TStoixeiouEvr *target, TStoixeiouEvr source);

//oliki apokripsi
char* TSEvr_getName(TStoixeiouEvr temp);
char* TSEvr_getCity(TStoixeiouEvr temp);
char* TSEvr_getCountry(TStoixeiouEvr temp);
char* TSEvr_getIATA(TStoixeiouEvr temp);
char* TSEvr_getICAO(TStoixeiouEvr temp);

#endif
