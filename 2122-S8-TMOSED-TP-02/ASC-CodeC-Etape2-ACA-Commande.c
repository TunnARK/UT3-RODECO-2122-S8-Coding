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

	int ES = 1, EP = 1;
	int Ap1,Ap2,Ap3,Et1,Et2,Et3,PO;

	// decrire la commande a mettre en oeuvre ici
	while(1) {
		Ap1 = LireEntree(0);
		Ap2 = LireEntree(1);
		Ap3 = LireEntree(2);
		Et1 = LireEntree(3);
		Et2 = LireEntree(4);
		Et3 = LireEntree(5);
		PO  = LireEntree(6);

		//Bloc M
		switch(EP)
			case 1:		if (Et2)	{ ES = 2; break; }
			case 2: 	if (PO)		{ ES = 3; break; }
			case 3: 	if (!PO)	{ ES = 4; break; }
			case 4: 	if ()			{ ES = 3; break; }
			case 5: 	if ()			{ ES = 3; break; }
			case 6: 	if ()			{ ES = 3; break; }
			case 7: 	if ()			{ ES = 3; break; }
			case 8: 	if ()			{ ES = 3; break; }
			case 9:		if ()			{ ES = 3; break; }
			case 10:	if ()			{ ES = 3; break; }

		EP=ES;
		printf("EP = %d, ES = %d ",EP , ES);

		// Bloc F
		if ( EP = ( || ) ) { EcrireSortie(0,1) }

		if ( EP = ( || ) ) { EcrireSortie(0,0) }

		if ( EP = ( || ) ) { EcrireSortie(1,1) }

		if ( EP = ( || ) ) { EcrireSortie(1,1) }
	}

	Liberer_Carte () ;
	return (0) ;
}
