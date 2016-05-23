#pragma once
#include <algorithm>
#include "Litterale.h"
#include "ComputerException.h"
#include <iostream>
using namespace std;


class Item {
private:
	Litterale* lit;
public:
	Item() { lit = nullptr; };
	inline void setLitterale(Litterale* const l) { lit = l; };
	inline Litterale* const getLitterale() const {
		if (lit == 0)
			throw ComputerException("erreur");
		return lit;
	};
	void raz() { lit = nullptr; };
};


class Pile {
	Item* items;
	int nb;
	int nbMax;
	int nbAffiche;
	string message;
	void agrandissementCapacite();
public:
	Pile();
	~Pile();
	void affiche() const;
	void push(Litterale* const l);
	void pop();
	bool estVide() const;
	int taille() const;
	Litterale* const top() const;
	void setMessage(const string& m);
	string getMessage() const;
	void setNbItemsToAffiche(unsigned int n);
};

