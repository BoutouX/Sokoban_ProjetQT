#ifndef CIBLE_H
#define CIBLE_H
#include "case.h"

#include <QLabel>
#include <QWidget>

class Cible : public Case
{
    Q_OBJECT
public:
    int classe=2;
    explicit Cible (QWidget *parent = nullptr);
    void setSize() ;

private:
    QLabel *imageLabel;

};


#endif // CIBLE_H
