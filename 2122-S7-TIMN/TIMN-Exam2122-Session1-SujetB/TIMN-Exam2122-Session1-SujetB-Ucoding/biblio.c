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
#include "biblio.h"

//////////////////////////
int Pafficher_menu()
{
    /*************DEBUT DU CODE ENSEIGNANT*****************/

    int choix=0;

    while ((choix<1) || (choix>6))
    {
      printf("\n");
      printf(">>> Menu calendrier :\n");
      printf("\t Taper 1 pour :\t Saisir la date\n");
      printf("\t Taper 2 pour :\t Vérifier si c’est une annee bissextile\n");
      printf("\t Taper 3 pour :\t Calculer le nombre de jours dans 1 mois\n");
      printf("\t Taper 4 pour :\t Trouver le jour correspondant a la date\n");
      printf("\t Taper 5 pour :\t Afficher le jour correspondant a la date\n \t !!! Faire 4 avant 5 !!!\n");
      printf("\t Taper 6 pour :\t Quitter le programme\n\n");

      printf(">>> Votre choix = ");
      scanf("%d",&choix);
      printf("\n");
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

    printf("\t Saisir le jour (1-31): ");
    scanf("%d", &le_jour[0]);

    printf("\t Saisir le mois (1-12): ");
    scanf("%d", &le_jour[1]);

    printf("\t Saisir l'annee (0++): ");
    scanf("%d", &le_jour[2]);


    printf("\n");

    /**************Fin DU CODE ETUDIANT******************/
}




int bissextile(int annee)
{
  /* Fonction qui renvoie un entier 0 ou 1   */
  /* pour indiquer si l'annee est bissextile ou non */
  /* en fonction de l'annee en parametre */
    /*************DEBUT DU CODE ETUDIANT*****************/

    // Une année An est bissextile
    // (Si An est divisible par 4) Et (Si An n’est pas divisible par 100
    // Sinon An doit être divisible par 400)

    int result = 0 ; // annee non bissextile par defaut

    if( annee % 4 == 0 && annee % 100 != 0 ){
      result = 1; // annee bissextile
    }else{
      if(annee % 400 == 0){
        result = 1; // annee bissextile
      }
    }

    return result;

    /**************Fin DU CODE ETUDIANT******************/
}

int longueur_mois(int mois, int annee)
{
  /* Fonction qui renvoie la longueur du mois   */
  /* en fonction de l'annee et du mois */
  /*  en parametres de la fonction */
    /*************DEBUT DU CODE ETUDIANT*****************/

    int result = 0;
    // declaration d'un tableau statique:
    // type nom[taille] = {valeur,...};
    int tab_longueur_mois[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
    // declaration d'un tableau dynamique:
    //int* tabdy;
    //tabdy = (int*) malloc(12*sizeof(int)); // sizeof est en octet

    if( mois == 2 ){
      if( bissextile( annee ) ){ // inutile de faire une verification "== 1"
        result = 29; // 29 jours dans les annees bissextile
      }else{
        result = 28; // 28 jours dans les annees bissextile
      }
    }else{
      result = tab_longueur_mois[ mois - 1 ];
    }

    return result;

    /**************Fin DU CODE ETUDIANT******************/
}

enum jour trouver_jour(int le_jour[])
{
  /* Fonction qui renvoie le jour en fonction   */
  /* de la date contenue dans le tableau "le_jour" */
  /*  en paramètre de la fonction */
    /*************DEBUT DU CODE ETUDIANT*****************/

    //réveillon (An) = réveillon (0) + An + nombre_annee_bissextile (An). FAUX
    //réveillon (An) = réveillon (0) + An + nombre_annee_bissextile (An+1). VRAI
    //calendrier (jour, mois, An) = réveillon(An-1) + nombre_de_jours(jour, mois, An)

    int i;
    int reveillon = 0;
    int nombre_annee_bissextile = 0;
    int nombre_jours = 0;
    int calendrier = 0;
    int result;

    nombre_annee_bissextile = (le_jour[2] / 4 - le_jour[2] / 100 + le_jour[2] / 400);
    printf("\t nombre_annee_bissextile = %d\n", nombre_annee_bissextile);

    reveillon = 0 + le_jour[2] - 1 + nombre_annee_bissextile;
    printf("\t reveillon = %d\n", reveillon);

    for( i = 0; i < le_jour[1]; i++ ){
      nombre_jours += longueur_mois( i, le_jour[2] );
      printf("\t \t nombre_jours(%d) = %d\n", i, nombre_jours);
    }
    nombre_jours += le_jour[0];
    printf("\t nombre_jours = %d\n", nombre_jours);
    calendrier = reveillon + nombre_jours;
    printf("\t calendrier = %d\n\n", calendrier);

    result = calendrier % 7;
    printf("\t %d = ((0 + %d + %d) + %d)*7 + %d\n\n", calendrier, le_jour[2]-1, nombre_annee_bissextile, nombre_jours, result);

    return result;

    /**************Fin DU CODE ETUDIANT******************/
}

char * convertir_jour(enum jour un_jour)
{
  /* Fonction qui renvoie le nom du jour en fonction   */
  /* de la valeur contenue dans le parametre "un_jour" */
  /* 0 pour dimanche, 1 pour lundi, ..., 6 pour samedi */

    /*************DEBUT DU CODE ETUDIANT*****************/

    // demandez pas pourquoi ca marhce je sais pas...
    switch (un_jour) {
      case dimanche : return "dimanche";
      case lundi    : return "lundi";
      case mardi    : return "mardi";
      case mercredi : return "mercredi";
      case jeudi    : return "jeudi";
      case vendredi : return "vendredi";
      case samedi   : return "samedi";
    }

    // AUTRE OPTION
    // char* tabjour[] = {"dimanche","lundi","mardi","mercredi","jeudi","vendredi","samedi"};
    // return tabjour[un_jour];

    return "error";

    /**************Fin DU CODE ETUDIANT******************/
}
