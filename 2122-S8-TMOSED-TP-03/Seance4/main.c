#define MAX_NOM 200

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.c"


void NettoyerLaChaine (char *);

void CreerStructure (char [MAX_NOM], Transition **, Place **);
void GenererBlocF (Transition *TransitionsRdP, char [MAX_NOM]);
void GenererLog (Place * Pmef, Transition * Tmef, char [MAX_NOM]);
void GenererPlaces (Place *, char [MAX_NOM]);
void GenererBlocG (Place *, char [MAX_NOM]);
void codef (Transition * Tstart, char LeFichierEnC[MAX_NOM]);

int main(void)
{
Transition * TransitionsRdP=NULL;
Place      * PlacesRdP=NULL;


char LeFichierTINA[MAX_NOM]   = "etiquette.ndr";
char LeFichierLog[MAX_NOM]    = "etiquette.log";
char LeFichierEnC[MAX_NOM]    = "DescriptionTransitions.c";
char LeFichierPlaces[MAX_NOM] = "LesPlaces.c";
char LeFichierBlocG[MAX_NOM]  = "CalculDesSorties.c";

printf ("nom du fichier a Mouliner :");
scanf ("%s",LeFichierTINA);
strcpy(LeFichierLog,LeFichierTINA);
strcat(LeFichierTINA, ".ndr");
strcat(LeFichierLog,".log");


// ouverture du fichier issus de tina

CreerStructure (LeFichierTINA, &TransitionsRdP, &PlacesRdP);


GenererLog (PlacesRdP, TransitionsRdP, LeFichierLog);
GenererPlaces (PlacesRdP, LeFichierPlaces);
GenererBlocF (TransitionsRdP, LeFichierEnC);
GenererBlocG (PlacesRdP, LeFichierBlocG);


return 1;
}
