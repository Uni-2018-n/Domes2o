/*************************************************
Arxeio ylopoihshs	: TStoixeiouOuras.h
Syggrafeas			: A. Kalamakis
Skopos				: Diepafi typou stoixeiou ths oyras
Revision 			: Antonis Kalamakis sdi1800056
**************************************************/

#ifndef __TSTOIXEIOUOURAS_H__
#define __TSTOIXEIOUOURAS_H__

typedef struct {
	int XronosEisodou; /* Minute of entering queue */
	int XronosEksipiretisis;

} TSOuras; /* name TSOuras is used in ATD Oura - not to be changed */

void TSOurasSetValue(TSOuras *stoixeioPtr, TSOuras testdata);
/* name TSOurasSetValue is used in ATD Oura - not to be changed */

/* All names below indicate that Typos Stoixeiou is Pelatis (Car) */

void PelatisSetXronoEisodou(TSOuras *stoixeioPtr, int xronos);
int  PelatisGetXronoEisodou(TSOuras stoixeio);

void PelatisSetXronoEksipiretisis(TSOuras *stoixeioPtr, int duration);
int PelatisGetXronoEksipiretisis(TSOuras stoixeio);

#endif
