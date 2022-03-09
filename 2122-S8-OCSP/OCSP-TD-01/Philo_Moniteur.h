/* -------------------------------------------- */
/*  OCSP TD 01 Semaphore Philosophe - biblio.h  */
/* -------------------------------------------- */

#include <stdio.h>
#define nb_philo 5
#define nb_exec 10

/* declaration des fonctions du moniteur */
void Prendre_bag (int philo);
void Rendre_bag (int philo);

/* declaration des types */
enum etat_philo {pense, faim, mange};
enum etat_philo etat [nb_philo];
