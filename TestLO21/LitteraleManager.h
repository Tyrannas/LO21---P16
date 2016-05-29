#pragma once
#include "ComputerException.h"
#include "Litterale.h"

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
	Litterale& addLitterale(Litterale * const l);
	Litterale* const littFactory(TypeLitterale type, int p1, int p2 = NULL, double p3 = NULL, Numerique* p4 = nullptr, Numerique* p5 = nullptr, string = NULL);
	void removeLitterale(Litterale* const l);
	//LitteraleManager& operator=(const LitteraleManager&);
};
