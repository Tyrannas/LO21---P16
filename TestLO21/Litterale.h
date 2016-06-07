#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/*!
* \file Controleur.h
* \brief Ensemble des classes litterales
* \author Felix ALIE & Clement ROUTIER
* \version 1
*/




typedef enum
{
	tUndefined,
	tEntiere,
	tReelle,
	tRationnelle,
	tComplexe, 
	tAtome,
	tExpression,
	tProgramme
}TypeLitterale;


/*! \class Litterale
* \brief Classe abstraite representant toutes les litterales pouvant etres stockees
*/
class Litterale {
protected:
	TypeLitterale type; /*!< type precis de la litterale correspondant a un element d'une liste enumeree*/
public:
	/*!
	*  \brief Constructeur
	*/
	Litterale() : type(TypeLitterale::tUndefined) {};
	/*!
	*  \brief Affiche : Methode virtuelle pure pour l'affichage d'une litterale
	*/
	virtual void affiche() const = 0;
	/*!
	*  \brief Accesseur
	*  \return value : type precis de la litterale correspondant a un element d'une liste enumeree
	*/
	TypeLitterale getType() const { return type; }
	/*!
	*  \brief Clone : Methode virtuelle pure permettant de dupliquer un pointeur sur litterale
	*/
	virtual Litterale* clone() = 0;
	/*!
	*  \brief Surchage operateur==
	*/
	bool operator==(Litterale* l);
	/*!
	*  \brief Surchage operateur!=
	*/
	bool operator!=(Litterale* l);
	/*!
	*  \brief Surchage operateur<
	*/
	bool operator<(Litterale* l);
	/*!
	*  \brief Surchage operateur>
	*/
	bool operator>(Litterale* l);
	/*!
	*  \brief Surchage operateur<=
	*/
	bool operator<=(Litterale* l);
	/*!
	*  \brief Surchage operateur>=
	*/
	bool operator>=(Litterale* l);
};


/*! \class Expression
* \brief Classe representant une expression, c'est a dire une suite d'operations (heritage de Litterale)
*/
class Expression : public Litterale{
private:
	string expr; /*!< chaine de caractere representant le contenu de l'expression*/
public:
	/*!
	*  \brief Constructeur
	*  \param s : chaine de caractere representant le contenu de l'expression
	*/
	Expression(string s) : expr(s) { this->type = TypeLitterale::tExpression; }
	/*!
	*  \brief Accesseur
	*  \return chaine de caractere representant le contenu de l'expression
	*/
	const string getExpr() const { return expr; }
	/*!
	*  \brief Redefinition de la fonction d'affichage
	*/
	void affiche() const { 
		if (expr.length() > 20)
			cout << string(expr.begin(), expr.begin() + 16) << "...'";
		else
			cout << expr;
	}
	/*!
	*  \brief Redefinition de la fonction de clonage
	*/
	Expression* clone() { return new Expression(*this); }
};

/*! \class Programme
* \brief Classe representant un programme, c'est a dire une suite d'instructions (heritage de Litterale)
*/
class Programme : public Litterale {
private:
	string prog; /*!< chaine de caracteres representant le contenu du programme*/
public:
	/*!
	*  \brief Constructeur
	*  \param s : chaine de caractere representant le contenu du programme
	*/
	Programme(string s) : prog(s) { this->type = TypeLitterale::tProgramme; }
	/*!
	*  \brief Redefinition de la fonction d'affichage
	*/
	void affiche() const {
		if (prog.length() > 20)
			cout << string(prog.begin(), prog.begin() + 16) << "...]";
		else
			cout << prog;
	}
	/*!
	*  \brief Accesseur
	*  \return chaine de caracteres representant le contenu du programme
	*/
	string getProg() { return prog; }
	/*!
	*  \brief Editeur : permet de modifier le contenu du programme
	*  \param s : chaine de caracteres representant le nouveau contenu du programme
	*/
	void edit(string s) {prog = s;}
	/*!
	*  \brief Redefinition de la fonction de clonage
	*/
	Programme* clone() { return new Programme(*this); }
};

/*! \class Atome
* \brief Classe representant un atome, c'est a dire un identificateur (heritage de Litterale)
*/
class Atome : public Litterale {
private:
	string id; /*!< chaine de caractere representant l'identifiant*/
public:
	/*!
	*  \brief Constructeur
	*/
	Atome() { this->type = TypeLitterale::tAtome; }
	/*!
	*  \brief Accesseur
	*  \return chaine de caractere representant l'identifiant
	*/
	const string getId() const { return id; }
	/*!
	*  \brief Redefinition de la fonction d'affichage
	*/
	void affiche() const { cout << id; }
	/*!
	*  \brief Redefinition de la fonction de clonage
	*/
	Atome* clone() { return new Atome(*this); }
};


/*! \class Numerique
* \brief Classe abstraite representant un numerique, c'est a dire un nombre autre que complexe (heritage de Litterale)
*/
class Numerique : public Litterale {
public:
	/*!
	*  \brief Redefinition de la fonction d'affichage
	*/
	virtual void affiche() const = 0;
	/*!
	*  \brief Methode virtuelle pure permettant l'inversion du signe de la litterale
	*/
	virtual void neg() = 0;
	/*!
	*  \brief Redefinition de la fonction de clonage
	*/
	virtual Numerique* clone() = 0;
	/*!
	*  \brief Methode virtuelle pure permettant la recuperation de la valeur de la litterale sous forme de double pour comparaison
	*/
	virtual double getComp() = 0;
};

/*! \class Entiere
* \brief Classe representant un nombre entier (heritage de Numerique)
*/
class Entiere : public Numerique {
private:
	int val; /*!< valeur de la litterale entiere*/
public:
	/*!
	*  \brief Constructeur
	*  \param v : entier representant la valeur de la litterale
	*/
	Entiere(int v) : val(v) { this->type = TypeLitterale::tEntiere; }
	/*!
	*  \brief Accesseur
	*  \return s : entier representant la valeur de la litterale
	*/
	int getVal() const { return val; }
	/*!
	*  \brief Redefinition de la fonction d'affichage
	*/
	void affiche() const { cout << val; }
	/*!
	*  \brief Redefinition de la fonction d'inversion de signe
	*/
	void neg() { val = -val; }
	/*!
	*  \brief Editeur : permet de modifier la valeur de la litterale
	*  \param i : entier representant la nouvelle valeur de la litterale
	*/
	void setVal(int i) { val = i; }
	/*!
	*  \brief Redefinition de la fonction de clonage
	*/
	Entiere* clone() { return new Entiere(*this); }
	/*!
	*  \brief Redefinition de la fonction de comparaison
	*/
	double getComp() { return (double)val; }
};

/*! \class Reelle
* \brief Classe representant un nombre reel (heritage de Numerique)
*/
class Reelle : public Numerique {
private:
	double val; /*!< valeur de la litterale Reelle*/
public:
	/*!
	*  \brief Constructeur
	*  \param v : valeur de la litterale Reelle
	*/
	Reelle(double v) : val(v) { this->type = TypeLitterale::tReelle; };
	/*!
	*  \brief Construction d'une litterale Entiere a partir d'une litterale reelle
	*  \return litterale entiere
	*/
	Entiere toEntiere() {
		if (val - floor(val) == 0)
			return Entiere(floor(val));
	};
	/*!
	*  \brief Accesseur
	*  \return v : valeur de la litterale Reelle
	*/
	double getVal() const { return val; }
	/*!
	*  \brief Redefinition de la fonction d'affichage
	*/
	void affiche() const { cout << val; }
	/*!
	*  \brief Redefinition de la fonction de clonage
	*/
	Reelle* clone() { return new Reelle(*this); }
	/*!
	*  \brief Redefinition de la fonction d'inversion de signe
	*/
	void neg() { val = -val; }
	/*!
	*  \brief Redefinition de la fonction de comparaison
	*/
	double getComp() { return val; }
};

/*! \class Rationnelle
* \brief Classe representant un nombre rationnel (heritage de Numerique)
*/
class Rationnelle : public Numerique {
private:
	Entiere num; /*!< valeur du numerateur de la fraction (litterale entiere)*/
	Entiere den; /*!< valeur du denominateur de la fraction (litterale entiere)*/
public:
	/*!
	*  \brief Constructeur
	*  \param e1 : entiere representant le numerateur
	*  \param e2 : entiere representant le denominateur
	*/
	Rationnelle(Entiere e1, Entiere e2) :num(e1), den(e2) { this->type = TypeLitterale::tRationnelle; };
	/*!
	*  \brief Simplificateur de la fraction
	*/
	void simplification();
	/*!
	*  \brief Construction d'une litterale entiere a partir d'une litterale rationnelle
	*  \return litterale entiere
	*/
	Entiere toEntiere() {
		if (den.getVal() == 1)
			return Entiere(num.getVal());
	};
	/*!
	*  \brief Construction d'une litterale reelle a partir d'une litterale rationnelle
	*  \return litterale reelle
	*/
	Reelle toReelle() { return Reelle((num.getVal() / (double)den.getVal())); }
	/*!
	*  \brief Accesseur sur le numerateur
	*  \return valeur du numerateur de la fraction (litterale entiere)
	*/
	Entiere getNum() const { return num; }
	/*!
	*  \brief Accesseur sur le denominateur
	*  \return valeur du denominateur de la fraction (litterale entiere)
	*/
	Entiere getDen() const { return den; }
	/*!
	*  \brief Redefinition de la fonction d'affichage
	*/
	void affiche() const { cout << num.getVal() << "/" << den.getVal(); }
	/*!
	*  \brief Redefinition de la fonction de clonage
	*/
	Rationnelle* clone() { return new Rationnelle(*this); }
	/*!
	*  \brief Redefinition de la fonction d'inversion de signe
	*/
	void neg() { num.neg(); this->simplification(); }
	/*!
	*  \brief Redefinition de la fonction de clonage
	*/
	double getComp() { return this->toReelle().getComp(); }
};

/*! \class Complexe
* \brief Classe representant un nombre complexe (heritage de Litterale)
*/
class Complexe : public Litterale {
private:
	Numerique* re; /*!< valeur de la partie reelle du complexe (litterale numerique quelconque)*/
	Numerique* im; /*!< valeur de la partie imaginaire du complexe (litterale numerique quelconque)*/
public:
	/*!
	*  \brief Constructeur
	*  \param r : pointeur sur la litterale nuemerique representant la partie reelle
	*  \param i : pointeur sur la litterale nuemerique representant la partie imaginaire
	*/
	Complexe(Numerique* r, Numerique* i = nullptr) : re(r), im(i) { this->type = TypeLitterale::tComplexe; };
	/*!
	*  \brief Accesseur sur la partie reelle
	*  \return valeur de la partie reelle du complexe (litterale numerique quelconque
	*/
	Numerique* getRe() const { return re; }
	/*!
	*  \brief Accesseur sur la partie imaginaire
	*  \return valeur de la partie imaginaire du complexe (litterale numerique quelconque
	*/
	Numerique* getIm() const { return im; }
	/*!
	*  \brief Redefinition de la fonction d'affichage
	*/
	void affiche() const {
		(*re).affiche();
		cout << "$";
		if(im != nullptr) (*im).affiche();
	}
	/*!
	*  \brief Redefinition de la fonction de clonage
	*/
	Complexe* clone() { return new Complexe(*this); }
	/*!
	*  \brief Redefinition de la fonction d'inversion de signe
	*/
	void neg() { re->neg(); im->neg(); }
};


Entiere operator+(Entiere e1, Entiere e2);
Reelle operator+(Entiere e, Reelle r);
Rationnelle operator+(Entiere e, Rationnelle r);

Rationnelle operator+(Rationnelle r1, Rationnelle r2);
Reelle operator+(Rationnelle ra, Reelle re);
Rationnelle operator+(Rationnelle r, Entiere e);

Reelle operator+(Reelle r1, Reelle r2);
Reelle operator+(Reelle r, Entiere e);
Reelle operator+(Reelle re, Rationnelle ra);

Complexe operator+(Complexe& c, Entiere e);


/*!
*  \brief Surchage operateur+ sur deux litterales
*  \param l1 : reference sur la premiere litterale
*  \param l2 : reference sur la deuxieme litterale
*/
Litterale* operator+(Litterale& l1, Litterale& l2);

/*!
*  \brief Operateur DIV (division entiere) sur deux litterales
*  \param l1 : reference sur la premiere litterale
*  \param l2 : reference sur la deuxieme litterale
*/
Entiere* div(Litterale& l1, Litterale& l2);

/*!
*  \brief Operateur MOD (reste de la division entiere) sur deux litterales
*  \param l1 : reference sur la premiere litterale
*  \param l2 : reference sur la deuxieme litterale
*/
Entiere* mod(Litterale& l1, Litterale& l2);

/*!
*  \brief Operateur NUM (accesseur sur le numerateur)
*  \param l : reference sur une litterale
*/
Entiere* num(Litterale& l);
/*!
*  \brief Operateur DEN (accesseur sur le denominateur)
*  \param l : reference sur une litterale
*/
Entiere* den(Litterale& l);

/*!
*  \brief Operateur $ (constructeur d'un complexe a partir de deux litterales numeriques)
*  \param l1 : reference sur la premiere litterale
*  \param l2 : reference sur la deuxieme litterale
*/
Complexe* dollar(Litterale& l1, Litterale& l2);

/*!
*  \brief Operateur RE (accesseur sur la partie reelle)
*  \param l : reference sur une litterale
*/
Litterale* re(Litterale& l);
/*!
*  \brief Operateur IM (accesseur sur la partie imaginaire)
*  \param l : reference sur une litterale
*/
Litterale* im(Litterale& l);

/*!
*  \brief Operateur OR (test booleen "OU")
*  \param b1 : premiere expression booleenne
*  \param b2 : deuxieme expression booleenne
*/
bool boolOr(bool b1, bool b2);
/*!
*  \brief Operateur AND (test booleen "ET")
*  \param b1 : premiere expression booleenne
*  \param b2 : deuxieme expression booleenne
*/
bool boolAnd(bool b1, bool b2);
/*!
*  \brief Operateur NOT (test booleen "NON")
*  \param b : expression booleenne
*/
bool boolNot(bool b);
