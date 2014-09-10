#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "graphicchar.h"
#include <QList>
class gameController
{
private:

    const static int _FIELD_HEIGHT;
    const static int _FIELD_WIDTH;


protected:

public:
    gameController();
    int printUI();

    int run();



};

#endif // GAMECONTROLLER_H
