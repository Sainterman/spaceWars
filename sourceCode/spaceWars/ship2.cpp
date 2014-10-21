#include "ship2.h"


void ship2::initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    graphicObjects::initGraphicObject(pos,speed,dir,flR,flL,flT,flB);

    _graphRight.clear();
    _graphRight.append(graphicChar(point(4,0),'/',BG_RED));
    _graphRight.append(graphicChar(point(5,0),'/',BG_BLUE));
    _graphRight.append(graphicChar(point(3,1),219,BG_GREEN));
    _graphRight.append(graphicChar(point(4,1),219,BG_GREEN));
    _graphRight.append(graphicChar(point(5,1),219,BG_GREEN));
    _graphRight.append(graphicChar(point(6,1),219,BG_GREEN));
    _graphRight.append(graphicChar(point(7,1),'|',BG_RED));
    _graphRight.append(graphicChar(point(8,1),'<',BG_YELLOW));
    _graphRight.append(graphicChar(point(1,2),17,BG_RED));
    _graphRight.append(graphicChar(point(2,2),219,BG_BLUE));
    _graphRight.append(graphicChar(point(3,2),219,BG_BLUE));
    _graphRight.append(graphicChar(point(4,2),3,BG_WHITE));
    _graphRight.append(graphicChar(point(5,2),4,BG_WHITE));
    _graphRight.append(graphicChar(point(6,2),5,BG_WHITE));
    _graphRight.append(graphicChar(point(7,2),6,BG_WHITE));
    _graphRight.append(graphicChar(point(8,2),'|',BG_RED));
    _graphRight.append(graphicChar(point(9,2),'<',BG_YELLOW));
    _graphRight.append(graphicChar(point(3,3),219,BG_GREEN));
    _graphRight.append(graphicChar(point(4,3),219,BG_GREEN));
    _graphRight.append(graphicChar(point(5,3),219,BG_GREEN));
    _graphRight.append(graphicChar(point(6,3),219,BG_GREEN));
    _graphRight.append(graphicChar(point(7,3),'|',BG_RED));
    _graphRight.append(graphicChar(point(8,3),'<',BG_YELLOW));
    _graphRight.append(graphicChar(point(4,4),'\\',BG_RED));
    _graphRight.append(graphicChar(point(5,4),'\\',BG_BLUE));

    _graphLeft.clear();
    _graphLeft.append(graphicChar(point(4,0),'\\',BG_RED));
    _graphLeft.append(graphicChar(point(5,0),'\\',BG_BLUE));
    _graphLeft.append(graphicChar(point(1,1),'>',BG_GREEN));
    _graphLeft.append(graphicChar(point(2,1),'|',BG_GREEN));
    _graphLeft.append(graphicChar(point(3,1),219,BG_GREEN));
    _graphLeft.append(graphicChar(point(4,1),219,BG_GREEN));
    _graphLeft.append(graphicChar(point(5,1),219,BG_RED));
    _graphLeft.append(graphicChar(point(6,1),219,BG_YELLOW));
    _graphLeft.append(graphicChar(point(0,2),'>',BG_RED));
    _graphLeft.append(graphicChar(point(1,2),'|',BG_BLUE));
    _graphLeft.append(graphicChar(point(2,2),3,BG_BLUE));
    _graphLeft.append(graphicChar(point(3,2),4,BG_WHITE));
    _graphLeft.append(graphicChar(point(4,2),5,BG_WHITE));
    _graphLeft.append(graphicChar(point(5,2),6,BG_WHITE));
    _graphLeft.append(graphicChar(point(6,2),219,BG_WHITE));
    _graphLeft.append(graphicChar(point(7,2),219,BG_RED));
    _graphLeft.append(graphicChar(point(8,2),16,BG_YELLOW));
    _graphLeft.append(graphicChar(point(1,3),'>',BG_GREEN));
    _graphLeft.append(graphicChar(point(2,3),'|',BG_GREEN));
    _graphLeft.append(graphicChar(point(3,3),219,BG_GREEN));
    _graphLeft.append(graphicChar(point(4,3),219,BG_GREEN));
    _graphLeft.append(graphicChar(point(5,3),219,BG_RED));
    _graphLeft.append(graphicChar(point(6,3),219,BG_YELLOW));
    _graphLeft.append(graphicChar(point(4,4),'/',BG_RED));
    _graphLeft.append(graphicChar(point(5,4),'/',BG_BLUE));


     _graphUp.clear();
    _graphUp.append(graphicChar(point(4,0),30,BG_RED));
    _graphUp.append(graphicChar(point(2,1),219,BG_RED));
    _graphUp.append(graphicChar(point(3,1),219,BG_RED));
    _graphUp.append(graphicChar(point(4,1),3,BG_RED));
    _graphUp.append(graphicChar(point(5,1),219,BG_RED));
    _graphUp.append(graphicChar(point(6,1),219,BG_RED));
    _graphUp.append(graphicChar(point(1,2),'/',BG_RED));
    _graphUp.append(graphicChar(point(2,2),219,BG_RED));
    _graphUp.append(graphicChar(point(3,2),219,BG_RED));
    _graphUp.append(graphicChar(point(4,2),4,BG_RED));
    _graphUp.append(graphicChar(point(5,2),219,BG_RED));
    _graphUp.append(graphicChar(point(6,2),219,BG_RED));
    _graphUp.append(graphicChar(point(7,2),'\\',BG_RED));
    //graphicChar a14(point(0,3),'/',BG_RED);
    _graphUp.append(graphicChar(point(1,3),'/',BG_RED));
    _graphUp.append(graphicChar(point(2,3),219,BG_RED));
    _graphUp.append(graphicChar(point(3,3),219,BG_RED));
    _graphUp.append(graphicChar(point(4,3),5,BG_RED));
    _graphUp.append(graphicChar(point(5,3),219,BG_RED));
    _graphUp.append(graphicChar(point(6,3),219,BG_RED));
    _graphUp.append(graphicChar(point(7,3),'\\',BG_RED));
    //graphicChar a22(point(8,3),'\\',BG_RED);
    _graphUp.append(graphicChar(point(2,4),'-',BG_RED));
    _graphUp.append(graphicChar(point(3,4),'-',BG_RED));
    _graphUp.append(graphicChar(point(4,4),4,BG_RED));
    _graphUp.append(graphicChar(point(5,4),'-',BG_RED));
    _graphUp.append(graphicChar(point(6,4),'-',BG_RED));
    _graphUp.append(graphicChar(point(2,5),'^',BG_RED));
    _graphUp.append(graphicChar(point(3,5),'^',BG_RED));
    _graphUp.append(graphicChar(point(4,5),'-',BG_RED));
    _graphUp.append(graphicChar(point(5,5),'^',BG_RED));
    _graphUp.append(graphicChar(point(6,5),'^',BG_RED));

    _graphDown.clear();
    _graphDown.append(graphicChar(point(2,0),30,BG_RED));
    _graphDown.append(graphicChar(point(3,0),30,BG_RED));
    _graphDown.append(graphicChar(point(4,0),30,BG_RED));
    _graphDown.append(graphicChar(point(5,0),30,BG_RED));
    _graphDown.append(graphicChar(point(6,0),30,BG_RED));
    _graphDown.append(graphicChar(point(2,1),254,BG_RED));
    _graphDown.append(graphicChar(point(3,1),254,BG_RED));
    _graphDown.append(graphicChar(point(4,1),254,BG_RED));
    _graphDown.append(graphicChar(point(5,1),254,BG_RED));
    _graphDown.append(graphicChar(point(6,1),254,BG_RED));
    _graphDown.append(graphicChar(point(0,2),'\\',BG_RED));
    _graphDown.append(graphicChar(point(1,2),'\\',BG_RED));
    _graphDown.append(graphicChar(point(2,2),219,BG_RED));
    _graphDown.append(graphicChar(point(3,2),219,BG_RED));
    _graphDown.append(graphicChar(point(4,2),3,BG_RED));
    _graphDown.append(graphicChar(point(5,2),219,BG_RED));
    _graphDown.append(graphicChar(point(6,2),219,BG_RED));
    _graphDown.append(graphicChar(point(7,2),'/',BG_RED));
    _graphDown.append(graphicChar(point(8,2),'/',BG_RED));
    _graphDown.append(graphicChar(point(1,3),'\\',BG_RED));
    _graphDown.append(graphicChar(point(2,3),219,BG_RED));
    _graphDown.append(graphicChar(point(3,3),219,BG_RED));
    _graphDown.append(graphicChar(point(4,3),4,BG_RED));
    _graphDown.append(graphicChar(point(5,3),219,BG_RED));
    _graphDown.append(graphicChar(point(6,3),219,BG_RED));
    _graphDown.append(graphicChar(point(7,3),'/',BG_RED));
    _graphDown.append(graphicChar(point(6,3),254,BG_RED));
    _graphDown.append(graphicChar(point(2,4),31,BG_RED));
    _graphDown.append(graphicChar(point(3,4),31,BG_RED));
    _graphDown.append(graphicChar(point(4,4),31,BG_RED));
    _graphDown.append(graphicChar(point(5,4),31,BG_RED));
    _graphDown.append(graphicChar(point(6,4),31,BG_RED));
    _graphDown.append(graphicChar(point(4,5),31,BG_RED));

    fillHitArea();

    setDir(dir);



}

void ship2::fire2()
{


}

ship2::ship2()
{
}

ship2::ship2(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    initGraphicObject(pos,speed,dir,flR,flL,flT,flB);

}

