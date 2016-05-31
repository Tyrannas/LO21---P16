#pragma once
#include "LitteraleManager.h"
#include "Litterale.h"
#include"Pile.h"
#include"ComputerException.h"
#include "HashMap.h"
#include <regex>
#include <string>
#include <iostream>
#include <sstream>


using namespace std;

class Controleur {
	LitteraleManager& litMng;
	Pile& stack;
	HashMap& table;
public:
	Controleur(LitteraleManager& l, Pile& v, HashMap& t) :	litMng(l), stack(v), table(t) {}
	void parse(const string& c);
	void executer();
	void reset() { stack.clear(); litMng.clear(); }
	void operation(int i);
	void operationPile(int i);
	const int nbOpBin = 7;
};
