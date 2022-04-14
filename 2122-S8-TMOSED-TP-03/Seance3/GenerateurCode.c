#include "types.c"
#include <string.h>


void GenererBlocF (Transition * PremiereTransition, char LeFichierEnC[MAX_NOM])
{
	Transition *Tre;
	//Transition *Teng;
	Transition *Tcheck;
	char place[MAX_NOM]="0";
	char enr[10][MAX_NOM];
	int i=0;
	Arc * Arcs;
	//Arc *Arce;
	//Teng = PremiereTransition;
	Tre = PremiereTransition;
	Tcheck = PremiereTransition;
	Arcs = PremiereTransition->ArcsSortants;
	strcpy(place,Arcs->Place);
	//FILE *structure;
	//structure  = fopen(LeFichierEnC,"w");
	//printf("enr%c\n",enr[1][1]);
	while(Tre!=NULL){
		printf("ES_%c = EP_%c and %s\n",Tre->ArcsSortants->Place[1],Tre->ArcsEntrants->Place[1],Tre->Predicat);
		Tcheck = PremiereTransition;
		/*while(Tcheck!=NULL){
			if(Tcheck->ArcsSortants->Place==Arcs->Place){
				strcpy(enr[i][],Tcheck->Nom);//a modifier ou rajouter des trucs
				i++;
				printf(" transition lie a %s sont %s  dev y av %s\n",Tre->Nom,enr[i][],Tcheck->Nom);
			}	
			Tcheck=Tcheck->Suivant;	
		}*/
		i=0;
		Arcs = Tre->ArcsSortants;
		//Arce = Tre->ArcsEntrants;
		//printf("%s <- %s and %s\n",Tre->ArcsSortants->Place,Tre->Nom,Tre->ArcsEntrants->Place);
		/*while(Teng!=NULL){
			if(Arcs->Place ==Teng->ArcsSortants->Place){
				printf(" or ");
				printf("%s and %s",Teng->ArcsEntrants->Place,Teng->Nom);
			}
		}
		Teng = Tre;
		printf(";\n");*/
		Tre = Tre->Suivant;
	}
	//fclose(structure);

}
