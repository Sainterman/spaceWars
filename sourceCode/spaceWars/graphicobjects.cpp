#include "graphicobjects.h"

graphicObjects::graphicObjects()
{
    _direction = 0;
    _pos = point(0,0);
    //Graphic when pos is right
    _graphRight.append(graphicChar(point(0,0),'?'));
    _graphRight.append(graphicChar(point(1,0),'>'));
    //Graphic when pos is left
    _graphLeft.append(graphicChar(point(0,0),'<'));
    _graphLeft.append(graphicChar(point(0,1),'?'));
    //Graphic when pos is down
    _graphDown.append(graphicChar(point(0,0),'?'));
    _graphDown.append(graphicChar(point(0,1),'V'));
    //Graphic when pos is up
    _graphUp.append(graphicChar(point(0,0),'^'));
    _graphUp.append(graphicChar(point(0,1),'?'));

    //Initialize speed = 0
    _speed=0;

    //Define gaming borders






}

int graphicObjects::paint()
{

}

int graphicObjects::tic(double time)
{

}

int graphicObjects::checkHit(point p)
{

}

int graphicObjects::checkHit(QList<point> points)
{

}
