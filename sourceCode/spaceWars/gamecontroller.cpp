#include "gamecontroller.h"
const int gameController::_FIELD_HEIGHT=40;
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

    //player 1
    bg::setColor(BG_PINK);
    bg::gotoxy(0,_FIELD_HEIGHT+1);
    std::cout << "PLAYER 1 (";
    bg::setColor(BG_WHITE);
    if(_player1)
        std::cout << _player1->getLifes();
    else
        std::cout<<"*-*";
    bg::setColor(BG_PINK);
    std::cout<<")";
    bg::gotoxy(0,_FIELD_HEIGHT+2);
    std::cout<<"Speed Up : W";
    bg::gotoxy(0,_FIELD_HEIGHT+3);
    std::cout<<"Speed Down : S";
    bg::gotoxy(0,_FIELD_HEIGHT+4);
    std::cout<<"Turn Right : D";
    bg::gotoxy(0,_FIELD_HEIGHT+5);
    std::cout<<"Turn Left : A";
    bg::gotoxy(0,_FIELD_HEIGHT+6);
    std::cout<<"Fire 1 : SPACE";
    bg::gotoxy(0,_FIELD_HEIGHT+7);
    std::cout<<"Fire 2 : M";
    bg::gotoxy(0,_FIELD_HEIGHT+8);
    std::cout << "mines (";
    bg::setColor(BG_GREEN);
    if(_player1)
        std::cout << _player1->_numBullet2;
    bg::setColor(BG_PINK);
    std::cout<<")";


    //player 2
	bg::setColor(BG_RED);
    bg::gotoxy(20,_FIELD_HEIGHT+1);
    std::cout<<"PLAYER 2 (";
    bg::setColor(BG_WHITE);
    if(_player2)
        std::cout << _player2->getLifes();
    else
        std::cout<<"*-*";
    bg::setColor(BG_RED);
    std::cout<<")";
    bg::gotoxy(20,_FIELD_HEIGHT+2);
	std::cout<<"Speed Up : 5";
    bg::gotoxy(20,_FIELD_HEIGHT+3);
	std::cout<<"Speed Down : 2";
    bg::gotoxy(20,_FIELD_HEIGHT+4);
	std::cout<<"Turn Right : 3";
    bg::gotoxy(20,_FIELD_HEIGHT+5);
	std::cout<<"Turn Left : 1";
    bg::gotoxy(20,_FIELD_HEIGHT+6);
    std::cout<<"Fire 1 : 0";
    bg::gotoxy(20,_FIELD_HEIGHT+7);
    std::cout<<"Fire 2 : .";
    bg::gotoxy(20,_FIELD_HEIGHT+8);
    std::cout << "mines (";
    bg::setColor(BG_GREEN);
    if(_player2)
        std::cout << _player2->_numBullet2;
    bg::setColor(BG_RED);
    std::cout<<")";

    //player 3
    bg::setColor(BG_CYAN);
    bg::gotoxy(40,_FIELD_HEIGHT+1);
    std::cout<<"PLAYER 3 (";
    bg::setColor(BG_WHITE);
    if(_player3)
    std::cout << _player3->getLifes();
    else
        std::cout<<"*-*";
    bg::setColor(BG_CYAN);
    std::cout<<")";
    bg::gotoxy(40,_FIELD_HEIGHT+2);
    std::cout<<"Speed Up : I";
    bg::gotoxy(40,_FIELD_HEIGHT+3);
    std::cout<<"Speed Down : K";
    bg::gotoxy(40,_FIELD_HEIGHT+4);
    std::cout<<"Turn Right : L";
    bg::gotoxy(40,_FIELD_HEIGHT+5);
    std::cout<<"Turn Left : J";
    bg::gotoxy(40,_FIELD_HEIGHT+6);
    std::cout<<"Fire 1 : U";
    bg::gotoxy(40,_FIELD_HEIGHT+7);
    std::cout<<"Fire 2 : O";
    bg::gotoxy(40,_FIELD_HEIGHT+8);
    std::cout << "mines (";
    bg::setColor(BG_GREEN);
    if(_player3)
        std::cout << _player3->_numBullet2;
    bg::setColor(BG_CYAN);
    std::cout<<")";

    return 0;
}

int gameController::run()
{
    pickShip(&_p1,&_p2,&_p3);
    initGobjects();
    int time= msTime();
    for (;;)
    {
        addNewGraphObj();
        int elapsedTime= msTime()-time;
        time=msTime();

        for(int i=0;i<_gObjects.size();i++)
            _gObjects[i]->tic(elapsedTime);


        checkCollitions();
        removeDeadObjects();
        paintGame();
        recvUserCmd();

        //verificamos sisolo queda un jugador vivo
        int nAlive=0;
        if(_player1)
            nAlive++;
        if(_player2)
            nAlive++;
        if(_player3)
            nAlive++;
        if(nAlive<=1)
            break;

    }
    bg::clrscr();
    bg::gotoxy(25,20);
    std::cout<<"Player ";
    if(_player1)
        std::cout<<"1";
    if(_player2)
        std::cout<<"2";
    if(_player3)
        std::cout<<"3";
    std::cout<<" Wins!"<<"/n";
    bg::gotoxy(0,49);
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



        if(_p1==1)
        {
            ship* sh = new ship(point(_FIELD_WIDTH/4,_FIELD_HEIGHT/2),0,DIR_TOP,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
            sh->confCmd('w','s','d','a',' ','m');
            _gObjects.append(sh);
            _player1= sh;
        }
        else
        {
            ship2* sh= new ship2(point(_FIELD_WIDTH/4,_FIELD_HEIGHT/2),0,DIR_TOP,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
            sh->confCmd('w','s','d','a',' ','m');
            _gObjects.append(sh);
            _player1= sh;;
        }

        if(_p2==1)
        {
            ship* sh= new ship(point((_FIELD_WIDTH*2)/4,_FIELD_HEIGHT/2),0,DIR_DOWN,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
             sh->confCmd('5','2','3','1','0','.');
             _gObjects.append(sh);
             _player2 = sh;
        }
        else
        {
            ship2* sh= new ship2(point((_FIELD_WIDTH*2)/4,_FIELD_HEIGHT/2),0,DIR_DOWN,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
             sh->confCmd('5','2','3','1','0','.');
             _gObjects.append(sh);
             _player2 = sh;
        }

        if(_p3==1)
        {
            ship* sh= new ship(point((_FIELD_WIDTH*3)/4,_FIELD_HEIGHT/2),0,DIR_TOP,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
             sh->confCmd('i','k','l','j','u','o');
             _gObjects.append(sh);
             _player3 = sh;
        }
        else
        {
            ship2* sh= new ship2(point((_FIELD_WIDTH*3)/4,_FIELD_HEIGHT/2),0,DIR_TOP,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
             sh->confCmd('i','k','l','j','u','o');
             _gObjects.append(sh);
             _player3 = sh;
        }

   /* //crear tres naves
    ship* sh = new ship(point(_FIELD_WIDTH/4,_FIELD_HEIGHT/2),0,DIR_TOP,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
    sh->confCmd('w','s','d','a',' ','m');
    _gObjects.append(sh);
    _player1= sh;

   ship sh= new ship(point((_FIELD_WIDTH*2)/4,_FIELD_HEIGHT/2),0,DIR_DOWN,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
    sh->confCmd('5','2','3','1','0','.');
    _gObjects.append(sh);
    _player2 = sh;

   ship sh= new ship(point((_FIELD_WIDTH*3)/4,_FIELD_HEIGHT/2),0,DIR_TOP,_FIELD_WIDTH,0,0,_FIELD_HEIGHT);
    sh->confCmd('i','k','l','j','u','o');
    _gObjects.append(sh);
    _player3 = sh;
*/
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

int gameController::checkCollitions()
{
    QList<QPoint> foundCollitions;
    for(int i=0; i<_gObjects.size();i++)
    {
        graphicObjects* currGo=_gObjects[i];
        for(int j=0;j<_gObjects.size();j++)
        {
            if(j==i)
                continue;
            //tenemos en i y j la forma de comparar

            if(foundCollitions.indexOf(QPoint(i,j))>=0)
                continue;

            QList<point> hitArea=_gObjects[j]->getHitArea();
            int nHits=_gObjects[i]->checkHit(hitArea);
            if(nHits>0)
            {

                _gObjects[i]->hit(_gObjects[j]);
                _gObjects[j]->hit(_gObjects[i]);
                foundCollitions.append(QPoint(i,j));
                foundCollitions.append(QPoint(j,i));

            }

        }
    }
}

int gameController::addNewGraphObj()
{
    for(int i=0;i<_gObjects.size();i++)
        _gObjects.append(_gObjects[i]->createGo());
    return 0;
}

int gameController::removeDeadObjects()
{
    for(int i=0;i<_gObjects.size();i++)
        if(!_gObjects[i]->alive())
        {
            if(_gObjects[i]==_player1)
                _player1= NULL;
            if(_gObjects[i]==_player2)
                _player2=NULL;
            if(_gObjects[i]==_player3)
                _player3= NULL;
            delete _gObjects[i];
            _gObjects.removeAt(i);
            i--;

        }
    return 0;
}





gameController::gameController()
{

}

void gameController::pickShip(int* p1, int* p2, int* p3)
{
    /*
     primero:
     dibujar
     las naves.
     segundo.
     preguntar que nave quiere, a cada jugador.
     //como?
        preguntamos tres veces, primero juador1, luego jugador2 y luego jugador 3, con un cin.


     */


    std::cout<<"jugador1, porfavor elija con que nave quiere jugar: 1 o 2 "<<std::endl;
    std::cin>>(*p1);

    std::cout<<"jugador2, porfavor elija con que nave quiere jugar: 1 o 2 "<<std::endl;
    std::cin>>(*p2);

    std::cout<<"jugador3, porfavor elija con que nave quiere jugar: 1 o 2 "<<std::endl;
    std::cin>>(*p3);



}

