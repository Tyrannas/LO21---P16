#include <string>
#include <iostream>
#include <sstream>

class Litterale {
public:
	virtual void affiche();
	virtual Litterale getValue();
};

class Numerique : public Litterale {
public:
	virtual void neg();
};

class Entiere : public Numerique {
private:
	int val;
public:
	Entiere(int v) : val(v) {};
	int getVal() const { return val; }

};

class Reelle : public Numerique {
private:
	float val;
public:
	Reelle(float v) : val(v) {};
	Entiere toEntiere();
	float getVal() const { return val; }

};

class Rationnelle : public Numerique {
private:
	Entiere num;
	Entiere den;
public:
	Rationnelle(Entiere e1, Entiere e2) :num(e1), den(e2) {};
	void simplification();
	Entiere toEntiere();
	Entiere getNum() const { return num; }
	Entiere getDen() const { return den; }
};

class Complexe : public Litterale {
private:
	Numerique re;
	Numerique im;
public:
	Complexe(Numerique r, Numerique i) : re(r), im(i) {};
	Numerique getRe() const { return re; }
	Numerique getIm() const { return im; }
};