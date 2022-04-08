// cabine.h: interface for the cabine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CABINE_H__E56D5C77_D922_46D8_A367_86C00DDAAEB3__INCLUDED_)
#define AFX_CABINE_H__E56D5C77_D922_46D8_A367_86C00DDAAEB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "systeme.h"

class panneau_exterieur;

class cabine : public systeme  
{
public:
	enum nom_place {e_etage0, e_monter, e_etage1, e_descendre, e_appel1, e_appel0};
	cabine();
	virtual ~cabine();

	// Les methodes associees aux points de communication
	void appel1(void) {place_[e_appel1]++;};
	void appel0(void) {place_[e_appel0]++;};
	int  evolue(void);

private : 
	
public :


};

#endif // !defined(AFX_CABINE_H__E56D5C77_D922_46D8_A367_86C00DDAAEB3__INCLUDED_)
