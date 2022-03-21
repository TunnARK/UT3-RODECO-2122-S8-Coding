/* ------------------------------------------- */
/*  OCSP TD 02 Moniteur Rond Point - biblio.c  */
/* ------------------------------------------- */

#include <pthread.h>
#include "RondPoint_Moniteur.h"

pthread_mutex_t mutex_moniteur ;

// declaration condition
pthread_cond_t Cond_RP [ nb_voie ]; // file d'attente de taille nb_voie

// declaration variables partagees
int nb_voit_attente [ nb_voie ];
int nb_voit_RP = 0 ;
int voie_autorise = 0 ;

void Entrer_RP ( int voie ){
  pthread_mutex_lock ( & mutex_moniteur ); // debut zone critique

  // debugging data
  printf ( "\t\t DATA CHECK: \n" );
  printf ( "\t\t - nb_voie: %d \n" , nb_voie );
  printf ( "\t\t - nb_voie: %d \n" , nb_voie );

  nb_voit_attente [ voie ] += 1 ; // incremente le nb de voiture en attente

  if ( nb_voit_RP != 0 && voie_autorise != 0 ){
    pthread_cond_wait ( & Cond_RP [ voie ] , & mutex_moniteur ); // attente de la possibilite d'entrer
    // voiture entre
  }

  if ( nb_voit_RP == 0 ){
    voie_autorise = voie ; // mise a jour de la voie autorisee
  }

  nb_voit_attente [ voie ] -= 1 ; // decremente le nb de voiture en attente
  nb_voit_RP += 1 ; // incremente le nb de voiture dans le rond point

  pthread_mutex_unlock ( & mutex_moniteur); // fin zone critique
}

void Sortir_RP ( int voie ){
  pthread_mutex_lock ( & mutex_moniteur ); // debut zone critique

  nb_voit_RP -= 1 ; // decremente le nb de voiture dans le rond point

  if ( nb_voit_RP == 0 ){
    // declaration indice pour parcourrir les files d'attentes
    int i = 0 ;

    // changement de voie
    i = ( voie + 1 ) % nb_voie ; // modulo pour ne pas sortir du buffer

    // check pour trouver la prochaine voie en attente
    while( i != voie ){
      // si la voie n'a pas de voiture en attente on passe a la suivante
      // sinon on signale Cond_RP et sort de la boucle
      if ( nb_voit_attente [ i ] != 0 ){
        pthread_cond_signal ( & Cond_RP[ i ] );
        break; // sortir du while
      }
      // on passe a la voie suivante
      i = ( i + 1 ) % nb_voie ; // modulo pour ne pas sortir du buffer
    }
  }

  pthread_mutex_unlock( & mutex_moniteur); // fin zone critique
}
