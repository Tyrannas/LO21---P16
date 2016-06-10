#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <QMainWindow>
#include <QSignalMapper>
#include <QString>
#include "Controleur.h"
#include "LitteraleManager.h"
#include "Pile.h"
#include "HashMap.h"
#include <QKeyEvent>

namespace Ui {
class calculatrice;
}

class calculatrice : public QMainWindow
{
    Q_OBJECT

public:
    explicit calculatrice(QWidget *parent = 0);
    ~calculatrice();
    bool eventFilter(QObject *obj, QEvent *event);
    void keyPressEvent ( QKeyEvent * event );


private:
    Ui::calculatrice *ui;
    QString entree;
    LitteraleManager lm;
    Pile p;
    HashMap hm;
    Controleur c;



private slots:
    void readLitt(QString s);
    void execute(QString s = "");
    void space();

};

#endif // CALCULATRICE_H
