/* --------------------------------- */
/*  TMOSED TP2 ASC Code C - Etape 1  */
/*  Grp 2 AUDIC-RONK     1 parmis N  */
/* --------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <dask.h>
#include "ACS-CodeC-Etape1-ACA-EntreesSorties.c"

int main() {
  // declarer les informations ici
	Reserver_Carte () ;

  int p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13;
	int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13;

	p1=1; s1=1;
	p2=0;	s2=0;
	p3=0;	s3=0;
	p4=0;	s4=0;
	p5=0;	s5=0;
	p6=0;	s6=0;
	p7=0;	s7=0;
	p8=0;	s8=0;
	p9=0;	s9=0;
	p10=0;	s10=0;
	p11=0;	s11=0;
	p12=0;	s12=0;
	p13=0;	s13=0;

  // decrire la commande a mettre en oeuvre ici
  while(1){
  	s1  = (p1  && !(LireEntree(1) || LireEntree(2)) )||(p2  &&  !LireEntree(6));
  	s2  = (p2  && !(!LireEntree(6))                 )||(p3  &&   LireEntree(6));
  	s3  = (p3  && !(LireEntree(6))			            )||(p4  &&   LireEntree(3));
  	s4  = (p4  && !(LireEntree(3)) 			            )||(p5  &&   LireEntree(0)) || (p10 && LireEntree(0));
  	s5  = (p5  && !(LireEntree(0) || LireEntree(2)) )||(p6  &&  !LireEntree(6));
  	s6  = (p6  && !(!LireEntree(6)) 		            )||(p7  &&   LireEntree(6));
  	s7  = (p7  && !(LireEntree(6))			            )||(p8  &&   LireEntree(4)) || (p9  && LireEntree(4));
  	s8  = (p8  && !(LireEntree(4)) 		            	)||(p1  &&   LireEntree(1));
  	s9  = (p9  && !(LireEntree(4))  	            	)||(p10 &&   LireEntree(1));
  	s10 = (p10 && !(LireEntree(0) || LireEntree(1)) )||(p11 &&  !LireEntree(6));
  	s11 = (p11 && !(!LireEntree(6)) 	             	)||(p12 &&   LireEntree(6));
  	s12 = (p12 && !(LireEntree(6)) 		            	)||(p13 &&   LireEntree(5));
  	s13 = (p13 && !(LireEntree(5))  	            	)||(p1  &&   LireEntree(2)) || (p5  && LireEntree(2));

    //Bloc M
    p1=s1;
    p2=s2;
    p3=s3;
    p4=s4;
    p5=s5;
    p6=s6;
    p7=s7;
    p8=s8;
    p9=s9;
    p10=s10;
    p11=s11;
    p12=s12;
    p13=s13;

    // Debug Print
    printf("p1=%d,p2=%d,p3=%d,p4=%d,p5=%d,p6=%d,p7=%d,p8=%d,p9=%d,p10=%d,p11=%d,p12=%d,p13=%d\n",
            p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13);

    // Bloc F
  	if(p8 || p13) {
  		EcrireSortie(0,1);
  	}
  	if(p4 || p9) {
  		EcrireSortie(1,1);
  	}
  	if(p1 || p2 || p3 || p4 || p5 || p6 || p7 || p9 || p10 || p11 || p12) {
  		EcrireSortie(0,0);
  	}
  	if(p1 || p2 || p3 || p8 || p5 || p6 || p7 || p13 || p10 || p11 || p12) {
  		EcrireSortie(1,0);
  	}
  }

	Liberer_Carte () ;

  return (0) ;
}
