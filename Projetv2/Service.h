#pragma once
#include<regex>
#include<string>
using namespace std;
/*!
* \file Service.h
* \brief Ensemble de fonctions de service à l'usage du parseur. Les fonctions permettant de tester si la chaine d'entrée est un opérateur renvoient un entier qui sera parsé afin d'indique l'action à réaliser.
* \author Felix ALIE & Clement ROUTIER
* \version 1
*/

/*!
*  \brief estUnOperateurPile: renvoie un entier positif si la chaine correspond à un opérateur de pile, -1 sinon.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

int estUnOperateurPile(const string& s);

/*!
*  \brief estUnOperateurBinaire: renvoie un entier positif si la chaine correspond à un opérateur de binaire, -1 sinon.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

int estUnOperateurBinaire(const string& s);

/*!
*  \brief estUnOperateurUnaire: renvoie un entier positif si la chaine correspond à un opérateur de unaire, -1 sinon.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

int estUnOperateurUnaire(const string& s);

/*!
*  \brief estUneExpression: renvoie True si la chaine est une expression.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

bool estUneExpression(const string& s);


/*!
*  \brief estUnAtome: renvoie True si la chaine correspond à la création d'un atome
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

bool estUnAtome(const string& s);


/*!
*  \brief estUnProgramme: renvoie True si la chaine est une littérale programme.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

bool estUnProgramme(const string& s);

/*!
*  \brief estUnIdentifiant: renvoie True si la chaine est un identifiant de variable ou de programme.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

bool estUnIdentifiant(const string& s);

/*!
*  \brief estUnEntier: renvoie True si la chaine correspond à une littérale de type entier.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/


bool estUnEntier(const string& s);

/*!
*  \brief estUnReel: renvoie True si la chaine correspond à une littérale de type réel.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/


bool estUnReel(const string& s);

/*!
*  \brief estUnRationnel: renvoie True si la chaine correspond à une littérale de type rationnel.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

bool estUnRationnel(const string& s);


/*!
*  \brief estUnComplexe: renvoie True si la chaine correspond à une littérale de type complexe.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

bool estUnComplexe(const string& s);


/*!
*  \brief estUneAssignation: renvoie True si la chaine correspond à une assignation de variable.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

//bool estUneAssignation(const string& s);

/*!
*  \brief estUneAssignationProg: renvoie True si la chaine correspond à une assignation de programme.
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

//bool estUneAssignationProg(const string& s);

/*!
*  \brief estUneSuppression: renvoie True si la chaine correspond à une suppression de variable ou de programme
*  \param s, un référence constante sur une string. C'est la chaine à tester.
*/

bool estUneSuppression(const string& s);




