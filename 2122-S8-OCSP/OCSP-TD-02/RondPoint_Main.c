/* ----------------------------------------- */
/*  OCSP TD 02 Moniteur Rond Point - main.c  */
/* ----------------------------------------- */

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "RondPoint_Moniteur.h"

pthread_t voie_id [ nb_voie ]; // tableau pour l'identification des voies ?

void * Processus_Voiture ( void *arg ){

  int i, num_voie, exec = 0 ;

  // execution du processus (max nb_exec)
  while ( exec < nb_exec ){

    // on récupère le numéro du philosophe courant
    for ( i = 0 ; i < nb_voie ; i++ ){
      if ( voie_id [ i ] == pthread_self() ){
        num_voie = i ;
      }
    }

    // Entrer
    printf ( "\t |--> une voiture entre dans le rond point par la voie %d \n" , num_voie );
    Entre_RP ( num_voie );

    // Sortir
    printf ( "\t -->| une voiture venant de la voie %d sort du rond point \n" , num_voie );
    Sortir_RP ( num_voie );

    exec++ ; // incremente l'indice avant de passer a la prochaine execution
  }

  pthread_exit( 0 ); // fin thread
}

int main ( void ){

  int i , arg ;

  // creation des thread
  for ( i = 0 ; i < nb_voie ; i++ ){
    if ( pthread_create ( & voie_id [ i ] , NULL , Processus_Voiture , & arg ) != 0 ){
      printf ( "!!! erreur de creation de la thread %d" , i );
      exit ( 1 );
    }
  }

  // attende de la terminaison de tous les thread
  for ( i = 0 ; i < nb_voie ; i++ ){
    pthread_join ( voie_id [ i ] , NULL );
    printf ( "JOIN %d OK :\n" , i );
    printf ( "le procesuss %d est TERMINE" , i );
  }

  return 0 ;
}
