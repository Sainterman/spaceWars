#include "bullet.h"

void bullet::initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    graphicObjects::initGraphicObject(pos,speed,dir,flR,flL,flT,flB);
    _graphRight.clear();
    _graphRight.append(graphicChar(point(0,0),'~',BG_YELLOW));
    _graphRight.append(graphicChar(point(1,0),'>',BG_YELLOW));

    _graphLeft.clear();
    _graphLeft.append(graphicChar(point(1,0),'~',BG_YELLOW));
    _graphLeft.append(graphicChar(point(0,0),'<',BG_YELLOW));

    _graphDown.clear();
    _graphDown.append(graphicChar(point(0,0),'s',BG_YELLOW));
    _graphDown.append(graphicChar(point(0,1),'v',BG_YELLOW));

    _graphUp.clear();
    _graphUp.append(graphicChar(point(0,1),'s',BG_YELLOW));
    _graphUp.append(graphicChar(point(0,0),'^',BG_YELLOW));

    _hitAreaRight.clear();
    _hitAreaRight.append(point(1,0));

    _hitAreaLeft.clear();
    _hitAreaLeft.append(point (0,0));

    _hitAreaDown.clear();
    _hitAreaDown.append(point (0,1));

    _hitAreaUp.clear();
    _hitAreaUp.append(point(0,0));



    setDir(dir);

    _hitPower=2;

}

bullet::bullet()
{
    initGraphicObject(point(0,0),0.0,0,70,0,0,60);
}

bullet::bullet(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    initGraphicObject(pos,speed,dir,flR,flL,flT,flB);
}

int bullet::hit(const graphicObjects* hitObject)
{
    //int r = graphicObjects::hit(hitObject);
    _alive=false;

    return 0;
    //return r;

}

int bullet::setPos(point p)
{
   int r = graphicObjects::setPos(p);

   if(r)
       _alive=false;

   return r;


}
