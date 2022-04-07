#include "types.c"
#include <string.h>


void GenererBlocF (Transition * PremiereTransition, char LeFichierEnC[MAX_NOM])
{
	Transition *Tre;
	Transition *Teng;
	Transition *Tcheck;
	char place[MAX_NOM];
	char enr[MAX_NOM];
	int a=0,cont=0,i=0;
	Arc * Arcs;
	Arc *Arce;
	Teng = PremiereTransition;
	Tre = PremiereTransition;
	Tcheck = PremiereTransition;
	Arcs = PremiereTransition->ArcSortants;
	place = Arcs->Place;
	FILE *structure;
	structure  = fopen(LeFichierEnC,"w");

	while(Tre!=NULL){
		Tcheck = PremiereTransition;
		while(Tcheck!=NULL){

			if(Tcheck->ArcSortants->Place==Tre->ArcSortant->Place){
				enr[i]=Tcheck->Nom;
				i++;
			}
			Tcheck=Tchek->Suivant;	

		}
		i=0;
		Tcheck=PremierTransition;
		Arcs = Tre->ArcSortants;
		Arce = Tre->ArcEntrants;
		place = Arcs->Place;
		printf("%s <- %s and %s",Tre->ArcSortants->Place,Tre->Nom,Tre->ArcEntrants->Place);
		while(Teng!=NULL){
			if(place==Teng->ArcSortants->Place){
				printf(" or ");
				printf("%s and %s",Teng->ArcEntrants->Place,Teng->Nom);
			}
		}
		Teng = Tre;
		printf(";\n");
	}
	fclose(structure);

}
