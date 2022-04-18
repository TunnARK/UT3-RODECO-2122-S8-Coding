#include "types.c"
#include <string.h>

void codef (Transition * Tstart, char LeFichierEnC[MAX_NOM]){

	printf("\n\n>>> Code Block F:\n\n");

	// Declaration Variables
	Transition * Tencours ; // Transisition en cours de traitement
	Transition * Tverif		; // Transisition en cours de traitement (verif.)
	Transition * Tinter		; // Transisition intermediaire pour verification
	//	char PEencours[MAX_NOM]			; // Place ArcsEntrants en cours de traitement
	//	char PSencours[MAX_NOM]			; // Place ArcsSortants en cours de traitement

	// Variables pour garder trace des equatons deja ecrite
	int indice = 0 ;
	char Trace[20] = "" ;
	int flag = 1 ; // Autorisation de poursuivre

	int indver = 0 ;
	char Trver[20] = "" ;


	// Verification de Lecture et Extraction des donnees
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

	// Initialisation sur les parametres donnees a la fonction GenererBlocF
	Tencours = Tstart ;

	// Parcours des transitions pour recuperer les equations du bloc F
	while ( Tencours != NULL ) {
//		printf ( "\n\nTencours = %s \t Trace[%d] = %d \t flag = %d\n\n", Tencours->Nom, indice, Trace[indice], flag );

		// Ecriture autorisee
		if ( flag == 1 ) {
			printf("\t ES_%c = EP_%c and %s", Tencours->ArcsSortants->Place[1], Tencours->ArcsEntrants->Place[1], Tencours->Predicat );

			Trace[indice] = Tencours->ArcsSortants->Place[1] ;

			Tinter = Tencours->Suivant ;

			while ( Tinter != NULL ) {
//				printf ( "\n\n\t\t\t\tTinter = %s\n\n", Tinter->Nom );

				if ( Tinter->ArcsSortants->Place[1] == Tencours->ArcsSortants->Place[1] ) {
					printf(" or EP_%c and %s", Tinter->ArcsEntrants->Place[1], Tinter->Predicat );
				}

				Tinter = Tinter->Suivant ;
			}
		}

//		printf("\t\t\t\t\t\t\t\t Test suivant\n");
		Tencours = Tencours->Suivant ;

		// Autorisation
		if ( Tencours != NULL ) {
			for ( int i = 0 ; i < 20 ; i++ ) {
				if ( Tencours->ArcsSortants->Place[1] == Trace[i] ) {
					flag = 0 ; // Interdiction de poursuivre
//					printf("\nPSencours = %d =?= %d = Trace[%d] \t flag = %d \t Interdit", Tencours->ArcsSortants->Place[1], Trace[i], i, flag );
					break ;
				} else { flag = 1 ; }
//				printf( "\nPSencours = %d =?= %d = Trace[%d] \t flag = %d", Tencours->ArcsSortants->Place[1], Trace[i], i, flag );
			}
		} else { printf("Boucle Finie\n"); break; }

		indice++ ;
	}
};
