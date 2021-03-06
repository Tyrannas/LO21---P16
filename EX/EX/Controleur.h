#ifndef _CONTROLEUR_H
#define _CONTROLEUR_H

#include "LitteraleManager.h"
#include "Controleur.h"
#include "litterale.h"
#include"Pile.h"


#include <regex>
#include <string>
#include <iostream>
#include <sstream>

class Controleur {
	LitteraleManager& litMng;
	Pile& Stack;
public:
	Controleur(LitteraleManager& l, Pile& v) :
		litMng(l), Stack(v){}
	void parse(const string& c);
	void executer();
	void operation(int i);
};

#endif