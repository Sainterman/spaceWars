#include "gamecontroller.h"
const int gameController::_FIELD_HEIGHT=65;
const int gameController::_FIELD_WIDTH=70;

int gameController::printUI()
{
    QList<graphicChar> Area;


    for(int i=1;i<_FIELD_HEIGHT;i++)
    {
        Area.append(graphicChar(point(0,i),'|',BG_YELLOW));
        Area.append(graphicChar(point(_FIELD_WIDTH,i),'|',BG_YELLOW));
    }

    for(int i=1;i<_FIELD_WIDTH;i++)
    {
        Area.append(graphicChar(point(i,0),'_',BG_YELLOW));
        Area.append(graphicChar(point(i,_FIELD_HEIGHT),'-',BG_YELLOW));
    }

    for(int i=0;i<Area.size();i++)
    {
        Area[i].paint(point(0,0));
    }


    bg::setColor(BG_PINK);
    bg::gotoxy(0,66);
    std::cout << "PLAYER 1";
    bg::gotoxy(0,67);
    std::cout<<"Speed Up : W";
    bg::gotoxy(0,68);
    std::cout<<"Speed Down : S";
    bg::gotoxy(0,69);
    std::cout<<"Turn Right : D";
    bg::gotoxy(0,70);
    std::cout<<"Turn Left : A";
    bg::gotoxy(0,71);
    std::cout<<"Fire 1 : SPACE";
    bg::gotoxy(0,72);
    std::cout<<"Fire 2 : M";


	bg::setColor(BG_RED);
	bg::gotoxy(20,66);
	std::cout<<"PLAYER 2";
	bg::gotoxy(20,67);
	std::cout<<"Speed Up : 5";
	bg::gotoxy(20,68);
	std::cout<<"Speed Down : 2";
	bg::gotoxy(20,69);
	std::cout<<"Turn Right : 3";
	bg::gotoxy(20,70);
	std::cout<<"Turn Left : 1";
    bg::gotoxy(20,71);
    std::cout<<"Fire 1 : 0";
    bg::gotoxy(20,72);
    std::cout<<"Fire 2 : .";

    bg::setColor(BG_CYAN);
    bg::gotoxy(40,66);
    std::cout<<"PLAYER 3";
    bg::gotoxy(40,67);
    std::cout<<"Speed Up : I";
    bg::gotoxy(40,68);
    std::cout<<"Speed Down : K";
    bg::gotoxy(40,69);
    std::cout<<"Turn Right : L";
    bg::gotoxy(40,70);
    std::cout<<"Turn Left : J";
    bg::gotoxy(40,71);
    std::cout<<"Fire 1 : U";
    bg::gotoxy(40,72);
    std::cout<<"Fire 2 : O";

    return 0;
}

int gameController::run()
{
    initGobjects();
    int time= msTime();
    for (;;)
    {
        int elapsedTime= msTime()-time;
        time=msTime();

        for(int i=0;i<_gObjects.size();i++)
            _gObjects[i]->tic(elapsedTime);
        //TODO: Evaluar colisiones
        paintGame();
        recvUserCmd();
    }

    return 0;


}

int gameController::initGobjects()
{
    //Borro objetos en la lista
    for(int i=0;i<_gObjects.size();i++)
    {
        delete _gObjects[i];
        _gObjects.clear();
    }
    //crear tres naves
    ship* sh = new ship(point(_FIELD_WIDTH/4,_FIELD_HEIGHT/2),0,DIR_TOP,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
    sh->confCmd('w','s','d','a',' ','m');
    _gObjects.append(sh);

    sh= new ship(point((_FIELD_WIDTH*2)/4,_FIELD_HEIGHT/2),0,DIR_DOWN,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
    sh->confCmd('5','2','3','1','0','.');
    _gObjects.append(sh);

    sh= new ship(point((_FIELD_WIDTH*3)/4,_FIELD_HEIGHT/2),0,DIR_TOP,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
    sh->confCmd('i','k','l','j','u','o');
    _gObjects.append(sh);

    return 0;
}

int gameController::msTime()
{
    struct timeval tV;
    gettimeofday(&tV,NULL);
    int ms = tV.tv_sec * 1000 + tV.tv_usec/1000;
    return ms;
}

int gameController::paintGame()
{
    bg::clrscr();

    printUI();
    for (int i=0;i<_gObjects.size();i++)
        _gObjects[i]->paint();

    return 0;


}

int gameController::recvUserCmd()
{
    while(kbhit())
    {
        char c= getch();
        for(int i=0; i<_gObjects.size(); i++)
        {
            ship* sh=dynamic_cast<ship*>(_gObjects[i]);
            if(sh)
                sh->recvCmd(c);
        }
    }
    return 0;
}

gameController::gameController()
{
}
