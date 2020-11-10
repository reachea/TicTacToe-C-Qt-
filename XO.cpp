#include <XO.h>

Xo::Xo(QString player){
    owner = player;
}

QString Xo::getOwner(){
    return owner;
}
