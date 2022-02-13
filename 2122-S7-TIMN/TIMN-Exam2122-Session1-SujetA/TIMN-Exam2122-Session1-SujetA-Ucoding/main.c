//
//  main.c
//
// POUR COMPILER les fichiers main.c, biblio.c et biblio.h  FAIRE
// gcc -Wall -c biblio.c -lm && gcc -Wall -o main main.c biblio.o -lm && ./main
//
// 	NE PAS MODIFIER CE FICHIER
//
// 	Compiler avec les 2 commandes suivantes
//  gcc -Wall -c bibliothequeA.c -lm
//	gcc -Wall -o prog modele-examen-TIMN-21-22-session1A.c bibliothequeA.o -lm
//
//	Exécuter avec ./prog en salle i1
//	Exécuter avec ./prog.exe en salle g19-g22
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "biblio.h"

int main(void)
{

    float ** matrice_pi0;
    float ** matrice_pin;
    float ** matrice_P;
    float ** matrice_Pn;
    float ** matrice_Pinter;
    float ** matriceId;
    float ** matriceTestPn;
    float ** matriceTestPin;
    int i,j,k;
    int Taille;
    int etape_n=0; // variable de l'état n du système


    printf( "\n" );
    printf("Saisir la taille T : ");
    scanf("%d", &Taille);
    printf( "\n" );

    //matrices 1 X Taille
    matrice_pi0=(float **) malloc(1*sizeof(float*));
    matrice_pin=(float **) malloc(1*sizeof(float*));

    matriceTestPin=(float **) malloc(1*sizeof(float*));

    matrice_pi0[0]=(float *) malloc(Taille*sizeof(float));
    matrice_pin[0]=(float *) malloc(Taille*sizeof(float));

    matriceTestPin[0]=(float *) malloc(Taille*sizeof(float));

    //matrices Taille X Taille
    matrice_P=(float **) malloc(Taille*sizeof(float*));
    matrice_Pn=(float **) malloc(Taille*sizeof(float*));
    matrice_Pinter=(float **) malloc(Taille*sizeof(float*));

    matriceTestPn=(float **) malloc(Taille*sizeof(float*));


    // Initialisation des matrices

    matriceId=(float **)malloc(Taille*sizeof(float*)); //Déclaration du handler

  	for(i=0; i<Taille; i++)
  	{
  		matriceId[i]=(float *)malloc(Taille*sizeof(float));	//Création du pointeur sur les "cases"
  	}


  	for(i=0; i<Taille; i++) //Remplissage de la matrice
  	{
  		for(j=0; j<Taille; j++)
  		{
  				if(i==j)
  					{matriceId[i][j]=1;}
  				else
  					{matriceId[i][j]=0;}

  		}

  	}

  	printf("---Matrice Identitite---\n");
  	Afficher_matrice(Taille,Taille,matriceId);
  	printf("\n");


    for( i = 0; i < Taille; i++){
      matrice_pi0[0][i] = 0;
    }

    for(i=0;i<Taille;i++){

  		matrice_P[i]=(float *) malloc(Taille*sizeof(float));
      matrice_Pn[i]=(float *) malloc(Taille*sizeof(float));
      matrice_Pinter[i]=(float *) malloc(Taille*sizeof(float));

      matriceTestPn[i]=(float *) malloc(Taille*sizeof(float));

      for(j=0;j<Taille;j++){
              matrice_P[i][j]=0;
              matrice_Pn[i][j]=0;
              matrice_Pinter[i][j]=0;
  		}
	 }


    printf("Saisie de la Distribution initiale\n\n");
    Saisir_distribution_init(Taille, matrice_pi0);
    printf("Distribution initiale\n\n");
    Afficher_matrice(1,Taille, matrice_pi0);
    printf( "\n" );


    printf("Saisie de la matrice transiton P initiale\n\n");
    Saisir_matrice_transition(Taille, matrice_P);
    printf("matrice transiton P initiale\n\n");
    Afficher_matrice(Taille,Taille, matrice_P);
    printf( "\n" );


  	Produit_Pn(Taille, matrice_P, matriceId, matriceTestPn);
  	printf("Test de Produit_Pn:  PxId =\n\n");
  	Afficher_matrice(Taille, Taille, matriceTestPn);
    printf( "\n" );

    Calculer_PIn(Taille, matrice_pi0, matriceId, matriceTestPin);
  	printf("Test de Calculer_PIn:  PI0xId =\n\n");
  	Afficher_matrice(1, Taille, matriceTestPin);
    printf( "\n" );


    printf("Saisir l'état n du système à calculer : ");
    scanf("%d", &etape_n);
    printf( "\n" );

    /*
    printf("Affichage matrice Pinter\n\n");
    for(j=0;j<Taille;j++)
    {
        for(k=0;k<Taille;k++)
        {
            matrice_Pinter[j][k]=matrice_Pn[j][k];
            printf("\tmatrice_Pinter[%i][%i] = %f \n", j, k, matrice_Pinter[j][k]);
        }
    }
    printf( "\n" );

	   for (i=0;i<(etape_n-2);i++){

        Produit_Pn(Taille, matrice_P, matrice_Pinter, matrice_Pn);
        printf("Affichage matrice PxPinter=P^%d\n\n", 2 + (i + 1) );
        Afficher_matrice(Taille,Taille, matrice_Pn);
        printf( "\n" );
        //comme on écrase matice_Pn, il faut sauvegarder dans matrice_Pinter
        for(j=0;j<Taille;j++)
        {
            for(k=0;k<Taille;k++)
            {
                matrice_Pinter[j][k]=matrice_Pn[j][k];
			          printf("\tmatrice_Pinter[%i][%i] = %f \n", j, k, matrice_Pn[j][k]);
            }
        }

    }
    */

    // --- Code A start

    /*Initialisation des matrices avant calcul :
        * Matrice Pinter initialisée à Matrice P pour que le premier calcul soit P*P
        * Matrice Pn initialisée à Matrice P pour le cas etape_n = 1
        * Attention ce code ne marche que pour etape_n < 0
    */
    for(i=0;i<Taille;i++)
	  {
		    for(j=0;j<Taille;j++)
		    {
            matrice_Pn[i][j]=matrice_P[i][j];
            matrice_Pinter[i][j]=matrice_P[i][j];
    		}
	  }

    printf("Affichage matrice Pn\n\n");
    Afficher_matrice(Taille,Taille, matrice_Pn);
    printf( "\n" );

    printf("Affichage matrice Pinter\n\n");
    Afficher_matrice(Taille,Taille, matrice_Pinter);
    printf( "\n" );

  	for (i=1;i<etape_n;i++)
      {
          Produit_Pn(Taille, matrice_P, matrice_Pinter, matrice_Pn);
          printf("Affichage matrice PxPinter=P^%d\n\n", i );
          Afficher_matrice(Taille,Taille, matrice_Pn);
          printf( "\n" );
          //comme on écrase matice_Pn, il faut sauvegarder dans matrice_Pinter
          for(j=0;j<Taille;j++)
          {
              for(k=0;k<Taille;k++)
              {
                  matrice_Pinter[j][k]=matrice_Pn[j][k];
  			          printf("matrice_Pinter[%i][%i] = %f \n", j, k, matrice_Pn[j][k]);
              }
          }

      }

      // --- Code A end

      printf( "\n" );

      printf("Affichage matrice Pn\n\n");
      Afficher_matrice(Taille,Taille, matrice_Pn);
      printf( "\n" );

      printf("Affichage matrice Pinter\n\n");
      Afficher_matrice(Taille,Taille, matrice_Pinter);
      printf( "\n" );

      Calculer_PIn(Taille, matrice_pi0, matrice_Pn, matrice_pin);
      printf("matrice disribution pi_n \n\n");
      Afficher_matrice(1,Taille, matrice_pin);
      printf( "\n" );

      printf("Au revoir ! \n");
      printf( "\n" );


    return 0;
}
