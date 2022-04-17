#include "types.c"
#include <string.h>

void GenererLog (Place * Pmef, Transition * Tmef, char nom[MAX_NOM])
{
	Transition *Tre;
	Place *Pre;
	Arc * Arcs;
	Arc *Arce;
	Action *act;
	Tre = Tmef;
	Pre = Pmef;
	FILE *structure;
	structure  = fopen(nom,"w");
	fprintf(structure,"Liste des transitions\n");
	while(Tre!=NULL){
		fprintf(structure,"Nom de la transition = %s 	NbpE = %d 	NbpS = %d 	action = %s 	predicat = %s\n",Tre->Nom,Tre->NbPlacesEntree,Tre->NbPlacesSortie,Tre->Actions,Tre->Predicat);
		Arce = Tre->ArcsEntrants;
		Arcs = Tre->ArcsSortants;
		while(Arce!=NULL){			
			fprintf(structure,"Nom de l'arc= %s 	Poids = %d\n",Arce->Place,Arce->Poids);
			Arce = Arce->Suivant;
		}
		while(Arcs!=NULL){
			fprintf(structure,"Nom de l'arc= %s 	Poids = %d\n",Arcs->Place,Arcs->Poids);
			Arcs = Arcs->Suivant;
		}
		Tre=Tre->Suivant;
	}
	fprintf(structure,"Liste des places\n");
	while(Pre!=NULL){
		fprintf(structure,"Nom de la place= %s 	Mo = %d 	nbActions = %d\n",Pre->Nom,Pre->Mo,Pre->NbActions);
		act = Pre->Actions;
		while(act!=NULL){
			
			fprintf(structure,"Nom de l'action= %s \n",act->Actions);
			act = act->Suivant;
		}

		Pre=Pre->Suivant;
	}


	fclose(structure);
}
