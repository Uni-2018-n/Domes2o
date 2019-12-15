/*************************************************
Arxeio ylopoihshs	: ch6_Controller.h
Syggrafeas			: A. Kalamakis
Skopos				: header file of ch6_Controller.c
Revision 			: Antonis Kalamakis sdi1800056
**************************************************/
#ifndef __CH6_CONTROLLER_H__
#define __CH6_CONTROLLER_H__
#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"

typedef struct {
	int TimeBusy;
	int TimeInactive;
	int ArithmoPelaton;
	int enapomenonXronos;
	int xronos_anamonis;
}TController;

void ControllerDimiourgia(TController *Controller);
void ControllerNewCustomer(TController *Controller);
void ControllerSetXrono(TController *Controller, int xronosEksipiretisis);
void ControllerNoWork(TController *Controller);
void ControllerBusy(TController *Controller);
int ControllerFree(TController Controller);

int ControllerGetArithmosPelatwn(TController Controller);
int ControllerGetEnapomenonXronos(TController Controller);
int ControllerGetInactiveXronos(TController Controller);
int ControllerGetBussyXronos(TController Controller);

void ControllerSetXronosAnamonis(TController *Controller, int xronos_anamonis);
int ControllerGetXronosAnamonis(TController Controller);
#endif
