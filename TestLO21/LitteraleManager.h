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
};
