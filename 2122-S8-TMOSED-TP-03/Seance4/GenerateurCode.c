#include "types.c"
#include <string.h>

void GenererBlocF (Transition * Tstart, char LeFichierEnC[MAX_NOM]){
	printf("\n\n>>> Code Block F:\n\n");

	// Declaration Variables
	Transition * Tencours 	; // Transisition en cours de traitement
	Transition * Tinter			; // Transisition intermediaire pour verification
	Transition * Tinter2		; // Transisition intermediaire pour terme maintien

	// Variables pour garder trace des equatons deja ecrite
	int indice = 0 ;
	char Trace[20] = "" ;
	int flag = 1 ; // Autorisation de poursuivre

	//
	FILE * structure ;
	structure  = fopen(LeFichierEnC,"w");

/*
	// Verification de Lecture et Extraction des donnees
	Transition * Tverif		; // Transisition en cours de traitement (verif.)
	int indver = 0 ;
	char Trver[20] = "" ;

	printf( "\n--> Verification ET Extraction:\n\n" );

	Tverif = Tstart ;
	while ( Tverif != NULL ) {
		printf ( "Tverif = (tr,PE,PS) = ( %s , %s , %s )\n", Tverif->Nom, Tverif->ArcsEntrants->Place, Tverif->ArcsSortants->Place );
		Tverif = Tverif->Suivant ;
	}

	printf ( "\n" );

	Tverif = Tstart ;
	while ( Tverif != NULL ) {
		Trver[indver] = Tverif->ArcsSortants->Place[1] ;
		printf("Tverif = %s \t PEencours: %s -> %c \t PSencours: %s -> %c \t Trver[%d] = %d \t Predicat: %s \n", Tverif->Nom, Tverif->ArcsEntrants->Place, Tverif->ArcsEntrants->Place[1], Tverif->ArcsSortants->Place, Tverif->ArcsSortants->Place[1], indver, Trver[indver], Tverif->Predicat );
		Tverif = Tverif->Suivant ;
		indver++ ;
	}
*/

	// Initialisation sur les parametres donnees a la fonction GenererBlocF
	Tencours = Tstart ;

	// Parcours des transitions pour recuperer les equations du bloc F
	while ( Tencours != NULL ) {

		// Ecriture autorisee
		if ( flag == 1 ) {

			// Ecriture de l equation
			fprintf(structure,"\t ES_%c = EP_%c and %s", Tencours->ArcsSortants->Place[1], Tencours->ArcsEntrants->Place[1], Tencours->Predicat );
			Trace[indice] = Tencours->ArcsSortants->Place[1] ; // Tracabilite des places deja traitees

			Tinter = Tencours->Suivant ; // Tinter prends la valeur de Tencours Suivante

			while ( Tinter != NULL ) {
				// Si Tinter et Tencours ont d autres places sortants en commun alors completer equation
				if ( Tinter->ArcsSortants->Place[1] == Tencours->ArcsSortants->Place[1] ) {
					fprintf(structure," or EP_%c and %s", Tinter->ArcsEntrants->Place[1], Tinter->Predicat );
				}
				Tinter = Tinter->Suivant ; // Tinter Suivante
			}

			Tinter2 = Tencours ; // Tinter2 prends la valeur de Tencours Suivante

			while ( Tinter2 != NULL ) {
				// Regrouper les termes de maintiens (chercher les transitions non sensibilisees de place en cours)
				if ( Tinter2->ArcsSortants->Place[1] == Tencours->ArcsSortants->Place[1] ) {
					fprintf(structure," or EP_%c and not(%s)", Tinter2->ArcsSortants->Place[1], Tinter2->Predicat );
				}
				Tinter2 = Tinter2->Suivant ; // Tinter2 Suivante
			}
			fprintf(structure,"\n\n");
		}

		Tencours = Tencours->Suivant ; // Tencours Suivante

		// Autorisation
		if ( Tencours != NULL ) {
			for ( int i = 0 ; i < 20 ; i++ ) {
				if ( Tencours->ArcsSortants->Place[1] == Trace[i] ) {
					flag = 0 ; // Interdiction de poursuivre
					break ;
				} else { flag = 1 ; }
			}
		} else { printf("\n\n Boucle Finie \n\n"); break; }

		indice++ ;
	}
};
