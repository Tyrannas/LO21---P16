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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QPushButton *pushButton_FRAC;
    QPushButton *pushButton_1;
    QPushButton *pushButton_LP;
    QPushButton *pushButton_RP;
    QPushButton *pushButton_9;
    QPushButton *pushButton_DOT;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_0;
    QPushButton *pushButton_8;
    QPushButton *pushButton_LB;
    QPushButton *pushButton_COMPLEXE;
    QPushButton *pushButton_RB;
    QPushButton *pushButton_SPACE;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_DEN;
    QPushButton *pushButton_DOLLAR;
    QPushButton *pushButton_MUL;
    QPushButton *pushButton_DIVIDE;
    QPushButton *pushButton_EQ;
    QPushButton *pushButton_ADD;
    QPushButton *pushButton_SOUS;
    QPushButton *pushButton_MOD;
    QPushButton *pushButton_DIV;
    QPushButton *pushButton_NEG;
    QPushButton *pushButton_IF;
    QPushButton *pushButton_NUM;
    QPushButton *pushButton_RE;
    QPushButton *pushButton_IM;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_DUP;
    QPushButton *pushButton_CLEAR;
    QPushButton *pushButton_LASTOP;
    QPushButton *pushButton_LASTARG;
    QPushButton *pushButton_UNDO;
    QPushButton *pushButton_REDO;
    QPushButton *pushButton_DROP;
    QPushButton *pushButton_SWAP;
    QPushButton *pushButton_EVAL;
    QListWidget *listWidget;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_STO;
    QPushButton *pushButton_FORGET;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuEdition;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *calculatrice)
    {
        if (calculatrice->objectName().isEmpty())
            calculatrice->setObjectName(QStringLiteral("calculatrice"));
        calculatrice->resize(842, 622);
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
        ligneCommande->setGeometry(QRect(10, 10, 531, 41));
        QFont font;
        font.setFamily(QStringLiteral("Roboto Light"));
        font.setPointSize(13);
        ligneCommande->setFont(font);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 60, 295, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_FRAC = new QPushButton(gridLayoutWidget);
        pushButton_FRAC->setObjectName(QStringLiteral("pushButton_FRAC"));

        gridLayout->addWidget(pushButton_FRAC, 4, 1, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        QFont font1;
        font1.setPointSize(7);
        pushButton_1->setFont(font1);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_LP = new QPushButton(gridLayoutWidget);
        pushButton_LP->setObjectName(QStringLiteral("pushButton_LP"));

        gridLayout->addWidget(pushButton_LP, 3, 0, 1, 1);

        pushButton_RP = new QPushButton(gridLayoutWidget);
        pushButton_RP->setObjectName(QStringLiteral("pushButton_RP"));

        gridLayout->addWidget(pushButton_RP, 3, 2, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_DOT = new QPushButton(gridLayoutWidget);
        pushButton_DOT->setObjectName(QStringLiteral("pushButton_DOT"));

        gridLayout->addWidget(pushButton_DOT, 4, 0, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_0 = new QPushButton(gridLayoutWidget);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));

        gridLayout->addWidget(pushButton_0, 3, 1, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_LB = new QPushButton(gridLayoutWidget);
        pushButton_LB->setObjectName(QStringLiteral("pushButton_LB"));

        gridLayout->addWidget(pushButton_LB, 5, 0, 1, 1);

        pushButton_COMPLEXE = new QPushButton(gridLayoutWidget);
        pushButton_COMPLEXE->setObjectName(QStringLiteral("pushButton_COMPLEXE"));

        gridLayout->addWidget(pushButton_COMPLEXE, 4, 2, 1, 1);

        pushButton_RB = new QPushButton(gridLayoutWidget);
        pushButton_RB->setObjectName(QStringLiteral("pushButton_RB"));

        gridLayout->addWidget(pushButton_RB, 5, 2, 1, 1);

        pushButton_SPACE = new QPushButton(gridLayoutWidget);
        pushButton_SPACE->setObjectName(QStringLiteral("pushButton_SPACE"));

        gridLayout->addWidget(pushButton_SPACE, 5, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(310, 60, 241, 288));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(15);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_DEN = new QPushButton(gridLayoutWidget_2);
        pushButton_DEN->setObjectName(QStringLiteral("pushButton_DEN"));

        gridLayout_2->addWidget(pushButton_DEN, 4, 1, 1, 1);

        pushButton_DOLLAR = new QPushButton(gridLayoutWidget_2);
        pushButton_DOLLAR->setObjectName(QStringLiteral("pushButton_DOLLAR"));

        gridLayout_2->addWidget(pushButton_DOLLAR, 5, 0, 1, 1);

        pushButton_MUL = new QPushButton(gridLayoutWidget_2);
        pushButton_MUL->setObjectName(QStringLiteral("pushButton_MUL"));

        gridLayout_2->addWidget(pushButton_MUL, 2, 0, 1, 1);

        pushButton_DIVIDE = new QPushButton(gridLayoutWidget_2);
        pushButton_DIVIDE->setObjectName(QStringLiteral("pushButton_DIVIDE"));

        gridLayout_2->addWidget(pushButton_DIVIDE, 3, 0, 1, 1);

        pushButton_EQ = new QPushButton(gridLayoutWidget_2);
        pushButton_EQ->setObjectName(QStringLiteral("pushButton_EQ"));

        gridLayout_2->addWidget(pushButton_EQ, 4, 0, 1, 1);

        pushButton_ADD = new QPushButton(gridLayoutWidget_2);
        pushButton_ADD->setObjectName(QStringLiteral("pushButton_ADD"));

        gridLayout_2->addWidget(pushButton_ADD, 0, 0, 1, 1);

        pushButton_SOUS = new QPushButton(gridLayoutWidget_2);
        pushButton_SOUS->setObjectName(QStringLiteral("pushButton_SOUS"));

        gridLayout_2->addWidget(pushButton_SOUS, 1, 0, 1, 1);

        pushButton_MOD = new QPushButton(gridLayoutWidget_2);
        pushButton_MOD->setObjectName(QStringLiteral("pushButton_MOD"));

        gridLayout_2->addWidget(pushButton_MOD, 0, 1, 1, 1);

        pushButton_DIV = new QPushButton(gridLayoutWidget_2);
        pushButton_DIV->setObjectName(QStringLiteral("pushButton_DIV"));

        gridLayout_2->addWidget(pushButton_DIV, 1, 1, 1, 1);

        pushButton_NEG = new QPushButton(gridLayoutWidget_2);
        pushButton_NEG->setObjectName(QStringLiteral("pushButton_NEG"));

        gridLayout_2->addWidget(pushButton_NEG, 2, 1, 1, 1);

        pushButton_IF = new QPushButton(gridLayoutWidget_2);
        pushButton_IF->setObjectName(QStringLiteral("pushButton_IF"));

        gridLayout_2->addWidget(pushButton_IF, 6, 0, 1, 1);

        pushButton_NUM = new QPushButton(gridLayoutWidget_2);
        pushButton_NUM->setObjectName(QStringLiteral("pushButton_NUM"));

        gridLayout_2->addWidget(pushButton_NUM, 3, 1, 1, 1);

        pushButton_RE = new QPushButton(gridLayoutWidget_2);
        pushButton_RE->setObjectName(QStringLiteral("pushButton_RE"));

        gridLayout_2->addWidget(pushButton_RE, 5, 1, 1, 1);

        pushButton_IM = new QPushButton(gridLayoutWidget_2);
        pushButton_IM->setObjectName(QStringLiteral("pushButton_IM"));

        gridLayout_2->addWidget(pushButton_IM, 6, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 360, 541, 141));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_DUP = new QPushButton(gridLayoutWidget_3);
        pushButton_DUP->setObjectName(QStringLiteral("pushButton_DUP"));

        gridLayout_3->addWidget(pushButton_DUP, 0, 0, 1, 1);

        pushButton_CLEAR = new QPushButton(gridLayoutWidget_3);
        pushButton_CLEAR->setObjectName(QStringLiteral("pushButton_CLEAR"));

        gridLayout_3->addWidget(pushButton_CLEAR, 3, 0, 1, 1);

        pushButton_LASTOP = new QPushButton(gridLayoutWidget_3);
        pushButton_LASTOP->setObjectName(QStringLiteral("pushButton_LASTOP"));

        gridLayout_3->addWidget(pushButton_LASTOP, 0, 1, 1, 1);

        pushButton_LASTARG = new QPushButton(gridLayoutWidget_3);
        pushButton_LASTARG->setObjectName(QStringLiteral("pushButton_LASTARG"));

        gridLayout_3->addWidget(pushButton_LASTARG, 1, 1, 1, 1);

        pushButton_UNDO = new QPushButton(gridLayoutWidget_3);
        pushButton_UNDO->setObjectName(QStringLiteral("pushButton_UNDO"));

        gridLayout_3->addWidget(pushButton_UNDO, 2, 1, 1, 1);

        pushButton_REDO = new QPushButton(gridLayoutWidget_3);
        pushButton_REDO->setObjectName(QStringLiteral("pushButton_REDO"));

        gridLayout_3->addWidget(pushButton_REDO, 3, 1, 1, 1);

        pushButton_DROP = new QPushButton(gridLayoutWidget_3);
        pushButton_DROP->setObjectName(QStringLiteral("pushButton_DROP"));

        gridLayout_3->addWidget(pushButton_DROP, 1, 0, 1, 1);

        pushButton_SWAP = new QPushButton(gridLayoutWidget_3);
        pushButton_SWAP->setObjectName(QStringLiteral("pushButton_SWAP"));

        gridLayout_3->addWidget(pushButton_SWAP, 2, 0, 1, 1);

        pushButton_EVAL = new QPushButton(centralwidget);
        pushButton_EVAL->setObjectName(QStringLiteral("pushButton_EVAL"));
        pushButton_EVAL->setGeometry(QRect(390, 510, 151, 41));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(560, 0, 271, 561));
        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(9, 510, 331, 51));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_STO = new QPushButton(gridLayoutWidget_4);
        pushButton_STO->setObjectName(QStringLiteral("pushButton_STO"));

        gridLayout_4->addWidget(pushButton_STO, 0, 0, 1, 1);

        pushButton_FORGET = new QPushButton(gridLayoutWidget_4);
        pushButton_FORGET->setObjectName(QStringLiteral("pushButton_FORGET"));

        gridLayout_4->addWidget(pushButton_FORGET, 0, 1, 1, 1);

        calculatrice->setCentralWidget(centralwidget);
        menubar = new QMenuBar(calculatrice);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 842, 26));
        QFont font2;
        font2.setFamily(QStringLiteral("Rounded Elegance"));
        menubar->setFont(font2);
        menubar->setCursor(QCursor(Qt::ArrowCursor));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuEdition = new QMenu(menubar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        calculatrice->setMenuBar(menubar);
        statusbar = new QStatusBar(calculatrice);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        calculatrice->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuEdition->menuAction());
        menuMenu->addAction(actionQuitter);
        menuEdition->addAction(actionAnnuler_Ctrl_Z);
        menuEdition->addAction(actionR_tablie_Ctrl_Y);

        retranslateUi(calculatrice);

        QMetaObject::connectSlotsByName(calculatrice);
    } // setupUi

    void retranslateUi(QMainWindow *calculatrice)
    {
        calculatrice->setWindowTitle(QApplication::translate("calculatrice", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("calculatrice", "Quitter", 0));
        actionAnnuler_Ctrl_Z->setText(QApplication::translate("calculatrice", "Annuler ( Ctrl + Z)", 0));
        actionR_tablie_Ctrl_Y->setText(QApplication::translate("calculatrice", "R\303\251tablie (Ctrl + Y)", 0));
        pushButton_FRAC->setText(QApplication::translate("calculatrice", "/", 0));
        pushButton_1->setText(QApplication::translate("calculatrice", "1", 0));
        pushButton_LP->setText(QApplication::translate("calculatrice", "(", 0));
        pushButton_RP->setText(QApplication::translate("calculatrice", ")", 0));
        pushButton_9->setText(QApplication::translate("calculatrice", "9", 0));
        pushButton_DOT->setText(QApplication::translate("calculatrice", ".", 0));
        pushButton_7->setText(QApplication::translate("calculatrice", "7", 0));
        pushButton_3->setText(QApplication::translate("calculatrice", "3", 0));
        pushButton_2->setText(QApplication::translate("calculatrice", "2", 0));
        pushButton_4->setText(QApplication::translate("calculatrice", "4", 0));
        pushButton_5->setText(QApplication::translate("calculatrice", "5", 0));
        pushButton_6->setText(QApplication::translate("calculatrice", "6", 0));
        pushButton_0->setText(QApplication::translate("calculatrice", "0", 0));
        pushButton_8->setText(QApplication::translate("calculatrice", "8", 0));
        pushButton_LB->setText(QApplication::translate("calculatrice", "[", 0));
        pushButton_COMPLEXE->setText(QApplication::translate("calculatrice", "i", 0));
        pushButton_RB->setText(QApplication::translate("calculatrice", "]", 0));
        pushButton_SPACE->setText(QApplication::translate("calculatrice", "ESPACE", 0));
        pushButton_DEN->setText(QApplication::translate("calculatrice", "DEN", 0));
        pushButton_DOLLAR->setText(QApplication::translate("calculatrice", "$", 0));
        pushButton_MUL->setText(QApplication::translate("calculatrice", "*", 0));
        pushButton_DIVIDE->setText(QApplication::translate("calculatrice", "\303\267", 0));
        pushButton_EQ->setText(QApplication::translate("calculatrice", "=", 0));
        pushButton_ADD->setText(QApplication::translate("calculatrice", "+", 0));
        pushButton_SOUS->setText(QApplication::translate("calculatrice", "-", 0));
        pushButton_MOD->setText(QApplication::translate("calculatrice", "MOD", 0));
        pushButton_DIV->setText(QApplication::translate("calculatrice", "DIV", 0));
        pushButton_NEG->setText(QApplication::translate("calculatrice", "NEG", 0));
        pushButton_IF->setText(QApplication::translate("calculatrice", "IFT", 0));
        pushButton_NUM->setText(QApplication::translate("calculatrice", "NUM", 0));
        pushButton_RE->setText(QApplication::translate("calculatrice", "RE", 0));
        pushButton_IM->setText(QApplication::translate("calculatrice", "IM", 0));
        pushButton_DUP->setText(QApplication::translate("calculatrice", "DUP", 0));
        pushButton_CLEAR->setText(QApplication::translate("calculatrice", "CLEAR", 0));
        pushButton_LASTOP->setText(QApplication::translate("calculatrice", "LASTOP", 0));
        pushButton_LASTARG->setText(QApplication::translate("calculatrice", "LASTARG", 0));
        pushButton_UNDO->setText(QApplication::translate("calculatrice", "UNDO", 0));
        pushButton_REDO->setText(QApplication::translate("calculatrice", "REDO", 0));
        pushButton_DROP->setText(QApplication::translate("calculatrice", "DROP", 0));
        pushButton_SWAP->setText(QApplication::translate("calculatrice", "SWAP", 0));
        pushButton_EVAL->setText(QApplication::translate("calculatrice", "EVAL", 0));
        pushButton_STO->setText(QApplication::translate("calculatrice", "STO", 0));
        pushButton_FORGET->setText(QApplication::translate("calculatrice", "FORGET", 0));
        menuMenu->setTitle(QApplication::translate("calculatrice", "Menu", 0));
        menuEdition->setTitle(QApplication::translate("calculatrice", "Edition", 0));
    } // retranslateUi

};

namespace Ui {
    class calculatrice: public Ui_calculatrice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATRICE_H
