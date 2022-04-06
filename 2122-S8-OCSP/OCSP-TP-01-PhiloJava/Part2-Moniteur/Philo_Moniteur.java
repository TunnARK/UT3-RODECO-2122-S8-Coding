/* ----------------------------------------------------------- */
/*  OCSP TP1 Philosophe Part 2 Moniteur - Philo_Moniteur.java  */
/* ----------------------------------------------------------- */

package PhiloMoni;

import java.util.concurrent.locks.* ;

public class Philo_Moniteur {
	// Declaration variable Tampon
	int N = 0 ;

	// Definition du nombre de philosophes
	int Philo_Nb = 5 ;

	// Definition des etats possibles d un philosophe
	enum Etat { pense , afaim , mange };
	Etat etat[] = new Etat[Philo_Nb];

	// Declaration d une variable lock pour la gestion des zones critiques
	private Lock verrou = new ReentrantLock();

	// Declaration d un tableau de condition pour l acces au baguette
	private Condition Cond_Bag[] = new Condition[5];

	// Constructeur pour la classe Philo_Moniteur
	public Philo_Moniteur ( int argSize ) {
		// Definition d un tampon de taille argsize
		this.N = argSize ;
		// Declaration du tableau Cond_Bag avec un for
		for ( int i = 0 ; i < N ; i++ ) {
			Cond_Bag[i] = verrou.newCondition();
		}
	}

	// Methode pour initialiser tous les philosophes a l etat pense
	public void Philo_init ( int Philo ) {
		for (int i = 0; i < Philo_Nb; i++) {
			etat[i] = Etat.pense ;
		}
	}

	/*
	public boolean autorisation ( int Philo ) {
		int gauche = (Philo - 1) % Philo_Nb ;
		int droite = (Philo + 1) % Philo_Nb ;
		boolean P = (etat[Philo] == Etat.afaim) ;
		boolean G = (etat[gauche] == Etat.mange) ;
		boolean D = (etat[droite] == Etat.mange) ;
		return ( P && G && D );
	}
	*/

	// Methode pour connaitre le philosophe de gauche
	public int gauche ( int Philo ) {
		if (Philo == 0) {
			return 4 ;
		}
		else {
			return ( (Philo - 1) % Philo_Nb );
		}
	}

	// Methode pour connaitre le philosophe de droite
	public int droite ( int Philo ) {
		if (Philo == 0) {
			return 4 ;
		}
		else {
			return ( (Philo + 1) % Philo_Nb );
		}
	}

	// Methode pour autoriser l access aux baguettes
	public boolean autorisation ( int Philo ) {
		// On retourne 1 si pour un philo qui a faim les philos a sa gauche et a sa droite NE mange PAS
		return ( etat[Philo] == Etat.afaim && etat[gauche(Philo)] != Etat.mange && etat[droite(Philo)] != Etat.mange );
	}

	public void prendre_bag ( int Philo ) {
		verrou.lock (); // Debut de zone critique

		// Mettre a jour etat du philo a afaim
		etat[Philo] = Etat.afaim ;

		// Si Philo n est pas autorise a mange il doit attendre
		if ( (!autorisation(Philo)) ) {
			try {
				Cond_Bag [ Philo ].await ();
			}
			catch ( InterruptedException e ) {
				e.printStackTrace ();
			}
		}

		// Sinon il peut manger et on met a jour son etat a mange
		etat[Philo] = Etat.mange ;

		verrou.unlock (); // Fin de zone critique
	}

	public void rendre_bag ( int Philo ) {
		verrou.lock (); // Debut de zone critique

		// Mettre a jour etat du philo a pense
		etat[Philo] = Etat.pense ;

		// Si Philo de gauche et droite on l'autorisation de manger alors on signale
		if ( (autorisation( gauche(Philo) )) ) {
			Cond_Bag[ gauche(Philo) ].signal( );
		}
		if ( (autorisation( droite(Philo) )) ) {
			Cond_Bag[ droite(Philo) ].signal( );
		}

		verrou.unlock (); // Fin de zone critique
	}
}
