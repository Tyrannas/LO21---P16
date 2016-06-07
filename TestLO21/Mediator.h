#pragma once
#include "LitteraleManager.h"
#include"Pile.h"
#include"ComputerException.h"

class Mediator
{
public:
	Mediator(LitteraleManager* const L, Pile* const P) : litMng(L), stack(P) {}
	~Mediator() { delete litMng;  delete stack; }
	LitteraleManager* const litMng;
	Pile* const stack;
};

