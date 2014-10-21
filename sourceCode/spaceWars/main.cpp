#include <iostream>
#include "consoleTools/basicGraphic/basicgraphic.h"
#include "graphicchar.h"
#include "graphicobjects.h"
#include "ship.h"
#include <conio.h>
#include "gamecontroller.h"
int main(int argc, char *argv[])
{



    /*
    QList<graphicObjects> gos;
    gos.append(graphicObjects(point(6,2),0.002,DIR_RIGHT,50,0,0,30));
    gos.append(graphicObjects(point(0,4),0.003,DIR_RIGHT,50,0,0,30));
    gos.append(graphicObjects(point(20,20),0.004,DIR_TOP,50,0,0,30));
    gos.append(graphicObjects(point(50,10),0.01,DIR_LEFT,50,0,0,30));
    gos.append(graphicObjects(point(0,5),0.007,DIR_DOWN,50,0,0,30));
    gos.append(graphicObjects(point(21,30),0.006,DIR_TOP,50,0,0,30));
    gos.append(graphicObjects(point(20,20),0.005,DIR_LEFT,50,0,0,30));



    for(;;)
    {
        bg::clrscr();

        for(int i=0;i<gos.size();i++)
        {
            gos[i].paint();
            gos[i].tic(200);
        }

        Sleep(200);


    }
*/
   /* QList<ship> gos;
    gos.append(ship(point(5,5),0.0,DIR_RIGHT,70,0,0,75));
    gos.last().confCmd('w','s','d','a',' ','m');
    gos.append(ship(point(5,10),0.0,DIR_RIGHT,70,0,0,75));
    gos.last().confCmd('5','2','3','1','0','.');

    gameController SpaceWars;



    for(;;)
    {
        bg::clrscr();
        SpaceWars.printUI();

        int k;
        k= (kbhit()!= 0)? getch() : -1;

        for(int i=0;i<gos.size();i++)
        {
            if(k != -1)
                gos[i].recvCmd(k);
            gos[i].paint();
            gos[i].tic(100);
        }

        Sleep(100);


    }*/
    gameController SpaceWars;
    SpaceWars.run();


    return 0;
}
