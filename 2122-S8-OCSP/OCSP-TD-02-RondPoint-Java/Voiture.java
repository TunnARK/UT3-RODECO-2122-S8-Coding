// START CLASS VOITURE

package rond_point ;

public class Voiture extends Thread {

  private int voie = 0 ;
  Moniteur_RP RondPoint ;

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
        System.out.println ( "Voit voie " + this.voie + " entre" );
        // pause tourner
        Thread.sleep ( 500 );
      }
      catch ( InterruptedException ex ) {}
    }
    RondPoint.Sortir_RP ( voie );
    System.out.println ( "Voit voie " + this.voie + " sort" );
  }
}

// END CLASS VOITURE
