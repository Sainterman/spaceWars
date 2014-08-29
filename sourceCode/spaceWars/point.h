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
    int x() const;
    int y() const;

};
bool operator == (const point& p1,  const point& p2);//operador para comparar puntos
#endif // POINT_H
