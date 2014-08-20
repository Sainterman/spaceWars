#include "point.h"



point::point()
{
    point(0, 0);
}

point::point(int x, int y)
{
    _posX=x;
    _posY=y;
}

void point::setX(int x)
{
    _posX=x;

}

void point::setY(int y)
{
    _posY=y;
}

int point::x()
{
    return _posX;

}

int point::y()
{
    return _posY;
}
