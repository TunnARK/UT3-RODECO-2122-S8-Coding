// Class Moniteur_RP

package RP ;

import java.util.concurrent.locks.* ;

public class Moniteur_RP {
  int voie_autorise , nb_voit_RP ;
  int nb_voit_attente [] = new int [ 5 ];

  private final Lock verrou = new ReentrantLock ();
  // Cond_RP etant un tableau il le declarer ligne par ligne cf slide java p21
  private final Condition Cond_RP [] = verrou.newCondition ();

  public Moniteur_RP ( int argSize ) {
    N = argSize ; /* creation d'un tampon de taille argsize*/
    // on peut aussi declarer le tab Cond_RP ici
  }
}

// START METHODE ENTRER
public void Entrer_RP ( int voie ) throws InterruptedException {
  verrou.lock ();

  nb_voit_attente [ voie ] += 1 ;

  if ( (nb_voit_RP > 0 ) && ( voie_autorise != voie ) ) { // cf slide p8 pour les operateurs java

    try {
      Cond_RP [ voie ].await ();
    }
    catch ( InterruptedException e ) {
      e.printStackTrace ();
    }
  }

  if ( nb_voit_RP == 0 ) {
    voie_autorise = voie ;
    nb_voit_RP += 1 ;
    nb_voit_attente [ voie ] -= 1 ;
  }

  verrou.unlock ();
}
// END METHODE ENTRER



// START METHODE SORTIR
public void Sortir_RP ( int voie ) {
  verrou.lock ();

  nb_voit_RP -= 1 ;

  if ( nb_voit_RP == 0 ){
    i = ( voie + 1 ) % nb_voie ;

    do {
      if ( nb_voit_attente [ i ] != 0 ) {
        signal ( Cond_RP [ i ] );
        break;
      }
    i = ( voie + 1 ) % nb_voie ;
    } while ( i != voie )
  }

  verrou.unlock ();
}
// END METHODE SORTIR
