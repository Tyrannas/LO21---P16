#pragma once
#include "Litterale.h"
#include "ComputerException.h"
#include <regex>
#include <string>
#include <iostream>
#include <sstream>

const int TABLE_SIZE = 128;

/*!
* \file Controleur.h
* \brief Table de stockage et variables et des programmes
* \author Felix ALIE & Clement ROUTIER
* \version 1
*/


/*! \class HashEntry
* \brief Classe representant une entree de la HashMap
*/

class HashEntry {
private:
    string key; /*!< Chaine de caracteres servant d'identifiant a la variable ou au programme*/
	Litterale* value; /*!< Pointeur sur la litterale stockee*/
public:
	/*!
	*  \brief Constructeur
	*  \param key : chaine de caracteres servant d'identifiant a la variable ou au programme
	*  \param value : pointeur sur la litterale stockee
	*/
    HashEntry(string key, Litterale* value) : key(key), value(value) {}

	/*!
	*  \brief Accesseur
	*  \return chaine caracteres servant d'identifiant a la variable ou au programme
	*/
	string getKey() {
        return key;
	}

	/*!
	*  \brief Accesseur
	*  \return pointeur sur la litterale stockee
	*/
	Litterale* getValue() {
		return value;
	}
};


/*! \class HashMap
* \brief Classe reprentant la table de stockage
*/
class HashMap {
private:
	HashEntry **table; /*!< Tableau de pointeurs de HashEntry*/
public:
	/*!
	*  \brief Constructeur
	*/
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;
	}

	/*!
	*  \brief Accesseur dans la table
	*  \param key : chaine de caracteres servant d'identifiant a la variable ou au programme dont on cherche la valeur
	*  \return pointeur sur la litterale correspondante
	*/
    Litterale* get(string key) {
		int hash = 0;
        while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1);
		if (table[hash] == NULL)
            //throw ComputerException("Aucune valeur trouvee pour cet identifiant\n");
            qWarning("pas trouve de valeur correspondante");
		else {
			return table[hash]->getValue();
		}
	}

	/*!
	*  \brief Ajout d'une entree dans la table
	*  \param key : chaine de caracteres servant d'identifiant a la variable ou au programme a inserer
	*  \param value : pointeur sur la litterale correspondante a inserer
	*/
    void put(string key, Litterale* value) {
		int hash = 0;
        while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1);
		if (table[hash] != NULL)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}
	
	/*!
	*  \brief Oubli d'une entree de la table
	*  \param key : chaine de caracteres servant d'identifiant a la variable ou au programme
	*/
    void forget(string key) {
		int hash = 0;
        while (table[hash] != NULL && table[hash]->getKey() != key){
            hash = (hash + 1);
        }
		if (table[hash] != NULL) {
			delete table[hash];
			table[hash] = nullptr;
		}
		else
            //throw ComputerException("Aucune variable stockee avec ce nom. Suppression impossible\n");
            qWarning("Aucune valeur trouver a ce nom pour la suppression");
	}

	/*!
	*  \brief Destructeur
	*/
	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != NULL)
				delete table[i];
		delete[] table;
	}
	/*
	void affiche() {
		int hash = 0;
		cout << "|||||||||||||||||||||||||||||||||||\n";
		while (table[hash] != NULL){
			cout << table[hash]->getKey() << " ==> ";
			table[hash]->getValue()->affiche();
			cout << "\n";
			hash = (hash + 1);
		}
	}
	*/
};
