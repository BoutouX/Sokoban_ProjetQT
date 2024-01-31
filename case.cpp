#include "case.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>

Case :: Case (QWidget *parent): QWidget{parent} {

    QVBoxLayout *layout = new QVBoxLayout(this);
    imageLabel = new QLabel(this);
    layout->addWidget(imageLabel);

}
void Case::setImagePath(const QString &path)
{
    // Définir le chemin d'accès à l'image sur le QLabel
    QPixmap image(path);
    if (!image.isNull()) {
        imageLabel->setPixmap(image);
        imageLabel->setFixedSize(image.size());
    } else {
        qWarning() << "Échec du chargement de l'image depuis le chemin : " << path;
    }
}

void Case::setCoordinates(int x, int y)
{
    // Définir les coordonnées du widget Mur
    move(x, y);
}

void Case::setSize()
{
    int taille;
    taille = 50;
    // Régler la taille du widget Case
    setFixedSize(taille, taille);
    setImagePath(":/case/case.jpg");
}

void Case::setSizecible(){}
void Case::setSizemur(){}
void Case::classemur(){}
void Case::classecible(){}
