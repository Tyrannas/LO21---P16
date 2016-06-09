#include"Service.h"
#include<QString>
using namespace std;


int estUnOperateurPile(const string& s) {
    if (s == "DUP") return 1;
    if (s == "DROP") return 2;
    if (s == "SWAP") return 3;
    if (s == "LASTOP") return 4;
    if (s == "LASTARGS") return 5;
    if (s == "UNDO") return 6;
    if (s == "REDO") return 7;
    if (s == "CLEAR") return 8;
    return -1;
}

int estUnOperateurBinaire(const string& s) {
    if (s == "+") return 1;
    if (s == "-") return 2;
    if (s == "*") return 3;
    if (s == "/") return 4;
    if (s == "DIV") return 5;
    if (s == "MOD") return 6;
    if (s == "$") return 7;
    if (s == "IFT") return 8;
    return -1;
}

int estUnOperateurUnaire(const string& s){
    if (s == "NEG") return 1;
    if (s == "NUM") return 2;
    if (s == "DEN") return 3;
    if (s == "RE") return 4;
    if (s == "IM") return 5;
    return -1;
}

bool estUneExpression(const string& s) {
    regex reg("^'\.+'$");
    return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnProgramme(const string& s) {
    regex reg("^\\[\.+\\]$");
    return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnIdentifiant(const string& s) {
    regex reg("^[A-Z]+\\d*$");
    return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnEntier(const string& s) {
    regex reg(R"(^-?\d+$)");
    return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnReel(const string& s) {
    regex reg(R"(^-?\d+\.\d+$)");
    return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnRationnel(const string& s) {
    regex reg(R"(^-?\d+\/-?\d+$)");
    return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUnComplexe(const string& s) {
    regex reg(R"(^(-?(?:(?:\d+.\d+)|(?:\d+\/-?\d+)|(?:\d+)))\$(-?(?:(?:\d+.\d+)|(?:\d+\/-?\d+)|(?:\d+)))?$)");
    return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUneAssignation(const string& s) {
    regex reg("^STO\\s\\d+\\s'\\w+'$");
    return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUneAssignationProg(const string& s) {
    regex reg("^STO\\s\\[\.+\\]\\s'\\w+'$");
    return regex_match(s.cbegin(), s.cend(), reg);
}

bool estUneSuppression(const string& s) {
    regex reg("^FORGET\\s'\\w+'$");
    return regex_match(s.cbegin(), s.cend(), reg);
}
