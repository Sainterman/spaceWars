#ifndef SHIP2_H
#define SHIP2_H
#include "ship.h"
class ship2 : public ship
{
private:
    void initGraphicObject(point pos, float speed, char dir, int flR, int flL, int flT, int flB);
public:
    void fire2();

    ship2();
    ship2(point pos, float speed, char dir, int flR, int flL, int flT, int flB);
};

#endif // SHIP2_H
