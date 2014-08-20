#include <iostream>
#include "consoleTools/basicGraphic/basicgraphic.h"
#include "graphicchar.h"

int main(int argc, char *argv[])
{
    graphicChar c1(point(4,0),'/',BG_RED);
    graphicChar c2(point(4,3),'\\',BG_WHITE);
    point offset(60,30);
    c1.paint(offset);
    c2.paint(offset);

    bg::gotoxy(0,40);

    return 0;
}
