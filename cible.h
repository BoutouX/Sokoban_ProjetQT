#ifndef CIBLE_H
#define CIBLE_H
#include "case.h"

#include <QLabel>
#include <QWidget>

class Cible : public Case
{
    Q_OBJECT
public:
    explicit Cible (QWidget *parent = nullptr);
    void classecible();
    void setSizecible() ;
private:
    QLabel *imageLabel;

};




#endif // CIBLE_H
