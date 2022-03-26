/* --------------------------------- */
/*  TMOSED TP2 ASC Code C - Etape 2  */
/*  Grp 2 AUDIC-RONK     1 parmis N  */
/* --------------------------------- */

// Reserver_Carte ()
//   reserve la carte et fait la RAZ du port de sortie
//
// Liberer_Carte ()
//   libere la carte reservee
//
// LireEntree (EntreeNo)
//   renvoie la valeur lue sur la "EntreeNo"eme entree du port d'entree
//     EntreeNo dans [0..15]
//
// EcrireSortie (SortieNo, Valeur)
//   ecrit la "Valeur" sur la "SortieNo"eme sortie du port de sortie
//     SortieNo dans [0..7]
//     Valeur dans [0..1]

#include <stdio.h>
#include <stdlib.h>
#include <comedilib.h>

#define comedi_DINPUTSUBDEV 2  // entree numerique
#define comedi_DOUTPUTSUBDEV 3 // sortie numerique
comedi_t * it = NULL ;  // necessaire pour stocker les informations concernant la carte E/S
int comedi_err ;        // utile pour stocker (puis tester) la valeur renvoyee par une fonction comedi_xyz

// short int Card_Num=-1 ;
// short int ErrNo ;
unsigned int ValeurSortie=0 ;

void Reserver_Carte ()
{ // reserver la carte :
	it = comedi_open ("/dev/comedi0") ;
	if (it==NULL)
	{	comedi_perror ("\nReserver_Carte : erreur comedi_open") ;
		exit (-1) ;
	}
	// RAZ du port de sortie :
	ValeurSortie = 0 ;
	comedi_err = comedi_dio_bitfield2 (it, comedi_DOUTPUTSUBDEV, 255, &ValeurSortie, 0) ;
	if (comedi_err == -1)
	{	comedi_perror ("\nReserver_Carte : erreur comedi_dio_bitfield2") ;
		exit (-1) ;
  }
}

void Liberer_Carte ()
{
	comedi_err = comedi_close (it);
	if (comedi_err == -1)
	{	comedi_perror ("\nLiberer_Carte : erreur comedi_close") ;
		exit (-1) ;
  }
}

int LireEntree (int EntreeNo)
{ unsigned int ValeurLue, BitNo ;
	int BitLu ;
	comedi_err = comedi_dio_bitfield2 (it, comedi_DINPUTSUBDEV, 65535, &ValeurLue, 0) ;
	if (comedi_err == -1)
	{	printf("\nLireEntree : erreur comedi_dio_bitfield2") ;
		exit (-1) ;
  }
	BitNo = 1 << EntreeNo ;
	BitLu = ((ValeurLue & BitNo) == BitNo) ;
	return (BitLu) ;
}

void EcrireSortie (int SortieNo, int Valeur)
{	unsigned int BitNo ;
	BitNo = 1 << SortieNo ;
	if (Valeur)
	{	ValeurSortie = ValeurSortie | BitNo ;
	}
	else
	{	BitNo = ~BitNo ;
		ValeurSortie = ValeurSortie & BitNo ;
	}
	comedi_err = comedi_dio_bitfield2 (it, comedi_DOUTPUTSUBDEV, 255, &ValeurSortie, 0) ;
	if (comedi_err == -1)
	{	printf("\nEcrireSortie : erreur comedi_dio_bitfield2") ;
		exit (-1) ;
  }
}
