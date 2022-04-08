#ifndef __ROBOT__
#define __ROBOT__
#include <stdio.h> /* printf et scanf */
#include <string.h>
#include <unistd.h> /* open */
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <asm/io.h>
#include <rtai_shm.h>

#include "structure++.h"

extern Tab_Etudiant *ADDRESS;


/*-- Fonctions de lecture des differents Capteurs reels et Virtuels --*/
short C2();
short C1();
short I();
short C3();
short FinPrise();
short FinPose();
short T1();
short T2();
short TI();
short SCD();
short SCG();
short PE();
short OK_SECU();


/*-- Fonctions correspondant aux differentes Trajectoires --*/
void StopTi(short x);
void StartTi(short x);
void Stop2(short x);
void Start2(short x);
void Stop1(short x);
void Start1(short x);
void Prise(short x);
void Pose(short x);
void Droite(short x);
void Gauche(short x);
void SECU(short x);

/*-- Fonctions manipulation PPI --*/
void SetCtrlPPI(short x);
short GetPortA();
void SetPortA(short x);
short GetPortB();
void SetPortB(short x);
short GetPortC();
void  SetPortC(short x);

int init_comm(void);
void reset_comm(void);

#endif
