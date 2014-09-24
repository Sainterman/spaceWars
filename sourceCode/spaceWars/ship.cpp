#include "ship.h"
#include "consoleTools/basicGraphic/basicgraphic.h"
const float ship::_speed_step=0.003; //estas unidades son caracter/milisegundo
const float ship::_speedMax=0.05;
const float ship::_speedMin= 0;

void ship::initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{

    graphicObjects::initGraphicObject(pos,speed,dir,flR,flL,flT,flB);


    _graphRight.clear();
    _graphRight.append(graphicChar(point(0,0),'|',BG_GREEN));
    _graphRight.append(graphicChar(point(1,0),'\\',BG_GREEN));
    _graphRight.append(graphicChar(point(2,0),'_',BG_GREEN));
    _graphRight.append(graphicChar(point(0,1),'>',BG_CYAN));
    _graphRight.append(graphicChar(point(2,1),'_',BG_GREEN));
    _graphRight.append(graphicChar(point(3,1),'>',BG_GREEN));
    _graphRight.append(graphicChar(point(0,2),'|',BG_GREEN));
    _graphRight.append(graphicChar(point(1,2),'/',BG_GREEN));

    _graphLeft.clear();
    _graphLeft.append(graphicChar(point(1,0),'_',BG_GREEN));
    _graphLeft.append(graphicChar(point(2,0),'/',BG_GREEN));
    _graphLeft.append(graphicChar(point(3,0),'|',BG_GREEN));
    _graphLeft.append(graphicChar(point(0,1),'<',BG_GREEN));
    _graphLeft.append(graphicChar(point(1,1),'_',BG_GREEN));
    _graphLeft.append(graphicChar(point(3,1),'<',BG_CYAN));
    _graphLeft.append(graphicChar(point(2,2),'\\',BG_GREEN));
    _graphLeft.append(graphicChar(point(3,2),'|',BG_GREEN));

    _graphDown.clear();
    _graphDown.append(graphicChar(point(0,0),'_',BG_GREEN));
    _graphDown.append(graphicChar(point(1,0),'V',BG_CYAN));
    _graphDown.append(graphicChar(point(2,0),'_',BG_GREEN));
    _graphDown.append(graphicChar(point(0,1),'\\',BG_GREEN));
    _graphDown.append(graphicChar(point(1,1),'X',BG_RED));
    _graphDown.append(graphicChar(point(2,1),'/',BG_GREEN));
    _graphDown.append(graphicChar(point(0,2),'|',BG_GREEN));
    _graphDown.append(graphicChar(point(2,2),'|',BG_GREEN));
    _graphDown.append(graphicChar(point(1,3),'v',BG_GREEN));


    _graphUp.clear();
    _graphUp.append(graphicChar(point(0,3),'-',BG_GREEN));
    _graphUp.append(graphicChar(point(1,3),'^',BG_CYAN));
    _graphUp.append(graphicChar(point(2,3),'-',BG_GREEN));
    _graphUp.append(graphicChar(point(0,2),'/',BG_GREEN));
    _graphUp.append(graphicChar(point(1,2),'X',BG_RED));
    _graphUp.append(graphicChar(point(2,2),'\\',BG_GREEN));
    _graphUp.append(graphicChar(point(0,1),'|',BG_GREEN));
    _graphUp.append(graphicChar(point(2,1),'|',BG_GREEN));
    _graphUp.append(graphicChar(point(1,0),'^',BG_GREEN));

    fillHitArea();

    setDir(DIR_RIGHT);
    _hitPower=2;
    _lifes=9;

    _sUp = 0;
    _sDown = 0;
    _turnLeft = 0;
    _turnRight = 0;
    _fire1 = 0;
    _fire2 = 0;

}

ship::ship()
{

}

ship::ship(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    initGraphicObject(pos,speed,dir,flR,flL,flT,flB);

}



void ship::speedUP()
{
    _speed += _speed_step;

    if(_speed>_speedMax)//si la velocidad llega al  maximo
        _speed = _speedMax;
    _speed += _speed_step;
}

void ship::speedDown()
{
    _speed -= _speed_step;
    if(_speed < _speedMin)
        _speed = _speedMin;
}

void ship::turnRight()
{
    float w = getWidth();
    float h =getHeight();
    point pos = getPos();

    switch(_direction)
    {
    case DIR_RIGHT:
        pos.setX(pos.x()-h);
        pos.setY(pos.y());
        setDir(DIR_DOWN);
        break;
    case DIR_DOWN:
        pos.setX(pos.x()-(h-w));
        pos.setY(pos.y()-w);
        setDir(DIR_LEFT);
        break;
    case DIR_LEFT:
        pos.setX(pos.x()+w);
        pos.setY(pos.y()-(w-h));
        setDir(DIR_TOP);
        break;
    case DIR_TOP:
        pos.setX(pos.x());
        pos.setY(pos.y()+h);
        setDir(DIR_RIGHT);
        break;
     }
    setPos(pos);

}

void ship::turnLeft()
{
    float w = getWidth();
    float h =getHeight();
    point pos = getPos();
    switch(_direction)
    {
    case DIR_RIGHT:
        pos.setX(pos.x()-h);
        pos.setY(pos.y()-(w-h));
        setDir(DIR_TOP);
        break;
    case DIR_DOWN:
        pos.setX(pos.x());
        pos.setY(pos.y()-w);
        setDir(DIR_RIGHT);
        break;
    case DIR_LEFT:
        pos.setX(pos.x()+w);
        pos.setY(pos.y());
        setDir(DIR_DOWN);
        break;
    case DIR_TOP:
        pos.setX(pos.x()-(h-w));
        pos.setY(pos.y()+h);
        setDir(DIR_LEFT);
        break;
    }
    setPos(pos);
}

void ship::fire1()//disparo Tipo 1
{

}

void ship::fire2()//disparo tipo 2
{

}



int ship::confCmd(int sUp, int sDown, int turnRight, int turnLeft, int fire1, int fire2)
{
    _sUp = sUp;
    _sDown = sDown;
    _turnRight = turnRight;
    _turnLeft = turnLeft;
    _fire1 = fire1;
    _fire2 = fire2;

    return 0;
}

int ship::getLifes()
{
    return _lifes;

}

int ship::hit(const graphicObjects *hitObject)
{
    graphicObjects::hit(hitObject);
    _lifes -= hitObject->getHitPower();
    if(_lifes<=0)
        _alive=false;

    return 0;
}


int ship::recvCmd(int cmd)
{
    if(!(_sUp && _sDown && _turnLeft && _turnRight && _fire1 && _fire2))
        return -1;


    if(cmd == _sUp)
        speedUP();
    else if(cmd == _sDown)
        speedDown();
    else if(cmd == _turnLeft)
        turnLeft();
    else if(cmd == _turnRight)
        turnRight();
    else if(cmd == _fire1)
        fire1();
    else if(cmd == _fire2)
        fire2();
    else
        return 0;



    return 1;


}




