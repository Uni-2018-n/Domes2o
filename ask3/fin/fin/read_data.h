/*Antonis Kalamakis SDI1800056*/
#ifndef __read_data__
#define __read_data__
#include <stdio.h>
typedef struct TStoixeiouAirportS TStoixeiouAirport;
struct TStoixeiouAirportS{
	int AirportID;
	char* Name;
	char* City;
	char* Country;
	char* IATA;
	char* ICAO;
};

typedef struct TStoixeiouAirlineS TStoixeiouAirline;
struct TStoixeiouAirlineS{
	char* Airline;
	int AirlineID;
	char* srcAirport;
	int srcAirportID;
	char* dstAirport;
	int dstAirportID;
	char* Codeshare;
	int Stops;
	char* Equipment;
};

TStoixeiouAirport AirportReadFunc(int *error, FILE* airports);

int AirportGetID(TStoixeiouAirport temp);
char* AirportGetName(TStoixeiouAirport temp);
char* AirportGetCity(TStoixeiouAirport temp);
char* AirportGetCountry(TStoixeiouAirport temp);
char* AirportGetIATA(TStoixeiouAirport temp);
char* AirportGetICAO(TStoixeiouAirport temp);

int AirportDestroy(TStoixeiouAirport temp);

TStoixeiouAirline AirlineReadFunc(FILE *in, int *error);
char* AirlineGetAirline(TStoixeiouAirline temp);
int AirlineGetAirlineID(TStoixeiouAirline temp);
char* AirlineGetsrcAirport(TStoixeiouAirline temp);
int AirlineGetsrcAirportID(TStoixeiouAirline temp);
char* AirlineGetdstAirport(TStoixeiouAirline temp);
int AirlineGetdstAirportID(TStoixeiouAirline temp);
char* AirlineGetCodeshare(TStoixeiouAirline temp);
int AirlineGetStops(TStoixeiouAirline temp);
char* AirlineGetEquipment(TStoixeiouAirline temp);

void AirlineDestroy(TStoixeiouAirline temp);
#endif
