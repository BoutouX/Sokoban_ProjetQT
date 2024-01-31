#ifndef MUR_H
#define MUR_H

#include "case.h"

#include <QWidget>
#include <QLabel>


class Mur : public Case
{
    Q_OBJECT
public:

    explicit Mur (QWidget *parent = nullptr);
    void setSizemur();
    void classemur();

private:
    QLabel *imageLabel;

};

#endif // MUR_H
