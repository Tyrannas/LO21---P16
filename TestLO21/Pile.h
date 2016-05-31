#pragma once
#include <algorithm>
#include "Litterale.h"
#include "ComputerException.h"
#include <iostream>

using namespace std;

class Memento;

class Item {
private:
	Litterale* lit;
public:
	Item() { lit = nullptr; };
	inline void setLitterale(Litterale* const l) { lit = l; };
	inline Litterale* const getLitterale() const {
		//if (lit == 0)
		//	throw ComputerException("Erreur dans la recuperation de la litterale");
		return lit;
	};
	void raz() { lit = nullptr; };
};

class Memento {
	friend class Pile;
private:
	Item* items;
	int nb;
	Litterale* lastarg1;
	Litterale* lastarg2;
	string lastop;
public:
	Memento() { items = new Item[10]; nb = 0; lastarg1 = nullptr; lastarg2 = nullptr; lastop = ""; }
	int getnb() { return nb; }
	void save(Item* it, int n) {
		for (int i = 0; i < n; i++) {
			items[i] = it[i];
		}
		nb = n;
	}
	void setLastOp(Litterale* l1, Litterale* l2, string s) { lastarg1 = l1; lastarg2 = l2; lastop = s; }
	Litterale* getLastArg1() { return lastarg1; }
	Litterale* getLastArg2() { return lastarg2; }
	string getLastOp() { return lastop; }
	void debug() {
		for (int i = 0; i < nb; i++) {
			items[i].getLitterale()->affiche();
			cout << " ";
		}
	}
};

class Pile {
	friend class Memento;
private:
	Item* items;
	int nb;
	int nbMax;
	int nbAffiche;
	string message;
	void agrandissementCapacite();
	Memento myMemento;
	int etat =0;
public:
	Pile();
	~Pile();
	void affiche() const;
	void push(Litterale* const l);
	bool estVide() const;
	int taille() const;
	int tailleMax() const;
	int getEtat() { return etat; }
	void setEtat(int i) { etat=i; }
	Litterale* const top() const;
	void setNbItemsToAffiche(unsigned int n);
	void drop();
	void swap();
	//void lastop();
	//void lastargs();
	void clear();
	Memento& getMem() { return myMemento; }
	Item* getItems() { return items; }
	void annuler() {
		Item* temp = new Item[nb];
		int tempnb = nb;
		for (int i = 0; i < nb; i++) {
			temp[i] = items[i];
		}
		for (int i = 0; i < myMemento.nb; i++) {
			items[i] = myMemento.items[i];
		}
		nb = myMemento.nb;
		myMemento.save(temp, tempnb);
	}
	void debug() {
		for (int i = 0; i < nb; i++) {
			items[i].getLitterale()->affiche();
			cout << " ";
		}
	}
};


