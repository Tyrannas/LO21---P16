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
    int nb; /*!< Nombre d'entrée dans la table*/
	HashEntry **table; /*!< Tableau de pointeurs de HashEntry*/
public:
	/*!
	*  \brief Constructeur
	*/
	HashMap() {
        nb = 0;
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
            throw ComputerException("Aucune valeur trouvee pour cet identifiant\n");
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
            forget(key);
		table[hash] = new HashEntry(key, value);
        nb++;
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
            nb--;
		}
		else
            throw ComputerException("Aucune variable stockee avec ce nom. Suppression impossible\n");
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
    /*!
    *  \brief Implementation d'un interateur pour la classe HashMap. Permet de parcourir aisement les entrees de la table.
    */
    class Iterator
        {
        friend class HashMap;
        public:
            Iterator& operator++() { table++; return *this; }
            Iterator& operator--() { table--; return *this; }
            HashEntry* operator*() const { return *table; }
            bool operator!=(const Iterator& it) const { return (table != it.table); }
        private:
            HashEntry** table;
            Iterator(HashEntry** _t) :table(_t) {}
        };

    //Iterator getIterator() const { return Iterator(exps, nb); } // Implementation 1
    const Iterator begin() const { return Iterator(table); } /*!< Iterateur de debut de HashMap*/
    const Iterator end() const { return Iterator(table + nb); } /*!< Iterateur de fin de HashMap*/
    const Iterator rbegin() const { return Iterator(table + nb - 1); } /*!< Iterateur inverse de debut de HashMap*/
    const Iterator rend() const { return Iterator(table - 1); } /*!< Iterateur inverse de fin de HashMap*/
};
