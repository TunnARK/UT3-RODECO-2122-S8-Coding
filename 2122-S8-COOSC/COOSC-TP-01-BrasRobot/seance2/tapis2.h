
#ifndef TAPIS2_H
#define TAPIS2_H
#include "systeme.h"

#include <string>
#include <vector>

class tapis2 : public systeme
{
	public:
		tapis2();
		~tapis2();
		int evolue();
		int GetSignal();
		void init();
	private:
		void marche();
		void arreter();
		int signal;
};


#endif // TAPIS2_H
