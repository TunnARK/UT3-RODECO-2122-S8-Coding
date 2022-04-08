// cabine.cpp: implementation of the cabine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "cabine.h"
#include "panneau_exterieur.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cabine::cabine() : systeme(6)
{
	place_[e_etage0]++;
}

cabine::~cabine()
{

}

int cabine::evolue(void)
{
	int nb_tr=0;

	if (place_[e_etage0] && cab_bouton1())
	{
		place_[e_etage0]--; place_[e_monter]++;
        // monter();
		return(nb_tr++);
	}

	if (place_[e_monter] && cab_etage1())
	{
		place_[e_monter]--; place_[e_etage1]++;
		return(nb_tr++);
	}

	if (place_[e_etage1] && cab_bouton0())
	{
		place_[e_etage1]--; place_[e_descendre]++;
        // descendre();
		return(nb_tr++);
	}

	if (place_[e_descendre] && cab_etage0())
	{
		place_[e_descendre]--; place_[e_etage0]++;
		return(nb_tr++);
	}

	// Ajout pour fonctionnement avec le panneau exterieur
	if (place_[e_etage0] && place_[e_appel1])
	{
		place_[e_etage0]--; place_[e_appel1]--;
		place_[e_monter]++;
        // monter();
		return(nb_tr++);
	}

	if (place_[e_etage1] && place_[e_appel0])
	{
		place_[e_etage1]--; place_[e_appel0]--;
		place_[e_descendre]++;
        // descendre();
		return(nb_tr++);
	}

	return(nb_tr);
}
