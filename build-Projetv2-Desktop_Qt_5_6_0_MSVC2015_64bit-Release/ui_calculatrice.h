/********************************************************************************
** Form generated from reading UI file 'calculatrice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATRICE_H
#define UI_CALCULATRICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculatrice
{
public:
    QAction *actionQuitter;
    QAction *actionAnnuler_Ctrl_Z;
    QAction *actionR_tablie_Ctrl_Y;
    QWidget *centralwidget;
    QLineEdit *ligneCommande;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_RP;
    QPushButton *pushButton_LP;
    QPushButton *pushButton_FRAC;
    QPushButton *pushButton_9;
    QPushButton *pushButton_DOT;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_RB;
    QPushButton *pushButton_6;
    QPushButton *pushButton_0;
    QPushButton *pushButton_COMPLEXE;
    QPushButton *pushButton_8;
    QPushButton *pushButton_LB;
    QPushButton *pushButton_SPACE;
    QPushButton *pushButton_1;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_MUL;
    QPushButton *pushButton_DIVIDE;
    QPushButton *pushButton_DOLLAR;
    QPushButton *pushButton_MOD;
    QPushButton *pushButton_EQ;
    QPushButton *pushButton_SOUS;
    QPushButton *pushButton_ADD;
    QPushButton *pushButton_DEN;
    QPushButton *pushButton_RE;
    QPushButton *pushButton_NUM;
    QPushButton *pushButton_NEG;
    QPushButton *pushButton_IF;
    QPushButton *pushButton_DIV;
    QPushButton *pushButton_IM;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_LASTOP;
    QPushButton *pushButton_DUP;
    QPushButton *pushButton_CLEAR;
    QPushButton *pushButton_REDO;
    QPushButton *pushButton_SWAP;
    QPushButton *pushButton_DROP;
    QPushButton *pushButton_UNDO;
    QPushButton *pushButton_LASTARG;
    QPushButton *pushButton_STO;
    QPushButton *pushButton_FORGET;
    QPushButton *pushButton_EVAL;
    QPushButton *pushButton;
    QListWidget *affPile;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_VALIDER;
    QTextEdit *editProg;
    QLineEdit *nameProg;
    QLabel *label_3;
    QLabel *label_4;
    QListWidget *affVar;
    QListWidget *affVal;
    QLabel *label_5;
    QPushButton *valProg_2;
    QLineEdit *nameProg_2;
    QLabel *label_6;
    QTextEdit *affErreur;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *calculatrice)
    {
        if (calculatrice->objectName().isEmpty())
            calculatrice->setObjectName(QStringLiteral("calculatrice"));
        calculatrice->resize(1079, 605);
        QFont font;
        font.setFamily(QStringLiteral("Roboto Light"));
        calculatrice->setFont(font);
        calculatrice->setStyleSheet(QStringLiteral("QMainWindow{background-color:rgb(44,44,44);border:none;}"));
        actionQuitter = new QAction(calculatrice);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionAnnuler_Ctrl_Z = new QAction(calculatrice);
        actionAnnuler_Ctrl_Z->setObjectName(QStringLiteral("actionAnnuler_Ctrl_Z"));
        actionR_tablie_Ctrl_Y = new QAction(calculatrice);
        actionR_tablie_Ctrl_Y->setObjectName(QStringLiteral("actionR_tablie_Ctrl_Y"));
        centralwidget = new QWidget(calculatrice);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ligneCommande = new QLineEdit(centralwidget);
        ligneCommande->setObjectName(QStringLiteral("ligneCommande"));
        ligneCommande->setGeometry(QRect(0, 0, 311, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Roboto Light"));
        font1.setPointSize(13);
        ligneCommande->setFont(font1);
        ligneCommande->setStyleSheet(QStringLiteral("QLineEdit{border:none;background:rgb(122, 122, 122);color:white;}"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 40, 231, 362));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_RP = new QPushButton(gridLayoutWidget);
        pushButton_RP->setObjectName(QStringLiteral("pushButton_RP"));
        pushButton_RP->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_RP, 3, 2, 1, 1);

        pushButton_LP = new QPushButton(gridLayoutWidget);
        pushButton_LP->setObjectName(QStringLiteral("pushButton_LP"));
        pushButton_LP->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_LP, 3, 0, 1, 1);

        pushButton_FRAC = new QPushButton(gridLayoutWidget);
        pushButton_FRAC->setObjectName(QStringLiteral("pushButton_FRAC"));
        pushButton_FRAC->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_FRAC, 4, 1, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_DOT = new QPushButton(gridLayoutWidget);
        pushButton_DOT->setObjectName(QStringLiteral("pushButton_DOT"));
        pushButton_DOT->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_DOT, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_RB = new QPushButton(gridLayoutWidget);
        pushButton_RB->setObjectName(QStringLiteral("pushButton_RB"));
        pushButton_RB->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_RB, 5, 2, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_0 = new QPushButton(gridLayoutWidget);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        pushButton_0->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_0, 3, 1, 1, 1);

        pushButton_COMPLEXE = new QPushButton(gridLayoutWidget);
        pushButton_COMPLEXE->setObjectName(QStringLiteral("pushButton_COMPLEXE"));
        pushButton_COMPLEXE->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_COMPLEXE, 4, 2, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_LB = new QPushButton(gridLayoutWidget);
        pushButton_LB->setObjectName(QStringLiteral("pushButton_LB"));
        pushButton_LB->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_LB, 5, 0, 1, 1);

        pushButton_SPACE = new QPushButton(gridLayoutWidget);
        pushButton_SPACE->setObjectName(QStringLiteral("pushButton_SPACE"));
        pushButton_SPACE->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));

        gridLayout->addWidget(pushButton_SPACE, 5, 1, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(20, 60));
        QFont font2;
        font2.setPointSize(7);
        pushButton_1->setFont(font2);
        pushButton_1->setStyleSheet(QLatin1String("QPushButton{border:none; background:orange; color:white; min-width:20; min-height:60}\n"
"QPushButton:hover{background-color:red;}"));
        pushButton_1->setFlat(false);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(230, 40, 131, 352));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_MUL = new QPushButton(gridLayoutWidget_2);
        pushButton_MUL->setObjectName(QStringLiteral("pushButton_MUL"));
        pushButton_MUL->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_MUL, 2, 0, 1, 1);

        pushButton_DIVIDE = new QPushButton(gridLayoutWidget_2);
        pushButton_DIVIDE->setObjectName(QStringLiteral("pushButton_DIVIDE"));
        pushButton_DIVIDE->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_DIVIDE, 3, 0, 1, 1);

        pushButton_DOLLAR = new QPushButton(gridLayoutWidget_2);
        pushButton_DOLLAR->setObjectName(QStringLiteral("pushButton_DOLLAR"));
        pushButton_DOLLAR->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_DOLLAR, 5, 0, 1, 1);

        pushButton_MOD = new QPushButton(gridLayoutWidget_2);
        pushButton_MOD->setObjectName(QStringLiteral("pushButton_MOD"));
        pushButton_MOD->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_MOD, 0, 1, 1, 1);

        pushButton_EQ = new QPushButton(gridLayoutWidget_2);
        pushButton_EQ->setObjectName(QStringLiteral("pushButton_EQ"));
        pushButton_EQ->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_EQ, 4, 0, 1, 1);

        pushButton_SOUS = new QPushButton(gridLayoutWidget_2);
        pushButton_SOUS->setObjectName(QStringLiteral("pushButton_SOUS"));
        pushButton_SOUS->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_SOUS, 1, 0, 1, 1);

        pushButton_ADD = new QPushButton(gridLayoutWidget_2);
        pushButton_ADD->setObjectName(QStringLiteral("pushButton_ADD"));
        pushButton_ADD->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_ADD, 0, 0, 1, 1);

        pushButton_DEN = new QPushButton(gridLayoutWidget_2);
        pushButton_DEN->setObjectName(QStringLiteral("pushButton_DEN"));
        pushButton_DEN->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_DEN, 4, 1, 1, 1);

        pushButton_RE = new QPushButton(gridLayoutWidget_2);
        pushButton_RE->setObjectName(QStringLiteral("pushButton_RE"));
        pushButton_RE->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_RE, 5, 1, 1, 1);

        pushButton_NUM = new QPushButton(gridLayoutWidget_2);
        pushButton_NUM->setObjectName(QStringLiteral("pushButton_NUM"));
        pushButton_NUM->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_NUM, 3, 1, 1, 1);

        pushButton_NEG = new QPushButton(gridLayoutWidget_2);
        pushButton_NEG->setObjectName(QStringLiteral("pushButton_NEG"));
        pushButton_NEG->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_NEG, 2, 1, 1, 1);

        pushButton_IF = new QPushButton(gridLayoutWidget_2);
        pushButton_IF->setObjectName(QStringLiteral("pushButton_IF"));
        pushButton_IF->setMinimumSize(QSize(20, 50));
        pushButton_IF->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_IF, 6, 0, 1, 1);

        pushButton_DIV = new QPushButton(gridLayoutWidget_2);
        pushButton_DIV->setObjectName(QStringLiteral("pushButton_DIV"));
        pushButton_DIV->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_DIV, 1, 1, 1, 1);

        pushButton_IM = new QPushButton(gridLayoutWidget_2);
        pushButton_IM->setObjectName(QStringLiteral("pushButton_IM"));
        pushButton_IM->setMinimumSize(QSize(20, 50));
        pushButton_IM->setStyleSheet(QLatin1String("QPushButton{border:none; background:rgb(146, 204, 255); color:white; min-width:20; min-height:50}\n"
"QPushButton:hover{background-color:rgb(101, 161, 198)}"));

        gridLayout_2->addWidget(pushButton_IM, 6, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 390, 361, 191));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_LASTOP = new QPushButton(gridLayoutWidget_3);
        pushButton_LASTOP->setObjectName(QStringLiteral("pushButton_LASTOP"));
        pushButton_LASTOP->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_LASTOP, 0, 1, 1, 1);

        pushButton_DUP = new QPushButton(gridLayoutWidget_3);
        pushButton_DUP->setObjectName(QStringLiteral("pushButton_DUP"));
        pushButton_DUP->setMinimumSize(QSize(0, 50));
        pushButton_DUP->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_DUP, 0, 0, 1, 1);

        pushButton_CLEAR = new QPushButton(gridLayoutWidget_3);
        pushButton_CLEAR->setObjectName(QStringLiteral("pushButton_CLEAR"));
        pushButton_CLEAR->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_CLEAR, 3, 0, 1, 1);

        pushButton_REDO = new QPushButton(gridLayoutWidget_3);
        pushButton_REDO->setObjectName(QStringLiteral("pushButton_REDO"));
        pushButton_REDO->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_REDO, 3, 1, 1, 1);

        pushButton_SWAP = new QPushButton(gridLayoutWidget_3);
        pushButton_SWAP->setObjectName(QStringLiteral("pushButton_SWAP"));
        pushButton_SWAP->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_SWAP, 2, 0, 1, 1);

        pushButton_DROP = new QPushButton(gridLayoutWidget_3);
        pushButton_DROP->setObjectName(QStringLiteral("pushButton_DROP"));
        pushButton_DROP->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_DROP, 1, 0, 1, 1);

        pushButton_UNDO = new QPushButton(gridLayoutWidget_3);
        pushButton_UNDO->setObjectName(QStringLiteral("pushButton_UNDO"));
        pushButton_UNDO->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_UNDO, 2, 1, 1, 1);

        pushButton_LASTARG = new QPushButton(gridLayoutWidget_3);
        pushButton_LASTARG->setObjectName(QStringLiteral("pushButton_LASTARG"));
        pushButton_LASTARG->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_LASTARG, 1, 1, 1, 1);

        pushButton_STO = new QPushButton(gridLayoutWidget_3);
        pushButton_STO->setObjectName(QStringLiteral("pushButton_STO"));
        pushButton_STO->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_STO, 0, 2, 1, 1);

        pushButton_FORGET = new QPushButton(gridLayoutWidget_3);
        pushButton_FORGET->setObjectName(QStringLiteral("pushButton_FORGET"));
        pushButton_FORGET->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_FORGET, 1, 2, 1, 1);

        pushButton_EVAL = new QPushButton(gridLayoutWidget_3);
        pushButton_EVAL->setObjectName(QStringLiteral("pushButton_EVAL"));
        pushButton_EVAL->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton_EVAL, 2, 2, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white;min-height:50;}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));

        gridLayout_3->addWidget(pushButton, 3, 2, 1, 1);

        affPile = new QListWidget(centralwidget);
        affPile->setObjectName(QStringLiteral("affPile"));
        affPile->setGeometry(QRect(360, 40, 201, 541));
        QFont font3;
        font3.setFamily(QStringLiteral("Roboto Light"));
        font3.setPointSize(14);
        affPile->setFont(font3);
        affPile->setStyleSheet(QLatin1String("QListWidget{border:none;color:white;background:rgb(44,44,44);qproperty-alignment: AlignCenter;}\n"
"QListWidget::item{qproperty-alignment: AlignCenter;background:orange;margin-top:4}\n"
"QListWidget::item::hover{background:red;}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 0, 201, 41));
        label->setStyleSheet(QStringLiteral("QLabel{color:white;qproperty-alignment: AlignCenter;background:orange}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 0, 111, 41));
        label_2->setStyleSheet(QStringLiteral("QLabel{color:white;qproperty-alignment: AlignCenter;background:orange}"));
        pushButton_VALIDER = new QPushButton(centralwidget);
        pushButton_VALIDER->setObjectName(QStringLiteral("pushButton_VALIDER"));
        pushButton_VALIDER->setGeometry(QRect(310, 0, 51, 41));
        pushButton_VALIDER->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));
        editProg = new QTextEdit(centralwidget);
        editProg->setObjectName(QStringLiteral("editProg"));
        editProg->setGeometry(QRect(780, 40, 321, 301));
        QFont font4;
        font4.setPointSize(14);
        editProg->setFont(font4);
        editProg->setStyleSheet(QStringLiteral("background:rgb(122, 122, 122);color:white;"));
        nameProg = new QLineEdit(centralwidget);
        nameProg->setObjectName(QStringLiteral("nameProg"));
        nameProg->setGeometry(QRect(780, 380, 261, 41));
        nameProg->setFont(font4);
        nameProg->setStyleSheet(QStringLiteral("background:rgb(122, 122, 122);color:white;border:none"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(780, 0, 321, 41));
        QFont font5;
        font5.setBold(false);
        font5.setWeight(50);
        label_3->setFont(font5);
        label_3->setStyleSheet(QStringLiteral("QLabel{color:white;qproperty-alignment: AlignCenter;background:orange}"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(670, 0, 111, 41));
        label_4->setStyleSheet(QStringLiteral("QLabel{color:white;qproperty-alignment: AlignCenter;background:orange}"));
        affVar = new QListWidget(centralwidget);
        affVar->setObjectName(QStringLiteral("affVar"));
        affVar->setGeometry(QRect(560, 40, 111, 541));
        affVar->setFont(font3);
        affVar->setStyleSheet(QLatin1String("QListWidget{border:none;color:white;background:rgb(44,44,44);qproperty-alignment: AlignCenter;}\n"
"QListWidget::item{qproperty-alignment: AlignCenter;background:orange;margin-top:4}\n"
"QListWidget::item::hover{background:red;}"));
        affVal = new QListWidget(centralwidget);
        affVal->setObjectName(QStringLiteral("affVal"));
        affVal->setGeometry(QRect(670, 40, 111, 541));
        affVal->setFont(font3);
        affVal->setStyleSheet(QLatin1String("QListWidget{border:none;color:white;background:rgb(44,44,44);qproperty-alignment: AlignCenter;}\n"
"QListWidget::item{qproperty-alignment: AlignCenter;background:orange;margin-top:4}\n"
"QListWidget::item::hover{background:red;}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(780, 420, 321, 41));
        label_5->setFont(font5);
        label_5->setStyleSheet(QStringLiteral("QLabel{color:white;qproperty-alignment: AlignCenter;background:orange}"));
        valProg_2 = new QPushButton(centralwidget);
        valProg_2->setObjectName(QStringLiteral("valProg_2"));
        valProg_2->setGeometry(QRect(1040, 380, 41, 41));
        valProg_2->setStyleSheet(QLatin1String("QPushButton{background:rgb(44,44,44);border:none;color:white}\n"
"QPushButton:hover{background:rgb(72, 72, 72);}"));
        nameProg_2 = new QLineEdit(centralwidget);
        nameProg_2->setObjectName(QStringLiteral("nameProg_2"));
        nameProg_2->setGeometry(QRect(1500, 720, 251, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(780, 340, 321, 41));
        label_6->setFont(font5);
        label_6->setStyleSheet(QStringLiteral("QLabel{color:white;qproperty-alignment: AlignCenter;background:orange}"));
        affErreur = new QTextEdit(centralwidget);
        affErreur->setObjectName(QStringLiteral("affErreur"));
        affErreur->setGeometry(QRect(780, 460, 321, 121));
        affErreur->setFont(font4);
        affErreur->setStyleSheet(QStringLiteral("background:rgb(122, 122, 122);color:white;border:none"));
        calculatrice->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(calculatrice);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        calculatrice->setStatusBar(statusbar);

        retranslateUi(calculatrice);

        QMetaObject::connectSlotsByName(calculatrice);
    } // setupUi

    void retranslateUi(QMainWindow *calculatrice)
    {
        calculatrice->setWindowTitle(QApplication::translate("calculatrice", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("calculatrice", "Quitter", 0));
        actionAnnuler_Ctrl_Z->setText(QApplication::translate("calculatrice", "Annuler ( Ctrl + Z)", 0));
        actionR_tablie_Ctrl_Y->setText(QApplication::translate("calculatrice", "R\303\251tablie (Ctrl + Y)", 0));
        pushButton_RP->setText(QApplication::translate("calculatrice", ")", 0));
        pushButton_LP->setText(QApplication::translate("calculatrice", "(", 0));
        pushButton_FRAC->setText(QApplication::translate("calculatrice", "/", 0));
        pushButton_9->setText(QApplication::translate("calculatrice", "9", 0));
        pushButton_DOT->setText(QApplication::translate("calculatrice", ".", 0));
        pushButton_2->setText(QApplication::translate("calculatrice", "2", 0));
        pushButton_7->setText(QApplication::translate("calculatrice", "7", 0));
        pushButton_3->setText(QApplication::translate("calculatrice", "3", 0));
        pushButton_5->setText(QApplication::translate("calculatrice", "5", 0));
        pushButton_4->setText(QApplication::translate("calculatrice", "4", 0));
        pushButton_RB->setText(QApplication::translate("calculatrice", "]", 0));
        pushButton_6->setText(QApplication::translate("calculatrice", "6", 0));
        pushButton_0->setText(QApplication::translate("calculatrice", "0", 0));
        pushButton_COMPLEXE->setText(QApplication::translate("calculatrice", "i", 0));
        pushButton_8->setText(QApplication::translate("calculatrice", "8", 0));
        pushButton_LB->setText(QApplication::translate("calculatrice", "[", 0));
        pushButton_SPACE->setText(QApplication::translate("calculatrice", "ESPACE", 0));
        pushButton_1->setText(QApplication::translate("calculatrice", "1", 0));
        pushButton_MUL->setText(QApplication::translate("calculatrice", "*", 0));
        pushButton_DIVIDE->setText(QApplication::translate("calculatrice", "\303\267", 0));
        pushButton_DOLLAR->setText(QApplication::translate("calculatrice", "$", 0));
        pushButton_MOD->setText(QApplication::translate("calculatrice", "MOD", 0));
        pushButton_EQ->setText(QApplication::translate("calculatrice", "=", 0));
        pushButton_SOUS->setText(QApplication::translate("calculatrice", "-", 0));
        pushButton_ADD->setText(QApplication::translate("calculatrice", "+", 0));
        pushButton_DEN->setText(QApplication::translate("calculatrice", "DEN", 0));
        pushButton_RE->setText(QApplication::translate("calculatrice", "RE", 0));
        pushButton_NUM->setText(QApplication::translate("calculatrice", "NUM", 0));
        pushButton_NEG->setText(QApplication::translate("calculatrice", "NEG", 0));
        pushButton_IF->setText(QApplication::translate("calculatrice", "IFT", 0));
        pushButton_DIV->setText(QApplication::translate("calculatrice", "DIV", 0));
        pushButton_IM->setText(QApplication::translate("calculatrice", "IM", 0));
        pushButton_LASTOP->setText(QApplication::translate("calculatrice", "LASTOP", 0));
        pushButton_DUP->setText(QApplication::translate("calculatrice", "DUP", 0));
        pushButton_CLEAR->setText(QApplication::translate("calculatrice", "CLEAR", 0));
        pushButton_REDO->setText(QApplication::translate("calculatrice", "REDO", 0));
        pushButton_SWAP->setText(QApplication::translate("calculatrice", "SWAP", 0));
        pushButton_DROP->setText(QApplication::translate("calculatrice", "DROP", 0));
        pushButton_UNDO->setText(QApplication::translate("calculatrice", "UNDO", 0));
        pushButton_LASTARG->setText(QApplication::translate("calculatrice", "LASTARG", 0));
        pushButton_STO->setText(QApplication::translate("calculatrice", "STO", 0));
        pushButton_FORGET->setText(QApplication::translate("calculatrice", "FORGET", 0));
        pushButton_EVAL->setText(QApplication::translate("calculatrice", "EVAL", 0));
        pushButton->setText(QString());
        label->setText(QApplication::translate("calculatrice", "MEMOIRE", 0));
        label_2->setText(QApplication::translate("calculatrice", "VARIABLES", 0));
        pushButton_VALIDER->setText(QApplication::translate("calculatrice", "OK", 0));
        label_3->setText(QApplication::translate("calculatrice", "EDITION PROGRAMME", 0));
        label_4->setText(QApplication::translate("calculatrice", "VALEURS", 0));
        label_5->setText(QApplication::translate("calculatrice", "ERREURS", 0));
        valProg_2->setText(QApplication::translate("calculatrice", "OK", 0));
        label_6->setText(QApplication::translate("calculatrice", "NOM PROGRAMME", 0));
    } // retranslateUi

};

namespace Ui {
    class calculatrice: public Ui_calculatrice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATRICE_H
