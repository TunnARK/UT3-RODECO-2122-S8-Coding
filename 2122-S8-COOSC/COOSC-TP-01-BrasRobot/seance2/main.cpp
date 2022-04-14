// ////////////////////////////////////////////
// Pour compiler : make
// Pour lancer : run monprog
// Pour arreter : Connecter inter au port A bit 0. 0=ARRET 1=RUN
// //////////////////////////////////////////// 


#include <iostream>
#include <unistd.h> //pour sleep 

#include "robot++.h"
#include "tapis.h"
#include "tapis2.h"
#include "tindex.h"
#include "Bras.h"

using namespace std;

short fini(void) {return (GetPortA() & 1);}

int main (void)

{
  /* fin de vos declarations */

  if (!init_comm()) 
    exit (0);
  sleep(1); // pause de 1 seconde 

  /* Declarations */
	tapis t1;
	tapis2 t2;
	Bras rob;
	tindex tbin;
	int s1;
	int s2;
	int ct;
	int cti=0;
  /* debut de vos initialisations */
	t1.init();
	t2.init();
  	rob.init();
	tbin.init();
  /* fin de vos initialisations */
   cout << "Debut de l application" << endl;

  while ( !fini()) /* sortie quand PA0 = 1 */
    {
      /* 1. lecture des entrees */
	s1=t1.GetSignal();
 	s2=t2.GetSignal();
	cout << "valeur de s1" + s1 << endl ;
      /* 2. Evolution du R�eau de Petri */
	t1.evolue();
	t2.evolue();
	
	cti = tbin.evolue(cti);
	ct=rob.evolue(s1,s2);

      /* 3. Calcul des sorties et �riture des sorties sur les ports */
      cout << "dans la boucle" << endl;
    }
  reset_comm();
  return (1);

}
