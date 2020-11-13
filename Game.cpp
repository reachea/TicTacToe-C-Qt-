#include <Game.h>
#include "Button.h"
#include "Icon.h"
#include "QGraphicsTextItem"
#include <QImage>
#include <QBrush>
#include <QDebug>
#include <QMediaPlayer>

Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // setup the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
}

QString Game::getWhosTurn(){
    return whosTurn_;
}

void Game::setWhosTurn(QString player){
    // change whosTurn player
    whosTurn_ = player;

    // change whosTurnText
    whosTurnText->setPlainText(QString("Who's Turn: " + player));
}

void Game::nextPlayerTurn(){
    if (getWhosTurn() == QString("X")) {
        setWhosTurn(QString("O"));
    } else {
        setWhosTurn(QString("X"));
    }
}

// almost finish
void Game::gameEnd(int boardSize, QList<Xo *> neighborsVertical, QList<Xo *> neighborsHorizontal, QList<Xo *> neighborsLeftDiagonals, QList<Xo *> neighborsRightDiagonals){
    if (boardSize == 0) {

        drawPanel(162,68,700,632,Qt::darkCyan,1);

        QGraphicsTextItem *gameTie = new QGraphicsTextItem(QString("Game Tie!"));
        gameTie->setPos(450,100);
        QFont gameTieFont("cosmic sans", 15);
        gameTie->setFont(gameTieFont);
        scene->addItem(gameTie);

        Button *playButton = new Button(QString("Play Again"));
        int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
        int byPos = 275;
        playButton->setPos(bxPos,byPos);
        scene->addItem(playButton);
        connect(playButton,SIGNAL(clicked()),this,SLOT(start()));

        // create the quit button
        Button *quitButton = new Button(QString("Quit"));
        int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
        int qyPos = 450;
        quitButton->setPos(qxPos,qyPos);
        scene->addItem(quitButton);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    } else {
        int counter = 0;
        // check vertical
        for (size_t i=0, n=neighborsVertical.size(); i<n; i++) {
            if (getWhosTurn() == neighborsVertical[i]->owner) {
                counter = counter + 1;
            }
        }
        if (counter < 3) {
            counter = 0;
        }

        // check horizontal
        for (size_t i=0, n=neighborsHorizontal.size(); i<n; i++) {
            if (getWhosTurn() == neighborsHorizontal[i]->owner) {
                counter = counter + 1;
            }
        }
        if (counter < 3){
            counter = 0;
        }

        // check left diagonals
        for (size_t i=0, n=neighborsLeftDiagonals.size(); i<n; i++) {
            if (getWhosTurn() == neighborsLeftDiagonals[i]->owner) {
                counter = counter + 1;
            }
        }
        if (counter < 3) {
            counter = 0;
        }

        // check right diagonals
        for (size_t i=0, n=neighborsRightDiagonals.size(); i<n; i++) {
            if (getWhosTurn() == neighborsRightDiagonals[i]->owner) {
                counter = counter + 1;
            }
        }
        if (counter < 3) {
            counter = 0;
        }
        if (counter >= 3) {
            drawPanel(162,68,700,632,Qt::darkCyan,1);

            QGraphicsTextItem *gameTie = new QGraphicsTextItem(QString("Winner: ") + whosTurn_);
            gameTie->setPos(450,100);
            QFont gameTieFont("cosmic sans", 15);
            gameTie->setFont(gameTieFont);
            scene->addItem(gameTie);

            Button *playButton = new Button(QString("Play Again"));
            int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
            int byPos = 275;
            playButton->setPos(bxPos,byPos);
            scene->addItem(playButton);
            connect(playButton,SIGNAL(clicked()),this,SLOT(choice()));

            // create the quit button
            Button *quitButton = new Button(QString("Quit"));
            int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
            int qyPos = 450;
            quitButton->setPos(qxPos,qyPos);
            scene->addItem(quitButton);
            connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        } else {
            counter = 0;
        }
    }
}

void Game::mainMenu(){
    // clear the scene
    scene->clear();

    if (music->state() == QMediaPlayer::StoppedState) {
        music->play();
    }

    // set background image
    setBackgroundBrush(QBrush(QImage(":/images/AppData/backgroundv2.jpg")));

    // create the play button
    Button *playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    scene->addItem(playButton);
    connect(playButton,SIGNAL(clicked()),this,SLOT(choice()));

    // create the quit button
    Button *quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 450;
    quitButton->setPos(qxPos,qyPos);
    scene->addItem(quitButton);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
}

void Game::choice(){
    // prompt to choose player
    scene->clear();

    // draw panel
    drawPanel(162,0,700,768,Qt::darkGray,1);

    setBackgroundBrush(QBrush(QImage(":/images/AppData/game_bg_3.jpg")));

    QGraphicsTextItem *gameTie = new QGraphicsTextItem(QString("Choose one of the following:"));
    gameTie->setPos(380,100);
    QFont gameTieFont("cosmic sans", 15);
    gameTie->setFont(gameTieFont);
    scene->addItem(gameTie);

    Icon *xPlayer = new Icon(QString(":/images/AppData/x.png"), NULL,  "X");
    int bxPos = this->width()/2 - xPlayer->boundingRect().width()/2;
    int byPos = 275;
    xPlayer->setPos(bxPos,byPos);
    scene->addItem(xPlayer);
    connect(xPlayer,SIGNAL(clicked(QString)),this,SLOT(start(QString)));

    // create the quit button
    Icon *oPlayer = new Icon(QString(":/images/AppData/o.png"), NULL , "O");
    int qxPos = this->width()/2 - oPlayer->boundingRect().width()/2;
    int qyPos = 450;
    oPlayer->setPos(qxPos,qyPos);
    scene->addItem(oPlayer);
    connect(oPlayer,SIGNAL(clicked(QString)),this,SLOT(start(QString)));
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem *panel = new QGraphicsRectItem();
    panel->setRect(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::drawGUI(QString player){
    // draw panel
    drawPanel(162,0,700,768,Qt::darkGray,0.5);

    // show whos turn
    whosTurnText = new QGraphicsTextItem();
    setWhosTurn(player);
    QFont whosTurnFont("cosmic sans", 15);
    whosTurnText->setFont(whosTurnFont);
    whosTurnText->setPos(450,0);
    scene->addItem(whosTurnText);
}

void Game::start(QString player){
    // clear all scene
    scene->clear();

    // set background image
    setBackgroundBrush(QBrush(QImage(":/images/AppData/game_bg_3.jpg")));

    // add game title
    QGraphicsTextItem *textTitle = new QGraphicsTextItem(QString("Tic Tac Toe!"));
    QFont titleFont("comic sans", 50);
    textTitle->setFont(titleFont);
    int txPos = this->width()/2 - textTitle->boundingRect().width()/2;
    int tyPos = 150;
    textTitle->setPos(txPos,tyPos);
    scene->addItem(textTitle);

    // add back button
    Icon *backButton = new Icon(QString(":/images/AppData/back.png"));
    backButton->setPos(25,25);
    scene->addItem(backButton);
    connect(backButton,SIGNAL(clicked(QString)),this,SLOT(mainMenu()));

    // draw GUI
    drawGUI(player);

    // create mark board
    markBoard = new MarkBoard();
    markBoard->placeBoard(162,50,7,7);
}

