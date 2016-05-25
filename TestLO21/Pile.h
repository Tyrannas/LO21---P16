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
	//void pop();
	bool estVide() const;
	int taille() const;
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
};

/*
• DUP, opérateur unaire : empile une nouvelle littérale identique à celle du sommet de la pile.
• DROP, opérateur unaire : dépile la littérale au sommet de la pile.
• SWAP, opérateur binaire : intervertit les deux derniers éléments empilés dans la pile.
• LASTOP : applique le dernier opérateur utilisé.
• LASTARGS : empile les littérales utilisées pour la dernière opération.
• UNDO : rétablit l’état du calculateur avant la dernière opération.
• REDO : rétablit l’état du calculateur avant l’application de la dernière opération UNDO.
• CLEAR : vide tous les éléments de la pile.*/