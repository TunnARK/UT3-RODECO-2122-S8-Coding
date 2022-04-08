// Fonctions associees aux differents capteurs du systeme
////////////////////////////////////////////////////////
#include "stdafx.h"
#include "environnement.h"

//#include "conio.h"
//#include "windows.h"

// Capteurs associes aux boutons
bool _ext_bouton1=false; // Bouton etage 1 exterieur
bool _ext_bouton0=false; // Bouton etage 0 exterieur
bool _cab_bouton1=false; // Bouton etage 1 cabine
bool _cab_bouton0=false; // Bouton etage 0 cabine

// Capteurs de presence a l'etage
bool _cab_etage0=true;
bool _cab_etage1=true;

bool ext_bouton1(void) {return(_ext_bouton1);}; // Bouton etage 1 exterieur
bool ext_bouton0(void) {return(_ext_bouton0);}; // Bouton etage 0 exterieur
bool cab_bouton1(void) {return(_cab_bouton1);}; // Bouton etage 1 cabine
bool cab_bouton0(void) {return(_cab_bouton0);}; // Bouton etage 0 cabine

// Capteurs de presence a l'etage
bool cab_etage0(void) {return(_cab_etage0);};
bool cab_etage1(void) {return(_cab_etage1);};

// Lectures des entrees
void lecture_entrees(void)
{
	char readkey;

	_ext_bouton1=false;
	_ext_bouton0=false;
	_cab_bouton1=false;
	_cab_bouton0=false;

	//cout << "evaluation entrees \n(a:appel ext 1, q:appel ext 0, p:appel cabine 1, m:appel cabine 0)\n";
	cin >> readkey;
	//readkey=kbhit();
	//Sleep(1);
	cout << readkey <<endl;

	switch (readkey)
	{
	  case 'a' : cout<<"appel 1\n"; _ext_bouton1=true; break;
	  case 'q' : cout<<"appel 0\n"; _ext_bouton0=true; break;
	  case 'p' : cout<<"appel 1\n"; _cab_bouton1=true; break;
	  case 'm' : cout<<"appel 0\n"; _cab_bouton0=true; break;
	}

}
