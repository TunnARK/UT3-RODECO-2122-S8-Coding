/* ---------------------------------------------- */
/*  OCSP TP1 Philosophe Part 1 - Philo_Main.java  */
/* ---------------------------------------------- */

// START CLASS MAIN
package Philo ;

//import Philo. ;

public class Philo_Main {
  public static void main ( String [] args ) {
    
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
