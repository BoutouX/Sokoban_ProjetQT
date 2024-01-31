#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "case.h"
#include "cible.h"
#include "mur.h"
#include "personnage.h"

#include <QDebug>
#include <QList>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            tableau[i][j] = new Cible(this);
            tableau[i][j]->setCoordinates(i*(taille), j*(taille));
            tableau[i][j]->setSize();
            tableau[i][j]->setParent(this);

        }
    }

    delete tableau[8][8];
    tableau[8][8] = new Cible(this);
    tableau[8][8]->setCoordinates(8*(taille), 8*(taille));
    tableau[8][8]->setSizecible();
    tableau[8][8]->classecible();
    tableau[8][8]->setParent(this);

    delete tableau[2][ligne-2];
    tableau[2][ligne-2] = new Cible(this);
    tableau[2][ligne-2]->setCoordinates(2*(taille), (ligne-2)*(taille));
    tableau[2][ligne-2]->setSizecible();
    tableau[2][ligne-2]->classecible();
    tableau[2][ligne-2]->setParent(this);

    for (int i = 0; i < ligne; i++) {
        delete tableau[0][i];
        tableau[0][i] = new Mur(this);
        tableau[0][i]->setCoordinates(0*(taille), i*(taille));
        tableau[0][i]->setSizemur();
        tableau[0][i]->classemur();
        tableau[0][i]->setParent(this);

        delete tableau[col-1][i];
        tableau[col-1][i] = new Mur(this);
        tableau[col-1][i]->setCoordinates((col-1)*(taille), i*(taille));
        tableau[col-1][i]->setSizemur();
        tableau[col-1][i]->classemur();
        tableau[col-1][i]->setParent(this);

    }
    for (int j = 0; j < col; j++) {
        delete tableau[j][0];
        tableau[j][0] = new Mur(this);
        tableau[j][0]->setCoordinates(j*(taille), 0*(taille));
        tableau[j][0]->setSizemur();
        tableau[j][0]->classemur();
        tableau[j][0]->setParent(this);

        delete tableau[j][ligne-1];
        tableau[j][ligne-1] = new Mur(this);
        tableau[j][ligne-1]->setCoordinates(j*(taille), (ligne-1)*(taille));
        tableau[j][ligne-1]->setSizemur();
        tableau[j][ligne-1]->classemur();
        tableau[j][ligne-1]->setParent(this);

    }
    delete tableau[1][ligne-2];
    tableau[1][ligne-2] = new Mur(this);
    tableau[1][ligne-2]->setCoordinates(1*(taille), (ligne-2)*(taille));
    tableau[1][ligne-2]->setSizemur();
    tableau[1][ligne-2]->classemur();
    tableau[1][ligne-2]->setParent(this);

    delete tableau[1][ligne-3];
    tableau[1][ligne-3] = new Mur(this);
    tableau[1][ligne-3]->setCoordinates(1*(taille), (ligne-3)*(taille));
    tableau[1][ligne-3]->setSizemur();
    tableau[1][ligne-3]->classemur();
    tableau[1][ligne-3]->setParent(this);

    delete tableau[2][ligne-3];
    tableau[2][ligne-3] = new Mur(this);
    tableau[2][ligne-3]->setCoordinates(2*(taille), (ligne-3)*(taille));
    tableau[2][ligne-3]->setSizemur();
    tableau[2][ligne-3]->classemur();
    tableau[2][ligne-3]->setParent(this);

    delete tableau[3][ligne-3];
    tableau[3][ligne-3] = new Mur(this);
    tableau[3][ligne-3]->setCoordinates(3*(taille), (ligne-3)*(taille));
    tableau[3][ligne-3]->setSizemur();
    tableau[3][ligne-3]->classemur();
    tableau[3][ligne-3]->setParent(this);


    p = new Personnage(50,50);
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            tableau[i][j]->show();
        }
    }
    tableau[1][1]->hide();
}


void MainWindow::paintEvent(QPaintEvent* e) {

    QWidget::paintEvent(e);
    QPainter painter(this);

    p->dessiner(&painter);
}

void MainWindow::puisjemedeplacer(const int x, const int y){



    if (tableau[x/50][y/50]->classe==1) {
        tableau[p->getX()/50][p->getY()/50]->show();
        tableau[x/50][y/50]->hide();
        p->deplacer(x,y);

    }
    else if (tableau[x/50][y/50]->classe==2){
        tableau[p->getX()/50][p->getY()/50]->show();
        tableau[x/50][y/50]->hide();
        p->deplacer(x,y);

    }
}

void MainWindow::keyPressEvent(QKeyEvent* event) {

    int taille = 50;

    switch(event->key())
    {
    case Qt::Key_Left :
    {
        puisjemedeplacer(p->getX()-taille, p->getY());
        break;
    }
    case Qt::Key_Right :
    {
        puisjemedeplacer(p->getX()+taille,p->getY());
        break;
    }
    case Qt::Key_Down :
    {
        puisjemedeplacer(p->getX(),p->getY()+taille);
        break;
    }
    case Qt::Key_Up :
    {
        puisjemedeplacer(p->getX(),p->getY()-taille);
        break;
    }
    }
    repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}



