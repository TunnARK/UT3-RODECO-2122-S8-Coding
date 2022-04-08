// systeme.cpp : Implementation du Systeme
////////////////////////////////////////////////

#include "systeme.h"
#include <sstream>

// Construction / Destruction 

systeme::systeme(int nb_places)
{
  nb_place_=nb_places;
  place_ = new int [nb_places];
  for (int i=0;i<nb_places;i++) place_[i]=0;
};

systeme::~systeme(void) 
{
  delete place_;
};

ostream &operator<<(ostream& os, systeme &s)
{
  ostringstream new_aff;

  new_aff << "Marquage: "; 
  for (int p=0; p<s.nb_place_; p++)
    new_aff << s.place_[p] << "," ;
  new_aff << endl;
 
  if ((new_aff.str())!=s.affichage)
  {
	s.affichage = string(new_aff.str());
  	os << new_aff.str();
  }
  return(os);
}


  

