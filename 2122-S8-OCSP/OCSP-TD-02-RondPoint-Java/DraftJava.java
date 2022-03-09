/* --------------------------------------------- */
/*  OCSP TD 02 Moniteur Rond Point JAVA - Draft  */
/* --------------------------------------------- */



// START CLASS MONITEUR
package Buf ;

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
// END CLASS MONITEUR



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



// START CLASS VOITURE
import Buf.Moniteur_RP ;

public class Voiture extends Thread {

  private int voie = 0 ;
  Moniteur_RP Monbuffer ;

  public Voiture ( String Name , Moniteur_RP RP ) {
    this.voie = voie ;
    RondPoint = RP ;
  }

  public void run () {
    long start = System.currentTimeMillis ();

    // boucle tant que la durée de vie du Thread est < à 5 secondes
    while( System.currentTimeMillis () < ( start + ( 1000 * 5 ) ) ) {
      try {
        RondPoint.Entrer_RP ( voie );
        // pause tourner
        Thread.sleep ( 500 );
      }
      catch ( InterruptedException ex ) {}
    }
    RondPoint.Sortir_RP ( voie );
  }
}
// END CLASS VOITURE



// MAIN A FINIR
import Buf.*;

public class RP_main {
  public static void main ( String [] args ) {
    Moniteur_RP Tampon = new Moniteur_RP ( 3 );

    for ( int i = 1 ; i < 5 ; i++ ) {
      Voiture Voiture = new Voiture ( "Thread-PROD" + i , Tampon );
      System.out.println ( "Creation voiture " + i );
      Voiture.start ();
    }

    long start = System.currentTimeMillis ();

    while ( System.currentTimeMillis () < ( start + ( 1000 * 10 ) ) ) {
      System.out.println ( "Ligne affichée par le main" );
      try {
        Thread.sleep ( 800 );
      }
      catch ( InterruptedException ex ) {}
    }
  }
}
// MAIN A FINIR
