// ////////////////////////////////////////////
// Pour compiler : make
// Pour lancer : run monprog
// Pour arreter : Connecter inter au port A bit 0. 0=ARRET 1=RUN
// //////////////////////////////////////////// 


#include <iostream>
#include <unistd.h> //pour sleep 

#include "robot++.h"

using namespace std;

short fini(void) {return (GetPortA() & 1);}

int main (void)

{
  /* fin de vos declarations */

  if (!init_comm()) 
    exit (0);
  sleep(1); // pause de 1 seconde 

  /* Declarations */

  /* debut de vos initialisations */

  

  /* fin de vos initialisations */
   cout << "Debut de l application" << endl;
;
  while ( !fini()) /* sortie quand PA0 = 1 */
    {
      /* 1. lecture des entrees */

 

      /* 2. Evolution du R�eau de Petri */



      /* 3. Calcul des sorties et �riture des sorties sur les ports */
      cout << "dans la boucle" << endl;
    }
  reset_comm();
  return (1);

}
