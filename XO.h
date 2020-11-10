#ifndef XO_H
#define XO_H

#include <QGraphicsPixmapItem>

class Xo: public QGraphicsPixmapItem{
public:
    Xo(QString player);

    QString getOwner();

    QString owner;
};

#endif // XO_H
