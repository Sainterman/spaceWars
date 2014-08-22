#include <iostream>
#include "consoleTools/basicGraphic/basicgraphic.h"
#include "graphicchar.h"

int main(int argc, char *argv[])
{
    graphicChar c1(point(4,0),'/',BG_RED);
    graphicChar c2(point(5,0),'/',BG_BLUE);
    graphicChar c3(point(3,1),219,BG_GREEN);
    graphicChar c4(point(4,1),219,BG_GREEN);
    graphicChar c5(point(5,1),219,BG_GREEN);
    graphicChar c6(point(6,1),219,BG_GREEN);
    graphicChar c7(point(7,1),'|',BG_RED);
    graphicChar c8(point(8,1),'<',BG_YELLOW);
    graphicChar c9(point(1,2),17,BG_RED);
    graphicChar c10(point(2,2),219,BG_BLUE);
    graphicChar c11(point(3,2),219,BG_BLUE);
    graphicChar c12(point(4,2),3,BG_WHITE);
    graphicChar c13(point(5,2),4,BG_WHITE);
    graphicChar c14(point(6,2),5,BG_WHITE);
    graphicChar c15(point(7,2),6,BG_WHITE);
    graphicChar c16(point(8,2),'|',BG_RED);
    graphicChar c17(point(9,2),'<',BG_YELLOW);
    graphicChar c18(point(3,3),219,BG_GREEN);
    graphicChar c19(point(4,3),219,BG_GREEN);
    graphicChar c20(point(5,3),219,BG_GREEN);
    graphicChar c21(point(6,3),219,BG_GREEN);
    graphicChar c22(point(7,3),'|',BG_RED);
    graphicChar c23(point(8,3),'<',BG_YELLOW);
    graphicChar c24(point(4,4),'\\',BG_RED);
    graphicChar c25(point(5,4),'\\',BG_BLUE);


    point offset(10,10);
    c1.paint(offset);
    c2.paint(offset);
    c3.paint(offset);
    c4.paint(offset);
    c5.paint(offset);
    c6.paint(offset);
    c7.paint(offset);
    c8.paint(offset);
    c9.paint(offset);
    c10.paint(offset);
    c11.paint(offset);
    c12.paint(offset);
    c13.paint(offset);
    c14.paint(offset);
    c15.paint(offset);
    c16.paint(offset);
    c17.paint(offset);
    c18.paint(offset);
    c19.paint(offset);
    c20.paint(offset);
    c21.paint(offset);
    c22.paint(offset);
    c23.paint(offset);
    c24.paint(offset);
    c25.paint(offset);

    bg::gotoxy(0,20);

    return 0;
}
