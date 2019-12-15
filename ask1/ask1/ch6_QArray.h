/*************************************************
Arxeio ylopoihshs	: ch6_QArray.h
Syggrafeas			: A. Kalamakis
Skopos				: Header file of ATD Queue - counter - array
Revision 			: Antonis Kalamakis sdi1800056
**************************************************/
#ifndef __CH6_QARRAY_H__
#define __CH6_QARRAY_H__
#include "TStoixeiouOuras.h"

#define QSIZE 1000

typedef struct {
	int embros;		/* position of first element */
	int piso;		/* position of last  element */
	int metritis;   /* counter - elements in queue */
	int CountIn;
	int CountOut;

	TSOuras pinakas[QSIZE];	/* array of queue elements */
} TOuras;	   /* New Name of Type Queue */

void OuraDimiourgia(TOuras *oura);

int	OuraKeni	(TOuras oura);

int OuraProsthesi	(TOuras *oura, TSOuras stoixeio);
int OuraApomakrynsh (TOuras *oura, TSOuras *stoixeio);
int OuraGetSize(TOuras oura);

int GetCountIn(TOuras oura);
int GetCountOut(TOuras oura);

void SetCountIn(TOuras *oura, int value);
	void SetCountOut(TOuras *oura, int value);

int OuraSmaller(int size, TOuras oura[size], int i, int z);
#endif
