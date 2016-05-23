#include "Controleur.h"


///******* Fonctions de Service *****/

int estUnOperateur(const string& s) {
	if (s == "+") return 1;
	if (s == "-") return 2;
	if (s == "*") return 3;
	if (s == "/") return 4;
	return -1;
}

bool estUnEntier(const string& s) {
	regex reg(R"(\b\d+\b)");
	return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnReel(const string& s) {
	regex reg(R"(\b\d+,\d+\b)");
	return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnRationnel(const string& s) {
	regex reg(R"(\b\d+\/\d+\b)");
	return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnComplexe(const string& s) {
	regex reg(R"(\b\d+\+\d+\b)");
	return regex_match(s.cbegin(), s.cend(), reg);
}

///******Controleur******/


void Controleur::parse(const string& c) {
	int operateur = estUnOperateur(c);
	//si c'est un opérateur
	if (operateur != -1) {
		if (Stack.taille() >= 2)
			cout << "yolo"; //Controleur::operation(operateur);
	}
	//si c'est un littérale
	//on créé détermine le type
	//puis on créé l'objet à l'aide de la factory
	else {
		if (estUnEntier(c)) {
			Entiere* const e = dynamic_cast<Entiere* const>(litMng.littFactory(tEntiere, stoi(c)));
			Stack.push(e);
		}
		else if (estUnRationnel(c)) {
			cmatch res;
			regex rx("\\d+");
			regex_search(c.c_str(), res, rx);
			Rationnelle* const r = dynamic_cast<Rationnelle* const>(litMng.littFactory(tRationnelle, stoi(res[1]), stoi(res[2])));
			Stack.push(r);

		}
		else if (estUnReel(c)) {
			cmatch res;
			Reelle* const r = dynamic_cast<Reelle* const>(litMng.littFactory(tReelle, NULL, NULL, stod(c)));
			Stack.push(r);
		}
		else if (estUnComplexe(c)) {
			Numerique* l1 = nullptr;
			Numerique* l2 = nullptr;

			cmatch res;
			regex rx("[\\d,]+");
			regex_search(c.c_str(), res, rx);
			if (estUnEntier(res[1])) {
				Entiere* const e = dynamic_cast<Entiere* const>(litMng.littFactory(tEntiere, stoi(res[1])));
				l1 = e;
			}
			else if (estUnRationnel(res[1])) {
				cmatch res2;
				regex rx("\\d+");
				regex_search(c.c_str(), res2, rx);
				Rationnelle* const r = dynamic_cast<Rationnelle* const>(litMng.littFactory(tRationnelle, stoi(res2[1]), stoi(res2[2])));
				l1 = r;
			}
			else if (estUnReel(res[1])) {
				Reelle* const r = dynamic_cast<Reelle* const>(litMng.littFactory(tReelle, NULL, NULL, stod(res[1])));
				l1 = r;
			}

			if (estUnEntier(res[2])) {
				Entiere* const e = dynamic_cast<Entiere* const>(litMng.littFactory(tEntiere, stoi(res[2])));
				l2 = e;
			}
			else if (estUnRationnel(res[2])) {
				cmatch res2;
				regex rx("\\d+");
				regex_search(c.c_str(), res2, rx);
				Rationnelle* const r = dynamic_cast<Rationnelle* const>(litMng.littFactory(tRationnelle, stoi(res2[1]), stoi(res2[2])));
				l2 = r;
			}
			else if (estUnReel(res[2])) {
				Reelle* const r = dynamic_cast<Reelle* const>(litMng.littFactory(tReelle, NULL, NULL, stod(res[2])));
				l2 = r;
			}


			Complexe* const c = dynamic_cast<Complexe* const>(litMng.littFactory(tComplexe, NULL, NULL, NULL, l1, l2));
			Stack.push(c);
		}

		else throw ComputerException("Erreur, commande inconnue");
	}

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

//void Controleur::operation(int i)
//{
//	
//	Litterale& v1 = Stack.top();
//	Stack.pop();
//	Litterale& v2 = Stack.top();
//	if (1 <= i <= 4) { //opérateur binaires.
//		Stack.pop();
//	}
//
//	switch (i)
//	{
//	//addition
//	case 1:
//		Litterale& v3 = v1 + v2;
//		break;
//	//soustraction
//	case 2:
//		Litterale& v3 = v1 - v2;
//		break;
//	//multiplication
//	case 3:
//		Litterale& v3 = v1 * v2;
//		break;
//	//division
//	case 4:
//		Litterale& v3 = v1 / v2;
//		break;
//	default:
//		break;
//	}
//	Stack.push(v3);
//}
//

