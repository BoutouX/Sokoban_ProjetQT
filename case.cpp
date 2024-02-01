#include "case.h"
#include <QPixmap>
#include <string>

Case :: Case (int x, int y) {

    this->x = x;
    this->y = y;

}

void dessinercase(QPainter * c,int x, int y,char* chemin){
    c->setPen( QPen(Qt::black, 1) );
    c->drawPixmap(x,y,50,50,QPixmap(chemin));
}

