#ifndef CASE_H
#define CASE_H

#include <QObject>
#include <QWidget>
#include <QLabel>


class Case : public QWidget
{
    Q_OBJECT
public:
    int classe=1;
    explicit Case (QWidget *parent = nullptr);
    void setImagePath(const QString &path);
    void setCoordinates(int x, int y);

    void setSize();

    private:
    QLabel *imageLabel;
};

#endif // CASE_H
