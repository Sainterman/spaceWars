#include "graphicobjects.h"

graphicObjects::graphicObjects()
{
    _direction = DIR_LEFT;
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
    _fieldLimitBot=0;
    _fieldLimitLeft=0;
    _fieldLimitTop=0;
    _fieldLimtRight=0;

    //Define hit area
    _hitAreaRight.append(point(0,0));
    _hitAreaRight.append(point(1,0));
    _hitAreaLeft.append(point(0,0));
    _hitAreaLeft.append(point(1,0));
    _hitAreaDown.append(point(0,0));
    _hitAreaDown.append(point(0,1));
    _hitAreaUp.append(point(0,0));
    _hitAreaUp.append(point(0,1));

    //define edges///usa esos valores porque por defecto dibuja la nave a la izquierda
    _edgeRight=1;
    _edgeLeft=0;
    _edgeBot=0;
    _edgeTop=0;

    //define hit power
    _hitPower=1;

}

int graphicObjects::paint()
{
    switch(_direction)
    {
    case DIR_LEFT:
        for(int i=0;i<_graphLeft.size();i++)
            _graphLeft[i].paint(_pos);
        break;
    case DIR_RIGHT:
        for (int i=0; i<_graphRight.size();i++)
            _graphRight[i].paint(_pos);
        break;
    case DIR_DOWN:
        for(int i=0; i<_graphDown.size();i++)
            _graphDown[i].paint(_pos);
        break;
    case DIR_TOP:
        for(int i=0;i<_graphUp.size();i++)
            _graphUp[i].paint(_pos);
        break;
    default:
        return -1;//la direccion no es valida

    }

    return 0;
}

int graphicObjects::tic(double time)
{
    point newPos;

  //Intenta moverse
    switch(_direction)
    {
    case DIR_LEFT:
        newPos.setX(_pos.x()-_speed*time);
        newPos.setY(_pos.y());
        break;

    case DIR_RIGHT:
        newPos.setX(_pos.x()+ _speed*time);
        newPos.setY(_pos.y());
        break;

    case DIR_DOWN:
        newPos.setX(_pos.x());
        newPos.setY(_pos.y()+_speed*time);
        break;
    case DIR_TOP:
        newPos.setX(_pos.x());
        newPos.setY(_pos.y()-_speed*time);
    }

    //verify if the object is in the field
    bool objInside=true;

    switch(_direction)
    {
    case DIR_LEFT:
        if(newPos.x() +_edgeLeft <= _fieldLimitLeft)
            objInside=false;
        break;
    case DIR_RIGHT:
        if(newPos.x() + _edgeRight >= _fieldLimtRight)
            objInside=false;
        break;
    case DIR_DOWN:
        if(newPos.y()+_edgeBot >=_fieldLimitBot)
            objInside=false;
        break;
    case DIR_TOP:
        if(newPos.y()<=_fieldLimitTop)
            objInside=false;
        break;
    default:
        return -1;
        break;
    }

    //If objInside=true
    if(objInside=true)
    {
        _pos=newPos;
    }
    else
    {
        switch(_direction)
        {
        case DIR_RIGHT:
            _pos.setX(_fieldLimtRight-_edgeRight-1);
            break;
        case DIR_LEFT:
            _pos.setX(_fieldLimitLeft+1);
            break;
        case DIR_DOWN:
            _pos.setY(_fieldLimitBot-_edgeBot -1);
            break;
        case DIR_TOP:
            _pos.setY(_fieldLimitTop+1);
            break;
        }

        _speed=0;
    }
}

int graphicObjects::checkHit(point p)
{

}

int graphicObjects::checkHit(QList<point> points)
{

}
