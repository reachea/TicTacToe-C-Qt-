#include "Button.h"
#include <QBrush>
#include <QGraphicsTextItem>
#include <QPixmap>
#include <QFont>
#include <QCursor>

Button::Button(QString name, QGraphicsItem *parent){
    // create a rect
    setPixmap(QPixmap(":/images/AppData/button_modified.png"));

    // set text
    text = new QGraphicsTextItem(name,this);

    // modify button color and font
    text->setDefaultTextColor(Qt::white);
    QFont buttonFont("cosmic sans", 13);
    text->setFont(buttonFont);

    // set text position within button
    int xPos = pixmap().width()/2 - text->boundingRect().width()/2;
    int yPos = pixmap().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // Allow responding to the mouse event
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    text->setDefaultTextColor(Qt::darkCyan);
    setCursor(QCursor(Qt::PointingHandCursor));
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    text->setDefaultTextColor(Qt::white);
    setCursor(QCursor(Qt::ArrowCursor));
}
