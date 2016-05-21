#include "Controleur.h"

///******* Utile *****/

int estUnOperateur(const string& s) {
	if (s == "+") return 1;
	if (s == "-") return 2;
	if (s == "*") return 3;
	if (s == "/") return 4;
	return -1;
}

bool estUnEntier(const string& s) {
	unsigned int i = 0;
	for (i = 0; i<s.size(); i++)
		if (s[i]<'0' || s[i]>'9') return false;
	for (string::const_iterator it = s.begin(); it != s.end(); ++it)
		if (*it<'0' || *it>'9') return false;
	return true;
}

bool estUnReel(const string& s) {
	unsigned int i = 0;
	for (i = 0; i<s.size(); i++)
		if (s[i]<'0' || s[i]>'9') return false;
	for (string::const_iterator it = s.begin(); it != s.end(); ++it)
		if (*it<'0' || *it>'9') return false;
	return true;
}

///******Controleur******/


void Controleur::parse(const string& c) {
	int operateur = estUnOperateur(c);
	//si c'est un opérateur
	if (operateur != -1)
		if (Stack.taille >= 2)
			Controleur::operation(operateur);
	//si c'est un littérale
	//on créé détermine le type
	//puis on créé l'objet à l'aide de la factory
	
}

void Controleur::executer() {
	string c;
	do {
		Stack.affiche();
		cout << "?- ";
		cin >> c;
		if (c != "Exit") parse(c);
	} while (c != "Exit");
}

void Controleur::operation(int i)
{
	
	Litterale& v1 = Stack.top();
	Stack.pop();
	Litterale& v2 = Stack.top();
	if (1 <= i <= 4) { //opérateur binaires.
		Stack.pop();
	}

	switch (i)
	{
	//addition
	case 1:
		Litterale& v3 = v1 + v2;
		break;
	//soustraction
	case 2:
		Litterale& v3 = v1 - v2;
		break;
	//multiplication
	case 3:
		Litterale& v3 = v1 * v2;
		break;
	//division
	case 4:
		Litterale& v3 = v1 / v2;
		break;
	default:
		break;
	}
	Stack.push(v3);
}

