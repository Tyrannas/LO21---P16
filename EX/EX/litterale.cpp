#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "computer.h"



void Rationnelle::simplification() {
	// si le numerateur est 0, le denominateur prend la valeur 1
	if (num.getVal() == 0) {
		den = 1;
		return;
	}
	/* un denominateur ne devrait pas être 0;
	si c’est le cas, on sort de la méthode */
	if (num.getVal() == 0)
		return;
	/* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
	Denominateur (PGCD) entre le numerateur et le denominateur */
	Entiere a(num); 
	Entiere b(den);
	// on ne travaille qu’avec des valeurs positives...
	if (a.getVal() < 0)
		a.neg();
	if (b.getVal() < 0)
		b.neg();
	while (a.getVal() != b.getVal()) {
		if (a.getVal() > b.getVal())
			a.setVal(a.getVal() - b.getVal());
		else
			b.setVal(b.getVal() - a.getVal());
	}
	// on divise le numerateur et le denominateur par le PGCD=a
	num.setVal(num.getVal()/a.getVal());
	den.setVal(den.getVal()/a.getVal());
	// si le denominateur est négatif, on fait passer le signe - au denominateur
	if (den.getVal()<0) {
		den.neg();
		num.neg();
	}
}

// OPERATION SUR LITTERALE ENTIERE

Reelle operator+(Entiere e, Reelle r){ 
	return Reelle((double)e.getVal() + r.getVal()); 
}

Entiere operator+(Entiere e1, Entiere e2) {
	return Entiere(e1.getVal() + e2.getVal());
}

Rationnelle operator+(Entiere e, Rationnelle r) {
	return Rationnelle(e.getVal()*r.getDen().getVal()+r.getNum().getVal(), r.getDen().getVal());
}


// OPERATION SUR LITTERALE RATIONNELLE

Reelle operator+(Rationnelle ra, Reelle re) {
	return Reelle(ra.toReelle().getVal() + re.getVal());
}

Rationnelle operator+(Rationnelle r1, Rationnelle r2) {
	return Rationnelle(r1.getNum().getVal()*r2.getDen().getVal()+r2.getNum().getVal()*r1.getDen().getVal(),r1.getDen().getVal()*r2.getDen().getVal());
}

Rationnelle operator+(Rationnelle r, Entiere e) {
	return Rationnelle(e.getVal()*r.getDen().getVal() + r.getNum().getVal(), r.getDen().getVal());
}


// OPERATION SUR LITTERALE REELLE

Reelle operator+(Reelle r1, Reelle r2) {
	return Reelle(r1.getVal() + r2.getVal());
}

Reelle operator+(Reelle re, Rationnelle ra) {
	return Reelle(ra.toReelle().getVal() + re.getVal());
}

Reelle operator+(Reelle r, Entiere e) {
	return Reelle((double)e.getVal() + r.getVal());
}