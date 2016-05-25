#include "Controleur.h"
#include "Litterale.h"
#include "Pile.h"
#include "LitteraleManager.h"
#include "ComputerException.h"
#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
	Pile stack = Pile();
	LitteraleManager litMng = LitteraleManager();
	Controleur myCtrl(litMng, stack);
	Reelle r1(3.5);
	Litterale* l1(&r1);
	l1->affiche();
	myCtrl.executer();
	system("pause");
	return 0;
}