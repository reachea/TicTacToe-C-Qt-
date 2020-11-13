#include <Mark.h>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <Game.h>
#include <QDebug>
#include <QMediaPlayer>

extern Game *game;

Mark::Mark(QGraphicsItem *parent){
    setRect(0,0,100,100);
}

QString Mark::getOwner(){
    return owner;
}

void Mark::player(QString player){
    owner = player;
    QMediaPlayer *placing = new QMediaPlayer();
    placing->setMedia(QUrl("qrc:/sounds/AppData/placing.wav"));

    Xo *xo = new Xo(owner);

    if (player == QString("X")) {
        xo->setPixmap(QPixmap(":/images/AppData/x.png"));
        xo->setPos(this->x(),this->y());
        game->scene->addItem(xo);
        createLines(xo);
        findNeighbors(xo);
        if(placing->state() == QMediaPlayer::PlayingState){
            placing->setPosition(0);
        } else if (placing->state() == QMediaPlayer::StoppedState){
            placing->play();
        }

    } else {
        xo->setPixmap(QPixmap(":/images/AppData/o.png"));
        xo->setPos(this->x(),this->y());
        game->scene->addItem(xo);
        createLines(xo);
        findNeighbors(xo);
        if(placing->state() == QMediaPlayer::PlayingState){
            placing->setPosition(0);
        } else if (placing->state() == QMediaPlayer::StoppedState){
            placing->play();
        }
    }
}

void Mark::mousePressEvent(QGraphicsSceneMouseEvent *event){
    game->scene->removeItem(this);

    player(game->getWhosTurn());

    game->markBoard->marks.removeAll(this);

    game->gameEnd(game->markBoard->marks.size(), neighborsVertical, neighborsHorizontal, neighborsLeftDiagonals, neighborsRightDiagonals);

    delete this;

    game->nextPlayerTurn();
}

// left over
void Mark::createLines(QGraphicsPixmapItem *player){
    QPointF centerPixmap(50,50);
    QPointF finalPixmap(centerPixmap.x(),centerPixmap.y()+300);
    QLineF ln(centerPixmap, finalPixmap);

    // vertical line
    for (int i=0, n=2; i<n; i++) {
        QLineF lnCopy(ln);
        lnCopy.setAngle(90+180*i);
        QGraphicsLineItem *line = new QGraphicsLineItem(lnCopy, player);
        linesVeritical.append(line);
        line->setVisible(false);
    }

    // horizontal line
    for (int i=0, n=2; i<n; i++) {
        QLineF lnCopy(ln);
        lnCopy.setAngle(180+180*i);
        QGraphicsLineItem *line = new QGraphicsLineItem(lnCopy, player);
        linesHorizontal.append(line);
        line->setVisible(false);
    }

    finalPixmap.setY(centerPixmap.y()+400);
    ln.setPoints(centerPixmap,finalPixmap);

    // left diagonals line
    for (int i=0, n=2; i<n; i++) {
        QLineF lnCopy(ln);
        lnCopy.setAngle(135+180*i);
        QGraphicsLineItem *line = new QGraphicsLineItem(lnCopy, player);
        linesLeftDiagonals.append(line);
        line->setVisible(false);
    }

    // right diagonals line
    for (int i=0, n=2; i<n; i++) {
        QLineF lnCopy(ln);
        lnCopy.setAngle(225+180*i);
        QGraphicsLineItem *line = new QGraphicsLineItem(lnCopy, player);
        linesRightDiagonals.append(line);
        line->setVisible(false);
    }
}

// left over
void Mark::findNeighbors(QGraphicsPixmapItem *player){
    for (size_t i=0, n=linesVeritical.size(); i<n; i++) {
        // if a line collides with item of type player, add it to neighbors

        // checking vertical
        QList<QGraphicsItem *> cItemsVertical = linesVeritical[i]->collidingItems();
        for (size_t j=0, n=cItemsVertical.size(); j<n; j++) {
            Xo* item = dynamic_cast<Xo *>(cItemsVertical[j]);
            if (cItemsVertical[j] != player && item) {
                 neighborsVertical.append(item);
            }
        }

        // checking horizontal
        QList<QGraphicsItem *> cItemsHorizontal = linesHorizontal[i]->collidingItems();
        for (size_t j=0, n=cItemsHorizontal.size(); j<n; j++) {
            Xo* item = dynamic_cast<Xo *>(cItemsHorizontal[j]);
            if (cItemsHorizontal[j] != player && item) {
                 neighborsHorizontal.append(item);
            }
        }

        // checking left diagonals
        QList<QGraphicsItem *> cItemsLeftDiagonals = linesLeftDiagonals[i]->collidingItems();
        for (size_t j=0, n=cItemsLeftDiagonals.size(); j<n; j++) {
            Xo* item = dynamic_cast<Xo *>(cItemsLeftDiagonals[j]);
            if (cItemsLeftDiagonals[j] != player && item) {
                 neighborsLeftDiagonals.append(item);
            }
        }

        // checking right diagonals
        QList<QGraphicsItem *> cItemsRightDiagonals = linesRightDiagonals[i]->collidingItems();
        for (size_t j=0, n=cItemsRightDiagonals.size(); j<n; j++) {
            Xo* item = dynamic_cast<Xo *>(cItemsRightDiagonals[j]);
            if (cItemsRightDiagonals[j] != player && item) {
                 neighborsRightDiagonals.append(item);
            }
        }
    }
}

