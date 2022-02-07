//
//  bibliothequeB.c
//  
//
//  Nom Etudiant :
//  Prenom Etudiant : 
//  Numero compte :
//  M1 EEAS
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliothequeB.h"

//////////////////////////
int Pafficher_menu()
{
    /*************DEBUT DU CODE ENSEIGNANT*****************/
  int choix=0;
  //  printf("coucou !\n");
  while ((choix<1) || (choix>6))
    {
      printf("Menu calendrier\n");
      printf("Saisir la date : taper 1\n");
      printf("Vérifier si c’est une annee bissextile : taper 2\n");
      printf("Calculer le nombre de jours dans 1 mois : taper 3\n");
      printf("Trouver le jour correspondant a la date : taper 4\n");
      printf("Afficher le jour correspondant a la date : taper 5\n");
      printf("Quitter le programme : taper 6\n");

      printf("choix = \n");
      scanf("%d",&choix);
    }    
    return choix;
    /*************FIN DU CODE ENSEIGNANT*****************/
}

//////////////////////////
void saisir_jour(int le_jour[])
{
  /* Fonction qui renvoie dans un tableau en paramètre   */
  /* le numero du jour, le numero du mois et l'année */
  /* dans, respectivement, la 1è, la 2è et la 3è case du tableau */
    /*************DEBUT DU CODE ETUDIANT*****************/

    /**************Fin DU CODE ETUDIANT******************/
}




int bissextile(int annee)
{
  /* Fonction qui renvoie un entier 0 ou 1   */
  /* pour indiquer si l'annee est bissextile ou non */
  /* en fonction de l'annee en parametre */
    /*************DEBUT DU CODE ETUDIANT*****************/

    /**************Fin DU CODE ETUDIANT******************/
}

int longueur_mois(int mois, int annee)
{
  /* Fonction qui renvoie la longueur du mois   */
  /* en fonction de l'annee et du mois */
  /*  en parametres de la fonction */
    /*************DEBUT DU CODE ETUDIANT*****************/

    /**************Fin DU CODE ETUDIANT******************/
}

enum jour trouver_jour(int le_jour[])
{
  /* Fonction qui renvoie le jour en fonction   */
  /* de la date contenue dans le tableau "le_jour" */
  /*  en paramètre de la fonction */
    /*************DEBUT DU CODE ETUDIANT*****************/

    /**************Fin DU CODE ETUDIANT******************/
}

char * convertir_jour(enum jour un_jour)
{
  /* Fonction qui renvoie le nom du jour en fonction   */
  /* de la valeur contenue dans le parametre "un_jour" */
  /* 0 pour dimanche, 1 pour lundi, ..., 6 pour samedi */

    /*************DEBUT DU CODE ETUDIANT*****************/

    /**************Fin DU CODE ETUDIANT******************/
}