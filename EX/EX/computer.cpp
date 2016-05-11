#include <string>
#include <iostream>
#include <sstream>
#include "computer.h"
#include <algorithm>
#include <regex>

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


void LitteraleManager::removeLitterale(Litterale& l) {
	int i=0;
	while (i < (nb-1) && lits[i] != &l) {
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

LitteraleManager::~LitteraleManager(){
	for (int i = 0; i < nb;i++)
		delete lits[i];
	delete[] lits;
}

/****Pile****/

void Pile::agrandissementCapacite() {
	cout << "Agrandissement de la pile\n";
	nbMax = nbMax + 10;
	Item *newItems = new Item[nbMax];
	for (int i = 0; i < nb; i++) {
		newItems[i] = items[i];
	}
	Item *oldItems = items;
	items = newItems;
	delete[] oldItems;
}

Pile::Pile() {
	nb = 0;
	nbMax = 10;
	nbAffiche = 5;
	items = new Item[nbMax];
}

Pile::~Pile() {
	delete[] items;
}

void Pile::affiche() const {
	cout << "*********************************\n";
	cout << message << "\n";
	cout << "*********************************\n";
	for (int i = min(nb,nbAffiche); i > 0; i--) {
		//cout << "emplacement" << i;
		if (i <= nb) {
			cout << "\t";
			items[i - 1].getLitterale().affiche();
			cout << "\n";
			//cout << "yolo";
		}
		else
			cout << i << "\n";
	}
	cout << "*********************************\n";
	//cout << "on sort";
}
	
void Pile::push(Litterale& l) {
	if (nb == nbMax)
		agrandissementCapacite();
	Item i = Item();
	i.setLitterale(l);
	items[nb] = i;
	nb = nb + 1;
}
	
void Pile::pop() {
	if (estVide())
		throw ComputerException("La pile est vide, impossible de depiler");
	else {
		cout << "suppression du dernier item";
		nb--;
		items[nb].raz();
}
}

bool Pile::estVide() const {
	if (nb == 0)
		return true;
	else
		return false;
}


int Pile::taille() const {
	return nb;
}

Litterale& Pile::top() const {
	if(estVide())
		throw ComputerException("Pile vide");
	else 
		return items[nb-1].getLitterale();
}


void Pile::setMessage(const string& m) {
	message = m;
}

string Pile::getMessage() const {
	return message;
}

void Pile::setNbItemsToAffiche(unsigned int n) {
	nbAffiche = n;
}

///******* Utile *****/

bool estUnOperateur(const string& s) {
	if (s == "+") return true;
	if (s == "-") return true;
	if (s == "*") return true;
	if (s == "/") return true;
	return false;
}

bool estUnEntier(const string& s) {
	unsigned int i = 0;
	for (i = 0; i<s.size(); i++)
		if (s[i]<'0' || s[i]>'9') return false;
	for (string::const_iterator it = s.begin(); it != s.end(); ++it)
		if (*it<'0' || *it>'9') return false;
	return true;
}

bool estUnReel(const string& s) {
	unsigned int i = 0;
	for (i = 0; i<s.size(); i++)
		if (s[i]<'0' || s[i]>'9') return false;
	for (string::const_iterator it = s.begin(); it != s.end(); ++it)
		if (*it<'0' || *it>'9') return false;
	return true;
}

///******Controleur******/

void Controleur::commande(const string& c) {
	if (estUnEntier(c)) {
		Entiere* e = new Entiere(atoi(c.c_str()));
		litAff.push(*e);
	}
	else {

		if (estUnOperateur(c)) {
			if (litAff.taille() >= 2) {
				/*
				Litterale v2 = litAff.top();
				litMng.removeLitterale(litAff.top());
				litAff.pop();
				Litterale v1 = litAff.top();
				litMng.removeLitterale(litAff.top());
				litAff.pop();
				
				int res;
				if (c == "+") res = v1 + v2;
				if (c == "-") res = v1 - v2;
				if (c == "*") res = v1*v2;
				if (c == "/") {
					if (v2 != 0) 	res = v1 / v2;
					else {
						litAff.setMessage("Erreur : division par zero");
						// restauration de la pile
						litAff.push(litMng.addLitterale(v1));
						res = v2;
					}
					
				}
				Litterale& l = litMng.addLitterale(res);
				litAff.push(l);
				*/
			}
			else {
				litAff.setMessage("Erreur : pas assez d'arguments");
			}
		}
		else litAff.setMessage("Erreur : commande inconnue");
	}
}

void Controleur::executer() {
	string c;
	do {
		litAff.affiche();
		cout << "?- ";
		cin >> c;
		if (c != "Exit") commande(c);
	} while (c != "Exit");
}
