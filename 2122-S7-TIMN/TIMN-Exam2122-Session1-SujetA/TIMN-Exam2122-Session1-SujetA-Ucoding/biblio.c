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
				printf( "\tSaisir l'element 1x%d :\t", j + 1 );
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
				printf( "\tSaisir l'element %dx%d :\t", i + 1, j + 1 );
				scanf( "%f", &matrice_P[i][j] );
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

		int i; int j;
		float somme = 0;
		//printf("test Calculer_PIn\n");
		for( i = 0; i < taille; i++){

			//printf("test i = %d\n", i);

			for( j = 0; j < taille; j++){

				//printf("test j = %d\n", j);

				// Calcul matriecelle en fixant une ligne puis parcourant les colonnes
				// de Pi_mat mais en fixant une colonne de P_mat pour parcourir ses cols
				somme += Pi_mat[0][j] * P_mat[j][i];

				//printf("test somme = %f\n", somme);

				// Stockage de somme dans Pi_n_mat
				Pi_n_mat[0][i] = somme;

				//printf("test Pi_n_mat[0][%d] = %f\n", j, Pi_n_mat[0][j]);

			}
			// Reinitialiser somme avant de changer i mais apres finir la boucle j
			somme = 0;
		}

    /**************Fin DU CODE ETUDIANT******************/
}

//////////////////////////
// NE PAS MODIFIER CET EN-TETE
void Produit_Pn(int taille, float **P1_mat,  float **P2_mat, float **Pn_mat)
{
    /*************DEBUT DU CODE ETUDIANT*****************/
		/*
		int i; int j;
		float somme = 0;
		//printf("test Calculer_PIn\n");
		for( i = 0; i < taille; i++){

			//printf("test i = %d\n", i);

			for( j = 0; j < taille; j++){

				//printf("test j = %d\n", j);

				// Calcul matriecelle en fixant une ligne puis parcourant les colonnes
				// de Pi_mat mais en fixant une colonne de P_mat pour parcourir ses cols
				somme += P1_mat[i][j] * P2_mat[j][i];

				//printf("test somme = %f\n", somme);

				// Stockage de somme dans Pi_n_mat
				Pn_mat[i][j] = somme;

				//printf("test Pi_n_mat[0][%d] = %f\n", j, Pi_n_mat[0][j]);

			}
			// Reinitialiser somme avant de changer i mais apres finir la boucle j
			somme = 0;
		}
		*/
		int j,l,c;
		float somme; //Variable mémorisant la somme

		for(l=0; l<taille; l++) //Parcours des lignes
		{
			for(c=0; c<taille; c++) //Parcours des colonnes
			{



					for(j=0; j<taille; j++) //Indice servant à parcourir la colonne de P1 vs la ligne de P2
					{
						somme+=P1_mat[l][j]*P2_mat[j][c];	//La ligne est fixe pour P1 et la colonne est fixe pour P2
					}


				Pn_mat[l][c]=somme;
				somme=0; //RAZ de la somme avant passage à l'element suivant



			}



		}

    /**************Fin DU CODE ETUDIANT******************/
}
