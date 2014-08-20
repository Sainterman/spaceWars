#ifndef POINT_H
#define POINT_H

class point
{
private:
    int _posX, _posY;

public:
    point();
    point(int x, int y);
    void setX(int x);
    void setY(int y);
    int x();
    int y();
};

#endif // POINT_H
