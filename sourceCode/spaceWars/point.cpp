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



int point::x() const
{
    return _posX;

}

int point::y() const
{
    return _posY;
}


bool operator ==(const point &p1, const point &p2) //operador para comparar puntos
{
    return (p1.x()==p2.x())&&(p1.y()==p2.y());
}
