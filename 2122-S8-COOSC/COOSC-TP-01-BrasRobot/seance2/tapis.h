
#ifndef TAPIS_H
#define TAPIS_H
#include "systeme.h"

#include <string>
#include <vector>

class tapis : public systeme
{
	public:
		tapis();
		~tapis();	
		int evolue();
		int GetSignal();
		void init();
	private:
		void marche();
		void arreter();
		int signal;
};


#endif // TAPIS_H
