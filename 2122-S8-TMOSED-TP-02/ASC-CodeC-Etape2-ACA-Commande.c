/* --------------------------------- */
/*  TMOSED TP2 ASC Code C - Etape 2  */
/*  Grp 2 AUDIC-RONK     1 parmis N  */
/* --------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <dask.h>
#include "ASC-CodeC-Etape2-ACA-EntreesSorties.c"

int main() {
	// declarer les informations ici
	Reserver_Carte () ;
	// on initialise l etat present et l etat suivant a 1
	int ES = 1, EP = 1;
	// on créer nos variables qui retiendront les valeurs des Entrées
	int Ap1,Ap2,Ap3,Et1,Et2,Et3,PO;
	// ces entiers-ci vont permettre de retenir les boutons qui ont ete appuyes
	int A1,A2,A3;
	// decrire la commande a mettre en oeuvre ici

	while(1) { // on fait une boucle infinie
		// on lit les entrees pour retenir leurs valeurs
		Ap1 = LireEntree(0);
		Ap2 = LireEntree(1);
		Ap3 = LireEntree(2);
		Et1 = LireEntree(3);
		Et2 = LireEntree(4);
		Et3 = LireEntree(5);
		PO  = LireEntree(6);

		// si l un des boutons a ete appuye alors il est enregistre dans une des trois variables
		if (Ap1 = 1) { A1 = 1; }
		if (Ap2 = 1) { A2 = 1; }
		if (Ap3 = 1) { A3 = 1; }

		// bloc M
		switch(EP) {
			// pour cette partie on utilise les équations de franchissements
			case 1:
				if (A1)	{ ES = 5; break; }
				else {
					if (A2) { ES = 3; break;}
					else {
						if (A3 && !A1) { ES = 8; break;}}
				}
			case 3:
				if (A2 && !Et3 || A3) { ES = 6; break; }
				else { if (A2 && !Et1){ ES = 7; break; } }
			case 5: 	if (Et1) { ES = 9;  break; }
			case 6: 	if (Et2) { ES = 10; break; }
			case 7: 	if (Et2) { ES = 10; break; }
			case 8: 	if (Et3) { ES = 11; break; }
			case 9:
				if (PO) {
					ES = 12;
					A1 = 0; // l ascenceur est a l etage 1 donc l appui retenu peut etre oublie
					break;
				}
			case 10:
				if (PO) {
					ES = 13;
					A2 = 0; // l ascenceur est a l etage 2 donc l'appui retenu peut etre oublie
					break;
				}
			case 11:
				if (PO) {
					ES = 14;
					A3 = 0; // l ascenceur est a l etage 3 donc l appui retenu peut etre oublie
					break; }
			case 12:	if (!PO){ ES = 1; break; }
			case 13:	if (!PO){ ES = 1; break; }
			case 14:	if (!PO){ ES = 1; break; }
		}

		printf("EP = %d, ES = %d ",EP , ES); // on affiche les états avant le changement
		EP = ES; // l etat present prend pour valeur l etat suivant calcule


		// bloc F
		// monter est actif dans les etats 6 et 8
		if ( EP = ( 6 || 8 ) ) { EcrireSortie(0,1) }
		// monter est inactif dans tous les autres etats
		if ( EP = ( 1 || 5 || 3 || 9 || 7 || 11 || 12 || 10 || 14 || 13) ) { EcrireSortie(0,0) }
		// descendre est actif dans les états 5 et 7
		if ( EP = ( 5 || 7 ) ) { EcrireSortie(1,1) }
		// monter est inactif dans tous les autres etats
		if ( EP = ( 1 || 6 || 3 || 9 || 8 || 11 || 12 || 10 || 14 || 13) ) { EcrireSortie(1,1) }
	}

	Liberer_Carte () ;
	return (0) ;
}
