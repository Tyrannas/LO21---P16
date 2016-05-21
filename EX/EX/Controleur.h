#pragma once
#include "litterale.h"
#include "computer.h"
#include <string>
#include <iostream>
#include <sstream>

class Controleur {
	LitteraleManager& litMng;
	Pile& Stack;
	LitteraleFactory& litFact;
public:
	Controleur(LitteraleManager& l, Pile& v, LitteraleFactory& f) :
		litMng(l), Stack(v), litFact(f){}
	void parse(const string& c);
	void executer();
	void operation(int i);
};

class LitteraleFactory
{
public:
	LitteraleFactory();

private:

};

LitteraleFactory::LitteraleFactory()
{
}
