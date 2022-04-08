// Systeme.h : Systeme dont le comportement est base sur un RDP
///////////////////////////////////////////////////////////////

#ifndef __systeme_h_
#define __systeme_h_

#include <iostream>
#include <string>


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
   
   string affichage; 

  protected : 
    int * place_; // Les places du RdP
    int nb_place_;  // Le nombre de places du RdP


};


ostream &operator<<(ostream& os, systeme &s);

#endif

