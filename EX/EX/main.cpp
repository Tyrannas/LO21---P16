#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#ifndef _FICHIERS_H
#define _FICHIERS_H
#include "computer.h"
#endif

int main() {
	// Création des valeurs

	Entiere e1(3);
	Entiere e2(4);
	Rationnelle r1(e1, e2);
	r1.affiche();
	cout << "\n";
	r1.simplification();
	r1.affiche();
	cout << "\n";
	Reelle r2(3.4);
	//r2 = r1.toReelle();
	r2.affiche();
	cout << "\n";
	Complexe c1(&e1, &e2);

	//Calculs

	Litterale *l1 = &e1;
	Litterale *l2 = &e2;
	Litterale *l3 = *l1 + *l2;
	l3->affiche();
	cout << "\n";
	Litterale *l4 = &r1;
	Litterale *l5 = *l1 + *l4;
	l5->affiche();
	cout << "\n";
	Litterale *l6 = &r2;
	Litterale *l7 = *l1 + *l6;
	l7->affiche();
	cout << "\n";
	Litterale *l8 = &c1;
	//Litterale *l9 = *l1 + *l8;
	//l9->affiche();
	//cout << "\n";





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