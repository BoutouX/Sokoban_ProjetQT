#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "case.h"
#include "casevide.h"
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
            tableau[i][j] = new Casevide(i*(taille), j*(taille));
        }
    }

    delete tableau[8][8];
    tableau[8][8] = new Cible(8*(taille), 8*(taille));
    tableau[8][8]->isclasse();

    delete tableau[2][ligne-2];
    tableau[2][ligne-2] = new Cible(2*(taille), (ligne-2)*(taille));
    tableau[2][ligne-2]->isclasse();

    for (int i = 0; i < ligne; i++) {
        delete tableau[0][i];
        tableau[0][i] = new Mur(0*(taille), i*(taille));
        tableau[0][i]->isclasse();

        delete tableau[col-1][i];
        tableau[col-1][i] = new Mur((col-1)*(taille), i*(taille));
        tableau[col-1][i]->isclasse();

    }
    for (int j = 0; j < col; j++) {
        delete tableau[j][0];
        tableau[j][0] = new Mur(j*(taille), 0*(taille));
        tableau[j][0]->isclasse();

        delete tableau[j][ligne-1];
        tableau[j][ligne-1] = new Mur(j*(taille), (ligne-1)*(taille));
        tableau[j][ligne-1]->isclasse();

    }
    delete tableau[1][ligne-2];
    tableau[1][ligne-2] = new Mur(1*(taille), (ligne-2)*(taille));
    tableau[1][ligne-2]->isclasse();

    delete tableau[1][ligne-3];
    tableau[1][ligne-3] = new Mur(1*(taille), (ligne-3)*(taille));
    tableau[1][ligne-3]->isclasse();

    delete tableau[2][ligne-3];
    tableau[2][ligne-3] = new Mur(2*(taille), (ligne-3)*(taille));
    tableau[2][ligne-3]->isclasse();

    delete tableau[3][ligne-3];
    tableau[3][ligne-3] = new Mur(3*(taille), (ligne-3)*(taille));
    tableau[3][ligne-3]->isclasse();


    p = new Personnage(50,50);

}


void MainWindow::paintEvent(QPaintEvent* e) {

    QWidget::paintEvent(e);
    QPainter painter(this);

    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < col; j++) {
            if(tableau[i][j]->classe==1){
                tableau[i][j]->dessinercase(&painter,i ,j ,":/case/case.jpg");
            }
            else if(tableau[i][j]->classe==2){
                tableau[i][j]->dessinercase(&painter,i ,j ,":/cible/Cible.jpg");
            }
            else if(tableau[i][j]->classe==3){
                tableau[i][j]->dessinercase(&painter,i ,j ,":/mur/mur.jpg");
            }
        }
    }

    p->dessiner(&painter);
}

void MainWindow::puisjemedeplacer(const int x, const int y){



    if (tableau[x/50][y/50]->classe==1) {
        p->deplacer(x,y);

    }
    else if (tableau[x/50][y/50]->classe==2){
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



