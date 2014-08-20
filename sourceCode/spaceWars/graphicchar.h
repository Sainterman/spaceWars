#ifndef GRAPHICCHAR_H
#define GRAPHICCHAR_H
#include "point.h"
#include "consoleTools/basicGraphic/basicgraphic.h"
#include <iostream>
class graphicChar
{
private:
    point _pos;
    unsigned char _char;
    unsigned char _colour;
public:
    graphicChar();
    graphicChar(point pos, unsigned char ch, unsigned char colour);
    int paint(point offset);
};

#endif // GRAPHICCHAR_H
