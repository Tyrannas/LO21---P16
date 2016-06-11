#include "Litterale.h"
#include "ComputerException.h"



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
	num.setVal(num.getVal() / a.getVal());
	den.setVal(den.getVal() / a.getVal());
	// si le denominateur est négatif, on fait passer le signe - au denominateur
	if (den.getVal()<0) {
		den.neg();
		num.neg();
	}
}

/*
// OPERATION SUR LITTERALE ENTIERE

Reelle operator+(Entiere e, Reelle r) {
	return Reelle((double)e.getVal() + r.getVal());
}

Entiere operator+(Entiere e1, Entiere e2) {
	return Entiere(e1.getVal() + e2.getVal());
}

Rationnelle operator+(Entiere e, Rationnelle r) {
	return Rationnelle(e.getVal()*r.getDen().getVal() + r.getNum().getVal(), r.getDen().getVal());
}


// OPERATION SUR LITTERALE RATIONNELLE

Reelle operator+(Rationnelle ra, Reelle re) {
	return Reelle(ra.toReelle().getVal() + re.getVal());
}

Rationnelle operator+(Rationnelle r1, Rationnelle r2) {
	return Rationnelle(r1.getNum().getVal()*r2.getDen().getVal() + r2.getNum().getVal()*r1.getDen().getVal(), r1.getDen().getVal()*r2.getDen().getVal());
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


*/

Litterale* operator+(Litterale& l1, Litterale& l2) {

	// Recherche du type de la première litterale
	TypeLitterale type1 = l1.getType();
	// Recherche du type de la deuxieme litterale
	TypeLitterale type2 = l2.getType();

	/*****************************************************************************************/

	// Si la première litterale est un entier
	if (type1 == tEntiere) {
		Entiere* pt1 = dynamic_cast<Entiere*>(&l1);
		// Et que la deuxième est un entier
		if (type2 == tEntiere) {
			Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
			return (new Entiere(pt1->getVal() + pt2->getVal()));
		}
		// Et que la deuxième est un reel
		if (type2 == tReelle) {
			Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
			return (new Reelle((double)pt1->getVal() + pt2->getVal()));
		}
		// Et que la deuxième est un rationnel
		if (type2 == tRationnelle) {
			Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
			return (new Rationnelle(pt1->getVal()*pt2->getDen().getVal() + pt2->getNum().getVal(), +pt2->getDen().getVal()));
		}
		// Et que la deuxième est un complexe
		if (type2 == tComplexe) {
			Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
			Numerique* pRe = pt2->getRe();
			// Et que la partie réelle du complexe est un entier
			if (pRe->getType() == tEntiere) {
				Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
				Entiere* newpRe = new Entiere(pt1->getVal() + pt3->getVal());
				return (new Complexe(newpRe, pt2->getIm()));
			}
			// Et que la partie réelle du complexe est un reel
			if (pRe->getType() == tReelle) {
				Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
				Reelle* newpRe = new Reelle((double)pt1->getVal() + pt3->getVal());
				return (new Complexe(newpRe, pt2->getIm()));
			}
			// Et que la partie réelle du complexe est un rationnel
			if (pRe->getType() == tRationnelle) {
				Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
				Rationnelle* newpRe = new Rationnelle(pt1->getVal()*pt3->getDen().getVal() + pt3->getNum().getVal(), +pt3->getDen().getVal());
				return (new Complexe(newpRe, pt2->getIm()));
			}
		}
	}

	/*****************************************************************************************/

	// Si la première litterale est un reel
	if (type1 == tReelle) {
		Reelle* pt1 = dynamic_cast<Reelle*>(&l1);
		// Et que la deuxième est un entier
		if (type2 == tEntiere) {
			Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
			return (new Reelle(pt1->getVal() + (double)pt2->getVal()));
		}
		// Et que la deuxième est un reel
		if (type2 == tReelle) {
			Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
			return (new Reelle(pt1->getVal() + pt2->getVal()));
		}
		// Et que la deuxième est un rationnel
		if (type2 == tRationnelle) {
			Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
			return (new Reelle(pt1->getVal() + pt2->toReelle().getVal()));
		}
		// Et que la deuxième est un complexe
		if (type2 == tComplexe) {
			Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
			Numerique* pRe = pt2->getRe();
			// Et que la partie réelle du complexe est un entier
			if (pRe->getType() == tEntiere) {
				Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
				Reelle* newpRe = new Reelle(pt1->getVal() + (double)pt3->getVal());
				return (new Complexe(newpRe, pt2->getIm()));
			}
			// Et que la partie réelle du complexe est un reel
			if (pRe->getType() == tReelle) {
				Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
				Reelle* newpRe = new Reelle(pt1->getVal() + pt3->getVal());
				return (new Complexe(newpRe, pt2->getIm()));
			}
			// Et que la partie réelle du complexe est un rationnel
			if (pRe->getType() == tRationnelle) {
				Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
				Reelle* newpRe = new Reelle(pt1->getVal() + pt3->toReelle().getVal());
				return (new Complexe(newpRe, pt2->getIm()));
			}
		}
	}


	/*****************************************************************************************/

	// Si la première litterale est un rationnel
	if (type1 == tRationnelle) {
		Rationnelle* pt1 = dynamic_cast<Rationnelle*>(&l1);
		// Et que la deuxième est un entier
		if (type2 == tEntiere) {
			Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
			return (new Rationnelle(pt2->getVal()*pt1->getDen().getVal() + pt1->getNum().getVal(), pt1->getDen().getVal()));
		}
		// Et que la deuxième est un reel
		if (type2 == tReelle) {
			Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
			return (new Reelle(pt1->toReelle().getVal() + pt2->getVal()));
		}
		// Et que la deuxième est un rationnel
		if (type2 == tRationnelle) {
			Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
			return (new Rationnelle(pt1->getNum().getVal()*pt2->getDen().getVal() + pt2->getNum().getVal()*pt1->getDen().getVal(), pt1->getDen().getVal()*pt2->getDen().getVal()));
		}
		// Et que la deuxième est un complexe
		if (type2 == tComplexe) {
			Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
			Numerique* pRe = pt2->getRe();
			// Et que la partie réelle du complexe est un entier
			if (pRe->getType() == tEntiere) {
				Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
				Rationnelle* newpRe = new Rationnelle(pt3->getVal()*pt1->getDen().getVal() + pt1->getNum().getVal(), pt1->getDen().getVal());
				return (new Complexe(newpRe, pt2->getIm()));
			}
			// Et que la partie réelle du complexe est un reel
			if (pRe->getType() == tReelle) {
				Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
				Reelle* newpRe = new Reelle(pt1->toReelle().getVal() + pt3->getVal());
				return (new Complexe(newpRe, pt2->getIm()));
			}
			// Et que la partie réelle du complexe est un rationnel
			if (pRe->getType() == tRationnelle) {
				Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
				Rationnelle* newpRe = new Rationnelle(pt1->getNum().getVal()*pt3->getDen().getVal() + pt3->getNum().getVal()*pt1->getDen().getVal(), pt1->getDen().getVal()*pt3->getDen().getVal());
				return (new Complexe(newpRe, pt2->getIm()));
			}
		}
	}


	/*****************************************************************************************/

	// Si la première litterale est un complexe
	if (type1 == tComplexe) {
		Complexe* pt1 = dynamic_cast<Complexe*>(&l1);
		// On récupère le type de la partie réelle
		Numerique* pRe1 = pt1->getRe();
		// Si la partie réelle est un entier
		if (pRe1->getType() == tEntiere) {
			Entiere* ptx1 = dynamic_cast<Entiere*>(pRe1);
			// et que la deuxième est un entier
			if (type2 == tEntiere) {
				Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
				Entiere* newpRe = new Entiere(ptx1->getVal() + pt2->getVal());
				return (new Complexe(newpRe, pt1->getIm()));
			}
			// Et que la deuxième est un reel
			if (type2 == tReelle) {
				Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
				Reelle* newpRe = new Reelle((double)ptx1->getVal() + pt2->getVal());
				return (new Complexe(newpRe, pt1->getIm()));
			}
			// Et que la deuxième est un rationnel
			if (type2 == tRationnelle) {
				Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
				Rationnelle* newpRe = new Rationnelle(ptx1->getVal()*pt2->getDen().getVal() + pt2->getNum().getVal(), +pt2->getDen().getVal());
				return (new Complexe(newpRe, pt1->getIm()));
			}
			// Et que la deuxième est un complexe
		}
	}

}

Entiere* div(Litterale& l1, Litterale& l2) {
	if (l1.getType() == tEntiere && l2.getType() == tEntiere) {
		Entiere* pt1 = dynamic_cast<Entiere*>(&l1);
		Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
		return (new Entiere(pt1->getVal() / pt2->getVal()));
	}
	else
		throw ComputerException("Impossible d'effectuer DIV sur des litterales non entieres.\n");
}


Entiere* mod(Litterale& l1, Litterale& l2) {
	if (l1.getType() == tEntiere && l2.getType() == tEntiere) {
		Entiere* pt1 = dynamic_cast<Entiere*>(&l1);
		Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
		return (new Entiere(pt1->getVal() - ((pt1->getVal() / pt2->getVal()) * pt2->getVal())));
	}
	else
		throw ComputerException("Impossible d'effectuer MOD sur des litterales non entieres.\n");
}

Entiere* num(Litterale& l) {
	if (l.getType() == tRationnelle) {
		Rationnelle* pt1 = dynamic_cast<Rationnelle*>(&l);
		return (new Entiere(pt1->getNum()));
	}
	else if (l.getType() == tEntiere) {
		Entiere* pt1 = dynamic_cast<Entiere*>(&l);
		return pt1->clone();
	}
	else {
		throw ComputerException("Impossible d'effectuer NUM sur une litterale reelle ou complexe.\n");
	}
}

Entiere* den(Litterale& l) {
	if (l.getType() == tRationnelle) {
		Rationnelle* pt1 = dynamic_cast<Rationnelle*>(&l);
		return (new Entiere(pt1->getDen()));
	}
	else if (l.getType() == tEntiere) {
		return (new Entiere(1));
	}
	else
		throw ComputerException("Impossible d'effectuer DEN sur une litterale reelle ou complexe.\n");
}

Complexe* dollar(Litterale& l1, Litterale& l2) {
	if (l1.getType() != tComplexe && l2.getType() != tComplexe) {
		Numerique* pt1 = dynamic_cast<Numerique*>(&l1);
		Numerique* pt2 = dynamic_cast<Numerique*>(&l2);
		return (new Complexe(pt1->clone(), pt2->clone()));
	}
	else
		throw ComputerException("Impossible d'effectuer $ sur une litterale complexe.\n");
}

Litterale* re(Litterale& l) {
	if (l.getType() == tComplexe) {
		Complexe* pt1 = dynamic_cast<Complexe*>(&l);
		return pt1->getRe()->clone();
	}
	else {
		Numerique* pt1 = dynamic_cast<Numerique*>(&l);
		return pt1->clone();
	}
}

Litterale* im(Litterale& l) {
	if (l.getType() == tComplexe) {
		Complexe* pt1 = dynamic_cast<Complexe*>(&l);
		return pt1->getIm()->clone();
	}
	else {
		return (new Entiere(0));
	}
}

bool boolOr(bool b1, bool b2) {
	return (b1 || b2);
}

bool boolAnd(bool b1, bool b2) {
	return (b1 && b2);
}

bool boolNot(bool b) {
	return (!b);
}

/*
• =, !=, =<, >=, <, > : opérateurs binaires pour les tests respectivement égal, différent, inférieur ou égal,
supérieur ou égal, strictement inférieur, strictement supérieur.
*/



bool Litterale::operator==(Litterale * l)
{
	if ((l->getType() || this->getType()) == tExpression || (l->getType() || this->getType()) == tProgramme || (l->getType() || this->getType()) == tAtome || (l->getType() || this->getType()) == tComplexe)
		throw ComputerException("Impossible d'effectuer une comparaison sur ce type de Litterale\n");
	else {
		Numerique* pt1 = dynamic_cast<Numerique*>(this);
		Numerique* pt2 = dynamic_cast<Numerique*>(l);
		return (pt1->getComp() == pt2->getComp());
	}
}

bool Litterale::operator!=(Litterale * l)
{
	if ((l->getType() || this->getType()) == tExpression || (l->getType() || this->getType()) == tProgramme || (l->getType() || this->getType()) == tAtome || (l->getType() || this->getType()) == tComplexe)
		throw ComputerException("Impossible d'effectuer une comparaison sur ce type de Litterale\n");
	else {
		Numerique* pt1 = dynamic_cast<Numerique*>(this);
		Numerique* pt2 = dynamic_cast<Numerique*>(l);
		return (pt1->getComp() != pt2->getComp());
	}
}

bool Litterale::operator<(Litterale * l)
{
	if ((l->getType() || this->getType()) == tExpression || (l->getType() || this->getType()) == tProgramme || (l->getType() || this->getType()) == tAtome || (l->getType() || this->getType()) == tComplexe)
		throw ComputerException("Impossible d'effectuer une comparaison sur ce type de Litterale\n");
	else {
		Numerique* pt1 = dynamic_cast<Numerique*>(this);
		Numerique* pt2 = dynamic_cast<Numerique*>(l);
		return (pt1->getComp() < pt2->getComp());
	}
}

bool Litterale::operator>(Litterale * l)
{
	if ((l->getType() || this->getType()) == tExpression || (l->getType() || this->getType()) == tProgramme || (l->getType() || this->getType()) == tAtome || (l->getType() || this->getType()) == tComplexe)
		throw ComputerException("Impossible d'effectuer une comparaison sur ce type de Litterale\n");
	else {
		Numerique* pt1 = dynamic_cast<Numerique*>(this);
		Numerique* pt2 = dynamic_cast<Numerique*>(l);
		return (pt1->getComp() > pt2->getComp());
	}
}

bool Litterale::operator<=(Litterale * l)
{
	if ((l->getType() || this->getType()) == tExpression || (l->getType() || this->getType()) == tProgramme || (l->getType() || this->getType()) == tAtome || (l->getType() || this->getType()) == tComplexe)
		throw ComputerException("Impossible d'effectuer une comparaison sur ce type de Litterale\n");
	else {
		Numerique* pt1 = dynamic_cast<Numerique*>(this);
		Numerique* pt2 = dynamic_cast<Numerique*>(l);
		return (pt1->getComp() <= pt2->getComp());
	}
}

bool Litterale::operator>=(Litterale * l)
{
	if ((l->getType() || this->getType()) == tExpression || (l->getType() || this->getType()) == tProgramme || (l->getType() || this->getType()) == tAtome || (l->getType() || this->getType()) == tComplexe)
		throw ComputerException("Impossible d'effectuer une comparaison sur ce type de Litterale\n");
	else {
		Numerique* pt1 = dynamic_cast<Numerique*>(this);
		Numerique* pt2 = dynamic_cast<Numerique*>(l);
		return (pt1->getComp() >= pt2->getComp());
	}
}

Litterale* operator-(Litterale& l1, Litterale& l2) {

    // Recherche du type de la première litterale
    TypeLitterale type1 = l1.getType();
    // Recherche du type de la deuxieme litterale
    TypeLitterale type2 = l2.getType();

    /*****************************************************************************************/

    // Si la première litterale est un entier
    if (type1 == tEntiere) {
        Entiere* pt1 = dynamic_cast<Entiere*>(&l1);
        // Et que la deuxième est un entier
        if (type2 == tEntiere) {
            Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
            return (new Entiere(pt1->getVal() - pt2->getVal()));
        }
        // Et que la deuxième est un reel
        if (type2 == tReelle) {
            Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
            return (new Reelle((double)pt1->getVal() - pt2->getVal()));
        }
        // Et que la deuxième est un rationnel
        if (type2 == tRationnelle) {
            Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
            return (new Rationnelle(pt1->getVal()*pt2->getDen().getVal() - pt2->getNum().getVal(), pt2->getDen().getVal()));
        }
        // Et que la deuxième est un complexe
        if (type2 == tComplexe) {
            Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
            Numerique* pRe = pt2->getRe();
            // Et que la partie réelle du complexe est un entier
            if (pRe->getType() == tEntiere) {
                Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
                Entiere* newpRe = new Entiere(pt1->getVal() - pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un reel
            if (pRe->getType() == tReelle) {
                Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
                Reelle* newpRe = new Reelle((double)pt1->getVal() - pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un rationnel
            if (pRe->getType() == tRationnelle) {
                Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
                Rationnelle* newpRe = new Rationnelle(pt1->getVal()*pt3->getDen().getVal() - pt3->getNum().getVal(), pt3->getDen().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
        }
    }

    /*****************************************************************************************/

    // Si la première litterale est un reel
    if (type1 == tReelle) {
        Reelle* pt1 = dynamic_cast<Reelle*>(&l1);
        // Et que la deuxième est un entier
        if (type2 == tEntiere) {
            Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
            return (new Reelle(pt1->getVal() - (double)pt2->getVal()));
        }
        // Et que la deuxième est un reel
        if (type2 == tReelle) {
            Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
            return (new Reelle(pt1->getVal() - pt2->getVal()));
        }
        // Et que la deuxième est un rationnel
        if (type2 == tRationnelle) {
            Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
            return (new Reelle(pt1->getVal() - pt2->toReelle().getVal()));
        }
        // Et que la deuxième est un complexe
        if (type2 == tComplexe) {
            Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
            Numerique* pRe = pt2->getRe();
            // Et que la partie réelle du complexe est un entier
            if (pRe->getType() == tEntiere) {
                Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
                Reelle* newpRe = new Reelle(pt1->getVal() - (double)pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un reel
            if (pRe->getType() == tReelle) {
                Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
                Reelle* newpRe = new Reelle(pt1->getVal() - pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un rationnel
            if (pRe->getType() == tRationnelle) {
                Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
                Reelle* newpRe = new Reelle(pt1->getVal() - pt3->toReelle().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
        }
    }


    /*****************************************************************************************/

    // Si la première litterale est un rationnel
    if (type1 == tRationnelle) {
        Rationnelle* pt1 = dynamic_cast<Rationnelle*>(&l1);
        // Et que la deuxième est un entier
        if (type2 == tEntiere) {
            Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
            return (new Rationnelle(pt2->getVal()*pt1->getDen().getVal() - pt1->getNum().getVal(), pt1->getDen().getVal()));
        }
        // Et que la deuxième est un reel
        if (type2 == tReelle) {
            Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
            return (new Reelle(pt1->toReelle().getVal() - pt2->getVal()));
        }
        // Et que la deuxième est un rationnel
        if (type2 == tRationnelle) {
            Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
            return (new Rationnelle(pt1->getNum().getVal()*pt2->getDen().getVal() - pt2->getNum().getVal()*pt1->getDen().getVal(), pt1->getDen().getVal()*pt2->getDen().getVal()));
        }
        // Et que la deuxième est un complexe
        if (type2 == tComplexe) {
            Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
            Numerique* pRe = pt2->getRe();
            // Et que la partie réelle du complexe est un entier
            if (pRe->getType() == tEntiere) {
                Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
                Rationnelle* newpRe = new Rationnelle(pt3->getVal()*pt1->getDen().getVal() - pt1->getNum().getVal(), pt1->getDen().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un reel
            if (pRe->getType() == tReelle) {
                Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
                Reelle* newpRe = new Reelle(pt1->toReelle().getVal() - pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un rationnel
            if (pRe->getType() == tRationnelle) {
                Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
                Rationnelle* newpRe = new Rationnelle(pt1->getNum().getVal()*pt3->getDen().getVal() - pt3->getNum().getVal()*pt1->getDen().getVal(), pt1->getDen().getVal()*pt3->getDen().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
        }
    }


    /*****************************************************************************************/

    // Si la première litterale est un complexe
    if (type1 == tComplexe) {
        Complexe* pt1 = dynamic_cast<Complexe*>(&l1);
        // On récupère le type de la partie réelle
        Numerique* pRe1 = pt1->getRe();
        // Si la partie réelle est un entier
        if (pRe1->getType() == tEntiere) {
            Entiere* ptx1 = dynamic_cast<Entiere*>(pRe1);
            // et que la deuxième est un entier
            if (type2 == tEntiere) {
                Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
                Entiere* newpRe = new Entiere(ptx1->getVal() - pt2->getVal());
                return (new Complexe(newpRe, pt1->getIm()));
            }
            // Et que la deuxième est un reel
            if (type2 == tReelle) {
                Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
                Reelle* newpRe = new Reelle((double)ptx1->getVal() - pt2->getVal());
                return (new Complexe(newpRe, pt1->getIm()));
            }
            // Et que la deuxième est un rationnel
            if (type2 == tRationnelle) {
                Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
                Rationnelle* newpRe = new Rationnelle(ptx1->getVal()*pt2->getDen().getVal() - pt2->getNum().getVal(), pt2->getDen().getVal());
                return (new Complexe(newpRe, pt1->getIm()));
            }
            // Et que la deuxième est un complexe
        }
    }

}

Litterale* operator*(Litterale& l1, Litterale& l2) {

    // Recherche du type de la première litterale
    TypeLitterale type1 = l1.getType();
    // Recherche du type de la deuxieme litterale
    TypeLitterale type2 = l2.getType();

    /*****************************************************************************************/

    // Si la première litterale est un entier
    if (type1 == tEntiere) {
        Entiere* pt1 = dynamic_cast<Entiere*>(&l1);
        // Et que la deuxième est un entier
        if (type2 == tEntiere) {
            Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
            return (new Entiere(pt1->getVal() * pt2->getVal()));
        }
        // Et que la deuxième est un reel
        if (type2 == tReelle) {
            Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
            return (new Reelle((double)pt1->getVal() * pt2->getVal()));
        }
        // Et que la deuxième est un rationnel
        if (type2 == tRationnelle) {
            Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
            return (new Rationnelle(pt1->getVal()*pt2->getNum().getVal(), pt2->getDen().getVal()));
        }
        // Et que la deuxième est un complexe
        if (type2 == tComplexe) {
            Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
            Numerique* pRe = pt2->getRe();
            // Et que la partie réelle du complexe est un entier
            if (pRe->getType() == tEntiere) {
                Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
                Entiere* newpRe = new Entiere(pt1->getVal() * pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un reel
            if (pRe->getType() == tReelle) {
                Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
                Reelle* newpRe = new Reelle((double)pt1->getVal() * pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un rationnel
            if (pRe->getType() == tRationnelle) {
                Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
                Rationnelle* newpRe = new Rationnelle(pt1->getVal()*pt3->getNum().getVal(), pt3->getDen().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
        }
    }

    /*****************************************************************************************/

    // Si la première litterale est un reel
    if (type1 == tReelle) {
        Reelle* pt1 = dynamic_cast<Reelle*>(&l1);
        // Et que la deuxième est un entier
        if (type2 == tEntiere) {
            Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
            return (new Reelle(pt1->getVal() * (double)pt2->getVal()));
        }
        // Et que la deuxième est un reel
        if (type2 == tReelle) {
            Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
            return (new Reelle(pt1->getVal() * pt2->getVal()));
        }
        // Et que la deuxième est un rationnel
        if (type2 == tRationnelle) {
            Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
            return (new Reelle(pt1->getVal() * pt2->toReelle().getVal()));
        }
        // Et que la deuxième est un complexe
        if (type2 == tComplexe) {
            Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
            Numerique* pRe = pt2->getRe();
            // Et que la partie réelle du complexe est un entier
            if (pRe->getType() == tEntiere) {
                Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
                Reelle* newpRe = new Reelle(pt1->getVal() * (double)pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un reel
            if (pRe->getType() == tReelle) {
                Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
                Reelle* newpRe = new Reelle(pt1->getVal() * pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un rationnel
            if (pRe->getType() == tRationnelle) {
                Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
                Reelle* newpRe = new Reelle(pt1->getVal() * pt3->toReelle().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
        }
    }


    /*****************************************************************************************/

    // Si la première litterale est un rationnel
    if (type1 == tRationnelle) {
        Rationnelle* pt1 = dynamic_cast<Rationnelle*>(&l1);
        // Et que la deuxième est un entier
        if (type2 == tEntiere) {
            Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
            return (new Rationnelle(pt2->getVal()*pt1->getDen().getVal(), pt1->getDen().getVal()));
        }
        // Et que la deuxième est un reel
        if (type2 == tReelle) {
            Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
            return (new Reelle(pt1->toReelle().getVal() * pt2->getVal()));
        }
        // Et que la deuxième est un rationnel
        if (type2 == tRationnelle) {
            Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
            return (new Rationnelle(pt1->getNum().getVal()*pt2->getNum().getVal(),pt1->getDen().getVal()*pt2->getDen().getVal() ));
        }
        // Et que la deuxième est un complexe
        if (type2 == tComplexe) {
            Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
            Numerique* pRe = pt2->getRe();
            // Et que la partie réelle du complexe est un entier
            if (pRe->getType() == tEntiere) {
                Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
                Rationnelle* newpRe = new Rationnelle(pt3->getVal()*pt1->getNum().getVal(), pt1->getDen());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un reel
            if (pRe->getType() == tReelle) {
                Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
                Reelle* newpRe = new Reelle(pt1->toReelle().getVal() * pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un rationnel
            if (pRe->getType() == tRationnelle) {
                Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
                Rationnelle* newpRe = new Rationnelle(pt1->getNum().getVal()*pt3->getNum().getVal(), pt1->getDen().getVal()*pt3->getDen().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
        }
    }


    /*****************************************************************************************/

    // Si la première litterale est un complexe
    if (type1 == tComplexe) {
        Complexe* pt1 = dynamic_cast<Complexe*>(&l1);
        // On récupère le type de la partie réelle
        Numerique* pRe1 = pt1->getRe();
        // Si la partie réelle est un entier
        if (pRe1->getType() == tEntiere) {
            Entiere* ptx1 = dynamic_cast<Entiere*>(pRe1);
            // et que la deuxième est un entier
            if (type2 == tEntiere) {
                Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
                Entiere* newpRe = new Entiere(ptx1->getVal() * pt2->getVal());
                return (new Complexe(newpRe, pt1->getIm()));
            }
            // Et que la deuxième est un reel
            if (type2 == tReelle) {
                Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
                Reelle* newpRe = new Reelle((double)ptx1->getVal() * pt2->getVal());
                return (new Complexe(newpRe, pt1->getIm()));
            }
            // Et que la deuxième est un rationnel
            if (type2 == tRationnelle) {
                Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
                Rationnelle* newpRe = new Rationnelle(ptx1->getVal()*pt2->getNum().getVal(), pt2->getDen().getVal());
                return (new Complexe(newpRe, pt1->getIm()));
            }
            // Et que la deuxième est un complexe
        }
    }
}


Litterale* operator/(Litterale& l1, Litterale& l2) {

    // Recherche du type de la première litterale
    TypeLitterale type1 = l1.getType();
    // Recherche du type de la deuxieme litterale
    TypeLitterale type2 = l2.getType();

    /*****************************************************************************************/

    // Si la première litterale est un entier
    if (type1 == tEntiere) {
        Entiere* pt1 = dynamic_cast<Entiere*>(&l1);
        // Et que la deuxième est un entier
        if (type2 == tEntiere) {
            Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
            return (new Reelle((double)pt1->getVal() / (double)pt2->getVal()));
        }
        // Et que la deuxième est un reel
        if (type2 == tReelle) {
            Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
            return (new Reelle((double)pt1->getVal() / pt2->getVal()));
        }
        // Et que la deuxième est un rationnel
        if (type2 == tRationnelle) {
            Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
            return (new Rationnelle(pt1->getVal()*pt2->getDen().getVal(), pt2->getNum().getVal()));
        }
        // Et que la deuxième est un complexe
        if (type2 == tComplexe) {
            Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
            Numerique* pRe = pt2->getRe();
            // Et que la partie réelle du complexe est un entier
            if (pRe->getType() == tEntiere) {
                Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
                Reelle* newpRe = new Reelle((double)pt1->getVal() / (double)pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un reel
            if (pRe->getType() == tReelle) {
                Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
                Reelle* newpRe = new Reelle((double)pt1->getVal() / pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un rationnel
            if (pRe->getType() == tRationnelle) {
                Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
                Rationnelle* newpRe = new Rationnelle(pt1->getVal()*pt3->getDen().getVal(), pt3->getNum().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
        }
    }

    /*****************************************************************************************/

    // Si la première litterale est un reel
    if (type1 == tReelle) {
        Reelle* pt1 = dynamic_cast<Reelle*>(&l1);
        // Et que la deuxième est un entier
        if (type2 == tEntiere) {
            Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
            return (new Reelle(pt1->getVal() / (double)pt2->getVal()));
        }
        // Et que la deuxième est un reel
        if (type2 == tReelle) {
            Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
            return (new Reelle(pt1->getVal() / pt2->getVal()));
        }
        // Et que la deuxième est un rationnel
        if (type2 == tRationnelle) {
            Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
            return (new Reelle(pt1->getVal() / pt2->toReelle().getVal()));
        }
        // Et que la deuxième est un complexe
        if (type2 == tComplexe) {
            Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
            Numerique* pRe = pt2->getRe();
            // Et que la partie réelle du complexe est un entier
            if (pRe->getType() == tEntiere) {
                Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
                Reelle* newpRe = new Reelle(pt1->getVal() / (double)pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un reel
            if (pRe->getType() == tReelle) {
                Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
                Reelle* newpRe = new Reelle(pt1->getVal() / pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un rationnel
            if (pRe->getType() == tRationnelle) {
                Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
                Reelle* newpRe = new Reelle(pt1->getVal() / pt3->toReelle().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
        }
    }


    /*****************************************************************************************/

    // Si la première litterale est un rationnel
    if (type1 == tRationnelle) {
        Rationnelle* pt1 = dynamic_cast<Rationnelle*>(&l1);
        // Et que la deuxième est un entier
        if (type2 == tEntiere) {
            Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
            return (new Rationnelle(pt2->getVal()*pt1->getDen().getVal(), pt1->getNum().getVal()));
        }
        // Et que la deuxième est un reel
        if (type2 == tReelle) {
            Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
            return (new Reelle(pt1->toReelle().getVal() / pt2->getVal()));
        }
        // Et que la deuxième est un rationnel
        if (type2 == tRationnelle) {
            Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
            return (new Rationnelle(pt1->getNum().getVal()*pt2->getDen().getVal(),pt1->getDen().getVal()*pt2->getNum().getVal() ));
        }
        // Et que la deuxième est un complexe
        if (type2 == tComplexe) {
            Complexe* pt2 = dynamic_cast<Complexe*>(&l2);
            Numerique* pRe = pt2->getRe();
            // Et que la partie réelle du complexe est un entier
            if (pRe->getType() == tEntiere) {
                Entiere* pt3 = dynamic_cast<Entiere*>(pRe);
                Rationnelle* newpRe = new Rationnelle(pt3->getVal(), pt1->getDen().getVal()*pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un reel
            if (pRe->getType() == tReelle) {
                Reelle* pt3 = dynamic_cast<Reelle*>(pRe);
                Reelle* newpRe = new Reelle(pt1->toReelle().getVal() / pt3->getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
            // Et que la partie réelle du complexe est un rationnel
            if (pRe->getType() == tRationnelle) {
                Rationnelle* pt3 = dynamic_cast<Rationnelle*>(pRe);
                Rationnelle* newpRe = new Rationnelle(pt1->getNum().getVal()*pt3->getDen().getVal(), pt1->getDen().getVal()*pt3->getNum().getVal());
                return (new Complexe(newpRe, pt2->getIm()));
            }
        }
    }


    /*****************************************************************************************/

    // Si la première litterale est un complexe
    if (type1 == tComplexe) {
        Complexe* pt1 = dynamic_cast<Complexe*>(&l1);
        // On récupère le type de la partie réelle
        Numerique* pRe1 = pt1->getRe();
        // Si la partie réelle est un entier
        if (pRe1->getType() == tEntiere) {
            Entiere* ptx1 = dynamic_cast<Entiere*>(pRe1);
            // et que la deuxième est un entier
            if (type2 == tEntiere) {
                Entiere* pt2 = dynamic_cast<Entiere*>(&l2);
                Reelle* newpRe = new Reelle(ptx1->getVal() / pt2->getVal());
                return (new Complexe(newpRe, pt1->getIm()));
            }
            // Et que la deuxième est un reel
            if (type2 == tReelle) {
                Reelle* pt2 = dynamic_cast<Reelle*>(&l2);
                Reelle* newpRe = new Reelle((double)ptx1->getVal() / pt2->getVal());
                return (new Complexe(newpRe, pt1->getIm()));
            }
            // Et que la deuxième est un rationnel
            if (type2 == tRationnelle) {
                Rationnelle* pt2 = dynamic_cast<Rationnelle*>(&l2);
                Rationnelle* newpRe = new Rationnelle(ptx1->getVal()*pt2->getDen().getVal(), pt2->getNum().getVal());
                return (new Complexe(newpRe, pt1->getIm()));
            }
            // Et que la deuxième est un complexe
        }
    }
}
