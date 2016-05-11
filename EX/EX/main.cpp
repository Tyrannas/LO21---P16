#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#ifndef _FICHIERS_H
#define _FICHIERS_H
#include "computer.h"
#endif

int main() {
	Entiere e1(3);
	Entiere e2(4);
	Rationnelle r1(e1, e2);
	r1.affiche();
	r1.simplification();
	r1.affiche();
	Reelle r2(3);
	r2 = r1.toReelle();
	r2.affiche();
	Rationnelle r3 = e1 + r1;
	Rationnelle r4 = r1 + e1;
	cout << "\n";
	r3.affiche();
	cout << "\n";
	r4.affiche();
	cout << "\n";
	Complexe c1(&r1, &e1);
	c1.affiche();
	cout << "\n ************************ \n";
	Item i1;
	i1.setLitterale(e1);
	Item i2;
	i2.setLitterale(r1);
	Pile pile2;
	pile2.push(e1);
	pile2.push(r1);
	pile2.affiche();
	//i1.getLitterale().affiche();
	//pile1.push(e1);
	//pile1.push(r1);
	

	regex pattern{ "[[:digit:]]*\.[[:digit:]]*" }; // on recherche le motif "abc"
	string target{ "3.27" };
	bool result = regex_match(target, pattern);
	cout << boolalpha << result << endl;

	/*
	cout << "\n\n ATTENTION LANCEMENT DU CONTROLEUR \n\n";
	LitteraleManager litmng;
	Pile pile1;
	pile1.setMessage("Voici la pile");
	Controleur controleur(litmng, pile1);
	controleur.executer();
	*/
	
	return 0;
}