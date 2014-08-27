#ifndef GRAPHICOBJECTS_H
#define GRAPHICOBJECTS_H
#include "graphicchar.h"
#include <QList>
#define DIR_RIGHT 0
#define DIR_LEFT 2
#define DIR_TOP 1
#define DIR_DOWN 3
class graphicObjects
{
private:
    // 0:RIGHT,1:TOP,2:LEFT,3:DOWN
    char _direction;

    point _pos;
    QList <graphicChar> _graphRight, _graphLeft, _graphUp, _graphDown;
    float _speed;
    int _fieldLimtRight, _fieldLimitLeft, _fieldLimitTop, _fieldLimitBot;
    QList <point> _hitAreaRight, _hitAreaLeft, _hitAreaUp, _hitAreaDown;
    //unsigned char _keyPosRight, _keyPosLeft, _keySpeedUp, _keySpeedDown;
    int _edgeRight, _edgeLeft, _edgeTop, _edgeBot;
    int _hitPower;

public:
    //Initialize all members
    graphicObjects();
    int paint();
    int tic(double time);//time en milisegundos
    int checkHit(point p);
    int checkHit(QList<point>points);

};

#endif // GRAPHICOBJECTS_H
