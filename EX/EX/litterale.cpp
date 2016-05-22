#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "computer.h"
#include "litterale.h"



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

// OPERATION SUR LITTERALE COMPLEXE

Complexe operator+(Complexe& c, Entiere e) {
	return c;
}




Litterale* operator+(Litterale& l1, Litterale& l2) {
	// Recherche du type de la première litterale
	TypeLitterale type1 = l1.getType();
	// Si c'est un entier
	if (type1 == tEntiere)
		Entiere* pt1 = dynamic_cast<Entiere*>(&l1);
	// Si c'est un reel
	else if (type1 == tReelle)
		Reelle* pt1 = dynamic_cast<Reelle*>(&l1);
	// Si c'est un rationnel
	else if (type1 == tRationnelle)
		Rationnelle* pt1 = dynamic_cast<Rationnelle*>(&l1);
	// Si c'est un complexe
	else if (type1 == tComplexe){
		// On cherche le type de la partie réelle
		Complexe* pt1 = dynamic_cast<Complexe*>(pt1->getRe);
		if (pt1->getRe.getType() == tEntiere)
			Entiere* pRe = dynamic_cast<Entiere*>(pt1->getRe);
		else if (pt1->getRe.getType() == tReelle)
			Reelle* pRe = dynamic_cast<Reelle*>(pt1->getRe);
		else if (pt1->getRe.getType() == tRationnelle)
			Rationnelle* pRe = dynamic_cast<Rationnelle*>(pt1->getRe);
		// Puis on cherche le type de la partie imaginaire
		if (pt1->getIm.getType() == tEntiere)
			Entiere* pIm = dynamic_cast<Entiere*>(pt1->getIm);
		else if (pt1->getIm.getType() == tReelle)
			Reelle* pIm = dynamic_cast<Reelle*>(pt1->getIm);
		else if (pt1->getIm.getType() == tRationnelle)
			Rationnelle* pIm = dynamic_cast<Rationnelle*>(pt1->getIm);


		// Recherche du type de la deuxieme litterale
		TypeLitterale type2 = l2.getType();
		// Si c'est un entier
		if (type2 == tEntiere)
			Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
		// Si c'est un reel
		else if (type2 == tReelle)
			Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
		// Si c'est un rationnel
		else if (type2 == tRationnelle)
			Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
		// Si c'est un complexe
		else if (type2 == tComplexe) {
			// On cherche le type de la partie réelle
			Complexe* pt2 = dynamic_cast<Complexe*>(pt2->getRe);
			if (pt2->getRe.getType() == tEntiere)
				Entiere* pRe = dynamic_cast<Entiere*>(pt2->getRe);
			else if (pt2->getRe.getType() == tReelle)
				Reelle* pRe = dynamic_cast<Reelle*>(pt2->getRe);
			else if (pt2->getRe.getType() == tRationnelle)
				Rationnelle* pRe = dynamic_cast<Rationnelle*>(pt2->getRe);
			// Puis on cherche le type de la partie imaginaire
			if (pt2->getIm.getType() == tEntiere)
				Entiere* pIm = dynamic_cast<Entiere*>(pt2->getIm);
			else if (pt2->getIm.getType() == tReelle)
				Reelle* pIm = dynamic_cast<Reelle*>(pt2->getIm);
			else if (pt2->getIm.getType() == tRationnelle)
				Rationnelle* pIm = dynamic_cast<Rationnelle*>(pt2->getIm);

	}
	/*
	Entiere* pt1 = dynamic_cast<Entiere*>(&l1);
	Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
	if (pt1 != 0 && pt2 != 0) {
		Entiere* result = new Entiere(pt1->getVal() + pt2->getVal());
		return result;
	}
	if (pt1 != 0 && pt2 == 0) {
		Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
		if (pt1 != 0 && pt2 != 0) {
			Rationnelle* result = new Rationnelle(pt1->getVal() * pt2->getDen().getVal() + pt2->getNum().getVal(), pt2->getDen().getVal());
			return result;
		}
		else {
			Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
			if (pt1 != 0 && pt2 != 0) {
				Reelle* result = new Reelle((double)pt1->getVal() + pt2->getVal());
				return result;
			}
			else {
				Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
				if (pt1 != 0 && pt2 != 0) {
					Complexe* result = new Complexe(pt1->getVal() + pt2->getRe(), pt2->getIm());
					return result;
				}
			}
		}
	}
	else throw "YOLO";
	*/
}