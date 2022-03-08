/* ------------------------------------------ */
/* OCSP TD 01 Semaphore Philosophe - biblio.c */
/* ------------------------------------------ */

#include <pthread.h>
#include "Moniteur_philo.h"

pthread_mutex_t mutex_moniteur;
pthread_cond_t acces [nb_philo];

int gauche (int philo)
{
  return ((philo-1) % nb_philo);
}

int droite (int philo)
{
  return ((philo+1) % nb_philo);
}

int autorisation (int philo)
{
  return (( etat[philo]==faim) && (etat[gauche(philo)]!=mange) && (etat[droite(philo)]!=mange));
}

void Prendre_bag (int philo)
{
  pthread_mutex_lock (&mutex_moniteur);
  etat[philo]=faim;
  if (!autorisation(philo))
    pthread_cond_wait (&acces[philo],&mutex_moniteur);
  etat[philo]=mange;
  pthread_mutex_unlock( &mutex_moniteur);
}

void Rendre_bag (int philo)
{
  pthread_mutex_lock (&mutex_moniteur);
  etat[philo]=pense;
  if (autorisation(droite(philo)))
    pthread_cond_signal (&acces[droite(philo)]);
  if (autorisation(gauche(philo)))
    pthread_cond_signal (&acces[gauche(philo)]);
  pthread_mutex_unlock( &mutex_moniteur);
}
