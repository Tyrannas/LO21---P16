#include "Pile.h"
using namespace std;
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
	cout << "*********************************\n";
	for (int i = min(nb, nbAffiche); i > 0; i--) {
		if (i <= nb) {
			cout << "\t";
			items[i - 1].getLitterale()->affiche();
			cout << "\n";
		}
		else
			cout << i << "\n";
	}
	cout << "*********************************\n";
}

void Pile::push(Litterale* const l) {
	if (nb == nbMax) {
		cout << nb << nbMax;
		cout << "Pile trop petite, on agrandit";
		agrandissementCapacite();
	}
	Item i = Item();
	i.setLitterale(l);
	items[nb] = i;
	nb = nb + 1;
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

int Pile::tailleMax() const {
	return nbMax;
}

Litterale* const Pile::top() const {
	if (estVide())
		throw ComputerException("Pile vide");
	else
		return items[nb-1].getLitterale();
}

/*
void Pile::setMessage(const string& m) {
	message = m;
}

string Pile::getMessage() const {
	return message;
}
*/

void Pile::setNbItemsToAffiche(unsigned int n) {
	nbAffiche = n;
}

void Pile::drop()
{
	if (estVide())
		throw ComputerException("La pile est vide, impossible de depiler");
	else {
		nb--;
		items[nb].raz();
	}
}

void Pile::swap()
{
	Litterale* l1 = top();
	this->drop();
	Litterale* l2 = top();
	this->drop();
	this->push(l1);
	this->push(l2);
}

void Pile::clear()
{
	while(!estVide())
		drop();	
}

