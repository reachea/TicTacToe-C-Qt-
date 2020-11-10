#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Button:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    // constructor
    Button(QString name, QGraphicsItem *parent=NULL);

    // public methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem *text;
};

#endif // BUTTON_H
