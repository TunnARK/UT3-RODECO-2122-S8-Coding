//
//  bibliothequeA.h
//  
//  

/////////////////// Examen TIMN - session 1 - 6 javnier 2022


#ifndef _bibliothequeA_h
#define _bibliothequeA_h

void Afficher_matrice(int nb_lignes,int nb_colonnes, float ** matrice);

void Saisir_distribution_init(int taille, float ** matrice_pi);

void Saisir_matrice_transition(int taille, float ** matrice_P);

void Calculer_PIn(int taille, float ** Pi_mat, float ** P_mat, float ** Pi_n_mat);

void Produit_Pn(int taille, float **P1_mat,  float **P2_mat, float **Pn_mat);


#endif
