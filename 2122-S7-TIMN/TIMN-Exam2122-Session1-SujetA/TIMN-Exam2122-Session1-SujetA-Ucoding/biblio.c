//
//  bibliothequeA.c
//
//
//
//  Numero compte examen :
//  Nom Etudiant :
//  Prenom Etudiant :
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "biblio.h"


//////////////////////////
// NE PAS MODIFIER CET EN-TETE
void Afficher_matrice(int nb_lignes,int nb_colonnes, float ** matrice)
{
    /*************DEBUT DU CODE ETUDIANT*****************/

		int i, j;

		for( i = 0; i < nb_lignes ; i++ ){
			for( j = 0; j < nb_colonnes ; j++){
				printf( "\t%f", matrice[i][j] );
			}
			printf( "\n" );
		}

    /**************Fin DU CODE ETUDIANT******************/
}

//////////////////////////
// NE PAS MODIFIER CET EN-TETE
void Saisir_distribution_init(int taille, float ** matrice_pi)
{
    /*************DEBUT DU CODE ETUDIANT*****************/

		int j;

		for( j = 0; j < taille ; j++ ){
				printf( "Saisir l'element 1x%d :\t", j + 1 );
				// Attention: besoin de mettre & pour acceder a l'adresse et la modifier
				scanf( "%f", &matrice_pi[0][j] );
		}
		printf( "\n" );

    /**************Fin DU CODE ETUDIANT******************/
}

//////////////////////////
// NE PAS MODIFIER CET EN-TETE
void Saisir_matrice_transition(int taille, float ** matrice_P)
{
    /*************DEBUT DU CODE ETUDIANT*****************/

		int i, j;

		for( i = 0; i < taille ; i++ ){
			for( j = 0; j < taille ; j++){
				printf( "Saisir l'element %dx%d :\t", i + 1, j + 1 );
				scanf( "\t%f", &matrice_P[i][j] );
			}
			printf( "\n" );
		}

    /**************Fin DU CODE ETUDIANT******************/
}

//////////////////////////
// NE PAS MODIFIER CET EN-TETE
void Calculer_PIn(int taille, float ** Pi_mat, float ** P_mat, float ** Pi_n_mat)
{
    /*************DEBUT DU CODE ETUDIANT*****************/

		int i, j;
		float somme;
		float produit;

		for(  )

    /**************Fin DU CODE ETUDIANT******************/
}

//////////////////////////
// NE PAS MODIFIER CET EN-TETE
void Produit_Pn(int taille, float **P1_mat,  float **P2_mat, float **Pn_mat)
{
    /*************DEBUT DU CODE ETUDIANT*****************/



    /**************Fin DU CODE ETUDIANT******************/
}
