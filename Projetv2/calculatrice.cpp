#include "Calculatrice.h"
#include "ui_calculatrice.h"

using namespace std;


calculatrice::calculatrice(QWidget *parent) :
    QMainWindow(parent),
    lm(LitteraleManager()),
    p(Pile()),
    hm(HashMap()),
    c(Controleur(lm,p,hm)),
    ui(new Ui::calculatrice)
{
    ui->setupUi(this);
    ui->ligneCommande->installEventFilter(this);
    QSignalMapper* mapLitt = new QSignalMapper(this);
    QSignalMapper* mapOp = new QSignalMapper(this);
    ui->affErreur->setDisabled(1);
    //ui->affErreur->setText("Erreur: haha bim, une erreur");

    connect(ui->pushButton_SPACE,SIGNAL(clicked()), this, SLOT(space()));
    connect(ui->pushButton_VALIDER,SIGNAL(clicked()), this, SLOT(execute()));
    connect(ui->affPile, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(stackClicked(QListWidgetItem*)));
    //connect(ui->actionQuitter,SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

    connect(ui->pushButton_0,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_1,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_2,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_3,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_4,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_5,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_6,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_7,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_8,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_9,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_LP,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_RP,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_LB,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_RB,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_DOT,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_COMPLEXE,SIGNAL(clicked()), mapLitt, SLOT(map()));
    connect(ui->pushButton_FRAC,SIGNAL(clicked()), mapLitt, SLOT(map()));

    //Touches sans actions sur la pile:
    mapLitt -> setMapping(ui->pushButton_0, "0");
    mapLitt -> setMapping(ui->pushButton_1, "1");
    mapLitt -> setMapping(ui->pushButton_2, "2");
    mapLitt -> setMapping(ui->pushButton_3, "3");
    mapLitt -> setMapping(ui->pushButton_4, "4");
    mapLitt -> setMapping(ui->pushButton_5, "5");
    mapLitt -> setMapping(ui->pushButton_6, "6");
    mapLitt -> setMapping(ui->pushButton_7, "7");
    mapLitt -> setMapping(ui->pushButton_8, "8");
    mapLitt -> setMapping(ui->pushButton_9, "9");
    mapLitt -> setMapping(ui->pushButton_LP, "(");
    mapLitt -> setMapping(ui->pushButton_RP, ")");
    mapLitt -> setMapping(ui->pushButton_LB, "[");
    mapLitt -> setMapping(ui->pushButton_RB, "]");
    mapLitt -> setMapping(ui->pushButton_DOT, ".");
    mapLitt -> setMapping(ui->pushButton_COMPLEXE, "$");
    mapLitt -> setMapping(ui->pushButton_FRAC, "/");


    connect(ui->pushButton_ADD,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_DIVIDE,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_SOUS,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_MUL,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_DOLLAR,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_IF,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_MOD,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_DIV,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_NEG,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_NUM,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_DEN,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_RE,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_IM,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_STO,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_FORGET,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_EVAL,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_DUP,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_DROP,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_SWAP,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_LASTOP,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_LASTARG,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_CLEAR,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_UNDO,SIGNAL(clicked()), mapOp, SLOT(map()));
    connect(ui->pushButton_REDO,SIGNAL(clicked()), mapOp, SLOT(map()));

    //Touches avec action:
    mapOp -> setMapping(ui->pushButton_ADD, "+");
    mapOp -> setMapping(ui->pushButton_DIVIDE, "/");
    mapOp -> setMapping(ui->pushButton_SOUS, "-");
    mapOp -> setMapping(ui->pushButton_MUL, "*");
    mapOp -> setMapping(ui->pushButton_DOLLAR, "$");
    mapOp -> setMapping(ui->pushButton_IF, "IFT");
    mapOp -> setMapping(ui->pushButton_MOD, "MOD");
    mapOp -> setMapping(ui->pushButton_DIV, "DIV");
    mapOp -> setMapping(ui->pushButton_NEG, "NEG");
    mapOp -> setMapping(ui->pushButton_NUM, "NUM");
    mapOp -> setMapping(ui->pushButton_DEN, "DEN");
    mapOp -> setMapping(ui->pushButton_RE, "RE");
    mapOp -> setMapping(ui->pushButton_IM, "IM");

    mapOp -> setMapping(ui->pushButton_STO, "STO");
    mapOp -> setMapping(ui->pushButton_FORGET, "FORGET");
    mapOp -> setMapping(ui->pushButton_EVAL, "EVAL");

    mapOp -> setMapping(ui->pushButton_DUP, "DUP");
    mapOp -> setMapping(ui->pushButton_DROP, "DROP");
    mapOp -> setMapping(ui->pushButton_SWAP, "SWAP");
    mapOp -> setMapping(ui->pushButton_LASTOP, "LASTOP");
    mapOp -> setMapping(ui->pushButton_LASTARG, "LASTARG");
    mapOp -> setMapping(ui->pushButton_CLEAR, "CLEAR");
    mapOp -> setMapping(ui->pushButton_UNDO, "UNDO");
    mapOp -> setMapping(ui->pushButton_REDO, "REDO");

    connect(mapLitt, SIGNAL(mapped(QString)), this, SLOT(readLitt(QString)));
    connect(mapOp, SIGNAL(mapped(QString)), this, SLOT(execute(QString)));
}

calculatrice::~calculatrice()
{
    delete ui;
}

void calculatrice::readLitt(QString s){
    this->entree += s;
    ui->ligneCommande->setText(this->entree);
}

void calculatrice::execute(QString s){
    ui->affErreur->clear();
    ui->affErreur->setStyleSheet("");
    if(this->entree.indexOf("'(") == -1){
        this->entree += s;
        QStringList sList = this->entree.split(" ");
        for(QStringList::iterator it = sList.begin(); it != sList.end(); ++it){
            QString current = *it;
            std::string input = current.toLocal8Bit().constData();
            try{
                this->c.parse(input);
            }
            catch(ComputerException e){
                string s = e.getInfo();
                QString erreur = QString::fromStdString(s);
                ui->affErreur->setText(erreur);
                ui->affErreur->setStyleSheet("QLineEdit{background-color : rgb(222,65,80); color: white}");
            }
        }
   }
   else{
        std::string input = this->entree.toLocal8Bit().constData();
        try{
            this->c.parse(input);
        }
        catch(ComputerException e){
            string s = e.getInfo();
            QString erreur = QString::fromStdString(s);
            ui->affErreur->setText(erreur);
            ui->affErreur->setStyleSheet("QLineEdit{background-color : rgb(222,65,80); color:white}");
        }
   }
    QStringList items;
    for (Pile::Iterator it = p.rbegin(); it != p.rend(); --it){
       Item i = *it;
       Litterale* test = i.getLitterale();
       const string& test2 = test->toString();
       QString qstr = QString::fromStdString(test2);
       items += qstr;
        qWarning("Test");
    }

    ui->affPile->clear();
    ui->affPile->addItems(items);

    this->entree.clear();
    ui->ligneCommande->clear();
}


void calculatrice::space(){
    this->entree += " ";
    ui->ligneCommande->setText(this->entree);
}

void calculatrice::stackClicked(QListWidgetItem *q)
{
    this->entree+=q->text();
    ui->ligneCommande->setText(this->entree);
}

void calculatrice::keyPressEvent(QKeyEvent *event)
{
    QKeySequence(Qt::Key_0,Qt::Key_1);
    if (event->matches(QKeySequence::Undo))
      {
        execute("UNDO");
      }
    if (event->matches(QKeySequence::Redo))
      {
        execute("REDO");
      }
    switch(event->key()){
        case Qt::Key_Return:
            execute("");
            break;
        case Qt::Key_Space:
            space();
            break;
        default: break;
    }
}

bool calculatrice::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->ligneCommande && event->type() == QEvent::KeyRelease)
    {
        QKeyEvent *kEvent = static_cast<QKeyEvent*>(event);
        if (kEvent->matches(QKeySequence::Undo))
          {
            execute("UNDO");
          }
        if (kEvent->matches(QKeySequence::Redo))
          {
            execute("REDO");
          }
        this->entree = ui->ligneCommande->text();
        if(this->entree.indexOf("'(") == -1){
            switch(kEvent->key()){
                case Qt::Key_Plus:
                    execute("");
                case Qt::Key_Minus:
                    execute("");
                case Qt::Key_multiply:
                    execute("");
                case Qt::Key_Slash:
                    execute("");
                case Qt::Key_Dollar:
                    execute("");
            }
        }
    }
    return QObject::eventFilter(obj, event);
}


