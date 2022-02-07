//
//  modele-examen-TIMN-21-22-session1B.c
//  
//
// 	NE PAS MODIFIER CE FICHIER
//
// 	Compiler avec les 2 commandes suivantes
//  gcc -Wall -c bibliothequeB.c -lm
//	gcc -Wall -o prog modele-examen-TIMN-21-22-session1B.c bibliothequeB.o -lm
//
//	Exécuter avec ./prog en salle i1
//	Exécuter avec ./prog.exe en salle g19-g22
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliothequeB.h"

int main(void)
{
  int choix=0,biss,longueur;
  int date[3]={1,1,0}; //1er janvier de l’an 0
  enum jour quel_jour;

  while (choix!=6)
    {
      choix=Pafficher_menu();
      switch(choix)
        {
        case 1 :
          saisir_jour(date);
	  printf("Le jour est : %d-%d-%d \n",date[0],date[1],date[2]);
	  break;
	case 2 :
          biss = bissextile(date[2]);
	  if (biss)
	    printf("%d est une année bissextile\n",date[2]);
	  else
	    printf("%d n’est pas une année bissextile\n",date[2]);
          break;
	case 3 :
          longueur = longueur_mois(date[1], date[2]);
	  printf("Il y a %d jours\n",longueur);
          break;
        case 4 :
          quel_jour = trouver_jour(date);
          printf("Le numero du jour est %d \n", quel_jour);
          break;
	case 5 :
	  printf("Le %d-%d-%d est un %s \n",date[0],date[1],date[2],
                 convertir_jour(quel_jour));
	  break;
        case 6 :
          printf("Au revoir ! \n");
          break;  
        }
    }
    return 0;
}
