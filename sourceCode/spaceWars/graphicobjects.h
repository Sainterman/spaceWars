#ifndef GRAPHICOBJECTS_H
#define GRAPHICOBJECTS_H
#include "graphicchar.h"
#include <QList>
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
    int tic(double time);
    int checkHit(point p);
    int checkHit(QList<point>points);

};

#endif // GRAPHICOBJECTS_H
