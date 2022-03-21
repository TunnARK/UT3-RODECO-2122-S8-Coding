package rond_poind;

//import RP.*;
import rond_poind.Moniteur_RP ;
import rond_poind.Voiture ;

public class RP_main {
public static void main ( String [] args ) {
  Moniteur_RP Tampon = new Moniteur_RP (5);

  for ( int i = 1 ; i < 5 ; i++ ) {
    Voiture Voiture = new Voiture (i , Tampon);
    System.out.println ( "Creation voiture " + i );
    Voiture.start ();
  }

  long start = System.currentTimeMillis ();

  while ( System.currentTimeMillis () < ( start + ( 1000 * 20 ) ) ) {
    //System.out.println ( "Ligne affichée par le main" );
    try {
      Thread.sleep ( 800 );
    }
    catch ( InterruptedException ex ) {}
  }
}
}
