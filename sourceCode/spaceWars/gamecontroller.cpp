#include "gamecontroller.h"
const int gameController::_FIELD_HEIGHT=65;
const int gameController::_FIELD_WIDTH=70;

int gameController::printUI()
{
    QList<graphicChar> Area;


    for(int i=1;i<_FIELD_HEIGHT;i++)
    {
        Area.append(graphicChar(point(0,i),'|',BG_YELLOW));
        Area.append(graphicChar(point(_FIELD_WIDTH,i),'|',BG_YELLOW));
    }

    for(int i=1;i<_FIELD_WIDTH;i++)
    {
        Area.append(graphicChar(point(i,0),'_',BG_YELLOW));
        Area.append(graphicChar(point(i,_FIELD_HEIGHT),'-',BG_YELLOW));
    }

    for(int i=0;i<Area.size();i++)
    {
        Area[i].paint(point(0,0));
    }


    bg::setColor(BG_PINK);
    bg::gotoxy(0,66);
    std::cout << "PLAYER 1";
    bg::gotoxy(0,67);
    std::cout<<"Speed up : W";
    bg::gotoxy(0,68);
    std::cout<<"Speed down : S";
    bg::gotoxy(0,69);
    std::cout<<"Right : D";
    bg::gotoxy(0,70);
    std::cout<<"Left : A";
}

gameController::gameController()
{
}
