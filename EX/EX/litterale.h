#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Litterale {
public:
	//virtual Litterale getValue();
	virtual void affiche() const = 0;
};

class Numerique : public Litterale {
public:
	//virtual void neg();
	virtual void affiche() const =0;
};

class Entiere : public Numerique {
private:
	int val;
public:
	Entiere(int v) : val(v) {};
	int getVal() const { return val; }
	void affiche() const { cout << val; }
	void neg() { val = -val; }
	void setVal(int i) { val = i; }
};

class Reelle : public Numerique {
private:
	double val;
public:
	Reelle(double v) : val(v) {};
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
	Rationnelle(Entiere e1, Entiere e2) :num(e1), den(e2) {};
	void simplification();
	Entiere toEntiere() {
		if (den.getVal() == 1)
			return Entiere(num.getVal());
	};
	Reelle toReelle() { return Reelle((num.getVal()/(double)den.getVal())); }
	Entiere getNum() const { return num; }
	Entiere getDen() const { return den; }
	void affiche() const { cout << num.getVal() << "/" << den.getVal(); }
};

class Complexe : public Litterale {
private:
	Numerique* re;
	Numerique* im;
public:
	Complexe(Numerique* r, Numerique* i) : re(r), im(i) {};
	Numerique* getRe() const { return re; }
	Numerique* getIm() const { return im; }
	void affiche() const { 
		(*re).affiche();
		cout << "$";
		(*im).affiche(); 
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
