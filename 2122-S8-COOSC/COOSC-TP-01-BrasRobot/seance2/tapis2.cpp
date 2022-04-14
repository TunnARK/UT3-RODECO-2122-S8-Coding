#include "tapis2.h"
#include "robot++.h"

// Constructors/Destructors
//  
tapis2::tapis2 () :systeme(3){
place_[0] = 1;
signal=0;
}

tapis2::~tapis2 () { }

//  
// Methods
//  
int tapis2::evolue(){
	if(place_[0]&&FinPrise()==1)
	{
		place_[0]--;
		place_[1]++;
		marche();
		signal=0;
	}
	if(place_[1]&&C1()==0)
	{
		place_[1]--;
		place_[2]++;
	}
	if(place_[2]&&C1()==1)
	{
		place_[2]--;
		place_[0]++;
		arreter();
		signal=1;
	}
return(0);
}

void tapis2::init(){
	arreter();
}


int tapis2::GetSignal(){
return(signal);
}
	

void tapis2::marche() {
	Start2(0);
	Stop2(1);
}
void tapis2::arreter() {
	Stop2(0);
	Start2(1);
}


