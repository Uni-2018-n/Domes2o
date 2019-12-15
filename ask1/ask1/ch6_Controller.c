/*************************************************
Arxeio ylopoihshs	: ch6_Controller.c
Syggrafeas			: A. Kalamakis
Skopos				: Functions for the Controller ATD
Revision 			: Antonis Kalamakis sdi1800056
**************************************************/
#include <stdio.h>
#include "ch6_Controller.h"

void ControllerDimiourgia(TController *Controller){
	Controller->TimeBusy = 0;
	Controller->TimeInactive = 0;
	Controller->ArithmoPelaton = 0;
	Controller->enapomenonXronos = 0;
	Controller->xronos_anamonis = 0.0;
}
void ControllerNewCustomer(TController *Controller){
	Controller->ArithmoPelaton += 1;
	Controller->TimeBusy += 1;
}
void ControllerSetXrono(TController *Controller, int xronosEksipiretisis){
	Controller->enapomenonXronos = xronosEksipiretisis;
}
void ControllerNoWork(TController *Controller){
	Controller->TimeInactive += 1;
}
void ControllerBusy(TController *Controller){
	Controller->TimeBusy += 1;
	Controller->enapomenonXronos -= 1;
}
int ControllerFree(TController Controller){
	return(Controller.enapomenonXronos == 0);
}
int ControllerGetArithmosPelatwn(TController Controller){
	return(Controller.ArithmoPelaton);
}
int ControllerGetEnapomenonXronos(TController Controller){
	return(Controller.enapomenonXronos);
}
int ControllerGetInactiveXronos(TController Controller){
	return(Controller.TimeInactive);
}
int ControllerGetBusyXronos(TController Controller){
	return(Controller.TimeBusy);
}
int ControllerGetXronosAnamonis(TController Controller){
	return(Controller.xronos_anamonis);
}
void ControllerSetXronosAnamonis(TController *Controller, int xronos_anamonis){
	Controller->xronos_anamonis = xronos_anamonis;
}
