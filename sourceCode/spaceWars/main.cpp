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

    graphicChar b1(point(4,0),'\\',BG_RED);
    graphicChar b2(point(5,0),'\\',BG_BLUE);
    graphicChar b3(point(1,1),'>',BG_GREEN);
    graphicChar b4(point(2,1),'|',BG_GREEN);
    graphicChar b5(point(3,1),219,BG_GREEN);
    graphicChar b6(point(4,1),219,BG_GREEN);
    graphicChar b7(point(5,1),219,BG_RED);
    graphicChar b8(point(6,1),219,BG_YELLOW);
    graphicChar b9(point(0,2),'>',BG_RED);
    graphicChar b10(point(1,2),'|',BG_BLUE);
    graphicChar b11(point(2,2),3,BG_BLUE);
    graphicChar b12(point(3,2),4,BG_WHITE);
    graphicChar b13(point(4,2),5,BG_WHITE);
    graphicChar b14(point(5,2),6,BG_WHITE);
    graphicChar b15(point(6,2),219,BG_WHITE);
    graphicChar b16(point(7,2),219,BG_RED);
    graphicChar b17(point(8,2),16,BG_YELLOW);
    graphicChar b18(point(1,3),'>',BG_GREEN);
    graphicChar b19(point(2,3),'|',BG_GREEN);
    graphicChar b20(point(3,3),219,BG_GREEN);
    graphicChar b21(point(4,3),219,BG_GREEN);
    graphicChar b22(point(5,3),219,BG_RED);
    graphicChar b23(point(6,3),219,BG_YELLOW);
    graphicChar b24(point(4,4),'/',BG_RED);
    graphicChar b25(point(5,4),'/',BG_BLUE);


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

    point offsetR(5,5);
    b1.paint(offsetR);
    b2.paint(offsetR);
    b3.paint(offsetR);
    b4.paint(offsetR);
    b5.paint(offsetR);
    b6.paint(offsetR);
    b7.paint(offsetR);
    b8.paint(offsetR);
    b9.paint(offsetR);
    b10.paint(offsetR);
    b11.paint(offsetR);
    b12.paint(offsetR);
    b13.paint(offsetR);
    b14.paint(offsetR);
    b15.paint(offsetR);
    b16.paint(offsetR);
    b17.paint(offsetR);
    b18.paint(offsetR);
    b19.paint(offsetR);
    b20.paint(offsetR);
    b21.paint(offsetR);
    b22.paint(offsetR);
    b23.paint(offsetR);
    b24.paint(offsetR);
    b25.paint(offsetR);

    bg::gotoxy(0,20);

    return 0;
}
