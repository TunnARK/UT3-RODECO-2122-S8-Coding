#include "Bras.h"
#include "robot++.h"

// Constructors/Destructors
//  

Bras::Bras () : systeme(11){
place_[0] = 1;
ct =0;
}

Bras::~Bras () { }

int Bras::evolue(int c1,int c2){
	if(place_[0]&&c1==1){
		place_[0]--;
		place_[1]++;
		arreter();
		Gauche(1);
	}
	if(place_[0]&&c2==1&&c1==0){
		place_[0]--;
		place_[2]++;
		arreter();
		Gauche(1);
	}
	if(place_[1]&&T1()==1)
	{
		place_[1]--;
		place_[3]++;
		arreter();
		Prise(1);
	}
	if(place_[2]&&T2()==1)
	{
		place_[2]--;
		place_[3]++;
		arreter();
		Prise(1);
	}
	if(place_[3]&&FinPose()==1)
	{	
		place_[3]--;
		place_[4]++;
		arreter();
		Droite(1);
	}
	if(place_[4]&&TI()==1)
	{
		place_[4]--;
		place_[5]++;
		arreter();
		Pose(1);
	}
	if(place_[5]&&FinPose()==0)
	{
		place_[5]--;
		place_[0]++;
		arreter();
		ct++;
	}
	if(place_[0]&&ct<8)
	{
		place_[0]--;
		place_[7]++;
		arreter();
		Gauche(1);
	}
	if(place_[7]&&TI()==1)
	{
		place_[7]--;
		place_[8]++;
		arreter();
		Prise(1);
	}
	if(place_[8]&&FinPrise()==1)
	{
		place_[8]--;
		place_[9]++;
		arreter();
		Droite(1);
	}
	if(place_[9]&&PE()==1)
	{
		place_[9]--;
		place_[10]++;
		arreter();
		Pose(1);
	}
	if(place_[10]&&FinPrise()==1)
	{
		place_[10]--;
		place_[6]++;
		arreter();
		ct--;	
	}
	if(place_[6]&&ct>0)
	{
		place_[6]--;
		place_[7]++;
		arreter();
		Gauche(1);
	}
	if(place_[6]&&ct==0)
	{
		place_[6]--;
		place_[0]++;
		arreter();
	}

return(0);
}

int Bras::GetCt(){
return(ct);
}


void Bras::init(){
	arreter();
	Droite(1);
	while(SCD()==1;
	arreter();
	Gauche(1);
	while(Ti()==1);
	arreter();
}	

void Bras::arreter(){
	Gauche(0);
	Droite(0);
	Prise(0);
	Pose(0);
}

