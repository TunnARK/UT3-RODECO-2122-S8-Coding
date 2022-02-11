//
//  biblio.h
//
//

/////////////////// Examen TIMN - session 1 - 6 javnier 2022


#ifndef _biblio_h
#define _biblio_h

void Afficher_matrice(int nb_lignes,int nb_colonnes, float ** matrice);

void Saisir_distribution_init(int taille, float ** matrice_pi);

void Saisir_matrice_transition(int taille, float ** matrice_P);

void Calculer_PIn(int taille, float ** Pi_mat, float ** P_mat, float ** Pi_n_mat);

void Produit_Pn(int taille, float **P1_mat,  float **P2_mat, float **Pn_mat);


#endif
