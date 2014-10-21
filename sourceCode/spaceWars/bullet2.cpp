#include "bullet2.h"

void bullet2::initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    graphicObjects::initGraphicObject(pos,speed,dir,flR,flL,flT,flB);

    _graphRight.clear();
    _graphRight.append(graphicChar(point(0,0),177,BG_RED));


    _hitAreaRight.clear();
    _hitAreaRight.append(point(0,0));

    setDir(dir);

    _hitPower=3;
}

bullet2::bullet2(point pos, int flR, int flL, int flT, int flB)
{
    initGraphicObject(pos,0,DIR_RIGHT,flR,flL,flT,flB);
}
