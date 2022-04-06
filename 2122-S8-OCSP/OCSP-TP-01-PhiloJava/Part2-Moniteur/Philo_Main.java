/* ------------------------------------------------------- */
/*  OCSP TP1 Philosophe Part 2 Moniteur - Philo_Main.java  */
/* ------------------------------------------------------- */

package PhiloMoni;

public class Philo_Main {
	public static void main(String[] args) {
		Philo_Moniteur Buffer = new Philo_Moniteur ( 5 );

	    for ( int i = 0 ; i < 5 ; i++ ) {
	      Philosophe Philosophe = new Philosophe ( "Thread-PROD" + i , Buffer, i );
	      System.out.println ( "Creation Philo " + i );
	      Philosophe.start ();
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
