package rond_poind;


import java.util.concurrent.locks.* ;

public class Moniteur_RP {
  int voie_autorise , nb_voit_RP, N ;
  int nb_voit_attente [] = new int [ 5 ];

  private Lock verrou = new ReentrantLock();
  // Cond_RP etant un tableau il le declarer ligne par ligne cf slide java p21
  private Condition Cond_RP[] = new Condition[5];
  
  public Moniteur_RP( int argSize ) {
    this.N = argSize ; /* creation d'un tampon de taille argsize*/
    // on peut aussi declarer le tab Cond_RP ici
    for ( int i = 0 ; i < N ; i++ ) {
        Cond_RP[i] = verrou.newCondition();
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
  int i = 0;
  nb_voit_RP -= 1;

  if ( nb_voit_RP == 0 ){
    i = ( voie + 1 ) % 5 ;//Nombre de voie

    do {
      if ( nb_voit_attente [ i ] != 0 ) {
    	  Cond_RP[i].signal( );
        break;
      }
    i = ( voie + 1 ) % 5 ;//Nombre de voie
    } while ( i != voie );
  }
  verrou.unlock();
}
}
// END METHODE SORTIR