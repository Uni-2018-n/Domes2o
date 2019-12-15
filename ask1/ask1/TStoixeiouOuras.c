/*************************************************
Arxeio ylopoihshs	: TStoixeiouOuras.c
Syggrafeas			: A. Kalamakis
Skopos				: Ylopoihsh typou stoixeiou ths oyras
Revision 			: Antonis Kalamakis sdi1800056
**************************************************/
#include <stdio.h>
#include "TStoixeiouOuras.h"

void TSOurasSetValue(TSOuras *stoixeioPtr, TSOuras data)
{
	*stoixeioPtr = data;  /* basic type assignment */
}

void PelatisSetXronoEisodou(TSOuras *stoixeioPtr, int xronos)
{
	stoixeioPtr->XronosEisodou=xronos;
}

int PelatisGetXronoEisodou(TSOuras stoixeio)
{
	return stoixeio.XronosEisodou;
}

void PelatisSetXronoEksipiretisis(TSOuras *stoixeioPtr, int duration){
	stoixeioPtr->XronosEksipiretisis = duration;
}

int PelatisGetXronoEksipiretisis(TSOuras stoixeio){
	return(stoixeio.XronosEksipiretisis);
}
