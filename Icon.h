#ifndef ICON_H
#define ICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class Icon:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    // constructor
    Icon(QString url, QGraphicsItem *parent=0, QString play=NULL);

    // public methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    QString getPlayer();
    void setPlayer(QString play);

    // public attributes
    QString player;
signals:
    void clicked(QString player);
};

#endif // ICON_H
