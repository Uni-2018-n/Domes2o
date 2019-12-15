/*Antonis Kalamakis SDI1800056*/
#include "Evretirio.h"

/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - mporeite na xrhsimopoihsete
   thn  domh #if ... #else ...#endif gia na diaforopihsete tis dyo ylopoihseis  */

#if (Simple)
#include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
#else
#include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
#endif


struct EvrNode{
       TStoixeiouEvr *DataArray; /* array of size MaxSize */
       int Index;              /* index of first available element in array */
       typos_deikti TreeRoot;     /* Root of DDA */
} EvrNode;

EvrPtr EvrConstruct(int MaxSize){
/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres -
	mporeite na xrhsimopoihsete thn  domh #if ... #else ...#endif */

   typos_deikti TreeRoot;
#if (Simple)
   printf("use simple BST\n");
   Tree_dimiourgia(&TreeRoot);
#else
    printf("use AVL BST\n");
    AVLTree_dimiourgia(&TreeRoot);
#endif
  EvrPtr E = malloc(sizeof(EvrNode)); /*initialization of Evretirio*/
  E->DataArray = malloc(MaxSize*sizeof(TStoixeiouEvr));
  E->Index = 0;
  E->TreeRoot = TreeRoot;
  return E;
}

int EvrInsert(EvrPtr E, FILE* airports){
  //EvrInsert with 2 modes, check with spesific number of inputs and with EOF
  int error=0;
  TStoixeiouAirport tempAirport;
  TStoixeiouDDA tempDDA;
  //for EOF type, it reads last character to see if the last character is EOF and stop if nessesery
  int x= getc(airports);//just to start the while loop read the first character(it will be ungetc later)
  //for spesific number of inputs initialize x and x++ it till its the number of inputs we want
  //int x = 0;
  while(x != EOF){
  //while(x < 102){
    ungetc(x, airports);//unread the check-character
  tempAirport = AirportReadFunc(&error, airports);//read each row of AirportLinux*.txt file
  if(error == 1){//check if AirportReadFunc returned any errors
    return 1;
  }
  E->DataArray[E->Index] = TSEvr_create(&error);//initialize the slot in the DataArray
  if(error == 1){//check for possible errors
    return 1;
  }
  TSEvr_setValue(&(E->DataArray[E->Index]), tempAirport);//get data from the row and copy it to DataArray
  TSDDA_setKey(&tempDDA, AirportGetID(tempAirport)); //prepare the DDA element to add to the tree
  TSDDA_setIndex(&tempDDA, E->Index);//set the index for the tree
  #if(Simple)//check AVL or BST
  Tree_eisagogi(&(E->TreeRoot), tempDDA, &error);//input the DDA element to the Tree
  #else
  int yps;
  AVLTree_eisagogi(&(E->TreeRoot), tempDDA, &yps, &error);
  #endif
  E->Index = E->Index + 1;//prepare the Index for the next input
  AirportDestroy(tempAirport);//destroy the temp elements
  x = getc(airports);//read the check-character
  //x++; //++ x if spesific number of inputs is used
  }
  return 0;
}

int EvrSearch(EvrPtr E, keyType key, int InOut, int * found){
  TStoixeiouDDA temp;//prepare the DDA element to search
  TSDDA_setKey(&temp, key);
  typos_deikti tempd;//output typos_deikti to access the full data of the knob if found
  #if(Simple)
  Tree_anazitisi(E->TreeRoot, temp, &tempd, found);//search it
  #else
  AVLTree_anazitisi(E->TreeRoot, temp, &tempd, found);
  #endif
  if(*found == 1){//if found
    #if(Simple)
    Tree_periexomeno(tempd, &temp);//get data from the found element
    #else
    AVLTree_periexomeno(tempd, &temp);
    #endif
    if(InOut){//update the In or Out in DataArray
      (E->DataArray[TSDDA_arrayIndex_GET(temp)]).In = (E->DataArray[TSDDA_arrayIndex_GET(temp)]).In + 1;
    }else{
      E->DataArray[TSDDA_arrayIndex_GET(temp)].Out = E->DataArray[TSDDA_arrayIndex_GET(temp)].Out + 1;
    }
  }
}

void endodiataksi(EvrPtr E, typos_deikti riza, FILE *out, int *counter){
  //default endodiataksi function
  TStoixeiouDDA temp;
  #if (Simple)
  if(!Tree_keno(riza)){//check if tree is empty
    endodiataksi(E, Tree_apaidi(riza), out, counter); //retrospectively check the left child knob
    Tree_periexomeno(riza, &temp);//print data of the current knob
    fprintf(out, "%d, %d, %d\n", TSDDA_key_GET(temp), E->DataArray[TSDDA_arrayIndex_GET(temp)].In, E->DataArray[TSDDA_arrayIndex_GET(temp)].Out);
    *counter = *counter + 1;
    endodiataksi(E, Tree_dpaidi(riza), out, counter);//continue with right child
  }
  #else
  if(!AVLTree_keno(riza)){
    endodiataksi(E, AVLTree_apaidi(riza), out, counter);
    AVLTree_periexomeno(riza, &temp);
    fprintf(out, "%d, %d, %d\n", TSDDA_key_GET(temp), E->DataArray[TSDDA_arrayIndex_GET(temp)].In, E->DataArray[TSDDA_arrayIndex_GET(temp)].Out);
    *counter = *counter + 1;
    endodiataksi(E, AVLTree_dpaidi(riza), out, counter);
  }
  #endif
}

int EvrPrintAll(EvrPtr E, FILE *out, int *counter){
    endodiataksi(E, E->TreeRoot, out, counter);//for oliki apokripsi had to create a new function
    return 0;
}

int InOutFill(EvrPtr E, FILE *roots){
  TStoixeiouAirline temp;
  int error = 0;
  int readcounter= 0, airportnotfound=0, airportfound=0;
  int found;
  int x= fgetc(roots);//same technique with EvrInsert for reading data
  while(x != EOF){
    ungetc(x, roots);
  temp = AirlineReadFunc(roots, &error);//read the from the rootLinux*.txt each line
  if(error == 1){ //check for errors
    return 1;
  }
  readcounter++;//++ the Count counter
  if(temp.srcAirportID != -1){//check if airplane is leaving
    EvrSearch(E, temp.srcAirportID, 0, &found);
    if(found){
      airportfound++;//update Found Counter
    }else{
      airportnotfound++;//update NotFound Counter
    }
  }else{
    airportnotfound++;//update NotFound Counter
  }
  if(temp.dstAirportID != -1){//check if airplane is coming
    EvrSearch(E, temp.dstAirportID, 1, &found);
    if(found){
      airportfound++;
    }else{
      airportnotfound++;
    }
  }else{
    airportnotfound++;
  }

  x = fgetc(roots);
  AirlineDestroy(temp);//delete temp element
  }
  printf("Count:%d\nFound:%d\nNotfound:%d\n", readcounter, airportfound, airportnotfound);//print found data
  return 0;
}



int EvrDestruct(EvrPtr *E){//free all used memory
  int temp = 0;
  while(temp < (*E)->Index){
    free((*E)->DataArray[temp].Name);
    free((*E)->DataArray[temp].City);
    free((*E)->DataArray[temp].Country);
    free((*E)->DataArray[temp].IATA);
    free((*E)->DataArray[temp].ICAO);
    temp++;
  }
  free((*E)->DataArray);
  #if(Simple)
  Tree_katastrofi(&((*E)->TreeRoot));
  #else
  AVLTree_katastrofi(&((*E)->TreeRoot));
  #endif
  free(*E);
  return 0;
}
