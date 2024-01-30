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
            tableau[i][j] = new Case(this);
            tableau[i][j]->setCoordinates(i*(taille), j*(taille));
            tableau[i][j]->setSize();
            tableau[i][j]->setParent(this);
            tableau[i][j]->show();
        }
    }

    delete tableau[8][8];
    tableau[8][8] = new Cible(this);
    tableau[8][8]->setCoordinates(8*(taille), 8*(taille));
    tableau[8][8]->setSize();
    tableau[8][8]->setParent(this);
    tableau[8][8]->show();

    p = new Personnage(50,50);

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



