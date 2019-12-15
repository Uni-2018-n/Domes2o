/*Antonis Kalamakis SDI1800056*/
#include "TSEvr.h"
#include <stdlib.h>
#include <string.h>
TStoixeiouEvr TSEvr_create(int *error){
  TStoixeiouEvr temp;
  /*initialize and check for errors */
  if(!(temp.Name = malloc(256*sizeof(char *)))){
    *error = 1;
  }
  if(!(temp.City = malloc(256*sizeof(char *)))){
    *error = 1;
  }
  if(!(temp.Country = malloc(256*sizeof(char *)))){
    *error = 1;
  }
  if(!(temp.IATA = malloc(256*sizeof(char *)))){
    *error = 1;
  }
  if(!(temp.ICAO = malloc(256*sizeof(char *)))){
    *error = 1;
  }
  temp.In = 0;
  temp.Out = 0;
  return temp;
}

int TSEvr_setValue (TStoixeiouEvr *target, TStoixeiouAirport source){
  strcpy(target->Name, source.Name);
  strcpy(target->City, source.City);
  strcpy(target->Country, source.Country);
  strcpy(target->IATA, source.IATA);
  strcpy(target->ICAO, source.ICAO);
}

int TSEvr_copy(TStoixeiouEvr *target, TStoixeiouEvr source){
  *target = source;
  return 0;
}


char* TSEvr_getName(TStoixeiouEvr temp){
  return temp.Name;
}

char* TSEvr_getCity(TStoixeiouEvr temp){
  return temp.City;
}

char* TSEvr_getCountry(TStoixeiouEvr temp){
  return temp.Country;
}

char* TSEvr_getIATA(TStoixeiouEvr temp){
  return temp.IATA;
}

char* TSEvr_getICAO(TStoixeiouEvr temp){
  return temp.ICAO;
}
