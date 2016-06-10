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

/*! \class Memento
* \brief Classe permettant la sauvegarde de l'etat du LitteraleManager
*/
class Memento {
	friend class LitteraleManager;
private:
	int nb; /*!< nombre de litterales actuellement stockees*/
	Litterale* lastArg1; /*!< pointeur sur la premiere des litterales utilisee lors de la derniere operation*/
	Litterale* lastArg2; /*!< pointeur sur la deuxieme des litterales utilisee lors de la derniere operation*/
	string lastOp; /*!< chaine de caractere representant la derniere operation effectuee*/
public:
	Litterale** lits; /*!< tableau de pointeurs sur des litterales*/
	/*!
	*  \brief Constructeur
	*/
	Memento() { lits = new Litterale*[10]; nb = 0; lastArg1 = nullptr; lastArg2 = nullptr; lastOp = ""; }
	/*!
	*  \brief Accesseur sur le nombre
	*  \return entier representant le nombre de litterales actuellement stockees
	*/
	int getnb() { return nb; }
	/*!
	*  \brief Sauvegarde de l'etat des litterales
	*  \param nlits : tableau de pointeurs de Litterales a sauvegarder
	*  \param n : nombre d'elements du tableau a sauvegarder
	*/
	void save(Litterale** nlits, int n) {
		for (int i = 0; i < n; i++) {
			lits[i] = nlits[i]->clone();
		}
		nb = n;
	}
	/*!
	*  \brief Accesseur sur le tableau de Litterales
	*  \return tableau de pointeurs de Litterales
	*/
	Litterale** getLits() { return lits; }
	/*!
	*  \brief Mise a jour de la derniere operation effectuee
	*  \param l1 : premiere des deux litterales utilisees pour le calcul
	*  \param l2 : deuxieme des deux litterales utilisees pour le calcul
	*  \param op : chaine de caracteres representant l'operation effectuee
	*/
	void updateOpe(Litterale* l1, Litterale* l2, string op) {
		lastArg1 = l1;
		lastArg2 = l2;
		lastOp = op;
	}
	/*
	void affiche() {
		for (int i = 0; i < nb; i++) {
			lits[i]->affiche();
			cout << " ";
		}
	}
	*/
	/*!
	*  \brief Accesseur sur le premier des deux arguments enregistres
	*  \return pointeur sur la premiere litterale
	*/
	Litterale* getLastArg1() { return lastArg1; }
	/*!
	*  \brief Accesseur sur le deuxieme des deux arguments enregistres
	*  \return pointeur sur la deuxieme litterale
	*/
	Litterale* getLastArg2() { return lastArg2; }
	/*!
	*  \brief Accesseur sur le dernier operateur utilise
	*  \return chaine de caractere representant le dernier operateur
	*/
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

	Memento myMemento; /*!< sauvegarde de l'etat precedent*/

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
    *  \brief Methode factory permettant de creer une litterale du type passe en parametre et de retourner un pointeur sur cette derniere.
	*  \param type : type precis de la litterale a creer
    *  \param p1 : int dans le cas de la création d'une littérale Entière
    *  \param p2 : deuxieme int dans le cas de la création d'une litterale rationnelle
    *  \param p3 : double dans le cas de la creation d'une littérale reelle
    *  \param p4 : pointeur sur numerique n°1 dans le cas de la création d'une litterale complexe
    *  \param p5 : second pointeur sur numerique dans le cas de la creation d'une litterale complexe
	*  \return reference sur la litterale cree
	*/
    Litterale* const littFactory(TypeLitterale type, int p1, int p2 = NULL, double p3 = NULL, Numerique* p4 = nullptr, Numerique* p5 = nullptr);
	/*!
	*  \brief Suppression d'une litterale du Manager
	*  \param l : pointeur sur la litterale a supprimer
	*/
	void removeLitterale(Litterale* const l);

	/*!
	*  \brief Retour a l'etat precedent du LitteraleManager
	*/
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
	/*!
	*  \brief Accesseur sur le memento
	*  \return dernier etat sauvegarde
	*/
	Memento& getMem() { return myMemento; }
	/*!
	*  \brief Accesseur sur le tableau de pointeurs de Litterales
	*  \return tableau de pointeurs de Litterales
	*/
	Litterale** getLits() { return lits; }
	/*!
	*  \brief Accesseur sur la taille du tableau
	*  \return entier representant le nombre de Litterale du LitteraleManager
	*/
	int taille() { return nb; }

};
