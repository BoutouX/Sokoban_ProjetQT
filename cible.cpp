#include "cible.h"

#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

Cible :: Cible (QWidget *parent): Case(parent){
    QVBoxLayout *layout = new QVBoxLayout(this);
    imageLabel = new QLabel(this);
    layout->addWidget(imageLabel);
}


void Cible::setSizecible()
{
    int taille = 50;
    // Régler la taille du widget Cible
    setFixedSize(taille, taille);
    setImagePath(":/cible/Cible.jpg");

}
void Cible::classecible(){
    classe = 2;
}
