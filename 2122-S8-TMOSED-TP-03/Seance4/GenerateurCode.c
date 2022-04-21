#include "types.c"
#include <string.h>


// Retourne la position du char c dans string
int get_index(char* string, char c) {
    char *e = strchr(string, c);
    if (e == NULL) {
        return -1; // message erreur si char not found
    }
    return (int)(e - string);
}

// Retourne la negation du predicat de la transition T
void Negation ( Transition * T, char * NegPred ) {
	char 	 x 		= '\''	; // on cherche la premiere occurence de ' dans le predicat
	char * un 	= "1" 	;
	char * zero = "0" 	;

	if ( T->Predicat[get_index(T->Predicat, x)+1] == un[0] ) {

		T->Predicat[get_index(T->Predicat, x)+1] = '0' ; // remplace 1 par 0

		*       NegPred = T->Predicat ; // stocke la negation du predicat dans NegPred
		printf("\n\n->%s\n\n", NegPred );
	} else {

		if ( T->Predicat[get_index(T->Predicat, x)+1] == zero[0] ) {

			T->Predicat[get_index(T->Predicat, x)+1] = '1' ; // remplace 0 par 1

			NegPred = T->Predicat ; // stocke la negationd du predicat dans NegPred
			printf("\n\n-->%s\n\n", NegPred );
		} else { printf("\n\n \t !!! \t error: \t no ' found in predicat\n\n"); }
	}
}

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
			//printf("\ncoucou1\n");
			// Ecriture de l equation
			printf("\t ES_%c = EP_%c and %s", Tencours->ArcsSortants->Place[1], Tencours->ArcsEntrants->Place[1], Tencours->Predicat );

			//printf("\ncoucou2\n");
			Trace[indice] = Tencours->ArcsSortants->Place[1] ; // Tracabilite des places deja traitees

			Tinter = Tencours->Suivant ; // Tinter prends la valeur de Tencours Suivante

			//printf("coucou3\n");

			while ( Tinter != NULL ) {
				// Si Tinter et Tencours ont d autres places sortants en commun alors completer equation
				//printf("coucou4\n");
				if ( Tinter->ArcsSortants->Place[1] == Tencours->ArcsSortants->Place[1] ) {
					printf(" or EP_%c and %s", Tinter->ArcsEntrants->Place[1], Tinter->Predicat );
					//printf("coucou5\n");
				}
				Tinter = Tinter->Suivant ; // Tinter Suivante
			}

			Tinter2 = Tencours ; // Tinter2 prends la valeur de Tencours Suivante

			while ( Tinter2 != NULL ) {
				// Regrouper les termes de maintiens (chercher les transitions non sensibilisees de place en cours)
				if ( Tinter2->ArcsSortants->Place[1] == Tencours->ArcsSortants->Place[1] ) {
					char * NegPred ;
					Negation( Tinter2, &NegPred );
					printf(" or EP_%c and %s", Tinter2->ArcsSortants->Place[1], NegPred );
				}
				Tinter2 = Tinter2->Suivant ; // Tinter2 Suivante
			}

			printf ( "\n\n" );
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