#ifndef CASE_H
#define CASE_H

#include <QPainter>
#include <QObject>
#include <QRect>

class Case
{
protected:
    int x,y;


public:
    int classe=1;
    Case (int x, int y);
    virtual void isclasse()=0;
    void dessinercase(QPainter * c,int x, int y, char* chemin);

};

#endif // CASE_H
