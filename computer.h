#ifndef _COMPUTER_H
#define _COMPUTER_H
#include <string>
#include <iostream>
#include <sstream>
#include "litterale.h"

using namespace std;

class ComputerException {
	string info;
public:
	ComputerException(const string& str) :info(str) {}
	string getInfo() const { return info; }
};

/*
class Expression {
private:
	int value;
public:
	Expression(int v) : value(v) {};
	inline int getValue() const { return value; }
	inline string toString() const { return to_string(value); }


};
*/
class LitteraleManager {
private:
	Litterale** lits;
	int nb;
	int nbMax;
	void agrandissementCapacite();
public:
	LitteraleManager();
	LitteraleManager(const LitteraleManager& lm);
	~LitteraleManager();
	Litterale& addLitterale(Litterale& l);
	void removeLitterale(Litterale& l);
	LitteraleManager& operator=(const LitteraleManager&);
};

class Item {
private:
	Litterale* lit;
public:
	Item() { lit = nullptr; };
	inline void setLitterale(Litterale& l) { lit = &l; };
	inline Litterale& getLitterale() const {
		if (lit == 0)
			throw ComputerException("erreur");
		return *lit; 
	};
	void raz() { lit = nullptr;	};
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
	void push(Litterale& l);
	void pop();
	bool estVide() const;
	int taille() const;
	Litterale& top() const;
	void setMessage(const string& m);
	string getMessage() const;
	void setNbItemsToAffiche(unsigned int n);
};

class Controleur {
	LitteraleManager& litMng;
	Pile& litAff;
public:
	Controleur(LitteraleManager& l, Pile& v) :
		litMng(l), litAff(v) {}
	void commande(const string& c);
	void executer();
};


#endif