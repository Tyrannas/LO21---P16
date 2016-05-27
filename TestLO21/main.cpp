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
	myCtrl.executer();
	system("pause");
	return 0;
}