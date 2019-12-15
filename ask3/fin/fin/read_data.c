/*Antonis Kalamakis SDI1800056*/
#include "read_data.h"
#include "TSDDA.h"
#include "TSEvr.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

TStoixeiouAirport AirportReadFunc(int *error, FILE* airports){
  /*this function reads one line from the airports file
    It initialize the struct and its variables, reports for any possible errors
    It cuts the line into parts, it assignes the data to the variables of the struct
    and it returns the stract
  */

  /* %[^;]; = read string untill ";" and read the ";"*/

  /*if scanf returns 0 it means that the input was ";;" so it reads the extra ";"
    and assignes the \N value into the struct.
  */

  	TStoixeiouAirport temp;
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

		fscanf(airports, "%d;", &(temp.AirportID));
    if(!fscanf(airports, "%[^;];", temp.Name)){
      fgetc(airports);
      strcpy(temp.Name, "\\N");
    }
    if(!fscanf(airports, "%[^;];", temp.City)){
      fgetc(airports);
      strcpy(temp.City, "\\N");
    }
    if(!fscanf(airports, "%[^;];", temp.Country)){
      fgetc(airports);
      strcpy(temp.Country, "\\N");
    }
    if(!fscanf(airports, "%[^;];", temp.IATA)){
      fgetc(airports);
      strcpy(temp.IATA, "\\N");
    }
    if(!fscanf(airports, "%[^\n]\n", temp.ICAO)){
      fgetc(airports);
      strcpy(temp.ICAO, "\\N");
    }
  	return temp;
}

int AirportGetID(TStoixeiouAirport temp){
  return temp.AirportID;
}

char* AirportGetName(TStoixeiouAirport temp){
  return temp.Name;
}
char* AirportGetCity(TStoixeiouAirport temp){
  return temp.City;
}
char* AirportGetCountry(TStoixeiouAirport temp){
  return temp.Country;
}
char* AirportGetIATA(TStoixeiouAirport temp){
  return temp.IATA;
}
char* AirportGetICAO(TStoixeiouAirport temp){
  return temp.ICAO;
}

int AirportDestroy(TStoixeiouAirport temp){
  free(temp.Name);
  free(temp.City);
  free(temp.Country);
  free(temp.IATA);
  free(temp.ICAO);
  return 0;
}

//airlines
TStoixeiouAirline AirlineReadFunc(FILE *in, int *error){
  /*similar with AirportReadFunc*/
  /*for int assignments if the scanf returns 0 it assignes an error value of -1*/
  TStoixeiouAirline temp;
  if(!(temp.Airline = malloc(256*sizeof(char *)))){
    *error = 1;
  }
  if(!(temp.srcAirport = malloc(256*sizeof(char *)))){
    *error = 1;
  }
  if(!(temp.dstAirport = malloc(256*sizeof(char *)))){
    *error = 1;
  }
  if(!(temp.Codeshare = malloc(256*sizeof(char *)))){
    *error = 1;
  }
  if(!(temp.Equipment = malloc(256*sizeof(char *)))){
    *error = 1;
  }

  char* probs; //probs is used to read untill ";" for a part with no valid data
  if(!(probs = malloc(256*sizeof(char *)))){
    *error = 1;
  }

  if(!fscanf(in,"%[^;];", temp.Airline)){
    fgetc(in);
    strcpy(temp.Airline, "\\N");
  }
  if(!fscanf(in,"%d;", &(temp.AirlineID))){
    fgetc(in);
    temp.AirlineID = -1;
    fscanf(in,"%[^;];", probs);
  }
  if(!fscanf(in,"%[^;];", temp.srcAirport)){
    fgetc(in);
    strcpy(temp.srcAirport, "\\N");
  }
  if(!fscanf(in,"%d;", &(temp.srcAirportID))){
    fgetc(in);
    temp.srcAirportID = -1;
    fscanf(in,"%[^;];", probs);
  }
  if(!fscanf(in,"%[^;];", temp.dstAirport)){
    fgetc(in);
    strcpy(temp.dstAirport, "\\N");
  }
  if(!fscanf(in,"%d;", &(temp.dstAirportID))){
    fgetc(in);
    temp.dstAirportID = -1;
    fscanf(in,"%[^;];", probs);
  }
  if(!fscanf(in,"%[^;];", temp.Codeshare)){
    fgetc(in);
    strcpy(temp.Codeshare, "\\N");
  }
  if(!fscanf(in,"%d;", &(temp.Stops))){
    fgetc(in);
    temp.Stops = -1;
    fscanf(in,"%[^;];", probs);
  }
  if(!fscanf(in,"%[^\n]\n", temp.Equipment)){
    fgetc(in);
    strcpy(temp.Equipment, "\\N");
  }
  free(probs);
  return temp;
}

char* AirlineGetAirline(TStoixeiouAirline temp){
  return temp.Airline;
}

int AirlineGetAirlineID(TStoixeiouAirline temp){
    return temp.AirlineID;
}

char* AirlineGetsrcAirport(TStoixeiouAirline temp){
    return temp.srcAirport;
}

int AirlineGetsrcAirportID(TStoixeiouAirline temp){
    return temp.srcAirportID;
}

char* AirlineGetdstAirport(TStoixeiouAirline temp){
    return temp.dstAirport;
}

int AirlineGetdstAirportID(TStoixeiouAirline temp){
    return temp.dstAirportID;
}

char* AirlineGetCodeshare(TStoixeiouAirline temp){
    return temp.Codeshare;
}

int AirlineGetStops(TStoixeiouAirline temp){
    return temp.Stops;
}

char* AirlineGetEquipment(TStoixeiouAirline temp){
    return temp.Equipment;
}

void AirlineDestroy(TStoixeiouAirline temp){
  free(temp.Airline);
  free(temp.srcAirport);
  free(temp.dstAirport);
  free(temp.Codeshare);
  free(temp.Equipment);
}
