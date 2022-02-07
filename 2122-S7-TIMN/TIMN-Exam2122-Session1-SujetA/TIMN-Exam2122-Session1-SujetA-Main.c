//
//  modele-examen-TIMN-21-22-session1A.c
//  
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
#include "bibliothequeA.h"

int main(void)
{

    float ** matrice_pi0;
    float ** matrice_pin;
    float ** matrice_P;
    float ** matrice_Pn;
    float ** matrice_Pinter;
    int i,j,k;
    int Taille;
    int etape_n=0; // variable de l'état n du système
    
    printf("Saisir la taille T : ");
    scanf("%d", &Taille);
    
    //matrices 1 X Taille
    matrice_pi0=(float **) malloc(1*sizeof(float*));
    matrice_pin=(float **) malloc(1*sizeof(float*));

    matrice_pi0[0]=(float *) malloc(Taille*sizeof(float));
    matrice_pin[0]=(float *) malloc(Taille*sizeof(float));

    //matrices Taille X Taille
    matrice_P=(float **) malloc(Taille*sizeof(float*));
    matrice_Pn=(float **) malloc(Taille*sizeof(float*));
    matrice_Pinter=(float **) malloc(Taille*sizeof(float*));


    for(i=0;i<Taille;i++)
	{
		matrice_P[i]=(float *) malloc(Taille*sizeof(float));
        matrice_Pn[i]=(float *) malloc(Taille*sizeof(float));
        matrice_Pinter[i]=(float *) malloc(Taille*sizeof(float));
		for(j=0;j<Taille;j++)
		{
            matrice_P[i][j]=0;
            matrice_Pn[i][j]=0;
            matrice_Pinter[i][j]=0;
		}
	}
    
    Saisir_distribution_init(Taille, matrice_pi0);
    printf("Distribution initiale\n");
    Afficher_matrice(1,Taille, matrice_pi0);

    Saisir_matrice_transition(Taille, matrice_P);
    printf("matrice transiton P initiale\n");
    Afficher_matrice(Taille,Taille, matrice_P);

	/*
	Produit_Pn(Taille, matrice_P, matrice_P, matrice_Pn);
	printf("Affichage matrice Pn\n");
	Afficher_matrice(Taille, Taille, matrice_Pn);
	*/

    printf("Saisir l'état n du système à calculer : ");
    scanf("%d", &etape_n);
    
   
	for (i=0;i<(etape_n-1);i++)
    {
        Produit_Pn(Taille, matrice_P, matrice_Pinter, matrice_Pn);
		printf("Coucou\n");
		Afficher_matrice(Taille,Taille, matrice_Pn);
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
	
    Calculer_PIn(Taille, matrice_pi0, matrice_Pn,matrice_pin);
    printf("matrice disribution pi_n \n");
    Afficher_matrice(1,Taille, matrice_pin);
    
    printf("Au revoir ! \n");
    
    
    return 0;
}

