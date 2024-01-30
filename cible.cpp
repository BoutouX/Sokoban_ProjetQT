#include "cible.h"

#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

Cible :: Cible (QWidget *parent): Case(parent){

}


void Cible::setSize()
{
    int taille = 50;
    // Régler la taille du widget Cible
    setFixedSize(taille, taille);
    setImagePath(":/cible/Cible.jpg");

}
