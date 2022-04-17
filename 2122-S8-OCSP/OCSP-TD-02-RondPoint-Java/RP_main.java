// START CLASS MAIN

package rond_point ;

import rond_point.Moniteur_RP ;
import rond_point.Voiture ;

public class RP_main {
  public static void main ( String [] args ) {
    Moniteur_RP Tampon = new Moniteur_RP ( 5 );

    for ( int i = 0 ; i < 5 ; i++ ) {
      Voiture Voiture = new Voiture ( i , Tampon );
      System.out.println ( "Creation voiture " + i );
      Voiture.start ();
    }

    long start = System.currentTimeMillis ();

    while ( System.currentTimeMillis () < ( start + ( 1000 * 20 ) ) ) {
      System.out.println ( "Ligne affichee par le main" );
      try {
        Thread.sleep ( 800 );
      }
      catch ( InterruptedException ex ) {}
    }
  }
}

// END CLASS MAIN
