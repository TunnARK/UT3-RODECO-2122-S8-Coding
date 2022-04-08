// Systeme.h : Systeme dont le comportement est base sur un RDP
///////////////////////////////////////////////////////////////

#ifndef __systeme_h_
#define __systeme_h_

#include <iostream>

using namespace std;

// Construction / Destruction 
class systeme
{
  enum nom_place{}; // Les noms associes aux places 

  public :
   systeme(int nb_places=0);
   virtual ~systeme(void);
   virtual int evolue(void)=0; // Evolution du RdP

   // Authorise l'acces aux membres prives a la methode operator<<
   friend ostream &operator<<(ostream& os, systeme &s); 

  protected : 
    int * place_; // Les places du RdP
    int nb_place_;  // Le nombre de places du RdP
};

ostream &operator<<(ostream& os, systeme &s);

#endif

