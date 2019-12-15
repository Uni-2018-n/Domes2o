/*Antonis Kalamakis SDI1800056*/
#ifndef __TSDDA__
#define __TSDDA__
#include <stdio.h>

typedef int keyType; /* integer key for airport */

typedef struct KeyIndex{
        keyType key;
        int arrayIndex;
} TStoixeiouDDA;

int TSDDA_setValue (TStoixeiouDDA *target, TStoixeiouDDA source);

int TSDDA_writeValue(FILE * output,TStoixeiouDDA data);

int TSDDA_setKey(TStoixeiouDDA *temp, keyType Val);

int TSDDA_setIndex(TStoixeiouDDA *temp, int Val);

/* basikes sygkriseis gia xrhsh sthn eisagcgh-diagarfh-anazhthsh se DDA */
int TSDDA_iso(TStoixeiouDDA, TStoixeiouDDA);
int TSDDA_mikrotero(TStoixeiouDDA, TStoixeiouDDA);
int TSDDA_megalytero(TStoixeiouDDA, TStoixeiouDDA);

/* symplhrvmatikes sygkriseis */
int TSDDA_mikrotero_iso(TStoixeiouDDA, TStoixeiouDDA);
int TSDDA_megalytero_iso(TStoixeiouDDA, TStoixeiouDDA);
int TSDDA_diaforo(TStoixeiouDDA, TStoixeiouDDA);

int TSDDA_arrayIndex_GET(TStoixeiouDDA temp);
int TSDDA_key_GET(TStoixeiouDDA temp);
#endif
