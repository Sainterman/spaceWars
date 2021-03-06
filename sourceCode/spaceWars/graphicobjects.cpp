#include "graphicobjects.h"



void graphicObjects::initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{

    //Graphic when pos is right
    _graphRight.append(graphicChar(point(0,0),'?'));
    _graphRight.append(graphicChar(point(1,0),'>'));
    //Graphic when pos is left
    _graphLeft.append(graphicChar(point(0,0),'<'));
    _graphLeft.append(graphicChar(point(1,0),'?'));
    //Graphic when pos is down
    _graphDown.append(graphicChar(point(0,0),'?'));
    _graphDown.append(graphicChar(point(0,1),'V'));
    //Graphic when pos is up
    _graphUp.append(graphicChar(point(0,0),'^'));
    _graphUp.append(graphicChar(point(0,1),'?'));


    //Define hit area
    _hitAreaRight.append(point(0,0));
    _hitAreaRight.append(point(1,0));
    _hitAreaLeft.append(point(0,0));
    _hitAreaLeft.append(point(1,0));
    _hitAreaDown.append(point(0,0));
    _hitAreaDown.append(point(0,1));
    _hitAreaUp.append(point(0,0));
    _hitAreaUp.append(point(0,1));

    //define hit power
    _hitPower=1;



    _alive=true;
    setDir(dir);
    setSpeed(speed);
    setFieldLimits(flR,flL,flT,flB);
    setPos(pos);

}

void graphicObjects::fillHitArea()
{
    _hitAreaRight.clear();
    for(int i=0;i<_graphRight.size();i++)
        _hitAreaRight.append(_graphRight[i].pos());

    _hitAreaLeft.clear();
    for(int i=0; i<_graphLeft.size(); i++)
        _hitAreaLeft.append(_graphLeft[i].pos());

    _hitAreaDown.clear();
    for(int i=0; i<_graphDown.size();i++)
        _hitAreaDown.append(_graphDown[i].pos());

    _hitAreaUp.clear();
    for(int i=0; i<_graphUp.size();i++)
        _hitAreaUp.append(_graphUp[i].pos());

}

graphicObjects::graphicObjects()
{
    initGraphicObject(point(0,0),0,DIR_LEFT,0,0,0,0);



}

graphicObjects::graphicObjects(point pos, float speed, char dir, int flR, int flL, int flT, int flB)
{
    initGraphicObject(pos,speed,dir,flR,flL,flT,flB);



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
        if(newPos.xi() +_edgeLeft <= _fieldLimitLeft)
            objInside=false;
        break;
    case DIR_RIGHT:
        if(newPos.xi() + _edgeRight >= _fieldLimtRight)
            objInside=false;
        break;
    case DIR_DOWN:
        if(newPos.yi()+_edgeBot >=_fieldLimitBot)
            objInside=false;
        break;
    case DIR_TOP:
        if(newPos.yi()<=_fieldLimitTop)
            objInside=false;
        break;
    default:
        return -1;
        break;
    }


    //tomar ultima posicion
    _lastPos=_pos;


//    //If objInside=true
//    if(objInside==true)
//    {
//        _pos=newPos;
//    }
//    else
//    {
//        switch(_direction)
//        {
//        case DIR_RIGHT:
//            _pos.setX(_fieldLimtRight-_edgeRight-1);
//            //_direction=DIR_DOWN;

//            break;
//        case DIR_LEFT:
//            _pos.setX(_fieldLimitLeft+1);
//            //_direction=DIR_TOP;
//            break;
//        case DIR_DOWN:
//            _pos.setY(_fieldLimitBot-_edgeBot -1);
//            //_direction=DIR_LEFT;
//            break;
//        case DIR_TOP:
//            _pos.setY(_fieldLimitTop+1);
//            //_direction=DIR_RIGHT;
//            break;
//        }
//        _speed=0;
//      }

        setPos(newPos);
        if(objInside!=true)
            _speed=0;

    return 0;

}

int graphicObjects::checkHit(point p)
{

    p.setX(p.x()-_pos.x());//transformar de global a local
    p.setY(p.y()-_pos.y());

    ///Grabbing reference of current hit Area
    QList<point>* currentHitArea;
    switch(_direction)
    {
    case DIR_RIGHT:
        currentHitArea=&_hitAreaRight;
        break;
    case DIR_LEFT:
        currentHitArea=&_hitAreaLeft;
        break;
    case DIR_DOWN:
        currentHitArea=&_hitAreaDown;
        break;
    case DIR_TOP:
        currentHitArea=&_hitAreaUp;
        break;
    }

    for(int i=0;i<currentHitArea->size();i++){
        if(p.roundAndComp(currentHitArea->at(i)))
            return 1;
    }
    return 0;

}

int graphicObjects::checkHit(const QList<point> &points)
{
    ///Check point to point
    int countPoints=0;
    for(int i=0;i<points.size();i++)
        countPoints += checkHit(points[i]);

    return countPoints;

}

void graphicObjects::setPos(float x, float y)
{
    setPos(point(x,y));
}

int graphicObjects::setPos(point p)
{
    int retValue=0;
    if((p.xi()+getWidth())>_fieldLimtRight)
    {
        p.setX(_fieldLimtRight-1-getWidth());
        retValue=1;
    }

    if(p.xi()<=_fieldLimitLeft)
    {
        p.setX(_fieldLimitLeft+1);
        retValue=1;
    }

    if(p.yi()+ getHeight()>=_fieldLimitBot)
    {
        p.setY(_fieldLimitBot-1-getHeight());
        retValue=1;
    }
    if(p.yi()<=_fieldLimitTop)
    {
        p.setY(_fieldLimitTop+1);
        retValue=1;
    }

    _pos=p;

    return retValue;
}

void graphicObjects::setSpeed(float s)
{
    _speed=s;
}

void graphicObjects::setFieldLimits(int R, int L, int T, int B)
{
    _fieldLimtRight=R;
    _fieldLimitLeft=L;
    _fieldLimitTop=T;
    _fieldLimitBot=B;
}

bool graphicObjects::setDir(char dir)
{
    if (dir>3 || dir<0)//validar
       return false;




    ///]Referencia del actual hit area


    QList<graphicChar>* currentGraphic;
    switch(dir)
    {
    case DIR_RIGHT:
        currentGraphic=&_graphRight;
        break;
    case DIR_LEFT:
        currentGraphic=&_graphLeft;
        break;
    case DIR_DOWN:
        currentGraphic=&_graphDown;
        break;
    case DIR_TOP:
        currentGraphic=&_graphUp;
        break;
    }

    if( currentGraphic->size()==0)
        return false;

    int maxX= currentGraphic->at(0).pos().x();
    int minX= currentGraphic->at(0).pos().x();
    int maxY= currentGraphic->at(0).pos().y();
    int minY= currentGraphic->at(0).pos().y();

    for (int i=0; i< currentGraphic->size();i++)
    {
        if( currentGraphic->at(i).pos().x()>maxX)
            maxX= currentGraphic->at(i).pos().x();
        if( currentGraphic->at(i).pos().x()<minX)
            minX= currentGraphic->at(i).pos().x();
        if( currentGraphic->at(i).pos().y()>maxY)
            maxY= currentGraphic->at(i).pos().y();
        if( currentGraphic->at(i).pos().y()<minY)
            minY= currentGraphic->at(i).pos().y();
    }
    _edgeRight=maxX;
    _edgeLeft=minX;
    _edgeBot=maxY;
    _edgeTop=minY;





    _direction=dir;

}

QList<point> graphicObjects::getHitArea()
{
    //devuelve en cordenadas globales
    QList<point> hitArea;
    switch(_direction)
    {
    case DIR_RIGHT:

        hitArea= _hitAreaRight;
        break;
    case DIR_LEFT:
        hitArea= _hitAreaLeft;
        break;
    case DIR_DOWN:
        hitArea= _hitAreaDown;
        break;
    case DIR_TOP:
        hitArea= _hitAreaUp;
        break;
    }
    for(int i=0; i<hitArea.size() ;i++)
    {
        hitArea[i].setX(hitArea[i].x()+_pos.x());
        hitArea[i].setY(hitArea[i].y()+_pos.y());
    }
    return hitArea;
}

 int graphicObjects::hit(const graphicObjects* hitObject)
{

   _speed=0;
   _pos=_lastPos;

   return 0;

}

float graphicObjects::getHeight()
{
    float height=_edgeBot-_edgeTop+1;
    return height;
}

float graphicObjects::getWidth()
{
    float width=_edgeRight-_edgeLeft+1;
    return width;
}

point graphicObjects::getPos()
{
    return _pos;
}

int graphicObjects::getHitPower() const
{
    return _hitPower;
}

bool graphicObjects::alive()
{
    return _alive;
}

QList<graphicObjects *> graphicObjects::createGo()
{
    QList<graphicObjects*> r;
    return r;
}




















