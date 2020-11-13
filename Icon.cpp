#include <Icon.h>
#include <QPixmap>
#include <QCursor>
#include <Game.h>

extern Game *game;

Icon::Icon(QString url, QGraphicsItem *parent, QString play) {
    // create an Icon
    setPixmap(QPixmap(url));

    // set player to given player
    setPlayer(play);

    // allow hover event
    setAcceptHoverEvents(true);
}

void Icon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked(player);
}

void Icon::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    setCursor(QCursor(Qt::PointingHandCursor));
}

void Icon::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    setCursor(QCursor(Qt::ArrowCursor));
}

QString Icon::getPlayer(){
    return player;
}

void Icon::setPlayer(QString play){
    player = play;
}
