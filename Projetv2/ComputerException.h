#pragma once
#include <string>
using namespace std;

/*!
* \file ComputerException.h
* \brief Gestion des erreurs
* \author Felix ALIE & Clement ROUTIER
* \version 1
*/


/*! \class ComputerException
* \brief Classe permettant la gestion des erreurs
*/
class ComputerException {
	string info; /*!< Chaine de caracteres decrivant l'erreur*/
public:
	/*!
	*  \brief Constructeur
	*  \param str : chaine de caracteres decrivant l'erreur
	*/
	ComputerException(const string& str) :info(str) {}
	/*!
	*  \brief Accesseur
	*  \return chaine de caracteres decrivant l'erreur
	*/
	string getInfo() const { return info; }
};
