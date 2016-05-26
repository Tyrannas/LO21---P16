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
	HashMap table;
public:
	Controleur(LitteraleManager& l, Pile& v) :	litMng(l), stack(v) {}
	void parse(const string& c);
	void executer();
	void operation(int i);
};
