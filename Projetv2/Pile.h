#pragma once
#include <algorithm>
#include "Litterale.h"
#include "ComputerException.h"
#include "LitteraleManager.h"
#include <iostream>
using namespace std;

class Memento;

/*!
* \file Controleur.h
* \brief Gestion de la pile et de ses items
* \author Felix ALIE & Clement ROUTIER
* \version 1
*/


/*! \class Item
* \brief Classe permettant d'encapsuler les litterales dans des items pour le stockage dans la pile
*/
class Item {
private:
	Litterale* lit; /*!< pointeur sur une litterale*/
public:
	/*!
	*  \brief Constructeur
	*/
	Item() { lit = nullptr; };
	/*!
	*  \brief Editeur : permet de changer la litterale pointee
	*  \param l : pointeur sur la nouvelle litterale
	*/
	inline void setLitterale(Litterale* const l) { lit = l; };
	/*!
	*  \brief Accesseur
	*  \return litterale pointee par l'item
	*/
	inline Litterale* const getLitterale() const {
		if (lit == 0)
			throw ComputerException("Erreur dans la recuperation de la litterale");
		return lit;
	};
	/*!
	*  \brief Reset de l'item
	*/
	void raz() { lit = nullptr; };
};


/*! \class Pile
* \brief Classe permettant de stocker les items sous forme de pile
*/
class Pile {
	friend class Memento;
	Item* items; /*!< tableau d'items*/
	int nb; /*!< nombre actuel d'items dans la pile*/
	int nbMax; /*!< nombre maximum d'items dans la pile*/
	int nbAffiche; /*!< nombre d'element a afficher*/
	/*!
	*  \brief Agrandisement de la pile si cette derniere est pleine
	*/
	void agrandissementCapacite();
public:
	/*!
	*  \brief Constructeur
	*/
	Pile();
	/*!
	*  \brief Destructeur
	*/
	~Pile();
	/*!
	*  \brief Affichage de la pile
	*/
	void affiche() const;
	/*!
	*  \brief Insertion d'une litterale dans la pile
	*  \param l : pointeur sur la litterale a inserer
	*/
	void push(Litterale* const l);
	/*!
	*  \brief Test sur la capacite de la pile
	*  \return 'true' si la pile est vide, 'false' sinon
	*/
	bool estVide() const;
	/*!
	*  \brief Accesseur sur le nombre
	*  \return nombre actuel d'items dans la pile
	*/
	int taille() const;
	/*!
	*  \brief Accesseur sur le nombre maximum
	*  \return nombre maximum d'items dans la pile
	*/
	int tailleMax() const;
	/*!
	*  \brief Acces au dernier element
	*  \return pointeur sur la litterale au sommet de la pile
	*/
	Litterale* const top() const;
	/*!
	*  \brief Accesseur sur le nombre a afficher
	*  \return nombre d'items a afficher
	*/
	void setNbItemsToAffiche(unsigned int n);
	/*!
	*  \brief Suppression du dernier element
	*/
	void drop();
	/*!
	*  \brief Inversion des deux derniers elements
	*/
	void swap();
	// void lastop(); necessite mémo
	// void lastargs(); necessite mémo
	// void undo(); necessite mémo
	// void redo(); necessite mémo
	/*!
	*  \brief Suppression de l'integralite des elements de la pile
	*/
	void clear();

	/*!
	*  \brief Reconstruction de la pile suite a un REDO
	*  \param m : memento du LitteralManager
	*/
	void reconstruire(Memento m) {
		this->clear();
		for (int i = 0; i < m.getnb();i++) {
			push(m.lits[i]);
		}
		nb = m.getnb();
		
	}
};





