
#ifndef TINDEX_H
#define TINDEX_H
#include "systeme.h"
#include "robot++.h"
#include <string>
#include <vector>

class tindex : public systeme
{
	public:
		tindex();
		~tindex();
		int evolue(int comp);
		void init();
		int GetComp();
	private:
		void marche();
		void arreter();
};


#endif // TINDEX_H
