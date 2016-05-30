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
		//if (lit == 0)
		//	throw ComputerException("Erreur dans la recuperation de la litterale");
		return lit;
	};
	void raz() { lit = nullptr; };
};
/*
class Memento
{
private:
	friend class Pile;
	Item* items;
	int nb;
public:
	Memento(Item* i, int n) : items(i), nb(n) {};
	void save(Pile p) {
		items = p.items;
		nb = p.nb;
	}
};
*/

class Pile {
	friend class Memento;
	Item* items;
	int nb;
	int nbMax;
	int nbAffiche;
	string message;
	void agrandissementCapacite();
	//Memento myMemento;
public:
	Pile();
	~Pile();
	void affiche() const;
	void push(Litterale* const l);
	//void pop();
	bool estVide() const;
	int taille() const;
	int tailleMax() const;
	Litterale* const top() const;
	//void setMessage(const string& m);
	//string getMessage() const;
	void setNbItemsToAffiche(unsigned int n);
	void dup();
	void drop();
	void swap();
	// void lastop(); necessite mémo
	// void lastargs(); necessite mémo
	// void undo(); necessite mémo
	// void redo(); necessite mémo
	void clear();
	/*void annuler() {
		this->items = this->myMemento.items;
		this->nb = this->myMemento.nb;
	}*/
};


