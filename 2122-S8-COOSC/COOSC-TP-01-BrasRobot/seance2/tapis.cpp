#include "tapis.h"
#include "robot++.h"

// Constructors/Destructors
//  
tapis::tapis () :systeme(3){
place_[0] = 1;
signal=0;
}

tapis::~tapis () { }

//  
// Methods
//  
int tapis::evolue(){

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

void tapis::init(){
	arreter();
}

int tapis::GetSignal(){
return(signal);
}
	
void tapis::marche() {
	Start1(0);
	Stop1(1);
}
void tapis::arreter() {
	Stop1(0);
	Start1(1);
}


