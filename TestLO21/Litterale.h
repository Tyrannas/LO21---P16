#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

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

class Litterale {
protected:
	TypeLitterale type;
public:
	//virtual Litterale getValue();
	virtual void affiche() const = 0;
	TypeLitterale getType() const { return type; }
	Litterale() : type(TypeLitterale::tUndefined) {};
};

class Expression : public Litterale{
private:
	string expr;
public:
	const string getExpr() const { return expr; }
	void affiche() const { 
		if (expr.length() > 20)
			cout << string(expr.begin(), expr.begin() + 16) << "...'";
		else
			cout << expr;
	}
	Expression(string s) : expr(s) { this->type = TypeLitterale::tExpression; }
};

class Programme : public Litterale {
private:
	string prog;
public:
	void affiche() const {
		if (prog.length() > 20)
			cout << string(prog.begin(), prog.begin() + 16) << "...]";
		else
			cout << prog;
	}
	string getProg() { return prog; }
	Programme(string s) : prog(s) { this->type = TypeLitterale::tProgramme; }
};

class Atome : public Litterale {
private:
	string id;
public:
	const string getId() const { return id; }
	Atome() { this->type = TypeLitterale::tAtome; };
	void affiche() const { cout << id; }
};


class Numerique : public Litterale {
public:
	//virtual void neg();
	virtual void affiche() const = 0;
};

class Entiere : public Numerique {
private:
	int val;
public:
	Entiere(int v) : val(v) { this->type = TypeLitterale::tEntiere; }
	int getVal() const { return val; }
	void affiche() const { cout << val; }
	void neg() { val = -val; }
	void setVal(int i) { val = i; }
};

class Reelle : public Numerique {
private:
	double val;
public:
	Reelle(double v) : val(v) { this->type = TypeLitterale::tReelle; };
	Entiere toEntiere() {
		if (val - floor(val) == 0)
			return Entiere(floor(val));
	};
	double getVal() const { return val; }
	void affiche() const { cout << val; }
};

class Rationnelle : public Numerique {
private:
	Entiere num;
	Entiere den;
public:
	Rationnelle(Entiere e1, Entiere e2) :num(e1), den(e2) { this->type = TypeLitterale::tRationnelle; };
	void simplification();
	Entiere toEntiere() {
		if (den.getVal() == 1)
			return Entiere(num.getVal());
	};
	Reelle toReelle() { return Reelle((num.getVal() / (double)den.getVal())); }
	Entiere getNum() const { return num; }
	Entiere getDen() const { return den; }
	void affiche() const { cout << num.getVal() << "/" << den.getVal(); }
};

class Complexe : public Litterale {
private:
	Numerique* re;
	Numerique* im;
public:
	Complexe(Numerique* r, Numerique* i = nullptr) : re(r), im(i) { this->type = TypeLitterale::tComplexe; };
	Numerique* getRe() const { return re; }
	Numerique* getIm() const { return im; }
	void affiche() const {
		(*re).affiche();
		cout << "$";
		if(im != nullptr) (*im).affiche();
	}
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


Litterale* operator+(Litterale& l1, Litterale& l2);

// Operations


Entiere* div(Litterale& l1, Litterale& l2);
Entiere* mod(Litterale& l1, Litterale& l2);

Entiere* num(Litterale& l);
Entiere* den(Litterale& l);

Complexe* dollar(Litterale& l1, Litterale& l2);

Numerique* re(Litterale& l);
Numerique* im(Litterale& l);

bool boolOr(bool b1, bool b2);
bool boolAnd(bool b1, bool b2);
bool boolNot(bool b);
