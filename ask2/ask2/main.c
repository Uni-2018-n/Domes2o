//Antonis Kalamakis sdi1800056
#include <stdio.h>
#include <stdlib.h>

#include "Session.h"

int main(int argc, char *argv[]) {
	InfoSessionPtr 	MySession1=NULL, MySession2 = NULL, CurrSession = NULL; //xrish tou CurrSession etsi oste an xriastei na allaksoume session
	int command;																														//apla na allaksoume ta dedomena tou CurrSession me ena =
	int fin = 1;
	char string[256];
	while(fin){
		printf("------------------------\n");
		printf("|1.New Session					\n");
		printf("|2.New Tab							\n");
		printf("|3.Show Current Tab			\n");
		printf("|4.Next Tab							\n");
		printf("|5.Previous Tab					\n");
		printf("|6.Tab Move Left				\n");
		printf("|7.Tab Move Right				\n");
		printf("|8.New Opening Address	\n");
		printf("|9.Show Opening Address	\n");
		printf("|10.Site Next						\n");
		printf("|11.Site Previous				\n");
		printf("|12.Site Show						\n");
		printf("|13.Tab Close						\n");
		printf("|14.Session Close				\n");
		printf("|15.New Address					\n");
		printf("|0.Exit									\n");//h epilogh 0 apodesmeuei thn mnhmh kai termatizei to programma stamatontas thn epanalypsh
		printf("------------------------\n");

		scanf("%d", &command);
		while(MySession1 == NULL && (command != 1 && command != 0)){
			printf("There is no Session please insert command 1 or 0\n");
			scanf("%d", &command);
		}
		switch(command){
			case 0:
				fin =0;
				if(MySession1 != NULL){
					if(SessionClose(MySession1) == 1){
						MySession1 = NULL;
					}else{
						printf("Error Closing Session1\n");
					}
				}
				if(MySession2 != NULL){
					if(SessionClose(MySession2) == 1){
						MySession2 = NULL;
					}else{
						printf("Error Closing Session2\n");
					}
				}
				break;
			case 1:
				printf("New Session, Opening Address:\n");
				scanf("%s", string);
				if(MySession1 == NULL){//elegxos gia to poio session na dhmhourghsei, an to 1o yparxei hdh tote ftiaxnei to deytero
					MySession1 = SessionNew(string);
					CurrSession = MySession1;
				}else if (MySession2 == NULL){
					MySession2 = SessionNew(string);
					CurrSession = MySession2;
				}else{// allios emfanizei minima la8ous oti mporei na exei mono 2 sessions
					printf("Error, max number of sessions is 2\n");
				}
				break;
			case 2:
				printf("Adding new tab to the Session\n");
				SessionNewTab(CurrSession);
				break;
			case 3:
				printf("Content of current tab:\n");
				SessionTabShow(CurrSession);
				break;
			case 4:
				printf("Next tab:\n");
				SessionTabNext(CurrSession);
				break;
			case 5:
				printf("Previus tab:\n");
				SessionTabPrev(CurrSession);
				break;
			case 6:
				printf("Tab move left:\n");
				SessionTabMoveLeft(CurrSession);
				break;
			case 7:
				printf("Tab move right:\n");
				SessionTabMoveRight(CurrSession);
				break;
			case 8:
				printf("New Opening Address set to: ");
				scanf("%s", string);
				SessionNewOpeningAddress(CurrSession, string);
				break;
			case 9:
				printf("Show Opening Address\n");
				SessionShowOpeningAddress(CurrSession);
				break;
			case 10:
				printf("Next Site:\n");
				SessionSiteNext(CurrSession);
				break;
			case 11:
				printf("Previous Site:\n");
				SessionSitePrev(CurrSession);
				break;
			case 12:
				printf("Site Show:\n");
				SessionSiteShow(CurrSession);
				break;
			case 13:
				printf("Closing Current Tab\n");
				if(SessionTabClose(CurrSession)== 1){//elegxos gia poi8anothta na einai to teleutaio tab(ara kleinei to session)
					if(CurrSession == MySession1){
						MySession1 = NULL;
					}else{
						MySession2 = NULL;
						CurrSession = MySession1;
					}
				}
				break;
			case 14:
				printf("Closing Session\n");
				if(CurrSession == MySession1){//elegxei gia to poio session einai to current session kai to kleinei
					if(SessionClose(MySession1) == 1){
						MySession1 = NULL;
					}else{
						printf("Error Closing Session1\n");
					}
				}else{
					if(SessionClose(MySession2) == 1){
						MySession2 = NULL;
						CurrSession = MySession1;//an to currsession einai to session 2 tote 8etei ws curr session to session 1
					}else{
						printf("Error Closing Session2\n");
					}
				}
				break;
			case 15:
				printf("Open New Address in Current Tab: ");
				scanf("%s", string);
				SessionNewAddress(CurrSession, string);
				break;
			default:
				printf("did nothing\n");
		}
		printf("\n");

}
	return 0;
}
