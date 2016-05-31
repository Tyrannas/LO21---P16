#pragma once
#include "ComputerException.h"
#include "Litterale.h"

#include <string>
#include <iostream>
#include <sstream>


class MementoLit {
	friend class LitteraleManager;
private:
	Litterale** lits;
	int nb;
public:
	MementoLit() { lits = new Litterale*[10]; nb = 0; }
	int getnb() { return nb; }
	void save(Litterale** nlits, int n) {
		for (int i = 0; i < n; i++) {
			lits[i] = nlits[i];
		}
		nb = n;
	}
	void affiche() {
		for (int i = 0; i < nb; i++) {
			lits[i]->affiche();
			cout << " ";
		}
	}
};

class LitteraleManager {
private:
	Litterale** lits;
	int nb;
	int nbMax;
	void agrandissementCapacite();
	MementoLit myMemento;
public:
	LitteraleManager();
	~LitteraleManager();
	Litterale& addLitterale(Litterale * const l);
	Litterale* const littFactory(TypeLitterale type, int p1, int p2 = NULL, double p3 = NULL, Numerique* p4 = nullptr, Numerique* p5 = nullptr);
	void removeLitterale(Litterale* const l);
	void clear() {
		while (nb != 0) {
			removeLitterale(lits[nb]);
			nb--;
		}
	}
	void annuler() {
		Litterale** temp = new Litterale*[nb];
		int tempnb = nb;
		for (int i = 0; i < nb; i++) {
			temp[i] = lits[i];
		}
		for (int i = 0; i < myMemento.nb; i++) {
			lits[i] = myMemento.lits[i];
		}
		nb = myMemento.nb;
		myMemento.save(temp, tempnb);
	}
	MementoLit& getMem() { return myMemento; }
	Litterale** getLits() { return lits; }
	int taille() { return nb; }
	void affiche(){
		for (int i = 0; i < nb; i++) {
			lits[i]->affiche();
			cout << " ";
		}
	}
};


