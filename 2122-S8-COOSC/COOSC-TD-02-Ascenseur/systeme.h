// Systeme.h : Systeme dont le comportement est base sur un RDP
///////////////////////////////////////////////////////////////

#include "stdafx.h" // Windows uniquement

#ifndef __systeme_h_
#define __systeme_h_

#include <iostream>
#include "environnement.h"
using namespace std;

// Construction / Destruction 
class systeme
{

  enum nom_place{}; // Les noms associes aux places 

  public :
   systeme(int nb_places);
   ~systeme(void);
   virtual int evolue(void)=0; // Evolution du RdP

   // Authorise l'acces aux membres prives a la methode operator<<
   //	friend ostream &operator<<(ostream&, const systeme &); // A commenter pour windows


//  private: // A commenter pour windows

    int *place_; // Les places du RdP
    int nb_place_;  // Le nombre de places du RdP
    // fonction de marquage
    void m_deplacer(nom_place source, nom_place destination);

	
};

ostream &operator<<(ostream& os, const systeme &s);


#endif

