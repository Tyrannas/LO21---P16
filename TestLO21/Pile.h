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
	// void lastop(); necessite m�mo
	// void lastargs(); necessite m�mo
	// void undo(); necessite m�mo
	// void redo(); necessite m�mo
	void clear();
};

/*
� DUP, op�rateur unaire : empile une nouvelle litt�rale identique � celle du sommet de la pile.
� DROP, op�rateur unaire : d�pile la litt�rale au sommet de la pile.
� SWAP, op�rateur binaire : intervertit les deux derniers �l�ments empil�s dans la pile.
� LASTOP : applique le dernier op�rateur utilis�.
� LASTARGS : empile les litt�rales utilis�es pour la derni�re op�ration.
� UNDO : r�tablit l��tat du calculateur avant la derni�re op�ration.
� REDO : r�tablit l��tat du calculateur avant l�application de la derni�re op�ration UNDO.
� CLEAR : vide tous les �l�ments de la pile.*/