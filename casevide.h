#ifndef CASEVIDE_H
#define CASEVIDE_H
#include "case.h"

#include<QPixmap>
#include <QPainter>
#include <QObject>
#include <QRect>

class Casevide : public Case
{
public:
    Casevide(int x, int y);
    void isclasse() override;
};

#endif // CASEVIDE_H
