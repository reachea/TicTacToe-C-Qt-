#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <MarkBoard.h>
#include <QMediaPlayer>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget *parent=NULL);

    // public attributes
    QGraphicsScene *scene;
    QGraphicsRectItem *rect;
    MarkBoard *markBoard;
    QMediaPlayer *music;

    // public methods
    QString getWhosTurn();
    void setWhosTurn(QString player);
    void nextPlayerTurn();
    void gameEnd(int boardSize, QList<Xo *> neighborsVertical, QList<Xo *> neighborsHorizontal, QList<Xo *> neighborsLeftDiagonals, QList<Xo *> neighborsRightDiagonals);
    void choosePlayer();

public slots:
    void start(QString player);
    void mainMenu();
    void choice();
private:
    // private methods
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI(QString player);

    // private attributes
    QString whosTurn_;
    QGraphicsTextItem *whosTurnText;
};

#endif // GAME_H
