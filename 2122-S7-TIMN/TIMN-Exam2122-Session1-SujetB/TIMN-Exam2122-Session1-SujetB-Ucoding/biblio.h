//
/////////////////// bibliothequeB.h
//
//
//

#ifndef BIBLIO_H
#define BIBLIO_H

enum jour {dimanche=0,lundi,mardi,mercredi,jeudi,vendredi,samedi};

int Pafficher_menu();
void saisir_jour(int le_jour[]);
int bissextile(int annee);
int longueur_mois(int mois, int annee);
enum jour trouver_jour(int le_jour[]);
char * convertir_jour(enum jour un_jour);

#endif
