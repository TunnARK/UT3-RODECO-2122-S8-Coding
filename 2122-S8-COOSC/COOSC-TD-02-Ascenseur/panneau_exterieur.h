// panneau_exterieur.h: interface for the panneau_exterieur class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PANNEAU_EXTERIEUR_H__81F2B533_5113_448D_98EE_3B5F6E2007D2__INCLUDED_)
#define AFX_PANNEAU_EXTERIEUR_H__81F2B533_5113_448D_98EE_3B5F6E2007D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "systeme.h"
#include "cabine.h"


class panneau_exterieur : public systeme
{

public:
	enum nom_place {e_libre};

	panneau_exterieur(cabine &);
	virtual ~panneau_exterieur();

	int evolue(void);

	cabine &cab_; // La cabine avec laquelle on se synchronise

};

#endif // !defined(AFX_PANNEAU_EXTERIEUR_H__81F2B533_5113_448D_98EE_3B5F6E2007D2__INCLUDED_)
