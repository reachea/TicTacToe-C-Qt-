#ifndef MARKBOARD_H
#define MARKBOARD_H

#include "Mark.h"
#include <QList>

class MarkBoard{
public:
    // constructor
    MarkBoard();

    // getters&setters
    QList<Mark *> getMarks();

    // place the board
    void placeBoard(int x, int y,int cols,int rows);

    Mark *mark;

    // list of marks
    QList<Mark *> marks;
private:
    // create a column
    void createMarkColumn(int x,int y,int rows);
};


#endif // MARKBOARD_H
