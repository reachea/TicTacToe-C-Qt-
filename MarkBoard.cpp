#include "MarkBoard.h"
#include "Game.h"

extern Game *game;

MarkBoard::MarkBoard(){

}

QList<Mark *> MarkBoard::getMarks(){
    return marks;
}

void MarkBoard::placeBoard(int x, int y, int cols, int rows){
    for (size_t i=0, n=cols; i<n; i++) {
        createMarkColumn(x+100*i,y,rows);
    }
}

void MarkBoard::createMarkColumn(int x, int y, int rows){
    for (size_t i=0, n=rows; i<n; i++) {
        mark = new Mark();
        mark->setPos(x,y+100*i);
        marks.append(mark);
        game->scene->addItem(mark);
    }
}
