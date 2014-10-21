#ifndef SHIP_H
#define SHIP_H
#include "graphicobjects.h"
#include "bullet.h"
#include "bullet2.h"
#include <sys/time.h>
class ship:public graphicObjects
{
private:
    void initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB);
    static const float _speed_step;
    static const float _speedMax;
    static const float _speedMin;
    static const float _bulletSpeed;
    int _sUp,_sDown,_turnRight,_turnLeft,_fire1,_fire2;
    int _lifes;


protected:
    int _time;
    int msTime();


public:
    ship();
    ship(point pos, float speed, char dir, int flR, int flL, int flT, int flB);
    void speedUP();
    void speedDown();
    void turnRight();
    void turnLeft();
    QList<graphicObjects*> createGo();
    QList<graphicObjects*> _firedBullet;
    void fire1();//disparo 1
    void fire2();//disparo 2
    int recvCmd(int cmd);
    int confCmd(int sUp,int sDown,int turnRight, int turnLeft, int fire1, int fire2 );//Llamar antes de recvCmd
    int getLifes();
    virtual int hit(const graphicObjects* hitObject);
    int _numBullet2;





};

#endif // SHIP_H
