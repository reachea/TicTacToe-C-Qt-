#ifndef MARK_H
#define MARK_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <XO.h>

class Mark: public QGraphicsRectItem {
public:
    Mark(QGraphicsItem *parent=NULL);
    void player(QString player);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void createLines(QGraphicsPixmapItem *player);

    void findNeighbors(QGraphicsPixmapItem *player);

    QList<Xo *> neighborsVertical;
    QList<Xo *> neighborsHorizontal;
    QList<Xo *> neighborsLeftDiagonals;
    QList<Xo *> neighborsRightDiagonals;

    QList<QGraphicsLineItem *> linesVeritical;
    QList<QGraphicsLineItem *> linesHorizontal;
    QList<QGraphicsLineItem *> linesLeftDiagonals;
    QList<QGraphicsLineItem *> linesRightDiagonals;

    QString getOwner();
private:
    QString owner;
};

#endif // MARK_H
