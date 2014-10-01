#ifndef BULLET_H
#define BULLET_H
#include "graphicobjects.h"
class bullet: public graphicObjects
{
private:

protected:
    void initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB);

public:
    bullet();
    bullet(point pos, float speed, char dir, int flR, int flL, int flT, int flB);
    virtual int hit(const graphicObjects* hitObject);
    virtual int setPos(point p);



};

#endif // BULLET_H
