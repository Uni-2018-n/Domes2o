/*Antonis Kalamakis SDI1800056*/
#include "TSDDA.h"


int TSDDA_setValue (TStoixeiouDDA *target, TStoixeiouDDA source){
  TSDDA_setKey(target, source.key);
  TSDDA_setIndex(target, source.arrayIndex);
  return 0;
}

int TSDDA_writeValue(FILE * output,TStoixeiouDDA data){
  fprintf(output, "%d;%d\n", data.key, data.arrayIndex);
  return 0;
}

int TSDDA_setKey(TStoixeiouDDA *temp, keyType Val){
  temp->key = Val;
  return 0;
}

int TSDDA_setIndex(TStoixeiouDDA *temp, int Val){
  temp->arrayIndex = Val;
  return 0;
}

int TSDDA_iso(TStoixeiouDDA s1, TStoixeiouDDA s2){
  if(s1.key == s2.key){
    return 1;
  }else{
    return 0;
  }
}

int TSDDA_mikrotero(TStoixeiouDDA s1, TStoixeiouDDA s2){
  if(s1.key < s2.key){
    return 1;
  }else{
    return 0;
  }
}

int TSDDA_megalytero(TStoixeiouDDA s1, TStoixeiouDDA s2){
  if(s1.key > s2.key){
    return 1;
  }else{
    return 0;
  }
}

/* The Following are already Implemented using Above */

int TSDDA_mikrotero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return TSDDA_mikrotero(s1,s2)||TSDDA_iso(s1,s2);
}

int TSDDA_megalytero_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return TSDDA_megalytero(s1,s2)||TSDDA_iso(s1,s2);
}

int TSDDA_diaforo(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
    return !TSDDA_iso(s1,s2);
}



int TSDDA_arrayIndex_GET(TStoixeiouDDA temp){
  return temp.arrayIndex;
}

int TSDDA_key_GET(TStoixeiouDDA temp){
  return temp.key;
}
