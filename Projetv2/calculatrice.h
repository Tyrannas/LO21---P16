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
#include <string>
#include <QStringList>
#include <iostream>
#include <QDebug>
#include <QListWidgetItem>
#include <QFile>

/*!
* \file Calculatrice.h
* \brief Application principale liée à l'interface graphique de la calculette
* \author Felix ALIE & Clement ROUTIER
* \version 1
*/

namespace Ui {
class calculatrice;
}
/*! \class Calculatrice
* \brief Classe permetant de relier nos services de traitement à l'interface graphique
*/
class calculatrice : public QMainWindow
{
    Q_OBJECT

public:
    /*!
    *  \brief Constructeur
    */
    explicit calculatrice(QWidget *parent = 0);
    /*!
    *  \brief Destructeur
    */
    ~calculatrice();
    /*!
    *  \brief Permet de tester si un événement est déclenché sur l'un des widgets de l'application
    */
    bool eventFilter(QObject *obj, QEvent *event);
    /*!
    *  \brief Permet de détecter une entrée au clavier sur l'application, permet notamment de gérer des raccourcis tels que CTRL+Z et CTRL+Y
    */
    void keyPressEvent ( QKeyEvent * event );



private:
    /*!
    *  \brief Interface graphique associée
    */
    Ui::calculatrice *ui;
    /*!
    *  \brief Chaine de caractere qu'on met à jour lorsqu'une entrée est réalisée sur l'interface. C'est cette chaine qui sera parsée par notre Controleur.
    */
    QString entree;
    /*!
    *  \brief Un booleen permettant de controler la restauration de session.
    */
    bool restored;
    /*!
    *  \brief Le LitteraleManager associe les litterales
    */


    LitteraleManager lm;
    /*!
    *  \brief Pile permettant de gerer les items
    */
    Pile p;
    /*!
    *  \brief HashMap permettant de gérer les variables
    */
    HashMap hm;
    /*!
    *  \brief Controleur permettant de gérer les différents calculs
    */
    Controleur c;



private slots:
    /*!
    *  \brief Fonction permettant de lire une litterale et de l'ajouter à chaine Calculatrice.entree
    *  \param Qstring s
    */
    void readLitt(QString s);
    /*!
    *  \brief Fonction permettant de vider Calculatrice.entree et de parser son contenu
    */
    void execute(QString s = "");
    /*!
    *  \brief Fonction permettant d'ajouter un espace à la ligne d'entrée, est appelée par clique ou par appuie sur la touche espace.
    */
    void space();
    /*!
    *  \brief Fonctionnant permettant d'ajouter le contenu d'un item de la pile à la ligne d'entrée des commandes lors d'un clic sur ce dernier.
    */
    void stackClicked(QListWidgetItem* q);
    /*!
    *  \brief Permet de modifier le programme sur lequel on clique.
    */
    void varClicked(QListWidgetItem* q);
    /*!
    *  \brief Fonction déclenchée lors de l'appuie sur le bouton ok de l'interface programme, ajoute un nouveau programme à la HashMap
    */
    void addProg();
    /*!
    *  \brief Fonction déclenchée lors de l'appuie sur le bouton SAVE de l'interface programme, permet de sauvegarder l'etat de la pile, les variables et les programmes utilisateur
    */
    void save();
    /*!
    *  \brief Fonction déclenchée lors de l'appuie sur le bouton SAVE de l'interface programme, permet de sauvegarder l'etat de la pile, les variables et les programmes utilisateur
    */
    void open();

};

#endif // CALCULATRICE_H
