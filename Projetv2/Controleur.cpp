#include "Controleur.h"
#include <QString>

///******* Fonctions de Service *****/

///******Controleur******/


void Controleur::parse(const string& c) {
    const char * test = c.c_str();
    qWarning(test);
    if (c == "UNDO") {
        if (canRedo)
            throw ComputerException("Impossible de faire deux Undo d'affile\n");
        stack.reconstruire(litMng.getMem());
        litMng.annuler();
        canRedo = true;
        return;
    }

    if (c == "REDO") {
        if (!canRedo)
            throw ComputerException("Impossible de Redo sans Undo\n");
        else {
            stack.reconstruire(litMng.getMem());
            litMng.annuler();
            canRedo = false;
        }
        return;
    }

    litMng.getMem().save(litMng.getLits(), litMng.taille());

    int operateurUnaire = estUnOperateurUnaire(c);
    int operateurBinaire = estUnOperateurBinaire(c);
    int operateurPile = estUnOperateurPile(c);

    //si c'est un opérateur
    if (estUneAssignation(c)) {
        cout << "assignation\n";
        cmatch res;
        regex rx(R"(\s(\d+)\s('\w+'))");
        regex_search(c.c_str(), res, rx);
        string var = res[2];
        string valeur = res[1];
        var.erase(remove(var.begin(), var.end(), '\''), var.end());
        parse(valeur);
        Litterale* newvalue = stack.top();
        stack.drop();
        table.put(var, newvalue);
        //cout << "on veut stocker la valeur: " << valeur << " dans " << var << "\n";
        //cout << "on vient de mettre la valeur : ",
        //table.get(var).affiche();
    }
    else if (estUneAssignationProg(c)) {
        cout << "assignationProg\n";
        cmatch res;
        regex rx(R"(\s(\[(\w|\s|\+)+\])\s('\w+'))");
        regex_search(c.c_str(), res, rx);
        string var = res[3];
        string valeur = res[1];
        //cout << res[1] << " et " << res[3];
        var.erase(remove(var.begin(), var.end(), '\''), var.end());
        parse(valeur);
        Litterale* newProg = stack.top();
        stack.drop();
        table.put(var, newProg);
        //cout << "Programme " << var << "enregistre";
    }
    else if (operateurUnaire != -1) {
        if(stack.taille() >= 1)
            Controleur::operationUnaire(operateurUnaire);
    }
    else if (operateurBinaire != -1) {
        if(stack.taille() >= 2)
            Controleur::operationBinaire(operateurBinaire);
    }
    else if (operateurPile != -1) {
            Controleur::operationPile(operateurPile);
    }
    //si c'est un littérale
    //on créé détermine le type
    //puis on créé l'objet à l'aide de la factory
    else {
        if (estUnIdentifiant(c)) {
            //cout << "C'est un identifiant ";
            Litterale* valeur = table.get(c);
            if (valeur->getType() != tProgramme) {
                //cout << "de valeur\n";
                stack.push(valeur);
            }
            else {
                //cout << "de programme\n";
                Programme* pt1 = dynamic_cast<Programme*>(valeur);
                string exec = pt1->getProg();
                exec.erase(remove(exec.begin(), exec.end(), '\]'), exec.end());
                exec.erase(remove(exec.begin(), exec.end(), '\['), exec.end());
                stringstream ss(exec);
                istream_iterator<std::string> begin(ss);
                istream_iterator<std::string> end;
                vector<std::string> vstrings(begin, end);
                copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
                for (int i = 0; i < vstrings.size();i++) {
                    parse(vstrings[i]);
                }
            }
        }
        else if (estUneSuppression(c)) {
            cout << "Suppression de la variable ";
            cmatch res;
            regex rx(R"(\s('\w+'))");
            regex_search(c.c_str(), res, rx);
            string var = res[1];
            var.erase(remove(var.begin(), var.end(), '\''), var.end());
            cout << var << "\n";
            table.forget(var);
        }
        else if (estUneExpression(c)) {
            cout << "C'est une expression\n";
            //Expression* const e = dynamic_cast<Expression* const>(litMng.littFactory(tExpression, NULL, NULL, NULL, NULL, NULL, c));
            //stack.push(e);
        }
        else if (estUnProgramme(c)) {
            //cout << "C'est un programme\n";
            //Programme* const p = dynamic_cast<Programme* const>(litMng.littFactory(tProgramme, NULL, NULL, NULL, NULL, NULL, c));
            //stack.push(p);
            Programme* const p = new Programme(c);
            litMng.addLitterale(p);
            stack.push(p);
        }
        else if (estUnEntier(c)) {
            try{
                Entiere* const e = dynamic_cast<Entiere* const>(litMng.littFactory(tEntiere, stoi(c)));
                stack.push(e);
            }
            catch(ComputerException e){
                string s = e.getInfo();
                const char * test = s.c_str();
                qWarning(test);
            }
        }
        else if (estUnRationnel(c)) {
            cmatch res;
            regex rx(R"((-?\d+)\/(-?\d+))");
            regex_search(c.c_str(), res, rx);
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
            regex rx(R"((-?(?:(?:\d+.\d+)|(?:\d+\/-?\d+)|(?:\d+)))\$(-?(?:(?:\d+.\d+)|(?:\d+\/-?\d+)|(?:\d+)))?)");
            regex_search(c.c_str(), res, rx);
            if (estUnEntier(res[1])) {
                Entiere* const e = dynamic_cast<Entiere* const>(litMng.littFactory(tEntiere, stoi(res[1])));
                l1 = e;
            }
            else if (estUnRationnel(res[1])) {
                cmatch res2;
                regex rx(R"((-?\d+)\/(-?\d+))");
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
                regex rx(R"((-?\d+)\/(-?\d+))");
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

/*void Controleur::executer() {
    string c;
    try {
        do {
            cout << "LitMngMem :";
            //litMng.getMem().affiche();
            cout << "\n";
            stack.affiche();
            cout << "?- ";
            getline(cin, c);
            if (c != "Exit") {
                cout << "string parsee: " << c <<"\n";
                parse(c);
            }
        } while (c != "Exit");
    }
    catch (ComputerException& c) {
        cout << c.getInfo();
    }
}*/

void Controleur::operationUnaire(int i){
    Litterale* const v1 = stack.top();
    Litterale* v2 = nullptr;
    stack.drop();
    switch(i){
        case 1:
            if (v1->getType() == tEntiere || v1->getType() == tRationnelle || v1->getType() == tReelle) {
                Numerique* pt1 = dynamic_cast<Numerique*>(v1);
                pt1->neg();
                v2 = pt1->clone();
                litMng.getMem().updateOpe(v1->clone(), nullptr, "NEG");
            }
            else if (v1->getType() == tComplexe) {
                Complexe* pt1 = dynamic_cast<Complexe*>(v1);
                pt1->neg();
                v2 = pt1->clone();
                litMng.getMem().updateOpe(v1->clone(), nullptr, "NEG");
            }
            else {
                throw ComputerException("Impossible d'effectuer NEG sur cet operateur");
            }
            break;
        case 2:
            v2 = num(*v1);
            litMng.getMem().updateOpe(v1->clone(), nullptr, "NUM");
            break;
        case 3:
            v2 = den(*v1);
            litMng.getMem().updateOpe(v1->clone(), nullptr, "DEN");
            break;
        case 4:
            v2 = re(*v1);
            litMng.getMem().updateOpe(v1->clone(), nullptr, "RE");
            break;
        case 5:
            v2 = im(*v1);
            litMng.getMem().updateOpe(v1->clone(), nullptr, "IM");
            break;
        default:
            break;
       }
    litMng.removeLitterale(v1);
    litMng.addLitterale(v2);
    stack.push(v2);
}

void Controleur::operationBinaire(int i)
{
    Litterale* const v1 = stack.top();
    const string& s = v1->toString();
    const char * debug = s.c_str();
    qWarning("v1:");
    qWarning(debug);
    stack.drop();
    Litterale* const v2 = stack.top();
    stack.drop();
    Litterale* v3 = nullptr;

    switch (i)
    {
        //addition
    case 1:
        v3 = *v1 + *v2;
        litMng.getMem().updateOpe(v1->clone(), v2->clone(), "+");
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
        //	Litterale& v3 = *v1 / *v2;
        //	break;
    case 5:
        v3 = div(*v1, *v2);
        litMng.getMem().updateOpe(v1->clone(), v2->clone(), "DIV");
        break;
    case 6:
        v3 = mod(*v1, *v2);
        litMng.getMem().updateOpe(v1->clone(), v2->clone(), "MOD");
        break;
    case 7:
        v3 = dollar(*v1, *v2);
        litMng.getMem().updateOpe(v1->clone(), v2->clone(), "$");
        break;
    case 8:
        //if (v1)
            //v2.eval();
        break;
    default:
        break;
    }
    litMng.removeLitterale(v1);
    litMng.removeLitterale(v2);
    litMng.addLitterale(v3);

    stack.push(v3);
}

void Controleur::operationPile(int i)
{
    Litterale* newl = nullptr;
    switch (i)
    {
    case 1:
        newl = stack.top()->clone();
        stack.push(newl);
        litMng.addLitterale(newl);
        break;
    case 2:
        stack.drop();
        break;
    case 3:
        stack.swap();
        break;
    case 4:
        parse(litMng.getMem().getLastOp());
        break;
    case 5:
        stack.push(litMng.getMem().getLastArg1());
        litMng.addLitterale(litMng.getMem().getLastArg1());
        if (litMng.getMem().getLastArg2() != nullptr) {
            stack.push(litMng.getMem().getLastArg2());
            litMng.addLitterale(litMng.getMem().getLastArg2());
        }
        break;
    case 8:
        stack.clear();
        break;
    default:
        break;
    }
}
