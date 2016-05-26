#include "Controleur.h"


///******* Fonctions de Service *****/

int estUnOperateur(const string& s) {
	if (s == "+") return 1;
	if (s == "-") return 2;
	if (s == "*") return 3;
	if (s == "/") return 4;
	if (s == "DIV") return 5;
	if (s == "MOD") return 6;
	if (s == "$") return 7;

	if (s == "NEG") return 10;
	if (s == "NUM") return 11;
	if (s == "DEN") return 12;
	if (s == "RE") return 13;
	if (s == "IM") return 14;
	return -1;
}

bool estUnEntier(const string& s) {
	regex reg(R"(\b\d+\b)");
	return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnReel(const string& s) {
	regex reg(R"(\b\d+\.\d+\b)");
	return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnRationnel(const string& s) {
	regex reg(R"(\b\d+\/\d+\b)");
	//cout << "Sa grande soeur c'est un rationnel";
	return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnComplexe(const string& s) {
	regex reg(R"(\b\d+\+\d+\b)");
	return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnIdentifiant(const string& s) {
	regex reg(R"(\b\w(\d|\w)*\b)");
	return regex_match(s.cbegin(), s.cend(), reg);
}

///******Controleur******/


void Controleur::parse(const string& c) {
	int operateur = estUnOperateur(c);
	//si c'est un opérateur
	if (operateur != -1) {
		if ((operateur < 10 && stack.taille() >= 2) || (operateur >= 10 && stack.taille() >= 1))
			Controleur::operation(operateur);
	}
	//si c'est un littérale
	//on créé détermine le type
	//puis on créé l'objet à l'aide de la factory
	else {
		if (estUnIdentifiant(c)) {
			cout << "C'est un identifiant mais je sais pas faire";
		}
		else if (estUnEntier(c)) {
			Entiere* const e = dynamic_cast<Entiere* const>(litMng.littFactory(tEntiere, stoi(c)));
			stack.push(e);
		}
		else if (estUnRationnel(c)) {
			cmatch res;
			regex rx(R"(\b(\d+)\/(\d+)\b)");
			regex_search(c.c_str(), res, rx);
			//cout << res[0];
			//cout << res[0] << " YOLO " << res[1]  << " YOLO " << res[2]  << " YOLO " << res[3] << " YOLO " << res[4];
			Rationnelle* const r = dynamic_cast<Rationnelle* const>(litMng.littFactory(tRationnelle, stoi(res[1]), stoi(res[2])));
			stack.push(r);

		}
		else if (estUnReel(c)) {
			cmatch res;
			Reelle* const r = dynamic_cast<Reelle* const>(litMng.littFactory(tReelle, NULL, NULL, stod(c)));
			stack.push(r);
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
			stack.push(c);
		}

		else throw ComputerException("Erreur, commande inconnue");
	}

}

void Controleur::executer() {
	string c;
	do {
		stack.affiche();
		cout << "?- ";
		cin >> c;
		if (c != "Exit") parse(c);
	} while (c != "Exit");
}

void Controleur::operation(int i)
{
	const int nbOpBinaires = 7;
	Litterale* v1 = stack.top();
	Litterale* v2 = nullptr;
	Litterale* v3 = nullptr;
	stack.drop();
	
	if (i <= nbOpBinaires) { //opérateur binaires.
		v2 = stack.top();
		stack.drop();
	}
	
	switch (i)
	{
	//addition
	case 1:
		v3 = *v1 + *v2;
		break;
	//soustraction
	//case 2:
	//	v3 = *v1 - *v2;
	//	break;
	////multiplication
	//case 3:
	//	v3 = *v1 * *v2;
	//	break;
	////division
	//case 4:
	//	Litterale& v3 = v1 / v2;
	//	break;
	case 5:
		v3 = div(*v1, *v2);
		break;
	case 6:
		v3 = mod(*v1, *v2);
		break;
	case 7:
		v3 = dollar(*v1, *v2);
		break;
	case 10:
		//v3 = neg(*v1);
		break;
	case 11:
		v3 = num(*v1);
		break;
	case 12:
		v3 = den(*v1);
		break;
	case 13:
		v3 = re(*v1);
		break;
	case 14:
		v3 = im(*v1);
		break;
	default:
		break;
	}
	litMng.removeLitterale(v1);
	if(i <= nbOpBinaires) litMng.removeLitterale(v2);
	litMng.addLitterale(v3);
	stack.push(v3);
}


