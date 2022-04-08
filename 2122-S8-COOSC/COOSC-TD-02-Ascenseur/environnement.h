// Fonctions associees aux differents capteurs du systeme
/////////////////////////////////////////////////////////

#ifndef __environnement_h_
#define __environnement_h_

#include <iostream>
using namespace std;

// Capteurs associes aux boutons
bool ext_bouton1(void) ; // Bouton etage 1 exterieur
bool ext_bouton0(void) ; // Bouton etage 0 exterieur
bool cab_bouton1(void) ; // Bouton etage 1 cabine
bool cab_bouton0(void) ; // Bouton etage 0 cabine

// Capteurs de presence a l'etage
bool cab_etage0(void) ;
bool cab_etage1(void) ;

void lecture_entrees(void);

// Gestion des Tickets

#endif
