
#ifndef BRAS_H
#define BRAS_H
#include "systeme.h"

#include <string>
#include <vector>

class Bras : public systeme
{
	public:
		Bras();
		~Bras();	
		int evolue(int c1,int c2);
		void init();
	private:
		void arreter();
		int ct;
};

#endif // BRAS_H
