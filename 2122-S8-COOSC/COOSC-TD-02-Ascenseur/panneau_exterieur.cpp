// panneau_exterieur.cpp: implementation of the panneau_exterieur class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "panneau_exterieur.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

panneau_exterieur::panneau_exterieur(cabine &cab) : systeme(3), cab_(cab)
{
	place_[e_libre]++;
}

panneau_exterieur::~panneau_exterieur()
{

}


int panneau_exterieur::evolue(void)
{
	int nb_tr=0;

	if (place_[e_libre] && ext_bouton1())
	{
		place_[e_libre]--; place_[e_libre]++;
		cab_.appel1(); return(nb_tr++);
	}
	if (place_[e_libre] && ext_bouton0())
	{
		place_[e_libre]--; place_[e_libre]++;
		cab_.appel0(); return(nb_tr++);
	}

	return(0);
}
