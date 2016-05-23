#include "Controleur.h"
#include "Litterale.h"
#include "Pile.h"
#include "LitteraleManager.h"
#include "ComputerException.h"
#include <iostream>
using namespace std;

int main() {
	LitteraleManager lmng();
	Pile stack();
	LitteraleManager* l = new LitteraleManager;
	l->littFactory(tEntiere, 5)->affiche();
	system("pause");
	return 0;
}