/*************************************************
Arxeio ylopoihshs	: ch6_QArray.c
Syggrafeas			: A. Kalamakis
Skopos				: ATD QUEUE with counter - array
Revision 			: Antonis Kalamakis sdi1800056
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ch6_QArray.h"


void OuraDimiourgia(TOuras *oura )
{
	oura->embros =  0;
	oura->piso = 0;
	oura->metritis = 0;
	oura->CountIn = 0;
	oura->CountOut = 0;
}

int OuraGetSize(TOuras oura){
	return (oura.metritis);
}


int OuraKeni(TOuras oura)
{
	return ( oura.metritis == 0 );
}

int OuraGemati(TOuras oura) /* OXI sthn diepafi-edv bohthitikh */
{
		return oura.metritis == QSIZE;
}

int OuraProsthesi(TOuras *oura, TSOuras stoixeio)
{
	if (OuraGemati(*oura))
		return 0;
	else
	{
		TSOurasSetValue(&(oura->pinakas[oura->piso]),stoixeio); /* abstraction of = for any type */
		oura->piso = ( oura->piso + 1 )% QSIZE;
		oura->metritis++;
	}
	return 1;
}

int OuraApomakrynsh(TOuras *oura, TSOuras *stoixeio)
{
	if (OuraKeni(*oura))
		return 0;
	else
	{
		TSOurasSetValue(stoixeio, oura->pinakas[oura->embros]); /* abstraction of = for any type */
		oura->embros = ( oura->embros + 1 )% QSIZE;
		oura->metritis--;
	}
	return 1;
}

int GetCountIn(TOuras oura){
	return(oura.CountIn);
}

int GetCountOut(TOuras oura){
	return(oura.CountOut);
}

void SetCountIn(TOuras *oura, int value){
	oura->CountIn += value;
}

void SetCountOut(TOuras *oura, int value){
	oura->CountOut += value;
}

int OuraSmaller(int size, TOuras oura[size], int i, int z){
	if(z>=size||i>=size){
		return i;
	}else	if(OuraGetSize(oura[i]) <= OuraGetSize(oura[z])){
		i= OuraSmaller(size, oura, i, i+1);
	}else{
		i= OuraSmaller(size, oura, z, z+1);
	}
	return i;
}
