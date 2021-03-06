#pragma once
#include "LitteraleManager.h"
#include "Litterale.h"
#include"Pile.h"
#include"ComputerException.h"
#include "HashMap.h"
#include <regex>
#include <string>
#include <iostream>
#include <sstream>
#include "Service.h"


using namespace std;

/*!
* \file Controleur.h
* \brief Base de lancement de l'application
* \author Felix ALIE & Clement ROUTIER
* \version 1
*/


/*! \class Controleur
* \brief Classe permettant de gerer l'ensemble de la calculatrice
*/

class Controleur {
	LitteraleManager& litMng; /*!< Gestion des litterales dans le controleur*/
	Pile& stack; /*!< Pile des litterales actuellement stockees*/
	HashMap& table; /*!< Table de stockage des variables et programmes*/
	bool canRedo;
public:
	/*!
	*  \brief Constructeur
	*  \param l : reference sur un litteraleManager
	*  \param v : reference sur une pile
	*  \param t : reference sur une hashmap
	*/
	Controleur(LitteraleManager& l, Pile& v, HashMap& t) :	litMng(l), stack(v), table(t), canRedo(false) {}
	/*!
	*  \brief Parseur : permet d'analyser la chaine entree par l'utilisateur
	*  \param c : chaine de caracteres entree au clavier
    */
    void parse(const string& c);
	/*!
	*  \brief Lanceur : permet de lancer l'application
	*/
    //void executer();
	/*!
    *  \brief OperationUnaire : permet d'effectuer une opération sur une littérale.
	*  \param i : un entier representant le type d'operation a realiser
	*/
    void operationUnaire(int i);
    /*!
    *  \brief OperationUnaire : permet d'effectuer une opération arithmetique entre litterales.
    *  \param i : un entier representant le type d'operation a realiser
    */
    void operationBinaire(int i);
	/*!
	*  \brief OperationPile : permet d'effectuer des operations directement sur la pile (DUP, SWAP, ...)
	*  \param i : un entier representant le type d'operation a realiser
	*/
	void operationPile(int i);
};
