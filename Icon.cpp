#include <Icon.h>
#include <QPixmap>
#include <QCursor>

Icon::Icon(QString url, QGraphicsItem *parent) {
    // create an Icon
    setPixmap(QPixmap(url));

    // allow hover event
    setAcceptHoverEvents(true);
}

void Icon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Icon::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    setCursor(QCursor(Qt::PointingHandCursor));
}

void Icon::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    setCursor(QCursor(Qt::ArrowCursor));
}
