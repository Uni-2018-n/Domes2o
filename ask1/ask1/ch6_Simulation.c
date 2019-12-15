/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.h
Syggrafeas			: A. Kalamakis
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			: Antonis Kalamakis sdi1800056
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"
#include "ch6_Controller.h"

int main(void){
	float					pithanotita_afiksis; 	/*pi8anothta afikshs*/
	unsigned int	xronos_eksipiretisis;	/*xronos e3yphrethshs enos pelath*/
	unsigned int	xronos_prosomoiosis; 	/*synolikos xronos prosomoiwshs*/

	unsigned int	xronos = 0;			/*roloi prosomoiwshs*/
	TSOuras				Pelatis;		/* o pelaths sthn oyra*/
	float					mesos_xronos;		/*mesos xronos anamonhs tvn pelatvn*/
	float					randomAfixi;
	int           tamiasInactive = 0;
	time_t				t;
	int 					i;
	int 					min;//minimum
	int 					max;//kai maximum tou xronos_eksipiretisis
	int 					size;//plithos elektwn
	int 					z;

	printf("Dwste units of time prosomoiwshs (0 <=):\n");
	scanf("%u", &xronos_prosomoiosis);
	printf("Pi8anothta afikshs in unit of time (0,1):\n");
	scanf("%f", &pithanotita_afiksis);
	printf("MIN-Xrono e3yphrethshs (>=1) in unit of times:\n");
	scanf("%u", &min);
	printf("MAX-Xrono e3yphrethshs (>=MIN) in unit of times:\n");
	scanf("%u", &max);
	printf("Give pl ourwn:\n");
	scanf("%d", &size);
	getchar();
	printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_prosomoiosis);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	printf("H diarkeia e3yphrethshs enos pelath einai apo [%d,%d] units of time.\n",min, max);
	printf("Plithos ourwn: %d\n\n", size);

	TOuras oura[size]; /*initialization of the arrays */
	TController Controller[size];
	for(i=0;i<size;i++){
		OuraDimiourgia(&oura[i]);
		ControllerDimiourgia(&Controller[i]);
	};

	srand(time(&t));
	while( xronos < xronos_prosomoiosis ){
		/* Pelatis- Aytokinhto  */
		randomAfixi = (float)rand()/(float)RAND_MAX;
		if ( randomAfixi < pithanotita_afiksis ){
			xronos_eksipiretisis = min + rand()%(max+1-min);
			PelatisSetXronoEisodou(&Pelatis, xronos);
			PelatisSetXronoEksipiretisis(&Pelatis, xronos_eksipiretisis);
			i= 1;
			z= 0;
			while(i<size){//euresh mikroterhs ouras
				if(GetCountIn(oura[z]) > GetCountIn(oura[i])){
					z = i;
				};
				i++;
			};
			if (!OuraProsthesi(&oura[z], Pelatis)){//prosthikh sthn mikroterh oyra
         			printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
          			getchar();
          			return 0;
      };
			SetCountIn(&oura[z], 1);/*oura[z].CountIn++*/
  	};//if (randomAfixi < pithanotita_afiksis)

		for(i=0;i<size;i++){
		  /* Tamias-Elegxos */
			if (ControllerFree(Controller[i])){	/*eley8eros tamias*/
				if (!OuraKeni(oura[i])){			/*yparxei pelaths*/
					OuraApomakrynsh(&oura[i],&Pelatis);		/*phgainei sto tamio*/
					ControllerSetXronosAnamonis(&Controller[i], (ControllerGetXronosAnamonis(Controller[i])+xronos - PelatisGetXronoEisodou(Pelatis)));
					/*h panw entolh: xronos_anamonis = xronos_anamonis + xronos - xronos_eisodoy);*/
					ControllerNewCustomer(&Controller[i]);
					ControllerSetXrono(&Controller[i], PelatisGetXronoEksipiretisis(Pelatis)-1); /* kallyptei to trexon unit time */
					SetCountOut(&oura[i], 1);/*oura[i].CountOut++*/
				}else
					ControllerNoWork(&Controller[i]);
			}else
					ControllerBusy(&Controller[i]);	/*o tamias apasxolhmenos me pelath */
		};
		xronos++; /*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	} /*while(xronos < xronos_prosomoiosis)*/
	for(i=0;i<size;i++){
		if (!ControllerGetArithmosPelatwn(Controller[i]))
			mesos_xronos = 0.0;
		else
			mesos_xronos = ((float)ControllerGetXronosAnamonis(Controller[i]))/((float)ControllerGetArithmosPelatwn(Controller[i]));
		printf("<------------------------------------------------------------------------>\n");
		printf("Gia oura %d:\n", i+1);
		printf("Eksyphreth8hkan %d pelates\n",ControllerGetArithmosPelatwn(Controller[i]));
		printf("O mesos xronos anamonhs htan %4.2f units of time.\n",mesos_xronos);
		printf("O tamias htan adranhs gia %d units of time\n", ControllerGetInactiveXronos(Controller[i]));
		printf("Den Eksyphrethuhkan %d pelates\n", OuraGetSize(oura[i]));
		printf("Mphkan: %d\n", GetCountIn(oura[i]));
		printf("Bghkan: %d\n", GetCountOut(oura[i]));
		//printf("\n");
}
		printf("<------------------------------------------------------------------------>\n");

	getchar();
	return 0;
}
