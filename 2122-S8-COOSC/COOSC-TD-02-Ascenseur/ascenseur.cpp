// ascenseur.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "systeme.h"
#include "cabine.h"
#include "panneau_exterieur.h"

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    
    // declaration des objets
	cabine Asc;
	panneau_exterieur P0(Asc);


    cout << "utilisation (pressez la touche puis enter): " << endl;
    cout << "touche a  : appel exterieur 1" << endl;
    cout << "touche q  : appel exterieur 0" << endl;
    cout << "touche p  : appel interieur 1" << endl;
    cout << "touche m  : appel interieur 0" << endl;
    cout << " ----------------------------" << endl;

	while(1)
    {
      // evolution des objets
	  P0.evolue();
      Asc.evolue();

      // affichage de l'etat
      cout <<"Asc : " <<  Asc;
	  cout << "P0 : " << P0;

      // lecture des entrees
      lecture_entrees();


    }


	return 0;
}

