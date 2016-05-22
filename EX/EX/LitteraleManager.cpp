#include"LitteraleManager.h"
#include"computer.h"
using namespace std;

/****LitteraleManager****/

void LitteraleManager::agrandissementCapacite() {
	cout << "Agrandissement du tableau\n";
	nbMax = nbMax + 10;
	Litterale **newLits = new Litterale*[nbMax];
	for (int i = 0; i < nb; i++) {
		newLits[i] = lits[i];
	}
	Litterale** oldLits = lits;
	lits = newLits;
	delete[] oldLits;
}

LitteraleManager::LitteraleManager() {
	nbMax = 10;
	lits = new Litterale*[nbMax];
	nb = 0;
}


Litterale& LitteraleManager::addLitterale(Litterale& l) {
	if (nb == nbMax)
		agrandissementCapacite();
	lits[nb++] = &l;
	return *lits[nb - 1];
}
 
Litterale * const LitteraleManager::littFactory(TypeLitterale type, int p1, int p2, double p3, Numerique * p4, Numerique * p5)
{
	if (type == TypeLitterale::tEntiere)
		return new Entiere(p1);
	if (type == TypeLitterale::tRationnelle)
		return new Rationnelle(p1, p2);
	if (type == TypeLitterale::tReelle)
		return new Reelle(p3);
	if (type == TypeLitterale::tComplexe)
		return new Complexe(p4, p5);
}


void LitteraleManager::removeLitterale(Litterale& l) {
	int i = 0;
	while (i < (nb - 1) && lits[i] != &l) {
		i++;
	}

	if (lits[i] != &l) {
		throw ComputerException("erreur");
	}
	delete lits[i];
	for (int j = i; j < nb; j++)
		lits[j] = lits[j + 1];
	nb--;
}

LitteraleManager::~LitteraleManager() {
	for (int i = 0; i < nb; i++)
		delete lits[i];
	delete[] lits;
}