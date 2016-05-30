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
	HashMap table = HashMap();
	Controleur myCtrl(litMng, stack, table);
	//cout << stack.taille() << stack.tailleMax();
	myCtrl.executer();
	system("pause");
	return 0;
}