
package RP ;

//import RP.*;
//import RP.Moniteur_RP ;
//import RP.Voiture ;

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
