#include "robot++.h"

Tab_Etudiant *ADDRESS;


/* Fonctions lisant les differents capteurs */
short C2() {return Lire_Val(ADDRESS->Tab_Capt[0]);}
short C1() {return Lire_Val(ADDRESS->Tab_Capt[1]);}
short I() {return Lire_Val(ADDRESS->Tab_Capt[2]);}
short C3() {return Lire_Val(ADDRESS->Tab_Capt[3]);}
short FinPrise() {return Lire_Val(ADDRESS->Tab_Capt[4]);}
short FinPose() {return Lire_Val(ADDRESS->Tab_Capt[5]);}
short T1() {return Lire_Val(ADDRESS->Tab_Capt[6]);}
short T2() {return Lire_Val(ADDRESS->Tab_Capt[7]);}
short TI() {return Lire_Val(ADDRESS->Tab_Capt[8]);}
short SCD() {return Lire_Val(ADDRESS->Tab_Capt[9]);}
short SCG() {return Lire_Val(ADDRESS->Tab_Capt[10]);}
short PE() {return Lire_Val(ADDRESS->Tab_Capt[11]);}
short OK_SECU() {return Lire_Val(ADDRESS->Tab_Capt[12]);}


/*-- Fonctionns actionnant les differentes Trajectoires --*/
void StopTi(short x) {ADDRESS->Tab_Traj[0] = ((x)==1);}
void StartTi(short x) {ADDRESS->Tab_Traj[1] = ((x)==1);}
void Stop2(short x) {ADDRESS->Tab_Traj[2] = ((x)==1);}
void Start2(short x) {ADDRESS->Tab_Traj[3] = ((x)==1);}
void Stop1(short x) {ADDRESS->Tab_Traj[4] = ((x)==1);}
void Start1(short x) {ADDRESS->Tab_Traj[5] = ((x)==1);}
void Prise(short x) {ADDRESS->Tab_Traj[6] =((x)==1);}
void Pose(short x) {ADDRESS->Tab_Traj[7] = ((x)==1);}
void Droite(short x) {ADDRESS->Tab_Traj[8] = ((x)==1);}
void Gauche(short x) {ADDRESS->Tab_Traj[9] = ((x)==1);}
void SECU(short x) {ADDRESS->Tab_Traj[10] = ((x)==1);}

/*-- Fonctions manipulation PPI --*/
void SetCtrlPPI(short x) {ADDRESS->Tab_PPI[3]= ((x)==1);}
short GetPortA() {return Lire_Val(ADDRESS->Tab_PPI[0]);}
void SetPortA(short x)  {ADDRESS->Tab_PPI[0]= ((x)==1);}
short GetPortB() {return Lire_Val(ADDRESS->Tab_PPI[1]);}
void SetPortB(short x)  {ADDRESS->Tab_PPI[1]= ((x)==1);}
short GetPortC() {return Lire_Val(ADDRESS->Tab_PPI[2]);}
void  SetPortC(short x)  {ADDRESS->Tab_PPI[2]= ((x)==1);}

#define NOM_MEMOIRE 0xaaaa

int init_comm(void)
{
  ADDRESS=(Tab_Etudiant *)rtai_malloc(NOM_MEMOIRE,sizeof(Tab_Etudiant));
  if(!ADDRESS)
    {
      printf("ERROR : Probleme Ouverture de la mémoire partagée \n");
      return 0;
    }
  else
    printf("Mémoire partagée correctement ouverte\n");
  sleep(1);
  return 1;
}

void reset_comm(void)
{ 
  StopTi(1);
  Stop2(1);
  Stop1(1);
  Prise(0);
  Pose(0);
  Droite(0);
  Gauche(0);
  do SECU(1); while(!OK_SECU());
  SECU(0);
  StopTi(0);
  Stop2(0);
  Stop1(0);
  rtai_free(NOM_MEMOIRE,ADDRESS);
}








