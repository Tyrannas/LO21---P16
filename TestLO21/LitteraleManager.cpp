#include"LitteraleManager.h"
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


Litterale& LitteraleManager::addLitterale(Litterale * const l) {
	if (nb == nbMax)
		agrandissementCapacite();
	lits[nb++] = l;
	return *lits[nb - 1];
}

Litterale * const LitteraleManager::littFactory(TypeLitterale type, int p1, int p2, double p3, Numerique * p4, Numerique * p5)
{
	if (type == TypeLitterale::tEntiere) {
		Entiere * const e = new Entiere(p1);
		addLitterale(e);
		return e;
	}
	if (type == TypeLitterale::tRationnelle) {
		Rationnelle * const r = new Rationnelle(p1, p2);
		addLitterale(r);
		return r;
	}
	if (type == TypeLitterale::tReelle) {
		Reelle * const r = new Reelle(p3);
		addLitterale(r);
		return r;
	}
	if (type == TypeLitterale::tComplexe) {
		Complexe * const c = new Complexe(p4, p5);
		addLitterale(c);
		return c;
	}
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