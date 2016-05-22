#ifndef _LITTMNG_H
#define _LITTMNG_H
#include "litterale.h"

#include <string>
#include <iostream>
#include <sstream>
class LitteraleManager {
private:
	Litterale** lits;
	int nb;
	int nbMax;
	void agrandissementCapacite();
public:
	LitteraleManager();
	//LitteraleManager(const LitteraleManager& lm);
	~LitteraleManager();
	Litterale& addLitterale(Litterale& l);
	Litterale* const littFactory(TypeLitterale type, int p1, int p2 = NULL, double p3 = NULL, Numerique* p4 = nullptr, Numerique* p5 = nullptr);
	void removeLitterale(Litterale& l);
	//LitteraleManager& operator=(const LitteraleManager&);
}

#endif

