#include "types.c"
#include <string.h>


void GenererBlocF (Transition * PremiereTransition, char LeFichierEnC[MAX_NOM])
{
	Transition *Tre;
	Transition *Tcheck;
	Transition *T;
	char tab[MAX_NOM];
	int i=0,j=0,z=0;
	T = PremiereTransition;
	Tre = PremiereTransition;
	Tcheck = PremiereTransition;
	//FILE *structure;
	//structure  = fopen(LeFichierEnC,"w");
	while(Tre!=NULL){
		T = PremiereTransition;
		while(T!=NULL||j==1){
			if(tab[i]==Tre->ArcsSortants->Place[1])
			{j=1;}
			i++;
			T = T->Suivant;
			printf("%c\n",tab[i]);
		}	
		if(j==0){
			printf("ES_%c = EP_%c and %s",Tre->ArcsSortants->Place[1],Tre->ArcsEntrants->Place[1],Tre->Predicat);
			Tcheck = Tre;
			while(Tcheck!=NULL){
				if(Tcheck->ArcsSortants->Place[1]==Tre->ArcsSortants->Place[1] && Tcheck!=Tre){
					printf(" or EP_%c and %s",Tcheck->ArcsEntrants->Place[1],Tcheck->Predicat);
				}	
				Tcheck=Tcheck->Suivant;	
			}
			printf("\n");
			tab[z] = Tre->ArcsSortants->Place[1];
			z++;
			Tre = Tre->Suivant;
		}
		j=0;
	}

	//fclose(structure);

}
