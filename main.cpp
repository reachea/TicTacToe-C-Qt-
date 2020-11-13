#include <QApplication>
#include <Game.h>

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();

    game->music = new QMediaPlayer();
    game->music->setMedia(QUrl("qrc:/sounds/AppData/background_2.wav"));

    game->show();

    game->mainMenu();

    return a.exec();
}
