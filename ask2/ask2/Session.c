//Antonis Kalamakis sdi1800056
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Session.h"

typedef struct TabNode *TabNodePtr;
typedef struct SiteNode *SiteNodePtr;

struct InfoSession {
	TabNodePtr FirstTab;
	TabNodePtr LastTab;
	TabNodePtr CurrTab;
	TabNodePtr AuxTab;
	char* 	  OpeningAddress;
};

struct TabNode {
	TabNodePtr PrevTab, NextTab;
	SiteNodePtr FirstSite;
	SiteNodePtr CurrSite;
};

struct SiteNode{
	SiteNodePtr PrevSite, NextSite;
	TabNodePtr UpTab;
	char *Address;
};

InfoSessionPtr SessionNew(char * OpeningAddress){//dimiourgeia xwrou sthn mnhmh
	InfoSessionPtr Session = malloc(sizeof(struct InfoSession));
	TabNodePtr Tab = malloc(sizeof(struct TabNode));
	SiteNodePtr Site = malloc(sizeof(struct SiteNode));
	Session->OpeningAddress = malloc(256*sizeof(char *));
	Site->Address= malloc(256*sizeof(char *));
																					//kai arxikopoihsh twn metablitwn me tis prwtes times
	Session->FirstTab = Tab;
	Session->LastTab = Tab;
	Session->CurrTab = Tab;
	Session->AuxTab = NULL;
	strcpy(Session->OpeningAddress, OpeningAddress);

	Tab->PrevTab = Tab;
	Tab->NextTab = Tab;
	Tab->FirstSite = Site;
	Tab->CurrSite = Site;

	Site->PrevSite = NULL;
	Site->NextSite = NULL;
	Site->UpTab = Tab;
	strcpy(Site->Address, OpeningAddress);
	SessionTabShow(Session);
	return Session;
}

void SessionNewTab(InfoSessionPtr Session){ //dimiourgeia tou kainourgiou tab kai tou prwtou site tou kainourgiou tab
	TabNodePtr NewTab = malloc(sizeof(struct TabNode));
	SiteNodePtr Site = malloc(sizeof(struct SiteNode));
	Site->Address= malloc(256*sizeof(char *));
																					//kai arxikopoihsh
	Site->PrevSite = NULL;
	Site->NextSite = NULL;
	Site->UpTab = NewTab;
	strcpy(Site->Address, Session->OpeningAddress);

	NewTab->PrevTab = Session->LastTab;
	NewTab->NextTab = Session->FirstTab;
	NewTab->FirstSite = Site;
	NewTab->CurrSite = Site;
	Session->LastTab->NextTab = NewTab;


	Session->LastTab = NewTab;
	(Session->FirstTab)->PrevTab = NewTab;
	Session->CurrTab = NewTab;

	SessionTabShow(Session);
}

void SessionTabShow(InfoSessionPtr Session){//emfanish dedomenwn tou trexon site apo to trexon tab
	printf("Current Site data: %s\n", ((Session->CurrTab)->CurrSite)->Address);
}

void SessionTabNext(InfoSessionPtr Info){
	Info->CurrTab = (Info->CurrTab)->NextTab;
}

void SessionTabPrev(InfoSessionPtr Info){
	Info->CurrTab = (Info->CurrTab)->PrevTab;
}

void SessionTabMoveLeft(InfoSessionPtr Session){
	if(Session->FirstTab == Session->CurrTab){//elegxos an einai to prwto
		return;
	}
	if(Session->LastTab == Session->CurrTab){// h to teleytaio tab
		Session->LastTab = Session->CurrTab->PrevTab;

	}
	//(an einai to prwto mhn kanei tipota giati den 8eloume na einai kykliko)
	Session->CurrTab->PrevTab->NextTab = Session->CurrTab->NextTab;
	Session->CurrTab->NextTab->PrevTab = Session->CurrTab->PrevTab;

	Session->AuxTab = Session->CurrTab->PrevTab->PrevTab;

	Session->CurrTab->PrevTab->PrevTab->NextTab = Session->CurrTab;
	Session->CurrTab->PrevTab->PrevTab = Session->CurrTab;

	Session->CurrTab->NextTab = Session->CurrTab->PrevTab;

	Session->CurrTab->PrevTab = Session->AuxTab;
	Session->AuxTab = NULL;
}

void SessionTabMoveRight(InfoSessionPtr Session){
	if(Session->FirstTab == Session->CurrTab){//elegxos an einai to prwto
		Session->FirstTab = Session->CurrTab->NextTab;
	}
	if(Session->LastTab == Session->CurrTab){//h to teleytaio
		return;
	}
	//gia na mhn yparxei kiklikotita an einai teleutaio den kanei tipota
		Session->AuxTab = Session->CurrTab->NextTab->NextTab;
		Session->CurrTab->PrevTab = Session->CurrTab->NextTab;
		Session->CurrTab->NextTab->PrevTab = Session->CurrTab->PrevTab;
		Session->CurrTab->NextTab = Session->AuxTab;
		Session->AuxTab->PrevTab = Session->CurrTab;
		Session->CurrTab->NextTab->NextTab= Session->CurrTab;
		Session->AuxTab->NextTab = Session->FirstTab;
		Session->FirstTab->PrevTab = Session->AuxTab;
		Session->FirstTab->NextTab = Session->CurrTab;
		Session->AuxTab = NULL;

}

void SessionNewOpeningAddress(InfoSessionPtr Session, char* NewOpeningAddress){
	strcpy(Session->OpeningAddress, NewOpeningAddress);
}

void SessionShowOpeningAddress(InfoSessionPtr Session){
	printf("Current Opening Address:%s\n", Session->OpeningAddress);
}

void SessionSiteNext(InfoSessionPtr Session){
	if(Session->CurrTab->CurrSite->NextSite != NULL){//elegxos an yparxei epomeno site
		Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->NextSite;
	}else{
		printf("No next Site\n");
	}
}

void SessionSitePrev(InfoSessionPtr Session){
	if(Session->CurrTab->CurrSite->PrevSite != NULL){//elegxos an yparxei proigoumeno site
		Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->PrevSite;
	}else{
		printf("No Previous site\n");
	}
}

void SessionSiteShow(InfoSessionPtr Session){//idio me to SessionTabShow
	printf("Current Site: %s\n", Session->CurrTab->CurrSite->Address);
}

int SessionTabClose(InfoSessionPtr Session){//prwta prepei na klisoume ola ta site kai na kleisoume kai to tab
	TabNodePtr CurrT = Session->CurrTab;
  CurrT->CurrSite = CurrT->FirstSite;
  while(CurrT->CurrSite->NextSite != NULL){//prwta pame sto teleutaio site
    CurrT->CurrSite = CurrT->CurrSite->NextSite;
  }//edw to currsite exei ws timh to teleytaio site

  while(CurrT->CurrSite->PrevSite != NULL){//kanoume free ola ta site apo to teleutaio pros to prwto
    free(CurrT->CurrSite->Address);
    free(CurrT->CurrSite->NextSite);
    CurrT->CurrSite = CurrT->CurrSite->PrevSite;
  }//edw CurrSite == NULL kai exoyme kanei free ola ta site kai ta site->address
  free(CurrT->CurrSite->Address);
	free(CurrT->CurrSite->NextSite);
	free(CurrT->CurrSite);//elef8erwnei to address, to epomeno site kai to trexon site (ara den yparxoun alla site se ayto to tab)
	//kai ksekinaei na elef8erwsei to tab analoga me thn 8esh tou sto session
  if(CurrT == Session->FirstTab && CurrT == Session->LastTab){//elegxei an einai to monadiko tab(ara kleinei kai to session)
    free(CurrT);
    free(Session->OpeningAddress);
    free(Session);
    printf("Session Closed\n");
    return 1;//ekelise to session ara epistrefei 1
  }else if(CurrT == Session->FirstTab){ //elegxei an einai to prwto tab(ara metabalei kai ta Firsttab kai tis times tou kainoyrgiou FirstTab)
    Session->AuxTab = CurrT->NextTab;
    Session->FirstTab = Session->AuxTab;
		Session->LastTab->NextTab = Session->FirstTab;
    Session->AuxTab->PrevTab = Session->LastTab;
    Session->CurrTab = Session->AuxTab;
    Session->AuxTab = NULL;
    free(CurrT);
  }else if(CurrT == Session->LastTab){ //kai elegxei an einai to teleutaio tab kai kanei tis kataliles leitourgies
    Session->AuxTab = CurrT->PrevTab;
    Session->AuxTab->NextTab = Session->FirstTab;
    Session->LastTab = Session->AuxTab;
    Session->FirstTab->PrevTab = Session->AuxTab;
    free(CurrT);
    Session->CurrTab = Session->AuxTab;
		Session->AuxTab = NULL;
	}else { //telos an to currtab den exei kapoia eidiki topo8esia sto session(oute prwto, oute teleutaio, oute monadiko) kanei tis kataliles leitourgies
    Session->AuxTab = CurrT->NextTab;
    CurrT->PrevTab->NextTab = Session->AuxTab;
    Session->AuxTab->PrevTab = CurrT->PrevTab;
    free(CurrT);
    Session->CurrTab = Session->AuxTab;
    Session->AuxTab = NULL;
  }
	return 0;//epistrefei 0 an to session eksakolou8ei na yparxei(yparxoun kiala tabs)
}

int SessionClose(InfoSessionPtr Session){
	while(SessionTabClose(Session)!= 1);//kalei thn SessionTabClose mexri na epistrepsei thn timh 1(oti exei kleisei to session)
	return 1;
}

void SessionNewAddress(InfoSessionPtr Session, char * NewAddress){//dimiourgei ena kainourgio site sto currtab,
	SiteNodePtr NewSite = malloc(sizeof(struct SiteNode));//desmeuei mnhmh
	NewSite->Address = malloc(256*sizeof(char *));
	strcpy(NewSite->Address, NewAddress);//kai to pros8etei sto CurrTab
	NewSite->UpTab = Session->CurrTab;
	NewSite->NextSite = NULL;
	NewSite->PrevSite = NewSite->UpTab->CurrSite;
	Session->CurrTab->CurrSite->NextSite = NewSite;
	NewSite->UpTab->CurrSite = NewSite;//to 8etei ws trexon site
}
