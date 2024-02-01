#ifndef MUR_H
#define MUR_H

#include "case.h"

#include<QPixmap>
#include <QPainter>
#include <QObject>
#include <QRect>

class Mur : public Case
{
public:
    Mur(int x, int y);
    void isclasse() override ;


};

#endif // MUR_H
