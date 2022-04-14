// systeme.cpp : Implementation du Systeme
////////////////////////////////////////////////

#include "systeme.h"

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
  os << "Marquage: "; 
  for (int p=0; p<s.nb_place_; p++)
    os << s.place_[p] << "," ;
  os << endl;
  return(os);
}


  

