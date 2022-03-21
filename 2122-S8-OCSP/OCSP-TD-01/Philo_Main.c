/* ------------------------------------------ */
/*  OCSP TD 01 Semaphore Philosophe - main.c  */
/* ------------------------------------------ */

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "Philo_Moniteur.h"

pthread_t philo_id[nb_philo];

void * philosophe (void *arg)
{
  int i, num_philo, compte=0;
  while (compte <nb_exec)
  /* on récupère le numéro du philosophe courant */
  {
    for (i=0; i<nb_philo;i++)
      if (philo_id[i]==pthread_self()) num_philo=i;
  printf("le philosophe %d PENSE \n", num_philo);
  sleep(3);
  printf(" le philosophe %d A FAIM \n",num_philo);
  Prendre_bag (num_philo);
  printf(" le philosophe %d MANGE \n",num_philo);
  sleep(3);
  printf(" le philosophe %d A FINI de MANGER \n",num_philo);
  Rendre_bag (num_philo);
  compte++;
  }
  pthread_exit(0);
}

int main ()
{
  int i , arg;

  /* creation des thread philosophe */
  for (i=0; i< nb_philo; i++)
  {
    if (pthread_create(&philo_id[i],NULL,philosophe,&arg) !=0)
    {
      printf("erreur de creatin de thread");
      exit (1);
    }
  }

  /* attende de la terminaison de tous les thread */
  for (i=0; i<nb_philo; i++)
  {
    pthread_join (philo_id[i],NULL);
    printf("JOIN %d OK :\n",i);
    //printf("le philosophe %d est TERMINE ",i);
  }
  return 0;
}
