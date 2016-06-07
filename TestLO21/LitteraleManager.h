#pragma once
#include "ComputerException.h"
#include "Litterale.h"

#include <string>
#include <iostream>
#include <sstream>

/*!
* \file Controleur.h
* \brief Gestion de l'ensemble des litterales
* \author Felix ALIE & Clement ROUTIER
* \version 1
*/


class Memento {
	friend class LitteraleManager;
private:
	int nb;
	Litterale* lastArg1;
	Litterale* lastArg2;
	string lastOp;
public:
	Litterale** lits;
	Memento() { lits = new Litterale*[10]; nb = 0; lastArg1 = nullptr; lastArg2 = nullptr; lastOp = ""; }
	int getnb() { return nb; }
	void save(Litterale** nlits, int n) {
		for (int i = 0; i < n; i++) {
			lits[i] = nlits[i]->clone();
		}
		nb = n;
	}
	Litterale** getLits() { return lits; }
	void updateOpe(Litterale* l1, Litterale* l2, string op) {
		lastArg1 = l1;
		lastArg2 = l2;
		lastOp = op;
	}
	void affiche() {
		for (int i = 0; i < nb; i++) {
			lits[i]->affiche();
			cout << " ";
		}
	}
	Litterale* getLastArg1() { return lastArg1; }
	Litterale* getLastArg2() { return lastArg2; }
	string getLastOp() { return lastOp; }
};





/*! \class LitteraleManager
* \brief Classe permettant de gerer toutes les litterales ajoutees une a une
*/
class LitteraleManager {
private:
	Litterale** lits; /*!< tableau de pointeurs sur des litterales*/
	int nb; /*!< nombre exacte de litterales dans le Manager*/
	int nbMax; /*!< nombre maximum de litterales dans le Manager*/
	/*!
	*  \brief Agrandissement du tableau de pointeurs si la taille maximale est atteinte
	*/
	void agrandissementCapacite();

	Memento myMemento;

public:
	/*!
	*  \brief Constructeur
	*/
	LitteraleManager();
	/*!
	*  \brief Destructeur
	*/
	~LitteraleManager();
	/*!
	*  \brief Ajout d'une litterale dans le Manager
	*  \param l : litterale a ajouter
	*  \return reference sur la litterale ajoutee
	*/
	Litterale& addLitterale(Litterale * const l);
	/*!
	*  \brief Creation de la litterale corespondant a la chaine de caracteres parsee dans le controleur
	*  \param type : type precis de la litterale a creer
	*  \param p1 : Felix
	*  \param p2 : Felix
	*  \param p3 : Felix
	*  \param p4 : Felix
	*  \param p5 : Felix
	*  \return reference sur la litterale cree
	*/
	Litterale* const littFactory(TypeLitterale type, int p1, int p2 = NULL, double p3 = NULL, Numerique* p4 = nullptr, Numerique* p5 = nullptr);
	/*!
	*  \brief Suppression d'une litterale du Manager
	*  \param l : pointeur sur la litterale a supprimer
	*/
	void removeLitterale(Litterale* const l);


	void annuler() {
		Litterale** temp = new Litterale*[nb];
		int tempnb = nb;
		for (int i = 0; i < nb; i++) {
			temp[i] = lits[i];
		}
		for (int i = 0; i < myMemento.nb; i++) {
			lits[i] = myMemento.lits[i];
		}
		/*
		for (int j = myMemento.nb; j <= nb; j++) {
			delete lits[j];
		}
		*/
		nb = myMemento.nb;
		myMemento.save(temp, tempnb);
	}
	Memento& getMem() { return myMemento; }
	Litterale** getLits() { return lits; }
	int taille() { return nb; }

};
