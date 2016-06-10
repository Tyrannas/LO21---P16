#include "mainwindow.h"
#include "Calculatrice.h"
#include "ComputerException.h"
#include "LitteraleManager.h"
#include "Pile.h"
#include "Controleur.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    try{
        QApplication a(argc, argv);
        calculatrice c;
        c.show();
        return a.exec();
       }
    catch(ComputerException e){
        string s = e.getInfo();
        const char * debug = s.c_str();
        qWarning(debug);
    }

}
