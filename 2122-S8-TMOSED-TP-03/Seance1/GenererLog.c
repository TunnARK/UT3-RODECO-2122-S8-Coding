#include "types.c"
#include <string.h>

void GenererLog (Place * Pmef, Transition * Tmef, char nom[MAX_NOM])
{
	int i=0;
	Transition *Tre;
	Tre = Tmef;
	FILE *structure;
	structure  = fopen("structure.txt","w");
	do{
		
		fprintf(structure,"Nom de la transition = %s NbpE = %d NbpS = %d action = %s predicat = %s\n",Tre->Nom,Tre->NbPlacesEntree,Tre->NbPlacesSortie,Tre->Actions,Tre->Predicat);
	}while(i!=0);
	fclose(structure);
}
