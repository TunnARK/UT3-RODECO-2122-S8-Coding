/* ------------------------------------------------------- */
/*  OCSP TP1 Philosophe Part 2 Moniteur - Philosophe.java  */
/* ------------------------------------------------------- */

package PhiloMoni;

import java.util.Random;

public class Philosophe extends Thread {
	int Philo = 0 ;
	Philo_Moniteur Table ;

	public Philosophe ( String Name , Philo_Moniteur Tab, int Philo_ID ) {
		this.Philo = Philo_ID ;
		Table = Tab ;
	}

	public void run () {
		long start = System.currentTimeMillis ();

		// boucle tant que la durée de vie du Thread est < à 5 secondes
		while( System.currentTimeMillis () < ( start + ( 1000 * 5 ) ) ) {
			try {
				Table.Philo_init( Philo );
				System.out.println ( "Philo " + this.Philo + " pense" );

				// pause pense
				Thread.sleep((long)(Math.random() * 1000));

				System.out.println ( "Philo " + this.Philo + " a faim" );

				Table.prendre_bag ( Philo );

				System.out.println ( "Philo " + this.Philo + " mange" );

				// pause a faim
				Thread.sleep((long)(Math.random() * 1000));

				Table.rendre_bag ( Philo );

				System.out.println ( "Philo " + this.Philo + " a fini de manger" );

				// pause pense
				Thread.sleep((long)(Math.random() * 1000));

			}
			catch ( InterruptedException ex ) {}
		}
	}
}
