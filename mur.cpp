#include "mur.h"

#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

Mur :: Mur (QWidget *parent): Case(parent){

}

void Mur::setSizemur()
{
    int taille = 50;
    // Régler la taille du widget Mur
    setFixedSize(taille, taille);
    setImagePath(":/mur/Mur.jpg");
}
void Mur::classemur(){
    classe = 3;
}



