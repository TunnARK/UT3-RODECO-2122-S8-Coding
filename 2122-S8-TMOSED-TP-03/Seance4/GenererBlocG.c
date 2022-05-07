#include "types.c"
#include <string.h>

void GenererBlocG (Place *PlacesRdP, char LeFichierBlocG[MAX_NOM]){
  printf("\n\n>>> Generation Code Block M\n\n");

	Place * pec;
 	Place * pinter;
	Action * act;
	Action * ainter;
	int indice = 0 ;
	char Trace[20] = "" ;
	int flag = 1 ; // Autorisation de poursuivre
	FILE *structure;
	structure  = fopen(LeFichierBlocG,"w");
	pec = PlacesRdP;

	while(pec != NULL){
		act = pec->Actions;
		pinter = pec;
			while(act!=NULL){
				if ( act != NULL ) {
					for ( int i = 0 ; i < 20 ; i++ ) {
						if ( act->Actions[0]== Trace[i] ) {
							flag = 0 ; // Interdiction de poursuivre
							break ;
						} else { flag = 1 ; }
					}
				}
				if(flag==1) {
					fprintf(structure, "%s <= EP_%c ",act->Actions,pec->Nom[1]);
					Trace[indice] = act->Actions[0];
					ainter = act;
					pinter = pec;
					while(pinter!=NULL){
						if(pinter!=pec){
							ainter=pinter->Actions;
							while(ainter!=NULL){
								if(ainter->Actions[0]==act->Actions[0]){
									fprintf(structure," or EP_%c",pinter->Nom[1]);
								}
								ainter=ainter->Suivant;
							}
						}
						pinter=pinter->Suivant;
					}
					fprintf(structure,";\n");
				}
				act = act->Suivant;
				indice++;
			}
		pec=pec->Suivant;
	}
  printf("\n\n>>> Generation Code Block M Finie\n\n");
};
